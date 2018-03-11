//
// Created by liqiang on 2018/2/25.
//

#ifndef UNIONFIND_UNIONFIND5_H
#define UNIONFIND_UNIONFIND5_H
#include <cassert>

//路径压缩
namespace UF5{
    class UnionFind{
    private:
        int* parent;
        int* rank;//rank[i]表示以i为根的集合的层数
        int count;

    public:
        UnionFind(int count){
            parent = new int[count];
            rank = new int[count];
            this->count = count;

            for (int i = 0; i < count; ++i) {
                parent[i] = i;
                rank[i] = 1;
            }
        }

        ~UnionFind(){
            delete[] parent;
            delete[] rank;
        }

        int find(int p){
            assert(p >=0 && p < count);

            //递归 由于递归 时间反而长了
            if( p!= parent[p])
                parent[p] = find(parent[p]);
            return parent[p];

            //迭代
//            while ( p!= parent[p]){
//                parent[p] = parent[parent[p]];
//                p = parent[p];
//            }
//            return p;
        }

        bool isConnected(int p,int q){
            return find(p) == find(q);
        }

        void unionElements(int p,int q){
            int pRoot = find(p);
            int qRoot = find(q);

            if(qRoot == pRoot)
                return;

            if(rank[pRoot] < rank[qRoot]){
                parent[pRoot] = qRoot;
            }else if (rank[qRoot] < rank[pRoot]){
                parent[qRoot] = pRoot;
            }else{
                //rank[pRoot] == rank[qRoot]
                parent[pRoot] = qRoot;
                rank[qRoot] += 1;
            }
        }

    };
}
#endif //UNIONFIND_UNIONFIND5_H
