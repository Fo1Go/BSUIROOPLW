cmake_minimum_required(VERSION 3.27)
project(LR2)

set(CMAKE_CXX_STANDARD 17)

add_executable(LR2 main.cpp
        Point.h
        Line.h
        utils.h)
