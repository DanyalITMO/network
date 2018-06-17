cmake_minimum_required(VERSION 3.0)
project(network)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE
        source/TCPServer.cpp
        source/TcpSession.cpp
        )
include_directories(include)
add_library(network SHARED ${SOURCE})
target_include_directories(network PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include )