#include <iostream>
#include <string>
#include <iomanip>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"
#include "MiniHeap.h"
#include "LazyPrimMST.h"
#include "IndexMinHeap.h"
#include "PrimMST.h"
#include "KruskalMST.h"


using namespace std;

int main() {
////    测试小根堆
////
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
//    while(!minHeap.isEmpty())
//        cout<<minHeap.extractMin()<<"\t";
//    cout<<endl;
//
//    cout<<minHeap.size()<<endl;
//
//    cout<<minHeap.contain(0)<<endl;

    string filename = "testG1.txt";
    int V = 8;

    SparseGraph<double> g = SparseGraph<double>(V, false);
    ReadGraph<SparseGraph<double>, double> readGraph(g, filename);

    // Test Lazy Prim MST
    cout<<"Test Lazy Prim MST:"<<endl;
    LazyPrimMST<SparseGraph<double>, double> lazyPrimMST(g);
    vector<Edge<double>> mst = lazyPrimMST.mstEdges();
    for( int i = 0 ; i < mst.size() ; i ++ )
        cout<<mst[i]<<endl;
    cout<<"The MST weight is: "<<lazyPrimMST.result()<<endl;

    cout<<endl;


    // Test Prim MST
    cout<<"Test Prim MST:"<<endl;
    PrimMST<SparseGraph<double>, double> primMST(g);
    mst = primMST.mstEdges();
    for( int i = 0 ; i < mst.size() ; i ++ )
        cout<<mst[i]<<endl;
    cout<<"The MST weight is: "<<primMST.result()<<endl;

    cout<<endl;


    // Test Kruskal MST
    cout<<"Test Kruskal MST:"<<endl;
    KruskalMST<SparseGraph<double>, double> kruskalMST(g);
    mst = kruskalMST.mstEdges();
    for( int i = 0 ; i < mst.size() ; i ++ )
        cout<<mst[i]<<endl;
    cout<<"The MST weight is: "<<kruskalMST.result()<<endl;
    return 0;

}