cmake_minimum_required(VERSION 4.0)
project(shimaneitdesignsim)

set(CMAKE_CXX_STANDARD 20)

add_executable(game main.cpp
                    ata.cpp
                    ata.h
)