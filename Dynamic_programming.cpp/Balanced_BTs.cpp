#include<iostream>
using namespace std;

int balancedBTs(int n)
{
    if(n<=1) return 1;

    int mod= 1e9+7;

    int x = balancedBTs(n-1); //No of BTs made by attaching subtrees of height(n-1) on both sides of the root
    int y = balancedBTs(n-2); //No of BTs made by attaching subtrees of height (n-1) and (n-2) on each side of the root

    int temp1= ((long long int)x*x)%mod;
    int temp2= (2* (long long int)x * y)%mod;
    int ans= (temp1+temp2)%mod;
    return ans;
}

//Memoisation

int balancedBTsHelper(int n, int* ans)
{
    if(n==0 || n==1)
    {
        return 1;
    }
    int mod= 1e9+7;

    if(ans[n]!=-1)
    {
        return ans[n];
    }

    int x= balancedBTsHelper(n-1, ans);
    int y= balancedBTsHelper(n-2, ans);

    int temp1= ((long long int)x*x)%mod;
    int temp2= ((long long int)x*y)%mod;

    ans[n]= (temp1+ temp2)%mod;
    return ans[n];
}

int balancedBTs2(int n)
{
    int * ans= new int[n+1];

    for(int i=0; i<=n; i++)
    {
        ans[i]=-1;
    }
    return balancedBTsHelper(n, ans);
}

// DP
int balancedBTs3(int n)
{
    int * ans= new int[n+1];
    if(n<=1) return 1;
    int mod= 1e9+7;
    ans[0]=1;
    ans[1]=1;

    for(int i=2; i<=n; i++)
    {
        int val1= ((long long int)ans[i-1]*ans[i-1])%mod;
        int val2= ((long long int)ans[i-2]*2*ans[i-1])%mod;
        ans[i]= (val1+val2)%mod;
    }
    return ans[n];
}

int main(){
    int n;
    cout<<"Enter height of the binary tree: ";
    cin>>n;
    cout<<balancedBTs3(n);
    return 0;
}