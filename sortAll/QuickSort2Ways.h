//
// Created by liqiang on 2018/2/14.
//

#ifndef SORTALL_QUICKSORT2WAYS_H
#define SORTALL_QUICKSORT2WAYS_H

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;



//二路partition
//提高了很多键值相同的情况下的性能
template <typename T>
int __partition2(T arr[],int l,int r){


    swap(arr[l],arr[rand()%(r-l+1)+l]);

    T v =  arr[l];

    //[l+1,i) <=v<=(j,r]
    int i = l+1,j=r;
    while(true){
        while( i<=r && arr[i] < v) i++;
        while( j>=l+1 && arr[j] > v) j--;
        if(i >= j)
            break;
        swap(arr[i],arr[j]);
        i++;
        j--;
    }

    swap(arr[l],arr[j]);
    return j;
}



//对[l,r]进行二路快速排序  递归
template <typename T>
void __quickSort2(T arr[],int l,int r){

    //递归终点
    if( l >= r)
        return;
    int p = __partition2(arr,l,r);
    __quickSort2(arr,l,p-1);
    __quickSort2(arr,p+1,r);
}



template <typename T>
void quickSort2(T arr[],int n){
    srand(time(NULL));
    __quickSort2(arr,0,n-1);
}

#endif //SORTALL_QUICKSORT2WAYS_H
