cmake_minimum_required(VERSION 3.8)
project(P3)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp
        edge.hpp
        edge.cpp
        liste.hpp
        node.hpp
        node.cpp DiGraph.cpp DiGraph.h DotGraphVisualizer.h input.h)

add_executable(P3 ${SOURCE_FILES})

