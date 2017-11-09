cmake_minimum_required(VERSION 3.9)

project(GASol)

# Use C++11 standard.
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# GASol source dir.
add_subdirectory(src bin)

