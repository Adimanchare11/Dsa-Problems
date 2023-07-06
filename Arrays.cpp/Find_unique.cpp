#include<iostream>
using namespace std;
int findUnique(int arr[], int n){
    int ans =0;
    for(int i=0; i<n; i++){
        ans= ans^arr[i];
    }
    return ans;
}

int main(){
    int arr[7]={5,3,1,2,3,5,2};

    cout<<"The Unique Element is: "<<findUnique(arr,7);
    return 0;
}