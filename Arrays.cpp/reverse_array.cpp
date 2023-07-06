#include<iostream>
using namespace std;

int reverse(int arr[], int n){
    int start=0;
    int end= n-1;

    while(start<=end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
    return 0;
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[5]= {1,2,3,4,5};
    reverse(arr,5);
    printArray(arr,5);
    return 0;
}