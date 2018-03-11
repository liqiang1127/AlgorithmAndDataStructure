//
// Created by liqiang on 2018/3/1.
//

#ifndef BELLMAN_FORD_EDGE_H
#define BELLMAN_FORD_EDGE_H

#include <iostream>
#include <cassert>

using namespace std;

template <typename Weight>
class Edge{
private:
    int a,b;//从 a 到 b 的边
    Weight weight;
public:
    Edge(int v,int w,Weight weight){
        this->a = v;
        this->b = w;
        this->weight = weight;
    }

    ~Edge(){

    }

    int v(){//返回起点
        return a;
    }

    int w(){//返回终点
        return b;
    }

    Weight wt(){
        return weight;
    }

    int other(int x){
        assert( x==a || x==b);
        return x==a ? b : a;
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

#endif //BELLMAN_FORD_EDGE_H
