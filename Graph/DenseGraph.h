//
// Created by liqiang on 2018/2/25.
//

#ifndef GRAPH_DENSEGRAPH_H
#define GRAPH_DENSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


//稠密图 - 邻接矩阵
class DenseGraph{
private:
    int n,m;//n表示节点数目 m表示边的数目
    bool directed;//是否是有向图
    vector<vector<bool>> g;// 邻接矩阵

public:
    DenseGraph(int n,bool directed){
        this->n = n;
        this->directed = directed;
        this->m = 0;
        for (int i = 0; i < n; ++i) {
            g.push_back(vector<bool>(n,false));
        }

    }

    ~DenseGraph(){

    }

    int V(){return n;}
    int E(){return m;}

    //参数是2个节点的索引
    void addEdge(int v,int w){
        assert(v>=0 && v<n);
        assert(w>=0 && w<n);

        if(hasEgde(v,w))
            return;

        g[v][w] = true;
        if(!directed)//如果是无向图
            g[w][v] = true;

        m++;
    }


    bool hasEgde(int v,int w){
        assert(v>=0 && v<n);
        assert(w>=0 && w<n);
        return g[v][w];
    }

    void show(){
        for( int i = 0 ; i < n ; i ++ ){
            for( int j = 0 ; j < n ; j ++ )
                cout<<g[i][j]<<"\t";
            cout<<endl;
        }
    }

    class adjIterator{
    private:
        DenseGraph &G;
        int v;
        int index;
    public:
        adjIterator(DenseGraph &graph,int v):G(graph){
            this->v = v;
            this->index = -1;
        }

        int begin(){
            index = -1;
            return next();
        }

        int next(){
            for ( index+=1 ; index < G.V() ; index++) {
                if(G.g[v][index])//一旦找到true 就返回
                    return index;
            }
            return -1;
        }

        bool end(){
            return index >= G.V();
        }
    };
};


#endif //GRAPH_DENSEGRAPH_H
