#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector <int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(40);
    int n=v.size();
    cout<<n;

    for(int i; i<n;i++)
    {
        cout<<v[i]<<endl;
        i++;
    }
    
    return 0;
}