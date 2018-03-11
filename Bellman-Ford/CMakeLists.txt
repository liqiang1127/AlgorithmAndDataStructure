cmake_minimum_required(VERSION 3.9)
project(Bellman_Ford)

set(CMAKE_CXX_STANDARD 11)

add_executable(Bellman_Ford main.cpp IndexMinHeap.h DenseGraph.h SparseGraph.h Edge.h ReadGraph.h BellmanFord.h)