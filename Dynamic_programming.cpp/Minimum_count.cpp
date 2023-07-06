#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int minimumCount(int n)
{
    if(sqrt(n)- sqrt(n)==0) return 1;
    if(n<=3) return n;

    int a= minimumCount(n-(1*1));
    int b= minimumCount(n-(2*2));
    int c= minimumCount(n-(3*3));
    int ans= min(a,min(b,c));
    return 1+ans;
}

int main(){
    int n;
    cout<<"enter number: ";
    cin>>n;
    cout<<minimumCount(1);
    
    return 0;
}