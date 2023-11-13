#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);
    int min[100];
        for(int i=0;i<100;i++){
            min[i]= INT_MAX;
        }
    
    
    for (int i = 0; i < 100; i++)
    {
        
        string val = "";
        do
        {
            fileInput >> val;
            if (val != "STOP")
            {
                if(val[0]=='1'||val[0]=='2'||val[0]=='3'||val[0]=='4'||val[0]=='5'||val[0]=='6'||val[0]=='7'||val[0]=='8'||val[0]=='9'||val[0]=='0'){
                int s = stoi(val);
                if (min[i] >= s)
                {
                    min[i] = s;
                }
            }
            }

        } while (val != "STOP");
        cout<<min[i]<<endl;
        fileOutput << min[i] << " ";
        fileOutput << "\n";
    }
}
