#include <thread>
#include <atomic>
#include <functional>

#include "reader.h"

#pragma once

class ReaderThread
{
public:

    ReaderThread();

    ~ReaderThread();

    void init();

    void start();

    void stop();

    void printReceivedContent() const;

private:

    static constexpr const float FREQ = 190.748689;

    static constexpr const uint16_t RED = 8;

    static constexpr const rp_acq_decimation_t DECIMATION = RP_DEC_64;

    static constexpr const uint8_t PREAMBLE = 'U';

    static constexpr const uint32_t RECV_SIZE = ADC_BUFFER_SIZE;

    static constexpr const uint32_t OUT_SIZE = 2040;

    static constexpr const uint32_t FRAME_SIZE = 255;

    std::thread m_readThread;

    std::atomic<bool>* m_stopReadThread;

    Reader m_readerInstance;

    float* m_buffer;

    uint8_t* m_rawBuffer;

    uint8_t* m_utilBuffer;
};
