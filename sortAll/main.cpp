#include <iostream>
#include "InsertionSort.h"
#include "BubbleSort.h"
#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "ShellSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "QuickSort2Ways.h"
#include "QuickSort3Ways.h"
#include "Heap.h"
#include "HeapSort.h"

int main() {

    int n = 1000000;
    int* arr1 = SortTestHelper::generateRandomArray(n,0,n);
    int* arr2 = SortTestHelper::copyIntArray(arr1,n);
    int* arr3 = SortTestHelper::copyIntArray(arr1,n);

    SortTestHelper::testSort("heapSort1",heapSort1,arr1,n);
    SortTestHelper::testSort("heapSort2",heapSort2,arr2,n);
    SortTestHelper::testSort("heapSort",heapSort,arr3,n);

    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    cout<<endl;
    return 0;
}