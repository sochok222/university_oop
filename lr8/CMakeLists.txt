cmake_minimum_required(VERSION 4.1)
project(lr8)

set(CMAKE_CXX_STANDARD 20)

add_executable(lr8
        main.cpp

        triad.cpp
        triad.h

        date.cpp
        date.h
)
