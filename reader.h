#include <iostream>
#include <bitset>
#include <atomic>

#include "rp.h"
#include "kiss_fft.h"

#pragma once

/** \name               Reader
 *  \brief              This class is used for reading on the analog port
**/
class Reader
{
public:

    /*******************************************************
     * \section             Constructor, Destructor
     *
    *******************************************************/
    
    /** \brief              Constructor
    **/
    Reader();

    /** \brief              Destructor
    **/
    ~Reader();
    
    /*******************************************************
     * \section             Methods and functions
     *
    *******************************************************/

    /** \brief              Set the parameters necessary for the reader (to work properly)
     *  \param[in]          preamble_ Preamble of all sent frames (placed at the beginning of a message)   
    **/
    void setParameters(uint8_t preamble_);

    /** \brief              Initialize reader object
     *  \param[in]          decimation_ Decimation used to extract data (according to data rate used)
     *  \param[in]          freq_ Frequency of the signal             
     *  \param[in]          redundancy_ Redundancy coefficient of data used            
    **/
    void initReader(rp_acq_decimation_t decimation_, float freq_, uint16_t redundancy_);

    /** \brief              Reset Reader parameters to default ones
    **/
    void resetReader();

    /** \brief              Analyse the received buffer (find the beginning of the frame and extract decimated data)
     *  \param[in]          buffer_ Buffer that has just been received
     *  \param[in]          buffSize_ Size of the received buffer
     *  \param[out]         dataOut_ Data that is extracted from the read buffer
     *  \param[in]          size_ Size of the extracted data array           
    **/
    void analyseBuffer(const float* buffer_, uint32_t buffSize_, uint8_t* dataOut_, uint32_t size_);

    /** \brief              Read data from the RP card (fill a receive buffer)
     *  \param[out]         buffer_ Buffer to fill with received data       
     *  \param[in]          buffSize_ Size of the received buffer
     *  \param[out]         state_ State of the RP trigger (waiting or triggered)
     *  \param[in]          stopWaiting_ If the thread is finished, stop wait             
    **/
    void readAnalog(float* buffer_, uint32_t buffSize_, rp_acq_trig_state_t& state_, std::atomic<bool>* stopWaiting_);

    /** \brief              Extract util data from the extracted data (as above) and delete redundancy
     *  \param[in]          rawData_ Raw data not processed yet
     *  \param[out]         rawSize_ Raw data length
     *  \param[out]         utilData_ Extracted data without redundancy
     *  \param[in]          rawSize_ Extracted data length
     *  \return             
    **/
    void extractBytes(uint8_t* rawData_, uint32_t rawSize_, uint8_t* utilData_, uint32_t utilSize_);

private:

    /*******************************************************
     * \section             Constants
     *
    *******************************************************/
    
    /// \brief              Default decimation factor
    static constexpr const rp_acq_decimation_t DEFAULT_DEC = RP_DEC_64;

    /// \brief              Default signal frequency
    static constexpr const float DEFAULT_FREQ = 4000.0;

    /// \brief              Default redundancy factor
    static constexpr const uint16_t DEFAULT_RED = 64;

    /// \brief              Default redundancy factor for reading (linked with the decimation factor choice)
    static constexpr const uint16_t DEFAULT_READ_RED = 5;

    /*******************************************************
     * \section             Private methods and functions
     *
    *******************************************************/
    
    /** \brief              In charge of finding the beginning of a frame thanks to the intercorrelation array
     *  \param[in]          interCorr_ Interrcorrelation array computed between preamble array and received buffer
     *  \param[out]         size_ Size of the array
     *  \return             Index of the maximum correlation which means the beginning of the frame
    **/
    uint32_t maxCorrIndex(kiss_fft_cpx* interCorr_, uint32_t size_) const;

    /** \brief              Compute bit duration in microseconds based on the decimation factor
     *  \return             Duration in microseconds
    **/
    uint32_t decimationToDurationUs();

    /*******************************************************
     * \section             Private members
     *
    *******************************************************/
    
    /// \brief              Decimation factor
    rp_acq_decimation_t m_decimation = DEFAULT_DEC;

    /// \brief              Preamble of frames that will help to find the beginning of the frame
    uint8_t m_preamble = 0x00;

    /// \brief              Preamble array with read redundancy applied (linked to the decimation factor choice)
    uint8_t* m_preambleRed;

    /// \brief              Received signal Fourier transormed
    kiss_fft_cpx* m_cpxSignal;

    /// \brief              Preamble Fourier transformed
    kiss_fft_cpx* m_cpxPreamble;

    /// \brief              Result of intercorrelation between preamble and signal computation
    kiss_fft_cpx* m_cpxCorr;

    /// \brief              Read redundancy (linked to the decimation factor choice)
    uint16_t m_nbValuesPerBit = DEFAULT_READ_RED;

    /// \brief              Signal frequency
    float m_genFreq = DEFAULT_FREQ;

    /// \brief              Redundancy
    uint16_t m_genRedundancy = DEFAULT_RED;
};
