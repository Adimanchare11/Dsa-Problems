#include<iostream>
using namespace std;

void reverse( int arr[], int n)
{
    for(int i=0 , j=n-1; i<= j; i++, j--)
    {
        int temp= arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
}

int main()
{
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;

    int *arr = new int[size];
    for(int i=0; i<size; i++)
    {
        cin>>arr[i];
    }

    reverse(arr, size);
    
    for(int i=0; i<size; i++)
    {
        cout<<arr[i];
    }

    delete [] arr;
}