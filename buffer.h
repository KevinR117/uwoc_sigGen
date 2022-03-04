#include <cstdint>
#include <mutex>
#include <iostream>

#pragma once

class Buffer
{
public:

    explicit Buffer(uint32_t size_);

    ~Buffer();

    void init();

    uint32_t size() const;

    uint8_t** buff() const;

    uint32_t beginIndex() const;

    uint32_t endIndex() const;

    bool available(uint32_t threshold_) const;

    bool addVals(const uint8_t* data_, uint32_t size_);

    uint32_t readAvailable(uint32_t allocatedSize_, uint8_t* dataOut_, uint32_t maxReadSize_);

private:

    uint32_t m_buffSize;

    uint8_t** m_content = nullptr;

    uint32_t m_beginRead = 0;

    uint32_t m_endRead = 0; // Excluded

    std::mutex m_mutex;
};
