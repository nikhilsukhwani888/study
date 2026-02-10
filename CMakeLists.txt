cmake_minimum_required(VERSION 3.15)

project(main LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Collect all cpp files
file(GLOB STACK_SOURCES
    stack/*.cpp
)

file(GLOB MULTITHREADING_SOURCES
    multithreading/*.cpp
)

add_executable(main
    main.cpp
    ${STACK_SOURCES}
    ${MULTITHREADING_SOURCES}
)

target_include_directories(main PRIVATE
    ${CMAKE_SOURCE_DIR}
    main
)
