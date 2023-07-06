// Given two integers M & N, calculate and return their multiplication using recursion. You can only use subtraction and addition for your calculation. No other operators are allowed.

#include<iostream>
using namespace std;

int multiplyNumbers(int m, int n)
{
    if(n==0) return 0;

    int smalloutput= m*(n-1);
    return m+smalloutput;
}


int main(){
    int m,n;
    cout<<"Enter the numbers: ";
    cin>>m>>n;
    cout<<"Their multiplication is: "<<multiplyNumbers(m,n);
    return 0;
}