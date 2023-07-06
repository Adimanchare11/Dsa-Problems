#include<iostream>
using namespace std;

bool search(int arr[], int n){
    for(int i=0;i<10; i++){
        if(arr[i]==n){
            return true;
        }
    }
    return false;
}

int main(){
    int arr[10] ={5,6,0,-3,-5,10,3,2,7,9};
    int n;
    cout<<"Enter element: ";
    cin>>n;

    if(search(arr,n)) cout<<"The element is present in the array";
    else
    cout<<"The element is not present in the array";

    return 0;
}