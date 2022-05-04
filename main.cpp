#include <iostream>
#include <thread>
#include <atomic>

#include "rp.h"
#include "reader_thread.h"
#include "generator_thread.h"

// TO DELETE, THIS LIBRARY WILL BE THEN USED DIRECTLY IN THE SERVER PROJECT, THIS IS JUST AN EXAMPLE PIECE OF CODE
int main()
{
    // Init card instance
    if(rp_Init() != RP_OK)
    {
        fprintf(stderr, "Rp api init failed!\n");
    }

    // Init and start reader thread instance
    ReaderThread read;
    read.init();
    read.start();

    // Init and start generator thread instance
    GeneratorThread gen;
    gen.init();
    gen.start();

    // Initialize a dummy frame for sending
    uint8_t data[510];
    uint8_t c = 'U';
    for (uint32_t i = 0; i < 510; i++)
    {
        data[i] = c;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    // Generate this frame on the RP analog output
    gen.addData(data, 510);

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    // Stop threads
    gen.stop();
    read.stop();

    // Release the card instance
    rp_Release();

    return 0;
}
