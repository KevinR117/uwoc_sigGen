# Signal Generator UWOC

## Usage

This library is supposed to be running on the RedPitaya card within the running server. Actually, the received data from the client will be passed to the signal generator and received data from the analog input of the card will be passed to the signal reader before being sent back to the distant client.
This has not been implemented yet, but this addition might be simple :
  Need to add the initialisation and start of threads (generator and reader) at the server initialisation and start.
  Then you just need to make the server send data when something is received on the card and add the generator send function into the receive handler of the server (callback called when data is received on the server and has to be generated through the analog output)

## Build and link

For that you just need to put the files into the server folder, and copy the CMakeLists content of the generator library to the server CMakeLists.

Finally, you need to link the generator library to the server executable. That should work !
