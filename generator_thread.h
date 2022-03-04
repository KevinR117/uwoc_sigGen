#include <thread>
#include <bitset>
#include <atomic>

#include "generator.h"
#include "buffer.h"

#pragma once

class GeneratorThread
{
public:

    GeneratorThread();

    ~GeneratorThread();

    void init();

    void start();

    void stop();

    void addData(uint8_t* data_, uint32_t size_);

private:

    static constexpr const float FREQ = 190.748689;

    static constexpr const uint32_t WAVEFORM_SIZE = 16384;

    static constexpr const float AMP = 1;

    static constexpr const Generator::redundancy_t RED = Generator::RED_8;

    static constexpr const uint32_t BUFF_SIZE = 32768;

    static constexpr const uint32_t FRAME_SIZE_BITS = WAVEFORM_SIZE / RED;

    static constexpr const uint32_t FRAME_SIZE_BYTES = (FRAME_SIZE_BITS / 8) - 1; // -1 to save place for preamble

    static constexpr const uint8_t PREAMBLE = 'U';

    void sendNextFrame();

    std::thread m_genThread;

    Generator m_generatorInstance;

    std::atomic<bool>* m_stopGenThread;

    Buffer* m_buffer;
};
