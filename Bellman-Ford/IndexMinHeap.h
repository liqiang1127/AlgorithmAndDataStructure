//
// Created by liqiang on 2018/3/1.
//

#ifndef BELLMAN_FORD_INDEXMINHEAP_H
#define BELLMAN_FORD_INDEXMINHEAP_H

#include <iostream>
#include <cassert>
using namespace std;


template <typename Item>
class IndexMinHeap{
private:
    Item *data;
    int *indexes;
    int *reverse;

    int capacity;
    int count;

    void shiftUp(int k){
        while( k > 1 && data[indexes[k]] < data[indexes[k/2]]){
            swap(indexes[k],indexes[k/2]);
            reverse[indexes[k]] = k;
            reverse[indexes[k/2]] = k/2;

            k/=2;
        }
    }

    void shiftDown(int k){
        while(2*k <= count){
            int j = 2*k;
            if(j+1 <= count && data[indexes[j+1]] < data[indexes[j]])
                j+=1;

            if(data[indexes[k]] <= data[indexes[j]])
                return ;

            swap(data[indexes[k]] < data[indexes[j]]);

            k = j;
        }
    }
public:
    IndexMinHeap(int capacity){
        this->capacity = capacity;
        this->count = 0;

        data = new Item[capacity+1];
        indexes = new int[capacity+1];
        reverse = new int[capacity+1];

        for (int i = 0; i <= capacity ; ++i) {
            reverse[i] = 0;
            indexes[i] = 0;
        }
    }

    ~IndexMinHeap(){
        delete[] data;
        delete[] indexes;
        delete[] reverse;
    }

    void insert(int i,Item item){
        //索引修正
        assert( i >=0 && i < capacity);

        i+=1;
        data[i] = item;

        indexes[++count] = i;
        reverse[indexes[count]] = count;

        shiftUp(count);
    }

    Item extractMin(){
        assert(count > 0);
        Item ret = data[indexes[1]];

        swap(indexes[1],indexes[count]);

        reverse[indexes[1]] = 1;
        reverse[indexes[count]] = 0;

        count--;

        shiftDown(1);

        return ret;
    }

    int extractMinIndex(){
        assert(count > 0);
        int ret = indexes[1];

        swap(indexes[1],indexes[count]);

        reverse[indexes[1]] = 1;
        reverse[indexes[count]] = 0;

        count--;

        shiftDown(1);

        return ret - 1;
    }

    Item getMin(){
        assert(count > 0);
        return data[indexes[1]];
    }

    int getMinIndex(){
        assert(count > 0);
        return indexes[1] - 1;
    }

    bool contain(int i){
        assert( i >= 0 && i <capacity);
        return reverse[i+1] != 0;
    }

    Item get(int i){
        return data[i+1];
    }


    void change(int i,Item item){
        i++;
        assert( i>0 && i<=count);

        int k = reverse[i];

        shiftDown(k);
        shiftUp(k);
    }
};

#endif //BELLMAN_FORD_INDEXMINHEAP_H
