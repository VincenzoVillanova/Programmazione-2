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

    for (int x = 0; x < 3; x++)
    {
        fileInput >> type >> n;
        if (type == "int")
        {
            int val;
            int cont = 0;
            for (int i = 0; i < n; i++)
            {
                fileInput >> val;
                QueueInt.enqueue(val);
                cont++;
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
            int cont = 0;
            for (int i = 0; i < n; i++)
            {
                fileInput >> val;
                QueueDouble.enqueue(val);
                cont++;
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
            bool val;
            int cont = 0;
            for (int i = 0; i < n; i++)
            {
                fileInput >> val;
                QueueBool.enqueue(val);
                cont++;
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
            int cont = 0;
            for (int i = 0; i < n; i++)
            {
                fileInput >> val;
                Queuechar.enqueue(val);
                cont++;
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