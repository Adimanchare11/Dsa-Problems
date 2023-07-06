#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> Klargest(int input[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i=0; i<k; i++)
    {
        pq.push(input[i]);
    }

    int j=0;
    for(int i=k; i<n; i++)
    {
        if(input[i]>pq.top())
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

    int *input= new int[1+size];

    cout<<"Enter elements: ";
    for(int i=0; i<size; i++)
    {
        cin>>input[i];
    }

    int k;
    cout<<"Enter k: ";
    cin>>k;

    cout<<k<<" Largest Elements in the input are : ";
    vector<int> output = Klargest(input, size, k);
    for (int i = 0; i < output.size(); i++) {
        cout<<output[i] << " ";
    }

    delete[] input;
    
    return 0;
}