// Given an integer array (of length n), find and print all the subsets of input array.
// Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
// Note : The order of subsets are not important. Just print the subsets in different lines.
// Input format :
// Line 1 : Integer n, Size of array
// Line 2 : Array elements (separated by space)

#include<iostream>
using namespace std;

void printSubsetsOfArray(int input[],int size, int output[],int outputSize){
    if(size == 0){
        for(int i=0;i<outputSize;i++){
            cout<<output[i]<<" ";
        }
        cout<<endl;
        return;
    }
    
    printSubsetsOfArray(input+1,size-1,output,outputSize);
    //assuming current elemnet is included in array
    int newoutput[20] = {};
    for(int i=0;i<outputSize;i++){
        newoutput[i] = output[i];
    }
    newoutput[outputSize] = input[0];
    printSubsetsOfArray(input+1,size-1,newoutput,outputSize+1);
}

void printSubsetsOfArray(int input[], int size) {
    int ans[20] = {};
    printSubsetsOfArray(input,size,ans,0);
}

int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}