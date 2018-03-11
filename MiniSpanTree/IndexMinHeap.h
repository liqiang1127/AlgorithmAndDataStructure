//
// Created by liqiang on 2018/2/27.
//

#ifndef MINISPANTREE_INDEXMINHEAP_H
#define MINISPANTREE_INDEXMINHEAP_H

#include <iostream>
#include <cassert>
using namespace std;


//最小索引堆
template <typename Item>
class IndexMinHeap{
private:
    Item *data;
    int *indexes;
    int *reverse;//通过元素的索引 找到索引所在的位置(k)

    int count;
    int capacity;

    void shiftUp(int k){
        while( k>1 && data[indexes[k]] < data[indexes[k/2]] ){
            swap(indexes[k],indexes[k/2]);
            reverse[indexes[k]] = k;
            reverse[indexes[k/2]] = k/2;

            k/=2;
        }
    }

    void shiftDown(int k){
        while ( k*2 <=count){
            int j = 2*k;

            if(j+1<=count && data[indexes[j]] > data[indexes[j+1]])
                j++;

            if(data[indexes[k]] <= data[indexes[j]])
                return;

            swap(indexes[j],indexes[k]);

            reverse[indexes[j]] = j;
            reverse[indexes[k]] = k;

            k=j;
        }
    }

public:
    IndexMinHeap(int capacity){
        data = new Item[capacity+1];
        indexes = new int[capacity+1];
        reverse =new int[capacity+1];

        this->count = 0;
        this->capacity = capacity;


        for (int i = 0; i <= capacity ; ++i)
            reverse[i] = 0;
    }

    ~IndexMinHeap(){
        delete[] data;
        delete[] indexes;
        delete[] reverse;
    }
    int size(){
        return count;
    }
    bool isEmpty(){
        return count == 0;
    }

    void insert(int i,Item item){
        assert( count + 1 <= capacity );
        assert( i + 1 >= 1 && i + 1 <= capacity );
        //索引 元素
        //外部索引 从0开始 我们这里从1开始 修正
        i+=1;

        data[i] = item;
        indexes[++count] = i;
        reverse[i] = count;

        shiftUp(count);
    }

    Item extractMin(){
        assert( count > 0 );

        Item ret = data[indexes[1]];
        swap( indexes[1] , indexes[count] );
        reverse[indexes[1]] = 1;
        reverse[indexes[count]] = 0;
        count--;
        shiftDown(1);
        return ret;
    }

    int extractMinIndex(){
        assert( count > 0 );
        //用户看来 索引从0开始 -1修正
        int ret = indexes[1] - 1;

        swap(indexes[1],indexes[count]);


        reverse[indexes[1]] = 1;
        reverse[indexes[count]] = 0;

        count--;
        shiftDown(1);

        return ret;
    }

    Item getMin(){
        assert( count > 0 );
        return data[indexes[1]];
    }

    int getMinIndex(){
        assert( count > 0 );
        return indexes[1] - 1;
    }

    bool contain(int i){
        return reverse[i+1] != 0;
    }

    Item get(int i){
        assert(contain(i));
        return data[i+1];

    }

    void change(int i,Item item){
        assert(contain(i));
        data[++i] = item;

        int k = reverse[i];
        shiftDown(k);
        shiftUp(k);

    }

};

#endif //MINISPANTREE_INDEXMINHEAP_H
