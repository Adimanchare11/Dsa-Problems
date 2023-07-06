// You have been given an integer array/list(ARR) of size N which contains numbers from 0 to (N - 2). Each number is present at least once. That is, if N = 5, the array/list constitutes values ranging from 0 to 3, and among these, there is a single integer value that is present twice. You need to find and return that duplicate number present in the array.

#include<iostream>
using namespace std;

int duplicate(int arr[], int n)
{
   int sum=0;

   for(int i=0; i<n; i++)
   {
    sum+=arr[i];
   }

   int sumformula= ((n-2)*(n-1))/2;
   return sum-sumformula;
}

int main(){
    int t;
    cout<<"Enter the number of test cases: ";
    cin>>t;
    while(t--)
    {
    int size;
    cout<<"Enter the size of the array: ";
        cin>>size;
        int *input= new int[size];
        for(int i=0; i<size; i++)
        {
            cin>>input[i];
        }
        cout<<"The Duplicate element is: "<<duplicate(input,size);
    }
   
    return 0;
}