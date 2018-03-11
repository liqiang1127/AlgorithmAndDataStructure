//
// Created by liqiang on 2018/2/28.
//

#ifndef MINISPANTREE_PRIMMST_H
#define MINISPANTREE_PRIMMST_H


#include <iostream>
#include <vector>
#include "IndexMinHeap.h"
#include "Edge.h"

using namespace std;


template <typename Graph,typename Weight>
class PrimMST{
private:
    Graph &G;
    IndexMinHeap<Weight> ipq;//为什么这里要用索引堆？
    //个人理解 这里我们需要记录某条边的权值 以及 这条边指向的未被访问的点
    //如果是最小堆 那么我们不能根据点取到边 弹出的边是2个点和一个权值的捆绑结构
    vector<Edge<Weight>*> edgeTo;
    bool *marked;//标记边有没有被访问过

    Weight mstWeight;
    vector<Edge<Weight>> mst;//记录最小生成树


    void visit(int v){
        assert(!marked[v]);
        marked[v] = true;

        typename Graph::adjIterator adj(G,v);
        for (Edge<Weight>* e = adj.begin(); !adj.end() ; e = adj.next()) {
            int w = e->other(v);

            if(!marked[w]){
                //如果这个边是横切边 lazy里面就直接丢进去 这里要根据这个边
                if(!edgeTo[w]){
                    //这个点没记录过横切边
                    ipq.insert(w,e->wt());
                    edgeTo[w] = e;
                }else if(e->wt() < edgeTo[w]->wt()){
                    ipq.change(w,e->wt());
                    edgeTo[w] = e;
                }
            }
        }
    }


public:
    PrimMST(Graph &graph):G(graph),ipq(IndexMinHeap<Weight>(G.V())){

        assert( graph.E() >= 1 );

        //初始化
        marked = new bool[G.E()];
        for (int i = 0; i < G.E() ; ++i) {
            marked[i] = false;
            edgeTo.push_back(NULL);
        }
        mst.clear();

        //处理一个点 以0点为例
        visit(0);
        while (!ipq.isEmpty()){
            //这条边一定是最小生成树的边
            int v = ipq.extractMinIndex();
            assert( edgeTo[v]);
            mst.push_back(*edgeTo[v]);
            visit(v);
        }

        mstWeight = mst[0].wt();
        for (int j = 1; j < mst.size() ; ++j) {
            mstWeight += mst[j].wt();
        }

    }

    ~PrimMST(){
        delete[] marked;
    }

    Weight result(){
        return mstWeight;
    }

    vector<Edge<Weight>> mstEdges(){
        return mst;
    }
};
#endif //MINISPANTREE_PRIMMST_H
