cmake_minimum_required(VERSION 3.9)
project(Dijkstra)

set(CMAKE_CXX_STANDARD 11)

add_executable(Dijkstra main.cpp DenseGraph.h SparseGraph.h ReadGraph.h IndexMinHeap.h Dijkstra.h Edge.h)