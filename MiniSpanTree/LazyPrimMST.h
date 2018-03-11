//
// Created by liqiang on 2018/2/27.
//

#ifndef MINISPANTREE_LAZYPRIMMST_H
#define MINISPANTREE_LAZYPRIMMST_H

#include <iostream>
#include <vector>
#include "Edge.h"
#include "MiniHeap.h"


using namespace std;

template <typename Graph,typename Weight>
class LazyPrimMST{
private:
    Graph &G;//图
    MiniHeap<Edge<Weight>> pq;// 优先队列 最坏的情况 所有边都要进优先队列 排序
    bool *marked;//点是否被标记了 根据marked不同的状态 区别切分区
    vector<Edge<Weight>> mst;//存储最小生产树种的 v-1个边
    Weight mstWeight;//最小生成树的权值和


    void visit(int v){
        //访问这个点 并且把这个点连接的[横切边] 放入优先队列

        assert(!marked[v]);//这个点没被访问过
        marked[v] = true;


        //懒在 只要是横切边 就一股脑丢进去
        typename Graph::adjIterator adj(G,v);
        for (Edge<Weight>* e = adj.begin(); !adj.end() ; e = adj.next()) {
            //两个点一个是true 一个是false 这个边是横切变 同时能防止 边重复进入优先队列
            if(!marked[e->other(v)]){
                pq.insert(*e);
            }
        }

    }

public:
    LazyPrimMST(Graph &graph):G(graph),pq(MiniHeap<Edge<Weight>>(graph.E())){
        marked = new bool[G.V()];
        for (int i = 0; i < G.V(); ++i) {
            marked[i] = false;
        }

        mst.clear();

        //lazy prim

        visit(0);
        while (!pq.isEmpty()){
            Edge<Weight> edge = pq.extractMin();
            if(marked[edge.v()] == marked[edge.w()])
                //两个边都被访问过 则这个边已经不是横切边了 丢弃
                continue;
            else{
                mst.push_back(edge);
                if(!marked[edge.v()])
                    visit(edge.v());
                else
                    visit(edge.w());
            }
        }

        mstWeight = mst[0].wt();
        for (int i = 1; i < mst.size() ; ++i) {
            mstWeight+=mst[i].wt();
        }

    }

    ~LazyPrimMST(){
        delete[] marked;
    }

    Weight result(){
        return mstWeight;
    }

    vector<Edge<Weight>> mstEdges(){
        return mst;
    }
};

#endif //MINISPANTREE_LAZYPRIMMST_H
