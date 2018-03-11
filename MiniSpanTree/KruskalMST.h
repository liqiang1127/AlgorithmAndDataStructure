//
// Created by liqiang on 2018/2/28.
//

#ifndef MINISPANTREE_KRUSKALMST_H
#define MINISPANTREE_KRUSKALMST_H

#include <iostream>
#include <vector>
#include "UnionFind.h"
#include "MiniHeap.h"
#include "Edge.h"

using namespace std;
template <typename  Graph,typename  Weight>
class KruskalMST{
private:
    vector<Edge<Weight>> mst;
    Weight weight;
public:
    KruskalMST(Graph &G){
        UnionFind uf(G.V());//判断是否成环
        MiniHeap<Edge<Weight>> pq(G.E());

        for (int i = 0; i < G.V(); ++i) {
            //这个边的迭代器 作用是遍历某个点所连接边
            typename Graph::adjIterator adj(G,i);
            for (Edge<Weight>* e = adj.begin(); !adj.end() ; e = adj.next()) {
                int v = e->other(i);
                if(v < i){
                    pq.insert(*e);
                }
            }
        }
        
        while (!pq.isEmpty() && mst.size() < G.E() - 1){
            Edge<Weight> e = pq.extractMin();
            if(uf.isConnected(e.w(),e.v()))
                //已经在一个并查集里面了 说明不能连接了 如果连接会形成环
                continue;

            mst.push_back(e);

            uf.unionElements(e.w(),e.v());
        }

        weight = mst[0].wt();
        for (int j = 1; j < mst.size() ; ++j) {
            weight+=mst[j].wt();
        }

    }

    ~KruskalMST(){

    }

    Weight result(){
        return weight;
    }

    vector<Edge<Weight>> mstEdges(){
        return mst;
    }
};

#endif //MINISPANTREE_KRUSKALMST_H
