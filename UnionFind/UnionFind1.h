//
// Created by liqiang on 2018/2/25.
//

#ifndef UNIONFIND_UNIONFIND1_H
#define UNIONFIND_UNIONFIND1_H

#include <iostream>
#include <cassert>

using namespace std;

//quick find
namespace UF1{
    class UnionFind{
    private:
        int* id;
        int count;

    public:
        UnionFind(int n){
            count = n;
            id = new int[n];
            for (int i = 0; i < n; ++i) {
                id[i] = i;
            }
        }

        ~UnionFind(){
            delete[] id;
        }

        int find(int p){
            assert( p>=0 && p < count);
            return id[p];
        }

        bool isConnected(int p,int q){
            return find(p) == find(q);
        }

        //  O(n)级别
        void unionElements(int p , int q){
            int pId = find(p);
            int qId = find(q);

            if(pId == qId)
                return;

            for (int i = 0; i < count; ++i) {
                if(id[i] == qId)
                    id[i] = pId;
            }
        }
    };

}

#endif //UNIONFIND_UNIONFIND1_H
