#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);
    int n = 0, m = 0;
    double sommatoria = 0;
    for (int i = 0; i < 100; i++)
    {
        do
        {
            int val=0;
            fileInput >> n >> m;
            int libri[n];
            int vend[m];
            for (int j = 0; j < n; j++)
            {
                fileInput >> libri[j];
            }
            for (int x = 0; x < m; x++)
            {
                fileInput >> vend[x];
            }
            for(int x=0;x<m;x++){
                for(int j=0;j<n;j++){
                    if(libri[j]==vend[x]){
                        val+=5;
                    }
                }
            }
            fileOutput << val << " ";
            fileOutput << "\n";
            val = 0;
        } while (fileInput.good());
    }
}
