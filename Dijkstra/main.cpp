#include <iostream>
#include <iomanip>
#include "ReadGraph.h"
#include "DenseGraph.h"
#include "SparseGraph.h"
#include "Dijkstra.h"
#include "IndexMinHeap.h"


using namespace std;


int main() {
//    int arr[7] = {7,3,4,2,1,5,6};
//
//    IndexMinHeap<int> minHeap(7);
//
//    for (int i = 0; i < 7; ++i) {
//        minHeap.insert(i,arr[i]);
//    }
//
//    cout<<minHeap.contain(0)<<endl;
//
//    minHeap.change(0,10);
//
//    while(!minHeap.isEmpty()) {
//        cout<<minHeap.extractMin()<<"\t";
//    }
//    cout<<endl;
//
//    cout<<minHeap.size()<<endl;
//
//    cout<<minHeap.contain(0)<<endl;
//
//    return 0;
    string filename = "testG1.txt";
    int V = 5;

    SparseGraph<int> g = SparseGraph<int>(V, true);
    //SparseGraph<int> g = SparseGraph<int>(V, false);
    ReadGraph<SparseGraph<int>, int> readGraph(g, filename);

    cout<<"Test Dijkstra:"<<endl<<endl;
    Dijkstra<SparseGraph<int>, int> dij(g,0);
    for( int i = 1 ; i < V ; i ++ ){
        cout<<"Shortest Path to "<<i<<" : "<<dij.shortestPathTo(i)<<endl;
        dij.showPath(i);
        cout<<"----------"<<endl;
    }

    return 0;
}