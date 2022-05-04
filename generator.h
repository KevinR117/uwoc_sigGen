#include <iostream>

#include "rp.h"

#pragma once

/** \name               Generator
 *  \brief              Control output analog port of the RP card (generation of signals)
**/
class Generator
{
public:

    /*******************************************************
     * \section             Enumerated types
     *
    *******************************************************/

    /// \brief              Redundancy of the generated signal (each bit is repeated <red_n> times in the sent signal)
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

    /*******************************************************
     * \section             Constructor, destructor
     *
    *******************************************************/

    /** \brief              Default assign constructor
    **/
    Generator() = default;

    /** \brief              Destructor
    **/
    ~Generator();

    /*******************************************************
     * \section             Methods and functions
     *
    *******************************************************/

    /** \brief              Set output analog port parameters
     *  \param[in]          amp_ Signal amplitude (in Volts)
     *  \param[in]          freq_ Signal frequency (frequency of bursts in Hertz)
     *  \param[in]          waveformSize_ Size of the waveform array (arbitrary definition of a burst)
    **/
    void setParameters(float amp_, float freq_, uint32_t waveformSize_);

    /** \brief              Initialize generator
     *  \param[in]          redundancy_ Redundancy of the signal (cf. enumerated type)
    **/
    void initGen(redundancy_t redundancy_);

    /** \brief              Reset generator to default parameters
    **/
    void resetGen();

    /** \brief              Get duration of a sent bit in nanoseconds
     *  \return             Bit time in nanoseconds
    **/
    float bitDurationNs() const;

    /** \brief              Generate waveform
     *  \param[in]          data_ Array containing the waveform "drawing"
     *  \param[in]          size_ Size of the waveform array
    **/
    void genWaveform(const bool* data_, uint32_t size_) const;

private:

    /*******************************************************
     * \section             Constants
     *
    *******************************************************/

    /// \brief              Default size of the waveform array
    static constexpr const uint32_t DEFAULT_WAVEFORM_SIZE = 16384;

    /// \brief              Default signal frequency (in Hertz)
    static constexpr const float DEFAULT_FREQ = 4000.0;

    /// \brief              Default signal amplitude (in Volts)
    static constexpr const float DEFAULT_AMP = 1.0;

    /// \brief              Default bits redundancy
    static constexpr const redundancy_t DEFAULT_RED = RED_64;

    /*******************************************************
     * \section             Private methods and functions
     *
    *******************************************************/

    /** \brief              Apply parameters to the card port (through RP API)
    **/
    void applyParameters();

    /// \brief              Generate the previously created waveform (through RP API)
    void generate() const;

    /*******************************************************
     * \section             Private members
     *
    *******************************************************/
    
    /// \brief              Signal amplitude
    float m_amp = DEFAULT_AMP;

    /// \brief              Signal frequency
    float m_freq = DEFAULT_FREQ;

    /// \brief              Size of the waveform array
    uint32_t m_waveformSize = DEFAULT_WAVEFORM_SIZE;

    /// \brief              Size of util data (without redundancy applied)
    uint32_t m_utilDataSize = 0;

    /// \brief              Time length of a burst (cf. RP documentation)
    float m_burstPeriod = 0.0;

    /// \brief              Bits redundancy
    redundancy_t m_red = DEFAULT_RED;

    /// \brief              Array containing waveform to generate
    float* m_waveform = nullptr;
};
