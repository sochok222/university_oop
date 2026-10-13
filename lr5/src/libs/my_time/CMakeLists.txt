cmake_minimum_required(VERSION 4.1)
project(Time)

set(${PROJECT_NAME}_src
        MyTime.cpp
        MyTime.h
)

add_library(${PROJECT_NAME} STATIC ${${PROJECT_NAME}_src})

target_include_directories(
        ${PROJECT_NAME}
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)