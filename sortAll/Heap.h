//
// Created by liqiang on 2018/2/17.
//

#ifndef SORTALL_HEAP_H
#define SORTALL_HEAP_H

#include <iostream>
#include <cmath>
#include <typeinfo>

using namespace std;


template <typename Item>
class Maxheap{

private:
    int count;
    Item* data;
    int capacity;

    void shiftUp(int k){
        while( k>1 && data[k/2] < data[k] ){
            swap(data[k/2],data[k]);
            k /=2;
        }
    }


    void shiftDown(int k){
        while( 2*k <= count){
            //有左孩子进行操作
            int j = 2 * k;

            //判断有没有右孩子&&右孩子和左孩子大小比一下
            if(j+1 <= count && data[j] < data[j+1])
                j+=1;

            if(data[k] > data[j])
                break;

            swap(data[k],data[j]);

            k = j;
        }
    }

public:
    Maxheap(int capacity){
        data = new Item[capacity + 1];
        count = 0;
        this->capacity = capacity;
    }

    Maxheap(Item arr[],int n){
        data = new Item[n+1];
        this->capacity = n;
        count = n;
        for(int i=0; i<n ;i++){
            data[i+1] = arr[i];
        }

        int j = count/2;
        for (int k = j; k > 0  ; k--) {
            shiftDown(k);
        }
    }

    ~Maxheap(){
        delete[] data;
    }

    int size(){
        return count;
    }

    bool isEmpty(){
        return count == 0;
    }

    void insert(Item item){
        assert(count + 1 <= capacity);
        data[count+1] = item;
        count++;
        shiftUp(count);
    }


    Item extractMax(){
        assert(count > 0 );
        Item ret = data[1];
        swap(data[1],data[count]);
        count --;
        shiftDown(1);
        return ret;
    }
};

#endif //SORTALL_HEAP_H
