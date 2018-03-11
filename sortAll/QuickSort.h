//
// Created by liqiang on 2018/2/14.
//

#ifndef SORTALL_QUICKSORT_H
#define SORTALL_QUICKSORT_H

#include <iostream>

using namespace std;


//划分数组 返回参考值的索引
template <typename T>
int __partition(T arr[],int l,int r){

    swap(arr[l],arr[rand()%(r-l+1)+l]);


    T v = arr[l];
    //[l+1,k] < v < [k+1,i)
    int k = l;
    for (int i = l+1; i <= r ; ++i) {
        if (arr[i] < v){
            swap(arr[i],arr[k+1]);
            k++;
        }
    }
    swap(arr[l],arr[k]);
    return k;
}




//对闭区间[l,r]快速排序
template <typename T>
void __quickSort(T arr[],int l,int r){
    if(l >= r)
        return;
    int p = __partition(arr,l,r);
    //分别对 其他2部分快速排序
    //只剩一个元素的时候不用排序了
    __quickSort(arr,l,p-1);
    __quickSort(arr,p+1,r);
}



template <typename T>
void quickSort(T arr[],int n){
    srand(time(NULL));
    __quickSort(arr,0,n-1);
}



#endif //SORTALL_QUICKSORT_H
