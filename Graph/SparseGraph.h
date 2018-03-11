//
// Created by liqiang on 2018/2/25.
//

#ifndef GRAPH_SPARSEGRAPH_H
#define GRAPH_SPARSEGRAPH_H

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

//稀疏图 - 邻接表
class SparseGraph{
private:
    int n,m;
    bool directed;
    vector<vector<int>> g;

public:
    SparseGraph(int n,bool directed){
        this->n = n;
        this->m = 0;
        this->directed = directed;

        for (int i = 0; i < n ; ++i) {
            g.push_back(vector<int>());
        }
    }

    ~SparseGraph(){

    }

    int V(){return n;}
    int E(){return m;}

    void addEdge(int v,int w){
        assert(v>=0 && v<n);
        assert(w>=0 && w<n);

        g[v].push_back(w);

        //v!=w 处理自环图
        //在邻接矩阵中不必考虑 v!=w 是因为 就算v==w 只是把g[v][w]中的true 再变成true 没啥用
        if(v !=w &&!directed)
            g[w].push_back(v);

        m++;
        //邻接表 不好处理平行边
    }

    bool hasEdge(int v,int w){
        assert(v>=0 && v<n);
        assert(w>=0 && w<n);

        for (int i = 0; i < g[v].size(); ++i) {
            if(g[v][i] == w)
                return true;
        }
        return false;
    }

    void show(){

        for( int i = 0 ; i < n ; i ++ ){
            cout<<"vertex "<<i<<":\t";
            for( int j = 0 ; j < g[i].size() ; j ++ )
                cout<<g[i][j]<<"\t";
            cout<<endl;
        }
    }

    class adjIterator{
    private:
        SparseGraph &G;
        int v;
        int index;

    public:
        adjIterator(SparseGraph &graph,int v):G(graph){
            this->v = v;
            this->index = 0;
        }

        int begin(){
            index = 0;
            if(G.g[v].size())
                return G.g[v][index];
            return -1;
        }

        int next(){
            index++;
            if(index < G.g[v].size())
                return G.g[v][index];
            return -1;
        }

        bool end(){
            return index >= G.g[v].size();
        }
    };
};

#endif //GRAPH_SPARSEGRAPH_H
