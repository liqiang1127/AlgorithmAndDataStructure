//
// Created by liqiang on 2018/2/27.
//

#ifndef MINISPANTREE_MINIHEAP_H
#define MINISPANTREE_MINIHEAP_H

#include <iostream>
#include <cassert>
#include <algorithm>


using namespace std;

template <typename Item>
class MiniHeap{
private:
    Item *data;
    int count;
    int capacity;

    void shiftUp(int k){
        while( k > 1 && data[k] < data[k/2]){
            //当前节点比父亲节点小交换
            swap(data[k],data[k/2]);
            k/=2;
        }
    }

    void shiftDown(int k){
        while( 2*k <= count){
            int j = 2*k;

            if(j+1 <= count && data[j+1] < data[j])
                j+=1;

            if(data[k] <= data[j])
                return;

            swap(data[k],data[j]);

            k = j;
        }
    }

public:
    MiniHeap(int capacity){
        this->capacity = capacity;
        this->count = 0;
        data = new Item[capacity + 1];
    }


    //heapify
    MiniHeap(Item arr[],int n){
        data = new Item[n+1];
        this->capacity = n;
        this->count = n;

        for (int i = 0; i < n; ++i) {
            data[i+1] = arr[i];
        }

        //从第一个非叶子节点开始 shiftDown 这个过程称为 heapify
        for (int j = n/2; j >=1 ; --j) {
            shiftDown(j);
        }
    }

    ~MiniHeap(){
        delete[] data;
    }

    void insert(Item item){
        assert(count + 1 <= capacity);

        //索引从1开始
        data[++count] = item;

        shiftUp(count);
    }

    Item extractMin(){
        assert( count > 0 );

        Item ret = data[1];

        swap(data[1],data[count]);

        count --;

        shiftDown(1);
        return ret;
    }

    bool isEmpty(){
        return count == 0;
    }

    int size(){return count;}
};

#endif //MINISPANTREE_MINIHEAP_H
