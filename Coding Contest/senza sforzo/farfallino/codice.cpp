#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main() {
    ifstream input("input.txt");
    fstream output("output.txt", fstream::out);

    string s;
    string voc = "aeiou";

    while (getline(input, s)) {
        string strfin;
        string var = "f";
        for (int j = 0; j < s.length(); j++) {
            if (voc.find(s[j]) != string::npos)
                strfin += s[j] + var + s[j];
            else
                strfin += s[j];
        }
        output << strfin << endl;
    }
}