#include <iostream>
using namespace std;

int fib(int n)
{
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }

    int smalloutput1 = fib(n-1);
    int smalloutput2 = fib(n-2);
    return smalloutput1 + smalloutput2;
}

int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<"The "<<n<<"th fiibonacci number is: "<<fib(n);
}