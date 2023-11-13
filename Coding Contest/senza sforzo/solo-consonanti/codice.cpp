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
    int n = 3;
    int lun = 0;
    do
    {
        fileInput >> lun;
        for (int i = 0; i < n; i++)
        {
            string s = "";
            fileInput >> s;
            int j=0;
            while(j<s.length()){
                if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u'){
                    s.erase(j,1);
                    j=0;
                }else{
                    j++;
                }
            }
            
            fileOutput << s << " ";
            cout<<s<<" ";
        }
        cout<<endl;
        fileOutput << "\n";

    } while (!fileInput.eof());
}