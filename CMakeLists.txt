cmake_minimum_required(VERSION 3.15)

project(study LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Collect all cpp files
file(GLOB STACK_SOURCES
    stack/*.cpp
)

add_executable(study
    main.cpp
    ${STACK_SOURCES}
)

target_include_directories(study PRIVATE
    ${CMAKE_SOURCE_DIR}
    study
)
