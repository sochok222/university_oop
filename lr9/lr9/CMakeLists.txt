cmake_minimum_required(VERSION 4.1)
project(lr9)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME}
        main.cpp

        Shape.cpp
        Shape.h
        Triangle.cpp
        Triangle.h
        Circle.cpp
        Circle.h
)
