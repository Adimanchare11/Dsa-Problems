// Given an array of length N and an integer x, you need to find all the indexes where x is present in the input array. Save all the indexes in an array (in increasing order).
// Do this recursively. Indexing in the array starts from 0.

#include<iostream>
using namespace std;

int allIndexes(int input[], int n, int x, int output[])
{
     static int index=-1;
    if(n==0)
    {
        return 0;
    }
    else{

    if(input[0]==x)
    {
    output[0]=++index;
    //cout<<index<<" ";
    return index;
    allIndexes(input+1,n-1,x,output+1);
    }
    else{
        ++index;
        allIndexes(input+1,n-1,x,output);
    }
    }
}

int main(){
    int n;
    cout<<"Enter the size of the array: ";
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    cout<<"Enter the element: ";
    cin >> x;
    
    int *output = new int[n];
    
    int size = allIndexes(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
    
    delete [] input;
    
    delete [] output;
    

}

