#include <iostream>
#include <string>
#include <fstream>
#include "stack.h"
using namespace std;
int main()
{

    Stack<int> StackInt;
    Stack<double> StackDouble;
    Stack<bool> StackBool;
    Stack<char> Stackchar;
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);
    string type = "";
    int n = 0;

    for (int x = 0; x < 100; x++)
    {
        fileInput >> type >> n;
        if (type == "int")
        {
            int val;
            int cont = 0;
            for (int i = 0; i < n; i++)
            {
                fileInput >> val;
                StackInt.push(val);
                cont++;
            }
            fileOutput << StackInt;
            fileOutput << "\n";
            for (int j = 0; j < cont; j++)
            {
                StackInt.pop();
            }
        }
        if (type == "double")
        {
            double val;
            int cont = 0;
            for (int i = 0; i < n; i++)
            {
                fileInput >> val;
                StackDouble.push(val);
                cont++;
            }

            fileOutput << StackDouble;
            fileOutput << "\n";
            for (int j = 0; j < cont; j++)
            {
                StackDouble.pop();
            }
        }
        if (type == "bool")
        {
            bool val;
            int cont = 0;
            for (int i = 0; i < n; i++)
            {
                fileInput >> val;
                StackBool.push(val);
                cont++;
            }
            fileOutput << StackBool;
            fileOutput << "\n";
            for (int j = 0; j < cont; j++)
            {
                StackBool.pop();
            }
        }
        if (type == "char")
        {
            char val;
            int cont = 0;
            for (int i = 0; i < n; i++)
            {
                fileInput >> val;
                Stackchar.push(val);
                cont++;
            }
            fileOutput << Stackchar;
            fileOutput << "\n";
            for (int j = 0; j < cont; j++)
            {
                Stackchar.pop();
            }
        }
    }
}