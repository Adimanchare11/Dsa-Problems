#include<iostream>
#include<queue>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

vector<int> ksmallestelements(int input[], int n, int k)
{
    priority_queue<int> pq;

    for(int i=0; i<k; i++)
    {
        pq.push(input[i]);
    }

    for(int i=k; i<n; i++)
    {
        if(pq.top()> input[i])
        {
            pq.pop();
            pq.push(input[i]);
        }
    }

    vector<int> v;
    while(!pq.empty())
    {
       v.push_back(pq.top());
       pq.pop();
    }
    return v;

}

int main(){

    int size;
    cout<<"Enter Size: ";
    cin>>size;

    int *input= new int[size];

    cout<<"Enter elements: ";
    for(int i=0; i<size; i++)
    {
        cin>>input[i];
    }

    int k;
    cout<<"Enter k: ";
    cin>>k;

    // vector<int> output= ksmallestelements(input,size,k);
    // sort(output.begin(),output.end());

    // for(int i=0; i<output.size(); i++)
    // {
    //     cout<<k<<" Smallest int the input are " <<output[i]<<endl;
    // }
    
    //delete [] input;

    vector<int> output = ksmallestelements(input, size, k);
    sort(output.begin(), output.end());

    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }

    delete[] input;
    
}