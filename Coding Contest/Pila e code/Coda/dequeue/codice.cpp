#include <iostream>
#include <string>
#include <fstream>
#include "queue.h"
using namespace std;
int main()
{

    Queue<int> QueueInt;
    Queue<double> QueueDouble;
    Queue<bool> QueueBool;
    Queue<char> Queuechar;
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
                if (s == "dequeue")
                {
                    QueueInt.dequeue();
                }
                else
                {
                    val = stoi(s.substr(1, s.length()));
                    QueueInt.enqueue(val);
                    cout << val << endl;
                    cont++;
                }
            }
            fileOutput << QueueInt;
            fileOutput << "\n";
            for (int j = 0; j < cont; j++)
            {
                QueueInt.dequeue();
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
                if (s == "dequeue")
                {
                    QueueDouble.dequeue();
                }
                else
                {
                    val = stod(s.substr(1, s.length()));
                    QueueDouble.enqueue(val);
                    cout << val << endl;
                    cont++;
                }
            }

            fileOutput << QueueDouble;
            fileOutput << "\n";
            for (int j = 0; j < cont; j++)
            {
                QueueDouble.dequeue();
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
                if (s == "dequeue")
                {
                    QueueBool.dequeue();
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
                    QueueBool.enqueue(val);
                    cout << val << endl;
                    cont++;
                }
            }
            fileOutput << QueueBool;
            fileOutput << "\n";
            for (int j = 0; j < cont; j++)
            {
                QueueBool.dequeue();
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
                if (s == "dequeue")
                {
                    Queuechar.dequeue();
                }
                else
                {
                    char c = s[s.length() - 1];
                    val = (int)c;
                    Queuechar.enqueue(val);
                    cout << val << endl;
                    cont++;
                }
            }
            fileOutput << Queuechar;
            fileOutput << "\n";
            for (int j = 0; j < cont; j++)
            {
                Queuechar.dequeue();
            }
        }
    }
}