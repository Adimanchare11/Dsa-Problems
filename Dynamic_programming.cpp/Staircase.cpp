#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int stairCase(int n)
{
    if(n==0)
    {
        return 1;
    }
    else if(n<0)
    {
        return 0;
    }
    else
    return stairCase(n-3)+stairCase(n-2)+stairCase(n-1);
}

//memoization
int stairCase_helper(int n, int* ans)
{
    if(n==0) return 1;
    if(n==1 || n==2) return n;

    ans[n]= stairCase_helper(n-3, ans)+stairCase_helper(n-2,ans)+ stairCase_helper(n-1,ans);
    return ans[n];
}
int stairCase1(int n)
{
    int * ans= new int [n+1];

    for(int i=0; i<=n; i++)
    {
        ans[i]= -1;
    }
    return stairCase_helper(n,ans);

}

int stairCase3(int n)
{
    int* ans= new int[n+1];
    long m= 1e9+7;

    ans[0]=1;
    ans[1]=1;
    ans[2]=2;

    for(int i=3; i<=n; i++)
    {
       ans[i]= (ans[i-3]%m+ans[i-2]%m+ans[i-1]%m)%m;
    }
    return ans[n];
}

int main(){
    // int n;
    // cout<<"Enter a number: ";
    // cin>>n;
    // cout<<stairCase3(n);
    // return 0;

    int t;
    cout<<"enter no. of test cases: ";
    cin>>t;
    vector<int> v;
    int n;
   
   for(int i =0 ; i<t; i++)
   {
     cin>>n;
     v.push_back(n);
   }

   for(int i=0; i<t;i++)
   {
    cout<<stairCase3(v[i])<<endl;
   }

    return 0;
    // write your code here
}