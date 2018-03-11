//
// Created by liqiang on 2018/2/13.
//

#ifndef SORTALL_MERGESORT_H
#define SORTALL_MERGESORT_H

#include <iostream>

using namespace std;


//归并 前闭后闭区间
template <typename T>
void __merge(T arr[],int l,int mid,int r){
    //开辟辅助空间，复制元素
    T aux[r-l+1];
    for (int i = l; i <= r; i++) {
        aux[i-l] = arr[i];
    }

    int i = l,j = mid+1;
    for (int k = l; k <= r ; ++k) {
        if(i > mid){
            arr[k] = aux[j-l];
            j++;
        }else if (j > r){
            arr[k] = aux[i-l];
            i++;
        }else if(aux[i-l] < aux[j-l]){
            arr[k] = aux[i-l];
            i++;
        }else{
            arr[k] = aux[j-l];
            j++;
        }
    }
}




template <typename T>
void __mergeSort(T arr[],int l,int r){
    if(l >= r)
        return;
    int mid = (l+r)/2;
    __mergeSort(arr,l,mid);
    __mergeSort(arr,mid+1,r);
    //对排序好的2个数组merge
    if(arr[mid] > arr[mid+1])
        __merge(arr,l,mid,r);
}




template <typename T>
void mergeSort(T arr[],int n){
    __mergeSort(arr,0,n-1);
}




//自底向上的归并
//没有利用随机存取的性质 可以利用这个特性 用于链表的排序nlogn
template <typename T>
void mergeSortBU(T arr[],int n){
    for (int sz = 1; sz <= n ; sz += sz) {
        for (int i = 0; i+sz < n ; i+= 2*sz) {
            //对[i,i+size-1] 和 [i+size,i+2*size-1] 归并
            __merge(arr,i,i+sz-1,min(n-1,i+2*sz-1));
        }
    }
}

#endif //SORTALL_MERGESORT_H
