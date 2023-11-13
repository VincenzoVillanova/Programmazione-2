#include <iostream>
#include <fstream>
#include <string>
#include "bst.h"
using namespace std;
int main()
{
    BST<int> bsti;
    BST<double> bstd;
    BST<bool> bstb;
    BST<char> bstc;
    string output = "";
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);

    string type = "";
    int n = 0;
    string visit = "";
    do
    {
        fileInput >> type >> n >> visit;
        output = "";
        if (type == "int")
        {
            int val[n];
            for (int i = 0; i < n; i++)
            {
                fileInput >> val[i];
                bsti.insert(val[i]);
            }
            if (visit == "inorder")
            {
                bsti.Puliscis();
                output="";
                bsti.inorder();
                output = bsti.Ritornas();
                fileOutput << output;
                fileOutput << "\n";
            }
            else if (visit == "preorder")
            {
                bsti.Puliscis();
                output="";
                bsti.preorder();
                output = bsti.Ritornas();
                fileOutput << output;
                fileOutput << "\n";
            }
            else
            {
                bsti.Puliscis();
                output="";
                bsti.postorder();
                output = bsti.Ritornas();
                fileOutput << output;
                fileOutput << "\n";
            }
            bsti.Puliscis();
            bsti.clear();
            output="";
        }
        if (type == "double")
        {
            double val[n];
            for (int i = 0; i < n; i++)
            {
                fileInput >> val[i];
                bstd.insert(val[i]);
            }
            if (visit == "inorder")
            {
                bstd.Puliscis();
                output="";
                bstd.inorder();
                output = bstd.Ritornas();
                fileOutput << output;
                fileOutput << "\n";
            }
            else if (visit == "preorder")
            {
                bstd.Puliscis();
                output="";
                bstd.preorder();
                output = bstd.Ritornas();
                fileOutput << output;
                fileOutput << "\n";
            }
            else
            {
                bstd.Puliscis();
                output="";
                bstd.postorder();
                output = bstd.Ritornas();
                fileOutput << output;
                fileOutput << "\n";
            }
            bstd.Puliscis();
            bstd.clear();
        }
        if (type == "bool")
        {
            bool val[n];
            for (int i = 0; i < n; i++)
            {
                fileInput >> val[i];
                bstb.insert(val[i]);
            }
            if (visit == "inorder")
            {
                bstb.Puliscis();
                output="";
                bstb.inorder();
                output = bstb.Ritornas();
                fileOutput << output;
                fileOutput << "\n";
            }
            else if (visit == "preorder")
            {
                bstb.Puliscis();
                output="";
                bstb.preorder();
                output = bstb.Ritornas();
                fileOutput << output;
                fileOutput << "\n";
            }
            else
            {
                bstb.Puliscis();
                output="";
                bstb.postorder();
                output = bstb.Ritornas();
                fileOutput << output;
                fileOutput << "\n";
            }
            bstb.Puliscis();
            bstb.clear();
        }
        if (type == "char")
        {
            char val[n];
            for (int i = 0; i < n; i++)
            {
                fileInput >> val[i];
                bstc.insert(val[i]);
            }
            if (visit == "inorder")
            {
                bstc.Puliscis();
                output="";
                bstc.inorder();
                output = bstc.Ritornas();
                fileOutput << output;
                fileOutput << "\n";
            }
            else if (visit == "preorder")
            {
                bstc.Puliscis();
                output="";
                bstc.preorder();
                output = bstc.Ritornas();
                fileOutput << output;
                fileOutput << "\n";
            }
            else
            {
                bstc.Puliscis();
                output="";
                bstc.postorder();
                output = bstc.Ritornas();
                fileOutput << output;
                fileOutput << "\n";
            }
            bstc.Puliscis();
            bstc.clear();
        }
    } while (fileInput.good());
    
}