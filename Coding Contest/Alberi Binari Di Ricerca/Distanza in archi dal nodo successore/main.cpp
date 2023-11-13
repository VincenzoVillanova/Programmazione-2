#include "bst2.h"
#include <fstream>

int main() {
    fstream input("input.txt", fstream::in);
    fstream output("output.txt", fstream::out);

    for(int i=0; i<100; i++) {
        string type;
        input >> type;

        int numOp;
        input >> numOp;

        int numSucc;
        input >> numSucc;

        BST<int> intBST;
        BST<double> doubleBST;

        for(int j=0; j<numOp; j++) {
            string op;
            input >> op;

            if(type == "int") {
                int value = stoi(op.substr(op.find(":") + 1));
                if(op.substr(0, op.find(":")) == "ins")
                    intBST.insert(value);
                else
                    intBST.remove(value);
            }else {
                double value = stod(op.substr(op.find(":") + 1));
                if(op.substr(0, op.find(":")) == "ins")
                    doubleBST.insert(value);
                else
                    doubleBST.remove(value);
            }
        }

        if(i == 75)
            doubleBST.inorder();


        for(int j=0; j<numSucc; j++) {
            if(type == "int") {
                int value;
                input >> value;

                int countEdge;
                BSTNode<int>* succ = intBST.successor(intBST.search(value), countEdge);
                if(!succ)
                    output << "INF ";
                else
                    output << countEdge << " ";
            }else {
                double value;
                input >> value;

                int countEdge;
                BSTNode<double>* succ = doubleBST.successor(doubleBST.search(value), countEdge);
                if(!succ)
                    output << "INF ";
                else
                    output << countEdge << " ";
            }
        }
        output << endl;
    }


}