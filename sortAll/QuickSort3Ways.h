//
// Created by liqiang on 2018/2/14.
//

#ifndef SORTALL_QUICKSORT3WAYS_H
#define SORTALL_QUICKSORT3WAYS_H

//三路快速排序

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

template <typename T>
void __quickSort3(T arr[],int l, int r){

    if( l >= r)
        return;

    swap(arr[l],arr[rand()%(r-l+1)+l]);

    T v = arr[l];

    //arr[l+1,lt] < v, arr[lt+1,i) = v, arr[gt,r] > v
    int lt = l , gt = r+1;
    int i = l+1;
    while ( i < gt){
        if(arr[i] < v){
            swap(arr[i],arr[lt+1]);
            i++;
            lt++;
        } else if (arr[i] > v){
            swap(arr[i],arr[gt-1]);
            gt--;
        } else {
            i++;
        }
    }
    swap(arr[l],arr[lt]);

    __quickSort3(arr,l,lt-1);
    __quickSort3(arr,gt ,r);


}


template <typename T>
void quickSort3(T arr[],int n){
    srand(time(NULL));
    __quickSort3(arr,0,n-1);
}

#endif //SORTALL_QUICKSORT3WAYS_H
