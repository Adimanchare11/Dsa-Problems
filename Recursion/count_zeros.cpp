// Given an integer N, count and return the number of zeros that are present in the given integer using recursion.

#include <iostream>
using namespace std;

int countzeros(int n)
 {

   if(n/10== 0){
        if(n%10 == 0){
            return 1 ;
        }else{
            return 0 ;
        }
    }
    int smalloutput= countzeros(n/10);
    int ld= n%10;

    if(ld==0)
    {
        return smalloutput+1;
    }

    return smalloutput;
 }

int main()
{
    int n;
    cout << "Enter a  number: ";
    cin >> n;
    cout << "The number of zeros in the " << n << " is: " << countzeros(n);
    return 0;
}