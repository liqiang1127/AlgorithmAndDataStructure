cmake_minimum_required(VERSION 3.9)
project(Graph)

set(CMAKE_CXX_STANDARD 11)

add_executable(Graph main.cpp DenseGraph.h SparseGraph.h ReadGraph.h Component.h Path.h ShortPath.h)