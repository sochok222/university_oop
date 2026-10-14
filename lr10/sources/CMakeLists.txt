cmake_minimum_required(VERSION 4.1)
project(lr10)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME}
        main.cpp

        Triangle.cpp
        Triangle.h
        TriangleBySides.h
        TriangleByPoints.h
        RightTriangle.h
)
