#include <iostream>
#include "BST.h"

using namespace std;

int main() {
    BST<int,int> bst = BST<int,int>();
    int keys[7] = {5,3,1,4,7,8,6};
    for (int i = 0; i < 7 ; ++i) {
        bst.insert(keys[i],keys[i]);
    }
    bst.preOrder();
    cout<<endl;
    bst.inOrder();
    cout<<endl;
    bst.postOrder();
    cout<<endl;
    bst.levelOrder();
    cout<<endl;

    bst.remove(3);

    bst.preOrder();
    cout<<endl;
    bst.inOrder();
    cout<<endl;
    bst.postOrder();
    cout<<endl;
    bst.levelOrder();
    cout<<endl;

//    cout<<*(bst.search(bst.minimum()))<<endl;
//    cout<<*(bst.search(bst.maxmum()))<<endl;

//    bst.removeMax();
//    bst.preOrder();

//    bst.removeMin();
//    bst.preOrder();
    return 0;
}