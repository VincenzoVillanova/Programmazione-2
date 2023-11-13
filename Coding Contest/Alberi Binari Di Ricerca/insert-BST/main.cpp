#include "bst.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    fstream fileOutput("output.txt", fstream::out);
    BST<int> bst;
    string s = "";
    bst.insert(40);
    bst.insert(25);
    bst.insert(21);
    bst.insert(18);
    bst.insert(57);
    bst.insert(36);
    bst.insert(46);
    bst.insert(32);
    bst.insert(78);
    bst.insert(52);
    bst.insert(13);
    bst.insert(44);

    bst.inorder();
    s = bst.Ritornas();
     fileOutput << s;
    fileOutput << "\n";
}
