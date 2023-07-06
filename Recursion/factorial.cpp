#include<iostream>
using namespace std;

int fact(int n)
{
    if(n==0)
    {
        return 1;
    }
    int smalloutput=fact(n-1);
    return n*smalloutput;
}

int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    int output=fact(n);
    cout<<"The factorial of "<<n<<" is "<<output;
    return 0;
}