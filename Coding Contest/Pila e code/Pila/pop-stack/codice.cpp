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
            string s;
            int cont = 0;
            for (int i = 0; i < n; i++)
            {
                fileInput >> s;
                if (s == "pop")
                {
                    StackInt.pop();
                }
                else
                {
                    val = stoi(s.substr(1, s.length()));
                    StackInt.push(val);
                    cout << val << endl;
                    cont++;
                }
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
            string s;
            int cont = 0;
            for (int i = 0; i < n; i++)
            {
                fileInput >> s;
                if (s == "pop")
                {
                    StackDouble.pop();
                }
                else
                {
                    val = stod(s.substr(1, s.length()));
                    StackDouble.push(val);
                    cout << val << endl;
                    cont++;
                }
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
            int val;
            string s;
            int cont = 0;
            for (int i = 0; i < n; i++)
            {
                fileInput >> s;
                if (s == "pop")
                {
                    StackBool.pop();
                }
                else
                {
                    char c = s[s.length() - 1];
                    if (c == '1')
                    {
                        val = true;
                    }
                    else
                    {
                        val = false;
                    }
                    StackBool.push(val);
                    cout << val << endl;
                    cont++;
                }
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
            string s;
            int cont = 0;
            for (int i = 0; i < n; i++)
            {
                fileInput >> s;
                if (s == "pop")
                {
                    Stackchar.pop();
                }
                else
                {
                    char c = s[s.length() - 1];
                    val = (int)c;
                    Stackchar.push(val);
                    cout << val << endl;
                    cont++;
                }
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