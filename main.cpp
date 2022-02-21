#include <iostream>
#include <thread>
#include <atomic>

#include "rp.h"
#include "generator.h"

//int initSignalGenerator()
//{
//    // WAVEFORM
//    int buffSize = 16384;
//    float waveform[buffSize];
//    int redundance = 64; // Puissance de 2
//    bool current = false;
//    for (int i = 0; i < buffSize; i += redundance)
//    {
//        for (int j = 0; j < redundance; j++)
//        {
//            waveform[i + j] = static_cast<float>(current);
//        }
//        current = !current;
//    }
//
//    // SIGNAL GENERATION
//    rp_GenTriggerSource(RP_CH_1, RP_GEN_TRIG_SRC_INTERNAL);
//
//    rp_GenWaveform(RP_CH_1, RP_WAVEFORM_ARBITRARY);
//    rp_GenArbWaveform(RP_CH_1, waveform, buffSize);
//    rp_GenAmp(RP_CH_1, 1.0);
//    rp_GenFreq(RP_CH_1, 16276.04166);
//
//    rp_GenMode(RP_CH_1, RP_GEN_MODE_BURST);
//    rp_GenBurstCount(RP_CH_1, 1);
//    rp_GenBurstRepetitions(RP_CH_1, 1);
//    rp_GenBurstPeriod(RP_CH_1, 61.44);
//}
//
//void initSignalReceiver()
//{
//    // SIGNAL ACQUISITION
//    rp_AcqReset();
//    rp_AcqSetDecimation(RP_DEC_1);
//    rp_AcqSetTriggerLevel(RP_T_CH_1, 0.2);
//    rp_AcqSetTriggerDelay(ADC_BUFFER_SIZE / 2);
//    rp_AcqSetTriggerSrc(RP_TRIG_SRC_CHA_PE);
//    rp_AcqStart();
//}
//
//void analyseBuffer(const float* buff_, uint32_t buffSize_, uint32_t startingIndex_, bool* outData_)
//{
//    uint32_t utilBuffSize = 7680; // The number of util data in the read buffer
//    uint32_t realBitSize = 30; // A bit is coded by 31.25 read values
//    //uint32_t skipValue = 124; // 31.25 exactly --> every 4 bits need to skip one octet to keep synchronized with the buffer
//    float tempSum = 0.0; // sum to compute average value
//    uint32_t count = 0;
//    float currentComputedVal;  // Average value of the last 31 octets read in the read buffer
//    bool currentComputedBit;
//    uint32_t effectiveIndex = 0; // Index of the current computed data bit
//    uint32_t bufferIndex = startingIndex_;
//
//    while (count < utilBuffSize)
//    {
//        if ((count % realBitSize) == 0)
//        {
//            // Compute average value
//            std::cout << "Index : " << effectiveIndex << "; sum : " << tempSum << std::endl;
//            currentComputedVal = tempSum / (static_cast<float>(realBitSize));
//            if (currentComputedVal < 0.5)
//            {
//                currentComputedBit = false;
//            }
//            else
//            {
//                currentComputedBit = true;
//            }
//            outData_[effectiveIndex] = currentComputedBit;
//            effectiveIndex++;
//            tempSum = 0.0;
//        }
//
//        // Adding value for computing average then
//        tempSum += buff_[bufferIndex];
//
//        if (bufferIndex + 1 == buffSize_)
//        {
//            bufferIndex = 0;
//        }
//        else
//        {
//            bufferIndex++;
//        }
//        count++;
//    }
//}

int main()
{
    if(rp_Init() != RP_OK)
    {
        fprintf(stderr, "Rp api init failed!\n");
    }

    bool data[2048];
    bool current = false;
    for (uint32_t i = 0; i < 2048; i++)
    {
	data[i] = current;
	if (i > 1000 && i < 1200)
	{
	    data[i] = 0;
	}
        current = !current;
    }
    
    Generator gen;

    gen.resetGen();
    gen.initGen(Generator::RED_8);
    gen.setParameters(1.0, 190.748689, 16384);

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    gen.genWaveform(data, 2048);

//    if(rp_Init() != RP_OK){
//        fprintf(stderr, "Rp api init failed!\n");
//    }
//
//    initSignalGenerator();
//    initSignalReceiver();
//
//    uint32_t recvSize = 16384;
//    float recv[recvSize];
//    rp_acq_trig_state_t state = RP_TRIG_STATE_WAITING;
//    auto* stopWait = new std::atomic<bool>();
//    *stopWait = false;
//
//    bool readData[256] = { false };
//
//    // Wait for the acquiring state to be triggered before reading the buffer
//    std::thread t([stopWait, &state, &recv, &recvSize, &readData]() -> void {
//        while(!(*stopWait))
//        {
//            rp_AcqGetTriggerState(&state);
//            if (state == RP_TRIG_STATE_TRIGGERED)
//            {
//                break;
//            }
//        }
//        rp_AcqGetOldestDataV(RP_CH_1, &recvSize, recv);
//        //std::cout << "READ CONTENT : " << std::endl;
//        uint32_t startingIndex = 0;
//        bool alreadyFound = false;
//        for (int i = 13000; i < recvSize; i++)
//        {
//            if ((recv[i] < -0.1 || recv[i] > 0.1) && !alreadyFound)
//            {
//                std::cout << "BEGIN OF DATA INDEX : " << i << std::endl;
//                startingIndex = i;
//                alreadyFound = true;
//            }
//            //std::cout << "index : " << i << "; "  <<  recv[i] << std::endl;
//        }
//        analyseBuffer(recv, recvSize, startingIndex, readData);
//        for (int i = 0; i < 256; i++)
//        {
//            std::cout << "index : " << i << "; " << readData[i] << std::endl;
//        }
//    });
//
//    std::this_thread::sleep_for(std::chrono::seconds(3));
//
//    // GENERATION OF BURST
//    rp_GenOutEnable(RP_CH_1);
//
//    std::this_thread::sleep_for(std::chrono::milliseconds(100));
//
//    *stopWait = true;
//    if (t.joinable())
//    {
//        t.join();
//    }
//
//    rp_Release();
//
//    delete stopWait;
//    stopWait = nullptr;

    return 0;
}
