// Given an array of length N and an integer x, you need to find if x is present in the array or not. Return true or false.

#include<iostream>
using namespace std;

bool checknum(int input[], int size, int x)
{
    if(size<0)
    {
        return false;
    }

    else if(input[0]== x)
    {
        return true;
    }
    return checknum(input+1 ,size-1, x);
}

int main(){
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int *input= new int[size];
    for(int i=0; i<size; i++)
    {
        cin>>input[i];
    }

    int x;
    cout<<"Enter the number which is to be find: ";

    if(checknum(input,size,x))
    {
        return true;
    }
    else return false;
    return 0;
}