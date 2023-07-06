#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int kthlargest(int arr[], int n, int k)
{
    priority_queue<int> pq;

    for(int i=0; i<n; i++)
    {
        pq.push(arr[i]);
    }
    
    for(int i=0; i<k-1; i++)
    {
        pq.pop();
    }
    return pq.top();
}

int main(){
    
    int size;
    cout<<"Enter size: ";
    cin>>size;

    int * input= new int[size];


    cout<<"Enter elements: ";
    for(int i=0; i<size; i++)
    {
        cin>>input[i];
    }
    
    int k;
    cout<<"Enter k: ";
    cin>>k;

    cout<<k<<"th largest element: "<<kthlargest(input,size,k);

    return 0;
}