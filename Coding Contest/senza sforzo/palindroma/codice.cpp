#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool checkPalindroma(string s) {
    string p = "";
    int cont=0;
    for(int i = 0; i < s.length(); i++) {
        p = s[i] + p;
    }
    for(int i=0;i<s.length();i++){
        if(s[i]==p[i]){
            cont++;
        }
    }
    if(s.length()-2==cont || p==s){
        return true;
    }else{
        return false;
    }
    
}

int main()
{
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);

    int n = 0;
    do
    {
        int cont = 0;
        string s;
        fileInput >> n;
        string str[n];
        
        for (int j = 0; j < n; j++)
        {
            fileInput >> str[j];
            if(checkPalindroma(str[j])){
                cont++;
            }
        }
        fileOutput << cont << " ";
        for (int j = 0; j < n; j++)
        {

            if(checkPalindroma(str[j])){
            
            fileOutput << str[j]<< " ";
            
            }
        }
        fileOutput << "\n";
        
       

    } while (fileInput.good());
}