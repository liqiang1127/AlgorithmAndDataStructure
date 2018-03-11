//
// Created by liqiang on 2018/3/1.
//

#ifndef BELLMAN_FORD_DENSEGRAPH_H
#define BELLMAN_FORD_DENSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>
#include "Edge.h"
using namespace std;


template <typename Weight>
//稠密图 -- 邻接矩阵
class DenseGraph{
private:
    int n,m;//记录 点数 边数;
    vector<vector<Edge<Weight>*>> g;
    bool directed;


public:
    DenseGraph(int n,bool directed){
        this->n = n;
        this->m = 0;
        this->directed = directed;

        for (int i = 0; i < n ; ++i) {
            g.push_back(vector<Edge<Weight>*>(n,NULL));
        }
    }

    ~DenseGraph(){
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <n ; ++j) {
                if(g[i][j])
                    delete g[i][j];
            }
        }
    }

    void addEdge(int v,int w,Weight weight){
        assert( v >= 0 && v < n);
        assert( w >= 0 && w < n);

        //有了就删去 并且更新权值（处理平行边）
        if(hasEdge(v,w)){
            delete g[v][w];
            if(!directed)
                delete g[w][v];
            m--;
        }

        g[v][w] = new Edge<Weight>(v,w,weight);
        if(!directed)
            g[w][v] = new Edge<Weight>(w,v,weight);
        m++;


    }

    bool hasEdge(int v,int w){
        assert( v >= 0 && v < n);
        assert( w >= 0 && w < n);

        return g[v][w] != NULL;
    }


    int V(){
        return n;
    }

    int E(){
        return m;
    }

    void show(){
        for (int i = 0; i < n ; ++i) {
            for (int j = 0; j < n ; ++j) {
                if(!g[i][j])
                    cout<<g[i][j]->wt()<<"\t";
                else
                    cout<<"NULL"<<"\t";
            }
            cout<<endl;
        }
    }

    class adjIterator{
    private:
        int index;
        DenseGraph &G;
        int v;

    public:
        adjIterator(DenseGraph &graph,int v):G(graph){
            this->v = v;
            index = -1;
        }

        ~adjIterator(){

        }

        Edge<Weight>* begin(){
            index = -1;
            return next();
        }

        Edge<Weight>* next(){
            index++;
            for (; index < G.g[v].size() ; index++) {
                if(G.g[v][index])
                    return G.g[v][index];
            }
            return NULL;
        }

        bool end(){
            return index >= G.g[v].size;
        }
    };
};

#endif //BELLMAN_FORD_DENSEGRAPH_H
