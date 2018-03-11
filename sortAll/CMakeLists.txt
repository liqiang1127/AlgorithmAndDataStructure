cmake_minimum_required(VERSION 3.9)
project(sortAll)

set(CMAKE_CXX_STANDARD 11)

add_executable(sortAll main.cpp InsertionSort.h BubbleSort.h SelectionSort.h ShellSort.h MergeSort.h QuickSort.h QuickSort2Ways.h QuickSort3Ways.h Heap.h HeapSort.h)