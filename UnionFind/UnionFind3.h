//
// Created by liqiang on 2018/2/25.
//

#ifndef UNIONFIND_UNIONFIND3_H
#define UNIONFIND_UNIONFIND3_H

#include <cassert>

//基于size的优化
namespace UF3{
    class UnionFind{
    private:
        int* parent;
        int* size;//size[i]表示以i为根的集合的元素个数
        int count;

    public:
        UnionFind(int count){
            parent = new int[count];
            size = new int[count];
            this->count = count;

            for (int i = 0; i < count; ++i) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        ~UnionFind(){
            delete[] parent;
            delete[] size;
        }

        int find(int p){
            assert(p >=0 && p < count);
            while ( p!= parent[p]){
                p = parent[p];
            }
            return p;
        }

        bool isConnected(int p,int q){
            return find(p) == find(q);
        }

        void unionElements(int p,int q){
            int pRoot = find(p);
            int qRoot = find(q);

            if(qRoot == pRoot)
                return;

            //元素少的往元素多的上面挂
            if(size[pRoot] > size[qRoot]){
                //q元素少
                parent[qRoot] = pRoot;
                size[pRoot] += size[qRoot];
            }else{
                //p元素少
                parent[pRoot] = qRoot;
                size[qRoot] += size[pRoot];
            }
        }

    };
}
#endif //UNIONFIND_UNIONFIND3_H
