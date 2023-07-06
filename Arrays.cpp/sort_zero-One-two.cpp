#include<iostream>
using namespace std;

void print(int n, int *arr){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

void sort(int n, int* arr){

    int count0=0, count1=0, count2=2;

    for(int i=0; i<n; i++){
        if(arr[i]==0){
            count0++;
        }

        else if(arr[i]==1){
            count1++;
        }

        else count2++;
    }
    
    int i=0;
    while(count0>0){
        arr[i]=0;
        i++;
        count0--;
    }
    while(count1>0){
        arr[i]=1;
        i++;
        count1--;
    }
    while(count2>0){
        arr[i]=2;
        i++;
        count2--;
    }
}

int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;

    int *arr= new int[n];
    cout<<"Enter Elements: ";

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    sort(n, arr);

    cout<<"Zero-One-Two Sorted elements: ";
    print(n, arr);

    return 0;
}