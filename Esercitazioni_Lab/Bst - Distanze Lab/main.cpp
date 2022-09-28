#include <iostream>
#include <string>
#include <fstream>
#include "bst.h"
using namespace std;
int main()
{
    string tipo = "", dim = "", valore = "", k = "", h = "";
    int dime = 0;
    ifstream file("input.txt");

    if (file.is_open())
    {
        while (file.good())
        {
            file >> tipo;
            if (tipo == "int")
            {
                BST<int> BSTinteri;
                file >> dim;
                dime = stoi(dim);
                int arr[dime];
                for (int i = 0; i < dime; i++)
                {
                    file >> valore;
                    valore = valore.substr(4, valore.length());
                    BSTinteri.insert(stoi(valore));
                }
                file >> k;
                file >> h;
                cout << "Distanza chiavi: " << BSTinteri.distanzaChiavi(stoi(k), stoi(h))<<endl;
                BSTinteri.setval();
                
            }
            else
            {
                BST<char> BSTchar;
                file >> dim;
                dime = stoi(dim);
                for (int i = 0; i < dime; i++)
                {

                    file >> valore;
                    valore = valore.substr(4, valore.length());
                    BSTchar.insert(valore[0]);
                }
                file >> k;
                file >> h;
                cout << "Distanza chiavi: " << BSTchar.distanzaChiavi(k[0],h[0])<<endl;
                BSTchar.setval();
                
            }
            /*
            cout << "---" << endl;
            if (tipo == "int")
            {
                BSTinteri.inorder();
            }
            else if (tipo == "char")
            {
                BSTchar.inorder();
            }
            BSTinteri.remove(BSTinteri.getRoot());*/
        }
    }
}
