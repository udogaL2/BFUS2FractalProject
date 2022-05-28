cmake_minimum_required(VERSION 3.20)
project(fractal_project)

set(CMAKE_CXX_STANDARD 14)

add_executable(fractal_project main.cpp src/BMP.cpp inc/BMP.h inc/mathutils/matrix.hpp src/fractal.cpp inc/fractal.h)