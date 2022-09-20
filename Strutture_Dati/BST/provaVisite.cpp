#include <iostream>
#include "bst.h"
using namespace std;

int main()
{

    BST<int> bst;

    try
    {
        bst.max();
    }
    catch (const char *ex)
    {
        std::cout << ex << std::endl;
    }

    bst.insert(4);
    bst.insert(2);
    bst.insert(6);
    bst.insert(1);
    bst.insert(3);
    bst.insert(5);
    bst.insert(7);

    bst.preorder();
    //   bst.inorder();
    //  bst.postorder();

    cout << "Indirizzo del nodo con key 4: " << bst.search(4) << endl;
    BSTNode<int> *aux = bst.search(4);

    cout << "Predecessore: " << bst.predecessor(aux) << endl;
    cout << "Successore: " << bst.successor(aux) << endl;
}