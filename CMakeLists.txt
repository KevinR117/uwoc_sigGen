cmake_minimum_required(VERSION 3.5.1)
project(test_server)

set(CMAKE_CXX_STANDARD 14)

find_package(Threads REQUIRED)
find_package(Boost REQUIRED)

add_definitions(-DBOOST_ERROR_CODE_HEADER_ONLY)
add_definitions(-DBOOST_SYSTEM_NO_DEPRECATED)

set(librp /opt/redpitaya/lib/librp.so)
set(librp_include /opt/redpitaya/include)

add_executable(main main.cpp generator.cpp generator_thread.cpp buffer.cpp)
target_include_directories(main PUBLIC ${Boost_INCLUDE_DIRS})
target_include_directories(main PUBLIC ${librp_include})
target_link_libraries(main PUBLIC ${Boost_LIBRARIES})
target_link_libraries(main PUBLIC ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(main PUBLIC ${librp})
