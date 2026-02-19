cmake_minimum_required(VERSION 4.0)
project(shimaneitdesignsim)

set(CMAKE_CXX_STANDARD 20)

if(APPLE)
    set(MAIN_SRC main_macos.cpp)
else()
    set(MAIN_SRC main.cpp)
endif()

add_executable(game ${MAIN_SRC}
                    ata.cpp
                    ata.h
)
