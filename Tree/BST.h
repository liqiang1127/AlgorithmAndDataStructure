//
// Created by liqiang on 2018/2/23.
//

#ifndef TREE_BST_H
#define TREE_BST_H

#include <iostream>
#include <queue>
#include <cassert>

using namespace std;

template <typename Key, typename Value>
class BST{
private:
    struct Node{
        Key key;
        Value value;
        Node* left;
        Node* right;

        Node(Key key,Value value){
            this->value = value;
            this->key = key;
            this->left = this->right = NULL;
        }

        Node(Node* node){
            this->key = node->key;
            this->left = node->left;
            this->right = node->right;
            this->value = node->value;
        }
    };

    Node* root;
    int count;

public:
    BST(){
        root = NULL;
        count = 0;
    }
    ~BST(){
        destroy(root);
    }
    int size(){
        return count;
    }

    bool isEmpty(){
        return count == 0;
    }

//        // 向二分搜索树中插入一个新的(key, value)数据对
//    void insert(Key key, Value value){
//        root = insert(root, key, value);
//    }


    void insert(Key key,Value value){
        root = insert(root,key,value);
    }

    bool contain(Key key){
        return contain(root,key);
    }

    Value* search(Key key){
        return search(root,key);
    }

    void preOrder(){
        preOrder(root);
    }

    void inOrder(){
        inOrder(root);
    }

    void postOrder(){
        postOrder(root);
    }

    void levelOrder(){
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* node = q.front();
            q.pop();

            cout<<node->value<<" ";

            if(node->left!= NULL)
                q.push(node->left);
            if(node->right != NULL)
                q.push(node->right);
        }
    }


    Key minimum(){
        assert(count != 0);
        Node* node = minimum(root);
        return node->key;
    }

    Key maxmum(){
        assert(count != 0);
        Node* node = maxmum(root);
        return node->key;
    }

    void removeMin(){
        if(root)
           root = removeMin(root);
    }

    void removeMax(){
        if(root)
            root = removeMax(root);
    }


    void remove(Key key){
        root = remove(root,key);
    }

private:
    //向以node为根的二叉搜索树中插入新的节点
    //返回插入新节点后二叉搜索树的根
    Node* insert(Node* node,Key key,Value value){
        if(node == NULL){
            count ++;
            return new Node(key,value);
        }
        if(node->key == key){
            //更新
            node->value = value;
        }else if(node->key < key){
            node->right = insert(node->right,key,value);
        }else{//node->key > key
            node->left = insert(node->left,key,value);
        }

        return node;
    }

    //在以node为根的二叉树中查找key 找到返回 true
    bool contain(Node* node,Key key){
        if(node == NULL)
            return false;

        if(node->key == key)
            return true;
        else if (key > node->key)
            return contain(node->right,key);
        else
            return contain(node->left,key);
    }

    //在以node为根的二叉树中查找key 若找到返回 key对应value的指针
    Value* search(Node* node,Key key){
        if(node == NULL)
            return NULL;

        if(node->key == key)
            return &(node->value);
        else if(key > node->key)
            return search(node->right,key);
        else
            return search(node->left,key);
    }

    //先序遍历以node为为根的二叉树
    void preOrder(Node* node){
        if(node != NULL){
            cout<<node->value<<" ";
            preOrder(node->left);
            preOrder(node->right);
        }

    }


    //中序遍历以node为根的二叉树
    void inOrder(Node* node){
        if(node != NULL ){
            inOrder(node->left);
            cout<<node->value<<" ";
            inOrder(node->right);
        }
    }

    //后续遍历以node为根的二叉树
    void postOrder(Node* node){
        if(node != NULL){
            postOrder(node->left);
            postOrder(node->right);
            cout<<node->value<<" ";
        }
    }

    void destroy(Node* node){
        if(node != NULL){
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }

    //在以node为根的二叉搜索树中寻找最小的元素
    Node* minimum(Node* node){
        if( node->left == NULL)
            return node;
        return minimum(node->left);
    }

    //在以node为根的二叉搜索树中寻找最大的元素
    Node* maxmum(Node* node){
        if(node->right == NULL)
            return node;
        return maxmum(node->right);
    }

    //在以node为根的二叉搜索树种删除最小的元素 返回删除节点后的子树的根
    Node* removeMin(Node* node){
        if(node->left == NULL){
            //这个逻辑对于node是不是叶子节点的情况都是对的
            //如果右孩子为null 这个逻辑也是对的
            Node* rightNode = node->right;
            count--;
            delete node;
            return rightNode;
        }
        node->left = removeMin(node->left);
        return node;
    }

    //在以node为根的二叉搜索树种删除最大的元素 返回删除节点后的子树的根
    Node* removeMax(Node* node){
        if(node->right == NULL){
            Node* leftNode = node->left;
            count--;
            delete node;
            return leftNode;
        }

        node->right = removeMax(node->right);
        return node;
    }

    //在以node为根的二叉搜索树种删除指定元素 返回删除节点后的子树的根
    Node* remove(Node* node,Key key){
        if(node == NULL)
            return NULL;

        if(key > node->key){
            node->right = remove(node->right,key);
            return node;
        }else if(key < node->key){
            node->left = remove(node->left,key);
            return node;
        }else {//key == node->key
            if(node->left == NULL){
                Node* rightNode = node->right;
                delete node;
                count--;
                return rightNode;
            }

            if(node->right == NULL){
                Node* leftNode = node->right;
                delete node;
                count--;
                return leftNode;
            }

            //左孩子右孩子都有 用右子树的最小值代替删除节点
            Node* successor = new Node(minimum(node->right));
            count++;

            successor->right = removeMin(node->right);
            successor->left = node->left;

            delete node;
            count --;
            return successor;
        }

    }
};
#endif //TREE_BST_H
