#include <iostream>
#include <fstream>
#include <string>
#include "bst.h"
using namespace std;

int main()
{

    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);

    BST<int> bsti;
    BST<double> bstd;
    int n = 0, m = 0;
    string type = "";
    fileInput >> type >> n >> m;
    if (type == "int")
    {
        int val[n];
        string s = "";
        for (int i = 0; i < n; i++)
        {
            fileInput >> s;
            val[i] = stoi(s.substr(4, s.length()));
            bsti.insert(val[i]);
        }
        int v = 0;
        for (int i = 0; i < m; i++)
        {
            fileInput >> v;
            BSTNode<int> *n1 = bsti.search(v);
            BSTNode<int> *n2 = bsti.successor(n1);
            if (!n2)
            {
                fileOutput << "INF ";
                cout << "INF ";
            }
            else
            {
                fileOutput << bsti.DistanzaSuccessore(n1) << " ";
                cout << bsti.DistanzaSuccessore(n1) << " ";
            }
        }
        bsti.clear();
    }
    if (type == "double")
    {
        double val[n];
        string s = "";
        for (int i = 0; i < n; i++)
        {
            fileInput >> s;
            val[i] = stoi(s.substr(4, s.length()));
            bstd.insert(val[i]);
        }
        double v = 0;
        for (int i = 0; i < m; i++)
        {
            fileInput >> v;
            BSTNode<double> *n1 = bstd.search(v);
            BSTNode<double> *n2 = bstd.successor(n1);
            if (n2)
            {
                fileOutput << "INF ";
                cout << "INF ";
            }
            else
            {
                fileOutput << bstd.DistanzaSuccessore(n1) << " ";
                cout << bstd.DistanzaSuccessore(n1) << " ";
            }
        }
        bstd.clear();
    }
    fileOutput << "\n";
    cout << endl;
}