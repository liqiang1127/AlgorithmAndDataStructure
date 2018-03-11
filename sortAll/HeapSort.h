//
// Created by liqiang on 2018/2/17.
//

#ifndef SORTALL_HEAPSORT_H
#define SORTALL_HEAPSORT_H


#include <iostream>
#include "Heap.h"

using namespace std;


template <typename T>
void __shiftDown(T arr[],int n,int k){
    while( 2*k+1 <= n-1){
        int  j = 2*k+1;

        if(j+1 <= n-1 && arr[j+1] > arr[j])
            j++;

        if(arr[k] >=  arr[j])
            break;

        swap(arr[k],arr[j]);

        k = j;
    }
}

template <typename T>
void heapSort1(T arr[],int n){
    Maxheap<int> maxheap = Maxheap<int>(n);

    for (int i = 0; i < n ; ++i) {
        maxheap.insert(arr[i]);
    }

    for (int i = n-1; i >= 0 ; i--) {
        arr[i] = maxheap.extractMax();
    }
}



//heapfy
template <typename T>
void heapSort2(T arr[],int n){
    Maxheap<int> maxheap = Maxheap<int>(arr,n);

    for (int i = n-1; i >= 0 ; i--) {
        arr[i] = maxheap.extractMax();
    }
}

//原地堆排序
template <typename T>
void heapSort(T arr[],int n){
    //对杂乱的数组heapfy
    for(int i = n/2-1 ; i >= 0; i--){
        __shiftDown(arr,n,i);
    }

    for(int i = n-1; i>0;--i){
        swap(arr[i],arr[0]);
        __shiftDown(arr,i,0);
    }
}

#endif //SORTALL_HEAPSORT_H
