#include "reader_thread.h"

ReaderThread::ReaderThread()
{
    m_stopReadThread = new std::atomic<bool>();
    *m_stopReadThread = false;

    m_buffer = new float[RECV_SIZE];
    m_rawBuffer = new uint8_t[OUT_SIZE];
    m_utilBuffer = new uint8_t[FRAME_SIZE];
}

ReaderThread::~ReaderThread()
{
    if (m_stopReadThread != nullptr)
    {
        delete m_stopReadThread;
        m_stopReadThread = nullptr;
    }

    if (m_buffer != nullptr)
    {
        delete[] m_buffer;
        m_buffer = nullptr;
    }

    if (m_rawBuffer != nullptr)
    {
        delete[] m_rawBuffer;
        m_rawBuffer = nullptr;
    }

    if (m_utilBuffer != nullptr)
    {
        delete[] m_utilBuffer;
        m_utilBuffer = nullptr;
    }
}

void ReaderThread::init()
{
    m_readerInstance.resetReader();
    m_readerInstance.setParameters(PREAMBLE);
    m_readerInstance.initReader(DECIMATION, FREQ, RED);
}

void ReaderThread::start()
{
    m_readThread = std::thread([this]() -> void {
        rp_acq_trig_state_t state = RP_TRIG_STATE_WAITING;
        while (!(*m_stopReadThread))
        {
            m_readerInstance.readAnalog(m_buffer, RECV_SIZE, state, m_stopReadThread);
            m_readerInstance.analyseBuffer(m_buffer, RECV_SIZE, m_rawBuffer, OUT_SIZE);
            m_readerInstance.extractBytes(m_rawBuffer, OUT_SIZE, m_utilBuffer, FRAME_SIZE);
//            this->printReceivedContent();
        }
    });
}

void ReaderThread::stop()
{
    *m_stopReadThread = true;

    if (m_readThread.joinable())
    {
        m_readThread.join();
    }
}

void ReaderThread::printReceivedContent() const
{
    std::cout << "RECEIVED : ";
    for (uint32_t i = 0; i < FRAME_SIZE; i++)
    {
        std::cout << std::hex << (uint16_t)m_utilBuffer[i] << " ";
    }
    std::cout << std::endl;
}
