#include <thread>
#include <atomic>
#include <functional>

#include "reader.h"

#pragma once

/** \name               ReaderThread
 *  \brief              Thread that is waiting for data to be received thanks to a reader instance
**/
class ReaderThread
{
public:

    /*******************************************************
     * \section             Constructor, destructor
     *
    *******************************************************/
    
    /** \brief              Constructor
    **/
    ReaderThread();

    /** \brief              Destructor
    **/
    ~ReaderThread();
    
    /*******************************************************
     * \section             Methods, functions
     *
    *******************************************************/

    /** \brief              Initialize thread
    **/
    void init();

    /** \brief              Start thread
    **/
    void start();

    /** \brief              Stop thread
    **/
    void stop();

    /** \brief              Print the extracted data from the initial received buffer (raw data)
    **/
    void printReceivedContent() const;

private:

    /*******************************************************
     * \section             Constants
     *
    *******************************************************/
    
    /// \brief              Signal frequency
    static constexpr const float FREQ = 190.748689;

    /// \brief              Redundancy factor
    static constexpr const uint16_t RED = 8;

    /// \brief              Decimation factor
    static constexpr const rp_acq_decimation_t DECIMATION = RP_DEC_64;

    /// \brief              Preamble used at the beginning of a frame
    static constexpr const uint8_t PREAMBLE = 'U';

    /// \brief              Size of a received buffer from RP analog input
    static constexpr const uint32_t RECV_SIZE = ADC_BUFFER_SIZE;

    /// \brief              Size of raw data extracted from a received buffer (still with redundancy)
    static constexpr const uint32_t OUT_SIZE = 2040;

    /// \brief              Final data size (without redundancy this time)
    static constexpr const uint32_t FRAME_SIZE = 255;

    /*******************************************************
     * \section             Private members
     *
    *******************************************************/
    
    /// \brief              Thread
    std::thread m_readThread;

    /// \brief              Tells when to stop the thread properly
    std::atomic<bool>* m_stopReadThread;

    /// \brief              Reader instance
    Reader m_readerInstance;

    /// \brief              Buffer that will be filled with data from the RP analog input
    float* m_buffer;

    /// \brief              Array containing extracted raw data (still with redundancy)
    uint8_t* m_rawBuffer;

    /// \brief              Array containing util data (without redundancy this time)
    uint8_t* m_utilBuffer;
};
