//
// Created by liqiang on 2018/2/13.
//

#ifndef SORTALL_SHELLSORT_H
#define SORTALL_SHELLSORT_H

#include <iostream>

using namespace std;

template <typename T>
void shellSort(T arr[],int n){
    int step = 1;
    while (step < n/3){
        step = 3 * step + 1;
    }

    while (step){
        for (int i = step; i < n ; ++i) {
            T e = arr[i];
            int j;
            for ( j = i; j >=step && e < arr[j-step]; j -= step) {
                arr[j] = arr[j-step];
            }
            arr[j] = e;
        }

        step /= 3;
    }

}

#endif //SORTALL_SHELLSORT_H
