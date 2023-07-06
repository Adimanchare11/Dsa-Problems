#include<iostream>
using namespace std;

int Duplicate(int arr[], int n){
    int ans=0;
    //XOR ing all the elements
    for(int i=0; i<n; i++){
        ans= ans^arr[i];
    }
    //XOR [1,n-1]
    for(int i=1; i<n; i++){
        ans = ans^i;
    }
    return ans;
}

int main(){
    int arr[6]={5,4,3,2,1,3};
   
    cout<<"Duplicate Element is : "<<Duplicate(arr,6);

    return 0;
}