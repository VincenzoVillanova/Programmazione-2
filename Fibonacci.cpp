#include<iostream>
using namespace std;

int Fib(int n){
    if(n==0){
        return 1;
    }
    if(n== 1){
        return 1;
    }
    return Fib(n-1)+Fib(n-2);
}
int main(){
    cout<<"Fib 4: "<<Fib(4);
}