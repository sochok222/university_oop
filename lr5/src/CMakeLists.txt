cmake_minimum_required(VERSION 4.1)
project(src)

set(CMAKE_CXX_STANDARD 20)

set(${PROJECT_NAME}_src
        main.cpp
)

add_executable(src ${${PROJECT_NAME}_src})

target_link_libraries(
        ${PROJECT_NAME}
        PRIVATE
        Time
)

add_subdirectory(libs)