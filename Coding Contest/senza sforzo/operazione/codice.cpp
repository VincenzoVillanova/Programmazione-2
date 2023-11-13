#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main()
{
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);
    int n = 0;
    long int ris = 0;
    do
    {
        fileInput >> n;
        for (int i = 0; i < n; i++)
        {
            string s = "";
            fileInput >> s;
            int index = 0;
            if (s.find("-") != string::npos)
            {
                index = s.find("-");
                string n1 = " ", n2 = " ";
                n1 = s.substr(0, index);
                n2 = s.substr(index+1, s.length() - 1);
                int num1 = 0, num2 = 0;
                num1 = stoi(n1);
                num2 = stoi(n2);
                ris = num1 - num2;
               
            }
            if (s.find("+") != string::npos)
            {
                index = s.find("+");
                string n1 = " ", n2 = " ";
                n1 = s.substr(0, index);
                n2 = s.substr(index+1, s.length() - 1);
                int num1 = 0, num2 = 0;
                
                num1 = stoi(n1);
                num2 = stoi(n2);
                ris = num1 + num2;
                
            
            }
            if (s.find("*") != string::npos)
            {
                index = s.find("*");
                string n1 = " ", n2 = " ";
                n1 = s.substr(0, index);
                n2 = s.substr(index+1, s.length() - 1);
                int num1 = 0, num2 = 0;
                num1 = stoi(n1);
                num2 = stoi(n2);
                ris = num1 * num2;
              
            }

            fileOutput << ris << " ";
        }

        fileOutput << "\n";

    } while (!fileInput.eof());
}