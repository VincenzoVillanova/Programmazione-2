#include "bst.h"
#include<iostream>
using namespace std;
int main(){
    BST<int> bst;
    bst.insert(40);
    bst.insert(25);
    bst.insert(21);
    bst.insert(18);
    bst.insert(57);
    bst.insert(36);
    bst.insert(46);
    bst.insert(32);

    bst.inorder();
    int na;
    na=bst.distanzasuccessore(bst.search(46));
    cout<<"Numero archi al successore di 46 = "<<na<<endl;
}