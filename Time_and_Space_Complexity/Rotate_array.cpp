// You have been given a random integer array/list(ARR) of size N. Write a function that rotates the given array/list by D elements(towards the left).
#include<iostream>
using namespace std;

void reverse(int arr[], int n)
{
    for(int i=0, j=n-1; i<=j; i++, j--)
    {
        int temp = arr[i];
        arr[i]= arr[j];
        arr[j]= temp;
    }
}

void rotate(int arr[], int size, int d)
{
    reverse(arr, size);
    reverse( arr+size-d, d);
    reverse(arr,size-d);

}

int main(){
    int t;
    cout<<"Enter the number of test cases: ";
    cin>>t;

   while(t--)
   { int size;
    cout<<"Enter the size of the array: ";
    cin>>size;

    int *input= new int[size];
    for(int i=0; i<size; i++)
    {
        cin>>input[i];
    }

    int d;
    cout<<"Enter the digit by which you have to rotate the array: ";
    cin>>d;

    rotate(input, size, d);

    for(int i=0; i<size; ++i)
    {
        cout<<input[i]<<" ";
    }

    delete [] input;
    cout<<endl;
   }
    return 0;
}