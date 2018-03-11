#include <iostream>
#include <cstdlib>
#include <time.h>
#include <assert.h>
#include <typeinfo>
#include <cmath>
#include "MaxHeap.h"
#include "MaxIndexHeap.h"


using namespace std;

void sortTest(MaxIndexHeap<int> maxheap){
    bool sign = true;
    int k = maxheap.extractMax();
    while (!maxheap.isEmpty()){
        int p = maxheap.extractMax();
        if(k < p){
            sign = false;
            break;
        }
        k = p;
    }
    if(sign){
        cout<<"sorted"<<endl;
    }else{
        cout<<"wrong!"<<endl;
    }
    cout<<endl;
}

void print(MaxIndexHeap<int> maxheap){
    while (!maxheap.isEmpty()){
        cout<<maxheap.extractMax()<<" ";
    }
    cout<<endl;
}


int main() {

    MaxIndexHeap<int> maxheap = MaxIndexHeap<int>(100);

    cout<<maxheap.size()<<endl;

    srand(time(NULL));
    for (int i = 0; i < 10 ; ++i) {
        maxheap.insert(i,rand()%1000);
    }

    cout<<maxheap.size()<<endl;

//    sortTest(maxheap);

    maxheap.change(2,10000);

//    sortTest(maxheap);

    print(maxheap);

    return 0;
}