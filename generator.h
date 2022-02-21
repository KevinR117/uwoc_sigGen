#include <iostream>

#include "rp.h"

#pragma once

class Generator
{
public:

    enum redundancy_t : uint16_t {
        RED_1 = 1,
        RED_2 = 2,
        RED_4 = 4,
        RED_8 = 8,
        RED_16 = 16,
        RED_32 = 32,
        RED_64 = 64,
        RED_128 = 128
    };

    Generator() = default;

    ~Generator();

    void setParameters(float amp_, float freq_, uint32_t waveformSize_);

    void initGen(redundancy_t redundancy_);

    void resetGen();

    float bitDurationNs() const;

    void genWaveform(const bool* data_, uint32_t size_) const;

private:

    static constexpr const uint32_t DEFAULT_WAVEFORM_SIZE = 16384;

    static constexpr const float DEFAULT_FREQ = 4000.0;

    static constexpr const float DEFAULT_AMP = 1.0;

    static constexpr const redundancy_t DEFAULT_RED = RED_64;

    void applyParameters();

    void generate() const;

    float m_amp = DEFAULT_AMP;

    float m_freq = DEFAULT_FREQ;

    uint32_t m_waveformSize = DEFAULT_WAVEFORM_SIZE;

    uint32_t m_utilDataSize = 0;

    float m_burstPeriod = 0.0;

    redundancy_t m_red = DEFAULT_RED;

    float* m_waveform = nullptr;
};
