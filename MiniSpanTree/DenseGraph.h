//
// Created by liqiang on 2018/2/27.
//

#ifndef MINISPANTREE_DENSEGRAPH_H
#define MINISPANTREE_DENSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>
#include "Edge.h"


using namespace std;

template <typename Weight>
//稠密图 -- 邻接矩阵
class DenseGraph{
private:
    int n,m;//n - 点的数目; m - 边的数目
    bool directed; // true 是有向图
    vector<vector<Edge<Weight> *>> g; //二维数组

public:
    DenseGraph(int n,bool directed){
        //初始化一个稠密图
        this->n = n;
        this->m = 0;
        this->directed = directed;
        for (int i = 0; i < n; ++i) {
            g.push_back(vector<Edge<Weight> *>(n,NULL));
        }
    }

    ~DenseGraph(){
        for (int i = 0; i < n ; ++i) {
            for (int j = 0; j < n ; ++j) {
                if(g[i][j] != NULL)
                    delete g[i][j];
            }
        }
    }

    void addEdge(int v,int w,Weight weight){
        assert( v >= 0 && v < n);
        assert( w >= 0 && w < n);

        //更新weight
        if(hasEdge(v,w)){
            delete g[v][w];
            if(!directed)
                delete g[w][v];
            m--;
        }

        g[v][w] = new Edge<Weight>(v,w,weight);
        if(!directed)//不是有向图 对应的也要变true
            g[w][v] = new Edge<Weight>(w,v,weight);
        m++;
    }

    bool hasEdge(int v,int w){
        assert( v >= 0 && v < n);
        assert( w >= 0 && w < n);

        return g[v][w] != NULL;
    }

    void show(){
        for (int i = 0; i < n ; ++i) {
            for (int j = 0; j < n ; ++j) {
                if(g[i][j])
                    cout<<g[i][j]->wt()<<"\t";
                else
                    cout<<"NULL"<<"\t";
            }
            cout<<endl;
        }
    }

    int V(){//vertex
        return n;
    }

    int E(){//edge
        return m;
    }

    class adjIterator{//某个点的访问迭代器 实现访问这个点的连接点
    private:
        DenseGraph &G;
        int v;
        int index;//访问索引
    public:
        adjIterator(DenseGraph &graph,int v):G(graph){
            this->v = v;
            //这里为什么要初始化 -1 ?
            //这和 begin 内部返回 next() 有很大关系
            this->index = -1;
        }

        ~adjIterator(){

        }

        Edge<Weight>* begin(){
            //这里不能从第一个开始
            //begin是返回 第一个有链接的点
            index = -1;
            return next();
        }

        Edge<Weight>* next(){
            index++;
            for ( ;  index < G.V() ; ++index) {
                if(G.g[v][index])
                    return G.g[v][index];
            }
            return NULL;
        }

        bool end(){
            return index >= G.V();
        }
    };

};

#endif //MINISPANTREE_DENSEGRAPH_H
