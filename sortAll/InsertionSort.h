//
// Created by liqiang on 2018/2/13.
//

#ifndef SORTALL_INSERTIONSORT_H
#define SORTALL_INSERTIONSORT_H

#include <iostream>

using namespace std;

template <typename T>
void insertionSort(T arr[],int n){
    //插入排序
    for (int i = 1; i < n ; ++i) {
        T e = arr[i];
        int j;
        for (j = i; j >= 1 && e < arr[j-1]; --j) {
            arr[j] = arr[j-1];
        }
        arr[j] = e;
    }
}

#endif //SORTALL_INSERTIONSORT_H
