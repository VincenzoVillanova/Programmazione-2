#include <iostream>
#include <fstream>

using namespace std;

/*long int fibonacci(int n) {
    if(n==0 || n==1)
        return 1;
    else
        return fibonacci(n-1)+fibonacci(n-2);
}*/

long int fibonacci(int n)
{
    if (n == 0 || n == 1)
        return 1;
    long int sum1 = 1, sum2 = 1, x;
    for (int i = 2; i <= n; i++)
    {
        x = sum2;
        sum2 = sum1;
        sum1 = x + sum2;
    }
    cout << sum1 << endl;
    return sum1;
}

int main()
{
    fstream input("input.txt", fstream::in);
    fstream output("output.txt", fstream::out);

    for (int i = 0; i < 100; i++)
    {
        long int numFibonacci;
        input >> numFibonacci;
        numFibonacci = fibonacci(numFibonacci - 1);
        output << numFibonacci << endl;
    }
}
