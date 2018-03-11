//
// Created by liqiang on 2018/2/28.
//

#ifndef DIJKSTRA_DIJSTRA_H
#define DIJKSTRA_DIJSTRA_H

#include <iostream>
#include <vector>
#include <stack>

#include "Edge.h"
#include "IndexMinHeap.h"

using namespace std;

//单源最短路径
template <typename Graph,typename Weight>
class Dijkstra{
private:
    Graph &G;
    int s;//源

    Weight* distTo;//从源点到各个点的距离
    bool* marked;//
//    int* from;//用于记录路径

    vector<Edge<Weight> *> from;//-----我们后面要把最短路径上的放在vector返回 只是用int只能知道 从哪个点的来的---
public:
    Dijkstra(Graph &graph,int s):G(graph){
        distTo = new Weight[G.V()];//点数
        marked = new bool[G.V()];

        this->s = s;

        for (int i = 0; i < G.V(); ++i) {
            distTo[i] = Weight();
            marked[i] = false;
            from.push_back(NULL);
        }

        IndexMinHeap<Weight> ipq(G.V());

        //一下2句是多余的
//        distTo[s] = Weight();
//        marked[s] = true;
        ipq.insert(s,distTo[s]);

        while (!ipq.isEmpty()){
            int v = ipq.extractMinIndex();

            marked[v] = true;

            typename Graph::adjIterator adj(G,v);
            for (Edge<Weight>* e = adj.begin(); !adj.end() ;  e = adj.next()) {
                int w = e ->other(v);
                if(!marked[w]){
                    if(from[w] == NULL || distTo[v] + e->wt() < distTo[w]){
                        distTo[w] = distTo[v] + e->wt();
                        from[w] = e;
                        if(!ipq.contain(w))
                            ipq.insert(w,distTo[w]);
                        else
                            ipq.change(w,distTo[w]);
                    }
                }
            }
        }


    }

    ~Dijkstra(){
        delete[] distTo;
        delete[] marked;
    }

    Weight shortestPathTo( int w ){
        assert( w >= 0 && w < G.V() );
        return distTo[w];
    }

    bool hasPathTo( int w ){
        assert( w >= 0 && w < G.V() );
        return marked[w];
    }

//    void shortestPath( int w, vector<Edge<Weight>> &vec ){
//        assert(hasPathTo(w));
//
//        stack<Edge<Weight> *> stack;
//
//        Edge<Weight> *e = from[w];
//        while (e->v() != this->s){
//            //不是从源点指过来的
//            stack.push(e);
//            e = from[e->v()];
//        }
//        //压入最后一条从源点指过来的边
//        stack.push(e);
//
//        while(!stack.empty()){
//            e = stack.top();
//            stack.pop();
//            vec.push_back(*e);
//        }
//    }

    void shortestPath( int w, vector<Edge<Weight>> &vec ){

        assert( w >= 0 && w < G.V() );

        stack<Edge<Weight>*> s;
        Edge<Weight> *e = from[w];
        while( e->v() != this->s ){
            s.push(e);
            e = from[e->v()];
        }
        s.push(e);

        while( !s.empty() ){
            e = s.top();
            vec.push_back( *e );
            s.pop();
        }
    }

    void showPath(int w){

        assert( w >= 0 && w < G.V() );

        vector<Edge<Weight>> vec;
        shortestPath(w, vec);
        for( int i = 0 ; i < vec.size() ; i ++ ){
            cout<<vec[i].v()<<" -> ";
            if( i == vec.size()-1 )
                cout<<vec[i].w()<<endl;
        }
    }
};

#endif //DIJKSTRA_DIJSTRA_H
