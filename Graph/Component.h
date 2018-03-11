//
// Created by liqiang on 2018/2/26.
//

#ifndef GRAPH_COMPONENT_H
#define GRAPH_COMPONENT_H


//求无向图的连通分量

template <typename Graph>
class Component{
private:
    Graph &G;
    int ccount;
    bool *visited;
    int *id;

    void dfs(int v){
        visited[v] = true;
        id[v] = ccount;
        typename Graph::adjIterator adj(G,v);

        for(int i = adj.begin() ; !adj.end() ; i = adj.next() ) {
                if(!visited[i])
                    dfs(i);
        }
    }

public:
    Component(Graph &graph):G(graph){
        visited = new bool[G.V()];
        id = new int[G.V()];
        ccount = 0;
        for (int i = 0; i < G.V(); ++i){
            visited[i] = false;
            id[i] = -1;
        }

        for (int i = 0; i < G.V() ; ++i) {
            if(!visited[i]){
                //当前节点没被访问过 就深度优先的递归访问
                dfs(i);
                ccount++;
            }
        }
    }

    ~Component(){
        delete[] visited;
        delete[] id;
    }

    int count(){
        return ccount;
    }

    bool isConnected(int v,int w){
        return id[v] == id[w];
    }

};

#endif //GRAPH_COMPONENT_H
