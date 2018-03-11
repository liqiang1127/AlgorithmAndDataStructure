//
// Created by liqiang on 2018/2/26.
//

#ifndef GRAPH_PATH_H
#define GRAPH_PATH_H

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//路径查询
template <typename Graph>
class Path{
private:
    Graph &G;
    bool *visited;
    int* from;
    int s;

    void dfs(int v){

        visited[v] = true;

        typename Graph::adjIterator adj(G,v);

        for (int i = adj.begin(); !adj.end() ; i = adj.next()) {
            if(!visited[i]){
                from[i] = v;
                dfs(i);
            }
        }
    }


public:
    Path(Graph &graph,int s):G(graph){

        assert( s >= 0 && s< G.V() );

        visited = new bool[G.V()];
        from = new int[G.V()];
        this->s = s;
        for (int i = 0; i < G.V(); ++i) {
            visited[i] = false;
            from[i] = -1;
        }

        dfs(s);
    }

    ~Path(){
        delete[] from;
        delete[] visited;
    }

    //s和w之间是否有路径
    bool hasPath(int w){
        assert( w >= 0 && w < G.V() );
        return visited[w];
    }

    //s w之间路径
    void path(int w,vector<int> &vec){
        assert( w >= 0 && w < G.V() );
        stack<int> s;

        int p = w;
        while (p != -1){
            s.push(p);
            p = from[p];
        }

        vec.clear();
        while (!s.empty()){
            vec.push_back(s.top());
            s.pop();
        }
    }

    void showPath(int w){
        assert( w >= 0 && w < G.V() );
        vector<int> vec;
        path(w,vec);

        for (int i = 0; i < vec.size() ; ++i) {
            cout<<vec[i];
            if( i == vec.size()-1)
                cout<<endl;
            else
                cout<<" -> ";
        }

    }
};

#endif //GRAPH_PATH_H
