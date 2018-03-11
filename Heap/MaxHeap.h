//
// Created by liqiang on 2018/2/23.
//

#ifndef HEAP_MAXHEAP_H
#define HEAP_MAXHEAP_H

#include <iostream>
#include <assert.h>
#include <cmath>
#include <typeinfo>

using namespace std;

template <typename Item>
class MaxHeap{
private:
    Item* data;
    int count;
    int capacity;

    void shiftUp(int k){
        while( k > 1 && data[k] > data[k/2]){
            swap(data[k] , data[k/2]);
            k/=2;
        }
    }

    void shiftDown(int k){
        while(k*2 <= count){
            int j = k*2;

            if(j+1 <= count && data[j+1] > data[j])
                j+=1;

            if(data[k] >= data[j])
                break;

            swap(data[k],data[j]);

            k=j;
        }
    }

public:
    MaxHeap(int capacity){
        data = new Item[capacity+1];
        this->capacity = capacity;
        count = 0;
    }
    ~MaxHeap(){
        delete[] data;
    }

    int size(){
        return count;
    }

    bool isEmpty(){
        return count == 0;
    }

    void insert(Item item){
        //检查是否已经满了
        assert(count + 1 <= capacity);

        //没满插入
        data[++count] = item;

        //维护堆
        shiftUp(count);
    }

    Item extractMax(){
        assert(!isEmpty());
        Item ret = data[1];
        swap(data[1],data[count]);
        count --;
        shiftDown(1);
        return ret;
    }
};

#endif //HEAP_MAXHEAP_H
