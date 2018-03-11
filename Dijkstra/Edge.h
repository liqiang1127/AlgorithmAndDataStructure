//
// Created by liqiang on 2018/2/28.
//

#ifndef DIJKSTRA_EDGE_H
#define DIJKSTRA_EDGE_H

#include <iostream>
#include <cassert>


using namespace std;

template <typename Weight>
class Edge{

private:
    int a,b;
    Weight weight;
public:
    Edge(int v,int w,Weight weight){
        this->a = v;
        this->b = w;
        this->weight = weight;
    }

    ~Edge(){

    }

    int v(){
        return a;
    }
    int w(){
        return b;
    }
    Weight wt(){
        return weight;
    }

    int other(int v){
        assert( v==a || v==b);
        return v == a ? b : a;
    }

    friend ostream& operator<<(ostream &os, const Edge &e){
        os<<e.a<<"-"<<e.b<<": "<<e.weight;
        return os;
    }

    bool operator<(Edge<Weight>& e){
        return weight < e.wt();
    }

    bool operator<=(Edge<Weight>& e){
        return weight <= e.wt();
    }

    bool operator>(Edge<Weight>& e){
        return weight > e.wt();
    }

    bool operator>=(Edge<Weight>& e){
        return weight >= e.wt();
    }

    bool operator==(Edge<Weight>& e){
        return weight == e.wt();
    }
};

#endif //DIJKSTRA_EDGE_H
