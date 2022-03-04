#include "generator_thread.h"

GeneratorThread::GeneratorThread()
{
    m_stopGenThread = new std::atomic<bool>();
    *m_stopGenThread = false;

    m_buffer = new Buffer(BUFF_SIZE);
}

GeneratorThread::~GeneratorThread()
{
    if (m_stopGenThread != nullptr)
    {
        delete m_stopGenThread;
        m_stopGenThread = nullptr;
    }

    if (m_buffer != nullptr)
    {
        delete m_buffer;
        m_buffer = nullptr;
    }
}

void GeneratorThread::init()
{
    m_buffer->init();

    m_generatorInstance.resetGen();
    m_generatorInstance.initGen(RED);
    m_generatorInstance.setParameters(AMP, FREQ, WAVEFORM_SIZE);
}

void GeneratorThread::start()
{
    m_genThread = std::thread([this]() -> void {
        while (!(*m_stopGenThread))
        {
            if (m_buffer->available(FRAME_SIZE_BYTES))
            {
                this->sendNextFrame();
            }
        }
    });
}

void GeneratorThread::stop()
{
    *m_stopGenThread = true;

    if (m_genThread.joinable())
    {
        m_genThread.join();
    }
}

void GeneratorThread::addData(uint8_t *data_, uint32_t size_)
{
    while (!m_buffer->addVals(data_, size_))
    {
        std::this_thread::yield();
    }
}

void GeneratorThread::sendNextFrame()
{
    uint8_t byteSize = 8;
    uint8_t bytes[FRAME_SIZE_BYTES];
    m_buffer->readAvailable(FRAME_SIZE_BYTES, bytes, FRAME_SIZE_BYTES);
    bool bits[FRAME_SIZE_BITS];

    // Preamble
    std::bitset<8> preamble(PREAMBLE);
    for (int8_t j = byteSize - 1; j >= 0; j--)
    {
        for (uint8_t i = 0; i < RED; i++)
        {
            bits[(i * RED) + (byteSize - j - 1)] = preamble[j];
        }
    }

    // Rest of data
    for (uint32_t k = 0; k < FRAME_SIZE_BYTES; k++)
    {
        std::bitset<8> byte(bytes[k]);
        for (int8_t j = byteSize - 1; j >= 0; j--)
        {
            for (uint8_t i = 0; i < RED; i++)
            {
                bits[((k + 1) * byteSize) + (i * RED) + (byteSize - j - 1)] = byte[j];
            }
        }
    }
    // Generate
    m_generatorInstance.genWaveform(bits, FRAME_SIZE_BITS);
}
