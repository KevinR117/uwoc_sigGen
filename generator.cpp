#include "generator.h"

#include <chrono>

/// \brief              Destructor
Generator::~Generator()
{
    if (m_waveform != nullptr)
    {
        delete m_waveform;
        m_waveform = nullptr;
    }
}

/// \brief              Set parameters to the generator object
void Generator::setParameters(float amp_, float freq_, uint32_t waveformSize_)
{
    if (amp_ < 0)
    {
        std::cout << "Amplitude need to be a positive float number" << std::endl;
    }
    else
    {
        m_amp = amp_;
    }
    if (freq_ < 0)
    {
        std::cout << "Frequency need to be a positive float number" << std::endl;
    }
    else
    {
        m_freq = freq_;
    }
    m_waveformSize = waveformSize_;
    m_utilDataSize = m_waveformSize / m_red;

    m_waveform = new float[m_waveformSize];

    this->applyParameters();
}

/// \brief              Initialize card generator
void Generator::initGen(redundancy_t redundancy_)
{
    // Set redundancy
    m_red = redundancy_;

    if (rp_IsApiInit())
    {
        // Trigger
        rp_GenTriggerSource(RP_CH_1, RP_GEN_TRIG_SRC_INTERNAL);

        // Mode set to arbitrary waveform
        rp_GenWaveform(RP_CH_1, RP_WAVEFORM_ARBITRARY);

        // Burst mode for sending a period only once
        rp_GenMode(RP_CH_1, RP_GEN_MODE_BURST);
        rp_GenBurstCount(RP_CH_1, 1);
        rp_GenBurstRepetitions(RP_CH_1, 1);

	// Enable output
        rp_GenOutEnable(RP_CH_1);
    }
    else
    {
        std::cout << "RP card not initialized" << std::endl;
    }
}

/// \brief              Reset card generator to default parameters
void Generator::resetGen()
{
    if (rp_IsApiInit())
    {
        rp_GenReset();
    }
    else
    {
        std::cout << "RP card not initialized" << std::endl;
    }
}

/// \brief              Get bit duration in nanoseconds
float Generator::bitDurationNs() const
{
    float res;
    res = (m_burstPeriod / static_cast<float>(m_utilDataSize)) * 1000;
    return res;
}

/// \brief              Apply generator parameters to the card
void Generator::applyParameters()
{
    if (rp_IsApiInit())
    {
        // Basic parameters
        rp_GenAmp(RP_CH_1, m_amp);
        rp_GenFreq(RP_CH_1, m_freq);

        // Set a period of one burst
        m_burstPeriod = (1 / m_freq) * 1000000;
        rp_GenBurstPeriod(RP_CH_1, static_cast<uint32_t>(m_burstPeriod));
    }
    else
    {
        std::cout << "RP card not initialized" << std::endl;
    }
}

/// \brief              Store a new waveform into the generator object
void Generator::genWaveform(const bool *data_, uint32_t size_) const
{
    if (rp_IsApiInit())
    {
        if (size_ != m_utilDataSize)
        {
            std::cout << "Given data buffer needs to contain " << m_utilDataSize << " bytes" << std::endl;
        }
        else
        {
	    for (uint32_t i = 0; i < size_; i++)
            {
                for (uint32_t j = 0; j < m_red; j++)
                {
                    m_waveform[(i * m_red) + j] = static_cast<float>(data_[i]);
                }
            }

	    rp_GenArbWaveform(RP_CH_1, m_waveform, m_waveformSize);
            this->generate();
        }
    }
    else
    {
        std::cout << "RP card not initialized" << std::endl;
    }
}

/// \brief              Generate the waveform on the output analog port of the RP card
void Generator::generate() const
{
    if (rp_IsApiInit())
    {
	// Trigger output
        rp_GenTrigger(RP_T_CH_1);

        // Set frequency again to make it ready again
        rp_GenFreq(RP_CH_1, m_freq);
    }
    else
    {
        std::cout << "RP card not initialized" << std::endl;
    }
}
