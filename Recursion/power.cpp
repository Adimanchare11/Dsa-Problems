// Write a program to find x to the power n (i.e. x^n). Take x and n from the user. You need to return the answer.
#include<iostream>
using namespace std;

int power(int x, int n){
    if(n==0){
        return 1;
    }

    int smalloutput= power(x,(n-1));
    return x*smalloutput;
}

int main(){
    int x,n;
    cout<<"Enter the number: ";
    cin>>x;
    cout<<"Enter the power: ";
    cin>>n;
    int output = power(x,n);
    cout<<"The value of "<<x<<" to the power "<<n<<" is: "<<output;
    return 0;
}