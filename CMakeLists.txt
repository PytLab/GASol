# CMake script to build GASol

cmake_minimum_required(VERSION 3.9.4)
project(GASol)

# Enable verbose output.
#set(CMAKE_VERBOSE_MAKEFILE ON)

# Use C++11 standard.
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set compiler options.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -Wall -Wextra -Werror -pedantic")

# GASol source dir.
add_subdirectory(src)

# GASol test dir.
add_subdirectory(test)

