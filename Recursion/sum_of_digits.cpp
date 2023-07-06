// Write a recursive function that returns the sum of the digits of a given integer.
#include<iostream>
using namespace std;

int sumofDigits(int n)
{
    if(n==0) return 0;
    int smalloutput= sumofDigits(n/10);
    int ld=n%10;
    return ld+smalloutput;
}

int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    cout<<"The sum of digits of "<<n<<" is: "<<sumofDigits(n);
    return 0;
}