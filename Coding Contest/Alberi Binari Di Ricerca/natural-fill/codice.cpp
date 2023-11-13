#include <iostream>
#include <fstream>
#include <string>
#include "bst.h"
using namespace std;
int main()
{
    BST<int> BstInt;
    BST<double> BstDouble;
    string output = "";
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);

    string type = "";
    int n = 0;
    int vali = 0;
    double vald = 0;
    for (int x = 0; x < 100; x++)
    {
        fileInput >> type >> n;
        if (type == "int")
        {
            for (int i = 0; i < n; i++)
            {
                fileInput>>vali;
                BstInt.insert(vali);
            }
            BSTNode<int> *aux = BstInt.min();
            BSTNode<int> *aux2 = BstInt.successor(aux);
            for (int i = 0; i < n; i++)
            {
                fileInput >> vali;
                int val=0;
                val=aux->getKey();
                aux2=BstInt.successor(aux);
                aux->setKey(vali);
                aux=aux2;
            }
            BstInt.postorder();
            fileOutput<<BstInt.Ritornas();
            fileOutput << "\n";
            BstInt.Puliscis();
            BstInt.clear();
        }
        if (type == "double")
        {
            for (int i = 0; i < n; i++)
            {
                fileInput >> vald;
                BstDouble.insert(vald);
            }
            BSTNode<double> *aux = BstDouble.min();
            BSTNode<double> *aux2 = BstDouble.successor(aux);
            for (int i = 0; i < n; i++)
            {
                fileInput >> vald;
                double val=0;
                val=aux->getKey();
                aux2=BstDouble.successor(aux);
                aux->setKey(vald);
                aux=aux2;
            }
            BstDouble.postorder();
            fileOutput<<BstDouble.Ritornas();
            fileOutput << "\n";
            BstDouble.Puliscis();
            cout << endl;
            BstDouble.clear();
        }
    }
}