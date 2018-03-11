//
// Created by liqiang on 2018/2/28.
//

#ifndef DIJKSTRA_DENSEGRAPH_H
#define DIJKSTRA_DENSEGRAPH_H

#include <iostream>
#include <vector>

#include "Edge.h"
using namespace std;


//稠密图 -- 邻接矩阵
template <typename Weight>
class DenseGraph{
private:
    int n,m;//n点数 m边数
    bool directed;
    vector<vector<Edge<Weight>*>> g;
public:
    DenseGraph(int n,bool directed){
        this->n = n;
        this->directed = directed;
        this->m = 0;

        for (int i = 0; i < n; ++i) {
            g.push_back(vector<Edge<Weight>*>(n,NULL));
        }
    }

    ~DenseGraph(){
        for (int i = 0; i < n ; ++i) {
            for (int j = 0; j < n ; ++j) {
                if(g[i][j])
                    delete g[i][j];
            }
        }
    }

    void addEdge(int v,int w,Weight weight){
        assert( v >=0 && v < n);
        assert( w >=0 && w < n);
        //已经有了 就删除掉重新插入（处理平行边）
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
                if(g[i][j])
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
            this->index = -1;
            this->v = v;
        }

        ~adjIterator(){}

        Edge<Weight>* begin(){
            index = -1;
            return next();
        }

        Edge<Weight>* next(){
            index++;
            for ( ; index < G.g[v].size() ; index++) {
                if(G.g[v][index])
                    return G.g[v][index];
            }
            return NULL;
        }

        bool end(){
            return index >= G.g[v].size();
        }

    };


};

#endif //DIJKSTRA_DENSEGRAPH_H
