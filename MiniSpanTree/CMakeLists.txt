cmake_minimum_required(VERSION 3.9)
project(MiniSpanTree)

set(CMAKE_CXX_STANDARD 11)

add_executable(MiniSpanTree main.cpp DenseGraph.h SparseGraph.h ReadGraph.h Edge.h MiniHeap.h LazyPrimMST.h IndexMinHeap.h PrimMST.h UnionFind.h KruskalMST.h)