//
// Created by liqiang on 2018/2/23.
//

#ifndef HEAP_MAXINDEXHEAP_H
#define HEAP_MAXINDEXHEAP_H

#include <iostream>
#include <assert.h>

using namespace std;

template <typename Item>
class MaxIndexHeap{
private:
    Item* data;
    int* indexes;
    int* reverse;
    int count;
    int capacity;

    void shiftUp(int k){
        while(k > 1 && data[indexes[k]] > data[indexes[k/2]]){
            swap(indexes[k],indexes[k/2]);
            reverse[indexes[k]] = k;
            reverse[indexes[k/2]] = k/2;
            k/=2;
        }
    }

    void shiftDown(int k){
        while(2*k<=count){
            int j = 2*k;
            if(j+1 <= count && data[indexes[j+1]] > data[indexes[j]])
                j+=1;

            if(data[indexes[k]] >= data[indexes[j]])
                break;

            swap(indexes[j],indexes[k]);
            reverse[indexes[j]] = j;
            reverse[indexes[k]] = k;

            k = j;
        }
    }


public:
    MaxIndexHeap(int capacity){
        data = new Item[capacity+1];
        indexes = new int[capacity+1];
        reverse = new int[capacity+1];
        for (int i = 0; i <= capacity ; ++i)
            reverse[i] = 0;

        count = 0;
        this->capacity = capacity;

    }

    ~MaxIndexHeap(){
        delete[] data;
        delete[] indexes;
//        delete[] reverse;
    }

    int size(){
        return count;
    }

    bool isEmpty(){
        return count == 0;
    }

    //i代表元素的索引 用于指定item在data中打的索引
    //用户看来 索引从0开始  而我们从1开始
    void insert(int i,Item item){
        assert(count+1 <= capacity);
        assert(i+1>=1 && i+1<= capacity);
        i+=1;

        data[i] = item;
        indexes[++count] = i;
        reverse[i] = count;

        shiftUp(count);
    }

    //弹出元素并删除
    Item extractMax(){
        assert(!isEmpty());

        Item ret = data[indexes[1]];

        swap(indexes[count],indexes[1]);
        reverse[indexes[1]] = 1;

        reverse[indexes[count]] = 0;
        count--;

        shiftDown(1);
        return  ret;
    }

    //获取最大元素的索引并删除
    int extractMaxIndex(){
        assert(!isEmpty());

        int ret = indexes[1] - 1;

        swap(indexes[1],indexes[count]);

        reverse[indexes[1]] = 1;

        reverse[indexes[count]] = 0;
        count--;

        shiftDown(1);

        return ret;

    }

    bool contain(int i){
        assert(i+1 >=1 && i+1 <=capacity);
        return reverse[i+1] != 0;
    }

    // 根据索引取出元素 这里的i 是indexes中的一个元素
    Item getItem(int i){
        assert(contain(i));
        return data[i+1];
    }

    void change(int i,Item item){
        assert(contain(i));
        data[++i] = item;
        int index = reverse[i];
        shiftUp(index);
        shiftDown(index);
    }
};

#endif //HEAP_MAXINDEXHEAP_H
