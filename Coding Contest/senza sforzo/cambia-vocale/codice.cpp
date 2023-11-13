#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;
int main() {
    fstream input("input.txt", fstream::in);
    fstream output("output.txt",fstream::out);

    for(int i=0; i<100; i++) {
        string arrOccurency[5];
        for(int j=0; j<5; j++) {
            input >> arrOccurency[j]; 
        }


        string line;
        getline(input, line);
        for (int j = 0; j < line.length(); j++) {
            for (int z = 0; z < 5; z++) {
                if (line[j] == arrOccurency[z][0]) {
                    line[j] = arrOccurency[z][2];
                    break;
                }
            }
        }
        line.erase(0,1);
        output << line << endl;
        

        
    }
}