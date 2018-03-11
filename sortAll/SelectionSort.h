//
// Created by liqiang on 2018/2/13.
//

#ifndef SORTALL_SELECTIONSORT_H
#define SORTALL_SELECTIONSORT_H

#include <iostream>


using namespace std;

template <typename T>
void selectionSort(T arr[],int n){
    //每次选择最小的
    int minIndex;
    for (int i = 0; i < n ; ++i) {
        //默认认为当前是最小的
        minIndex = i;
        for (int j = i+1 ; j < n ; ++j) {
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i],arr[minIndex]);
    }
}


#endif //SORTALL_SELECTIONSORT_H
