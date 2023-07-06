#include<iostream>
#include<algorithm>
using namespace std;

void print(int n, int* arr){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

void sortArray(int n, int* arr){
    int left= 0;
    int right= n-1;

    while(left<right){

        while(arr[left]==0){
            left++;
        }

        while(arr[right]==1){
            right--;
        }

        if(left<right){
            swap(arr[left], arr[right]);
            left++;
            right--;
        }

    }
}

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int * arr = new int[n];
    cout<<"Elements:";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sortArray(n,arr);
    print(n,arr);

    return 0;
}