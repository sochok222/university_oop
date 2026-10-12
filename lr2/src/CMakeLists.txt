cmake_minimum_required(VERSION 4.1)
project(src)

set(CMAKE_CXX_STANDARD 20)

set(${PROJECT_NAME}_src
        main.cpp

        Time.cpp
        Time.h
)

add_executable(src ${${PROJECT_NAME}_src})
