#include <iostream>
#include <bitset>
#include <atomic>

#include "rp.h"
#include "kiss_fft.h"

#pragma once

class Reader
{
public:

    Reader();

    ~Reader();

    void setParameters(uint8_t preamble_);

    void initReader(rp_acq_decimation_t decimation_, float freq_, uint16_t redundancy_);

    void resetReader();

    void analyseBuffer(const float* buffer_, uint32_t buffSize_, uint8_t* dataOut_, uint32_t size_);

    void readAnalog(float* buffer_, uint32_t buffSize_, rp_acq_trig_state_t& state_, std::atomic<bool>* stopWaiting_);

    void extractBytes(uint8_t* rawData_, uint32_t rawSize_, uint8_t* utilData_, uint32_t utilSize_);

private:

    static constexpr const rp_acq_decimation_t DEFAULT_DEC = RP_DEC_64;

    static constexpr const float DEFAULT_FREQ = 4000.0;

    static constexpr const uint16_t DEFAULT_RED = 64;

    static constexpr const uint16_t DEFAULT_READ_RED = 5;

    uint32_t maxCorrIndex(kiss_fft_cpx* interCorr_, uint32_t size_) const;

    uint32_t decimationToDurationUs();

    rp_acq_decimation_t m_decimation = DEFAULT_DEC;

    uint8_t m_preamble = 0x00;

    uint8_t* m_preambleRed;

    kiss_fft_cpx* m_cpxSignal;

    kiss_fft_cpx* m_cpxPreamble;

    kiss_fft_cpx* m_cpxCorr;

    uint16_t m_nbValuesPerBit = DEFAULT_READ_RED;

    float m_genFreq = DEFAULT_FREQ;

    uint16_t m_genRedundancy = DEFAULT_RED;
};
