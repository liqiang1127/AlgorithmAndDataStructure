//
// Created by liqiang on 2018/2/28.
//

#ifndef MINISPANTREE_UNIONFIND_H
#define MINISPANTREE_UNIONFIND_H

#include <iostream>
#include <cassert>

using namespace std;

//基于rank 路基压缩的优化
class UnionFind{
private:
    int *parent;//存各个节点的父节点
    int *rank;//基于rank的优化
    int count;
public:
    UnionFind(int count){
        this->count = count;
        parent = new int[count];
        rank = new int[count];


        for (int i = 0; i < count ; ++i) {
            //默认单个元素是集合
            parent[i] = i;
            rank[i] = 1;
        }
    }

    ~UnionFind(){
        delete[] parent;
        delete[] rank;
    }


    int find(int p){
        //找p节点的父节点
        assert( p>=0 && p<count);

        while( p != parent[p]){
            parent[p] = parent[parent[p]];
            p = parent[p];
        }

        return p;
    }

    bool isConnected(int p,int q){
        assert( p>=0 && p<count);
        assert( q>=0 && q<count);
        return find(p) == find(q);
    }

    void unionElements(int p,int q){
        assert( p>=0 && p<count);
        assert( q>=0 && q<count);

        int qRoot = find(q);
        int pRoot = find(p);

        if(pRoot == qRoot)
            return;

        //基于rank的优化
        if(rank[pRoot] > rank[qRoot]){
            parent[qRoot] = pRoot;
        }else if(rank[pRoot] < rank[qRoot]){
            parent[pRoot] = qRoot;
        }else{
            parent[pRoot] = qRoot;
            rank[qRoot] += 1;
        }
    }
};
#endif //MINISPANTREE_UNIONFIND_H
