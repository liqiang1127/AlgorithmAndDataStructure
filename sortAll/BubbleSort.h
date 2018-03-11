//
// Created by liqiang on 2018/2/13.
//

#ifndef SORTALL_BUBBLESORT_H
#define SORTALL_BUBBLESORT_H

#include <iostream>

using namespace std;

template <typename T>
void bubbleSort(T arr[],int n){
    bool isSwaped;
    for (int i = 0; i < n-1 ; ++i) {
        isSwaped = false;
        for (int j = 0; j < n-i-1 ; ++j) {
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                isSwaped = true;
            }
        }
        if(!isSwaped)
            return;
    }

}




#endif //SORTALL_BUBBLESORT_H
