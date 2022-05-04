cmake_minimum_required(VERSION 3.5.1)
project(uwoc_sigGen)

set(CMAKE_CXX_STANDARD 14)

find_package(Threads REQUIRED)
find_package(Boost REQUIRED)

add_definitions(-DBOOST_ERROR_CODE_HEADER_ONLY)
add_definitions(-DBOOST_SYSTEM_NO_DEPRECATED)

set(librp /opt/redpitaya/lib/librp.so)
set(librp_include /opt/redpitaya/include)
set(SRCS generator.cpp generator_thread.cpp buffer.cpp reader.cpp reader_thread.cpp kiss_fft.c)

add_library(uwoc_sigGen ${SRCS})
target_include_directories(uwoc_sigGen PUBLIC ${Boost_INCLUDE_DIRS} ${librp_include})
target_link_libraries(uwoc_sigGen PUBLIC ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} ${librp})

add_executable(test main.cpp)
target_link_libraries(test PUBLIC uwoc_sigGen)
