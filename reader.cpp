#include <chrono>

#include "reader.h"

/// \brief              Constructor
Reader::Reader()
{
    m_cpxSignal = new kiss_fft_cpx[ADC_BUFFER_SIZE];
    m_cpxPreamble = new kiss_fft_cpx[ADC_BUFFER_SIZE];
    m_cpxCorr = new kiss_fft_cpx[ADC_BUFFER_SIZE];
    m_preambleRed = new uint8_t[8 * m_nbValuesPerBit];
}

/// \brief              Destructor
Reader::~Reader()
{
    if (m_preambleRed != nullptr)
    {
        delete[] m_preambleRed;
        m_preambleRed = nullptr;
    }

    if (m_cpxSignal != nullptr)
    {
        delete[] m_cpxSignal;
        m_cpxSignal = nullptr;
    }

    if (m_cpxPreamble != nullptr)
    {
        delete[] m_cpxPreamble;
        m_cpxPreamble = nullptr;
    }

    if (m_cpxCorr != nullptr)
    {
        delete[] m_cpxCorr;
        m_cpxCorr = nullptr;
    }
}

/// \brief              Set parameters necessary to the reader
void Reader::setParameters(uint8_t preamble_)
{
    m_preamble = preamble_;
}

/// \brief              Initialize reader object
void Reader::initReader(rp_acq_decimation_t decimation_, float freq_, uint16_t redundancy_)
{
    m_genRedundancy = redundancy_;
    m_genFreq = freq_;
    m_decimation = decimation_;

    // Apply redundancy factor to the preamble (in order to be used later)
    std::bitset<8> preambleBitset(m_preamble);
    for (int8_t j = 8; j >= 0; j--)
    {
        for (uint32_t i = 0; i < m_nbValuesPerBit; i++)
        {
            m_preambleRed[(i * m_nbValuesPerBit) + (8 - j - 1)] = preambleBitset[j];
        }
    }

    // Initialize RP input
    if (rp_IsApiInit())
    {
        rp_AcqSetDecimation(m_decimation);
        rp_AcqSetTriggerLevel(RP_T_CH_1, 0.2);
        rp_AcqSetTriggerDelay(ADC_BUFFER_SIZE / 2);
    }
    else
    {
        std::cout << "RP card not initialized" << std::endl;
    }
}

/// \brief              Reset reader parameters to default ones
void Reader::resetReader()
{
    if (rp_IsApiInit())
    {
        rp_AcqReset();
    }
    else
    {
        std::cout << "RP card not initialized" << std::endl;
    }
}

/// \brief              Extract the received frame as raw data
void Reader::analyseBuffer(const float *buffer_, uint32_t buffSize_, uint8_t *dataOut_, uint32_t size_)
{


    if (buffSize_ != ADC_BUFFER_SIZE)
    {
        std::cout << "Wrong buffer size" << std::endl;
    }
    else
    {
        kiss_fft_cfg cfgSignal = kiss_fft_alloc(ADC_BUFFER_SIZE, false, nullptr, nullptr);
        kiss_fft_cfg cfgPreamble = kiss_fft_alloc(ADC_BUFFER_SIZE, false, nullptr, nullptr);
        kiss_fft_cfg cfgCorr = kiss_fft_alloc(ADC_BUFFER_SIZE, true, nullptr, nullptr);

        // Signal
        for (uint32_t i = 0; i < ADC_BUFFER_SIZE; i++)
        {
            m_cpxSignal[i].r = buffer_[i];
            m_cpxSignal[i].i = static_cast<float>(0);
        }
        kiss_fft_cpx cpxSignalFft[ADC_BUFFER_SIZE];
        kiss_fft(cfgSignal, m_cpxSignal, cpxSignalFft);

        // Preamble
        for (uint32_t i = 0; i < ADC_BUFFER_SIZE; i++)
        {
            if (i < (m_nbValuesPerBit * 8))
            {
                m_cpxPreamble[i].r =static_cast<float>(m_preambleRed[i]);
            }
            else
            {
                m_cpxPreamble[i].r = 0;
            }
            m_cpxPreamble[i].i = static_cast<float>(0);
        }
        kiss_fft_cpx cpxPreambleFft[ADC_BUFFER_SIZE];
        kiss_fft(cfgPreamble, m_cpxPreamble, cpxPreambleFft);

        // Make correlation between signals
        kiss_fft_cpx cpxCorrFft[ADC_BUFFER_SIZE];
        for (uint32_t i = 0; i < ADC_BUFFER_SIZE; i++)
        {
            cpxCorrFft[i].r = cpxSignalFft[i].r * cpxPreambleFft[i].r;
            cpxCorrFft[i].i = static_cast<float>(0);
        }
        kiss_fft(cfgCorr, cpxCorrFft, m_cpxCorr);

        // Maximal of intercorrelation
        uint32_t maxIndex = this->maxCorrIndex(m_cpxCorr, ADC_BUFFER_SIZE);

        // Then extract data from buffer based on the beginning of the message and ignoring preamble
        uint32_t count = 1;
        float tempAverage = 0;
        uint32_t outIndex = 0;
        for (uint32_t i = maxIndex + (m_genRedundancy * 8); i < (ADC_BUFFER_SIZE / m_genRedundancy); i++)
        {
            uint32_t realIndex = (i < ADC_BUFFER_SIZE) ? i : i % ADC_BUFFER_SIZE;
            tempAverage += buffer_[realIndex];
            count++;
            if ((count % m_nbValuesPerBit) == 0)
            {
                tempAverage /= static_cast<float>(m_nbValuesPerBit);
                dataOut_[outIndex] = static_cast<bool>(round(tempAverage));
                count = 1;
            }
        }
    }
}

/// \brief              Fill a receive buffer with data from RP analog input
void Reader::readAnalog(float* buffer_, uint32_t buffSize_, rp_acq_trig_state_t& state_, std::atomic<bool>* stopWaiting_)
{
    if (rp_IsApiInit())
    {
        if (buffSize_ != ADC_BUFFER_SIZE)
        {
            std::cout << "Wrong buffer size" << std::endl;
        }
        else
        {
            rp_AcqStart();
            rp_AcqSetTriggerSrc(RP_TRIG_SRC_CHA_PE);
            while(true)
            {
                if (*stopWaiting_)
                {
                    break;
                }
                rp_AcqGetTriggerState(&state_);
                if (state_ == RP_TRIG_STATE_TRIGGERED)
                {
                    std::cout << "TRIGGERED" << std::endl;
                    break;
                }
            }
            rp_AcqStop();

            // Read when triggered
            rp_AcqGetOldestDataV(RP_CH_1, &buffSize_, buffer_);
        }
    }
    else
    {
        std::cout << "RP card is not initialized" << std::endl;
    }
}

/// \brief              Find the beginning index of the frame
uint32_t Reader::maxCorrIndex(kiss_fft_cpx *interCorr_, uint32_t size_) const
{
    uint32_t res = 0;
    if (size_ != ADC_BUFFER_SIZE)
    {
        std::cout << "Wrong buffer size" << std::endl;
    }
    else
    {
        auto temp = static_cast<float>(0);
        // Look for the maximum correlation where the frame begin
        for (uint32_t i = 0; i < ADC_BUFFER_SIZE; i++)
        {
            if (interCorr_[i].r > temp)
            {
                temp = interCorr_[i].r;
                res = i;
            }
        }
    }
    return res;
}

/// \brief              Extract util data from raw data (and delete redundancy of data)
void Reader::extractBytes(uint8_t *rawData_, uint32_t rawSize_, uint8_t *utilData_, uint32_t utilSize_)
{
    if ((rawSize_ / 8) != utilSize_)
    {
        std::cout << "Wrong buffer size" << std::endl;
    }
    else
    {
        for (uint32_t i = 0; i < utilSize_; i++)
        {
            // Easier with a bitset object that we fill with util data
            std::bitset<8> val;
            for (int8_t j = 7; j >= 0; j++)
            {
                val[j] = rawData_[(i * 8) + j];
            }
            // Finally, cast it to get the real data
            utilData_[i] = static_cast<uint8_t>(val.to_ulong());
        }
    }
}

/// \brief              Get bit duration in microseconds according to the decimation factor
uint32_t Reader::decimationToDurationUs()
{
    switch(m_decimation)
    {
        case RP_DEC_1 : return 131;
        case RP_DEC_2 : return 262;
        case RP_DEC_4 : return 524;
        case RP_DEC_8 : return 1048;
        case RP_DEC_16 : return 2096;
        case RP_DEC_32 : return 4192;
        case RP_DEC_64 : return 8388;
        case RP_DEC_128 : return 16768;
        case RP_DEC_256 : return 33798;
        case RP_DEC_512 : return 67070;
        case RP_DEC_1024 : return 134200;
        case RP_DEC_2048 : return 268288;
        case RP_DEC_4096 : return 536500;
        case RP_DEC_8192 : return 1073000;
        case RP_DEC_16384 : return 2146000;
        case RP_DEC_32768 : return 4292000;
        case RP_DEC_65536 : return 8589000;
        default: throw std::runtime_error("Unknown decimation value");
    }
}
