//
// Created by liqiang on 2018/2/27.
//

#ifndef MINISPANTREE_SPARSEGRAPH_H
#define MINISPANTREE_SPARSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>
#include "Edge.h"

using namespace std;


template <typename Weight>
class SparseGraph{
private:
    int n,m;
    bool directed;
    vector<vector<Edge<Weight>*>> g;

public:
    SparseGraph(int n, bool directed){
        this->n = n;
        this->m = 0;
        this->directed = directed;
        for (int i = 0; i < n; ++i) {
            g.push_back(vector<Edge<Weight> *>());
        }
    }

    ~SparseGraph(){
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < g[i].size(); ++j) {
                delete g[i][j];
            }
        }
    }

    int V(){
        return n;
    }
    int E(){
        return m;
    }

    void addEdge(int v,int w,Weight weight){
        assert( v >=0 && v < n);
        assert( w >=0 && w < n);

        //v!=w 处理自环  平行边不好处理 不管
        g[v].push_back(new Edge<Weight>(v,w,weight));
        if(v != w &&!directed)
            g[w].push_back(new Edge<Weight>(w,v,weight));
        m++;
    }

    bool hasEdge(int v,int w){
        assert( v >=0 && v < n);
        assert( w >=0 && w < n);

        //O(n)
        for (int i = 0; i < g[v].size() ; ++i) {
            if(g[v][i]->other(v) == w)
                return true;
        }
        return false;
    }


    void show(){

        for( int i = 0 ; i < n ; i ++ ){
            cout<<"vertex "<<i<<":\t";
            for( int j = 0 ; j < g[i].size() ; j ++ )
                cout<<"( to:"<<g[i][j]->w()<<",wt:"<<g[i][j]->wt()<<")\t";
            cout<<endl;
        }
    }


    class adjIterator{
    private:
        int v;
        int index;
        SparseGraph &G;

    public:
        adjIterator(SparseGraph &graph,int v):G(graph){
            this->v = v;
            this->index = 0;
        }

        Edge<Weight>* begin(){
            index = 0;
            if(G.g[v].size())
                return G.g[v][index];
            return NULL;
        }

        Edge<Weight>* next(){
            index ++;
            if(index < G.g[v].size())
                return G.g[v][index];
            return NULL;
        }

        bool end(){
            return index >= G.g[v].size();
        }
    };

};


#endif //MINISPANTREE_SPARSEGRAPH_H
