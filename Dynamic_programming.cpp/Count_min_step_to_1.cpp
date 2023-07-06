#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int minSteps(int n)
{
    if(n<=1) return 0;

    int x= minSteps(n-1);

    int y= INT_MAX;
    int z= INT_MAX;

    if(n%2==0)
    {
         y=minSteps(n/2);
    }
    if(n%3==0)
    {
         z=minSteps(n/3);
    }
    int ans= min(x,min(y,z));
    return ans+1;
}

//Memoisation

int minStepsHelper(int n, int* ans)
{
    if(n<=1) return 0;

    if(ans[n]!=-1) return ans[n];

    int x= minStepsHelper(n-1, ans);
    int y= INT_MAX, z= INT_MAX;

    if(n%3==0) {
        y= minStepsHelper(n/3, ans);
    }
    if(n%2==0)
    {
        z= minStepsHelper(n/2, ans);
    }

    int output= min(x, min(y,z))+1;

    ans[n]= output;

    return ans[n];
}

int minSteps2(int n)
{
    int * ans = new int[n+1];

    for(int i=0; i<=n; i++)
    {
        ans[i]=-1;
    }

    return minStepsHelper(n, ans);
}

//DP

int minSteps3(int n)
{
    if(n<=1) return 0;
    int * ans= new int[n+1];

    ans[0]=0;
    ans[1]=0;
    for(int i=2; i<=n; i++)
    {
        int a= ans[i-1];

        int b= INT_MAX;
        int c= INT_MAX;

        if(i%2==0)
        {
            b=ans[i/2];
        }

        if(i%3==0)
        {
            c=ans[i/3];
        }
        ans[i]= min(a,min(b,c))+1;
       
    }
    int result= ans[n];
    
    return result;
}

int main(){
    
    int n;
    cout<<"Enter number: ";
    cin>>n;
    cout<<minSteps2(n);

    return 0;
}