// Given an array of length N and an integer x, you need to find and return the first index of integer x present in the array. Return -1 if it is not present in the array.
// First index means, the index of first occurrence of x in the input array.
// Do this recursively. Indexing in the array starts from 0.

#include<iostream>
using namespace std;

int firstindex(int a[], int size, int x)
{
 if(size==0)
 {
    return -1;
 }
 if(a[0]==x)
 {
    return 0;
 }
 int ans= firstindex(a+1, size-1,x);
 if(ans==-1)
 {
    return -1;
 }
 else if(ans!= -1)
 {
    return ans+1;
 }
 return 0;
}

int main(){
    int size;
    cout<<"Enter Size of the array: ";
    cin>>size;

    int *a= new int[size];
    for(int i=0;i<size;i++)
    {
        cin>>a[i];
    }

    int x;
    cout<<"Enter the number: ";
    cin>>x;

    cout<<"The first index of "<<x<<" is: "<<firstindex(a,size,x);

    return 0;
}