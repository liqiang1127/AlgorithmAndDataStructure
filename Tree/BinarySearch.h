//
// Created by liqiang on 2018/2/23.
//

#ifndef TREE_BINARYSEARCH_H
#define TREE_BINARYSEARCH_H

#include <iostream>

using namespace std;

//二分查找 适用对象 有序数组
//查找成功 返回索引 查找失败返回 -1
template <typename T>
int binarySearch(T arr[],int n,T target){
    //在[l,r]区间查找target
    int l=0,r=n-1;

    while(l <= r){
        int mid = l + (r-l)/2;
        if(arr[mid] == target)
            return mid;
        if(target > arr[mid])
            l = mid+1;
        else
            r = mid-1;
    }
    return -1;
}

//递归写法
template <typename T>
int __binarySearch2(T arr[],int l,int r,T target){

    //递归终点 没找到
    if( l > r)
        return -1;


    int mid = l + (r-l)/2;
    //直接找到
    if(arr[mid]==target)
        return mid;

    //arr[mid]不是target 进行递归
    if( target > arr[mid])
        return __binarySearch2(arr,mid+1,r,target);
    else
        return __binarySearch2(arr,l,mid-1,target);
}


template <typename T>
int binarySearch2(T arr[],int n,T target){
    return __binarySearch2(arr,0,n-1,target);
}


// 二分查找法, 在有序数组arr中, 查找target
// 如果找到target, 返回第一个target相应的索引index
// 如果没有找到target, 返回比target小的最大值相应的索引, 如果这个最大值有多个, 返回最大索引
// 如果这个target比整个数组的最小元素值还要小, 则不存在这个target的floor值, 返回-1
template <typename T>
int binarySearchFloor(T arr[],int n,T target){
    int l = -1,r = n-1;
    //此处为啥是 l < r
    //此处目的 是找到 第一个等于target的元素的索引-1的值
    //后面通过+1 判定
    while( l < r){
        //向上取整 避免死循环
        int mid = l + (r-l+1)/2;

        //不能等于！
        if(arr[mid] >= target)
            r = mid-1;
        else
            l = mid;
    }

    //看看l+1是不是target
    if(l+1<n && arr[l+1] == target)
        l+=1;

    return l;
}

// 二分查找法, 在有序数组arr中, 查找target
// 如果找到target, 返回最后一个target相应的索引index
// 如果没有找到target, 返回比target大的最小值相应的索引, 如果这个最小值有多个, 返回最小的索引
// 如果这个target比整个数组的最大元素值还要大, 则不存在这个target的ceil值, 返回整个数组元素个数n
template <typename T>
int binarySearchCeil(T arr[],int n,T target){
    int l = 0,r = n;

    while(l < r){
        int mid = l + (r - l)/2;

        if(arr[mid] <= target)
            l = mid + 1;
        else
            r = mid;
    }

    if(r-1>=0 && arr[r-1] == target)
        r-=1;

    return r;
}
#endif //TREE_BINARYSEARCH_H
