#include <thread>
#include <bitset>
#include <atomic>

#include "generator.h"
#include "buffer.h"

#pragma once

/** \name               GeneratorThread
 *  \brief              Thread that is waiting for data in order to send it thanks to a generator instance
**/
class GeneratorThread
{
public:

    /*******************************************************
     * \section             Constructor, destructor
     *
    *******************************************************/

    /** \brief              Assign constructor
    **/
    GeneratorThread();

    /** \brief              Destructor
    **/
    ~GeneratorThread();
    
    /*******************************************************
     * \section             Methods and functions
     *
    *******************************************************/

    /** \brief              Init thread
    **/
    void init();

    /** \brief              Start thread
    **/
    void start();

    /** \brief              Stop thread
    **/
    void stop();

    /** \brief              Add some data in the thread queue before being sent through the signal generator
     *  \param[in]          data_ Data to send
     *  \param[in]          size_ Data length
    **/
    void addData(uint8_t* data_, uint32_t size_);

private:

    /*******************************************************
     * \section             Constants
     *
    *******************************************************/
    
    /// \brief              Burst frequency (in Hertz)
    static constexpr const float FREQ = 190.748689; // this value is chosen for having exactly 5 decimated values per bit for reading

    /// \brief              Size of the waveform array
    static constexpr const uint32_t WAVEFORM_SIZE = 16384;

    /// \brief              Signal amplitude (in Volts)
    static constexpr const float AMP = 1;

    /// \brief              Bits redundancy
    static constexpr const Generator::redundancy_t RED = Generator::RED_8;

    /// \brief              Size of the thread data queue
    static constexpr const uint32_t BUFF_SIZE = 32768;

    /// \brief              Length of one frame (number of bits, without redundancy)
    static constexpr const uint32_t FRAME_SIZE_BITS = WAVEFORM_SIZE / RED;

    /// \brief              Length of one frame (number of bytes, without redundancy and without preamble)
    static constexpr const uint32_t FRAME_SIZE_BYTES = (FRAME_SIZE_BITS / 8) - 1; // -1 to save place for preamble

    /// \brief              Preamble of a frame
    static constexpr const uint8_t PREAMBLE = 'U';

    /*******************************************************
     * \section             Private methods and functions
     *
    *******************************************************/
    
    /** \brief              Send the next frame of the queue through the signal generator
    **/
    void sendNextFrame();

    /*******************************************************
     * \section             Private members
     *
    *******************************************************/
    
    /// \brief              Thread
    std::thread m_genThread;

    /// \brief              Signal generator instance
    Generator m_generatorInstance;

    /// \brief              Tells when to stop the thread properly
    std::atomic<bool>* m_stopGenThread;

    /// \brief              Thread queue
    Buffer* m_buffer;
};
