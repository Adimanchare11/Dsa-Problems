// Given the number 'n', find out and return the number of digits present in a number recursively.
#include<iostream>
using namespace std;

int count(int n)
{ 
    if(n==0) return 0;
    int smalloutput= count(n/10);
    return smalloutput+1;
}

int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"The Number contains "<<count(n)<<" digits ";
    return 0;
}
