// Given an array of length N, you need to find and return the sum of all elements of the array.
#include<iostream>
using namespace std;

int sum(int input[], int n)
{
    if(n==0) return 0;
    int smalloutput= sum(input+1, n-1);
    return input[0]+ smalloutput;
}

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;

    int *input= new int[n];
    for(int i=0; i<n; i++)
    {
        cin>> input[i];
    }

    cout<<"The sum of elements of the array is: "<<sum(input,n)<<endl;
    return 0;
}