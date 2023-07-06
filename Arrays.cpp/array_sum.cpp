#include<iostream>
using namespace std;

int printSum(int arr[], int n)
{
int sum = 0;
 for(int i=0; i<n; i++){
    sum+=arr[i];
 }
return sum;
}

int main(){
    int size;
    cout<<"Enter size of array:";
     int arr[100];
     cin>>size;
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }

    cout<<"Sum of all elements of array is: "<<printSum(arr,size);
    
    return 0;
}