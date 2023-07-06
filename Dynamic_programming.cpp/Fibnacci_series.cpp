#include<iostream>
using namespace std;

//Bruteforce: 1st approach which comes to our mind without any optimization
int fib(int n)
{
    if(n<=1) return n;

    int a= fib(n-1);
    int b= fib(n-2);

    return a+b;
}

//Dynamic programming(bottomup approach): iterative
int fib3(int n)
{
    int * ans= new int [n+1];

    ans[0]=0;
    ans[1]=1;

    for(int i=2; i<=n; i++)
    {
        ans[i]= ans[i-1]+ans[i-2];
    }
    return ans[n];
}


//Memoization(top down approach): recursive
int fib_helper(int n, int * ans)
{
    if(n<=1) return n;

    //check if ans already exist
    if(ans[n]!=-1)
    {
        return ans[n];
    }

    
    int a = fib_helper(n-1,ans);
    int b= fib_helper(n-2,ans);

    //save the output for future use
    ans[n]= a+b;

    //return the answer
    return ans[n];

}


int fib_2(int n)
{
    int*ans = new int[n+1];
    for(int i=0;i<=n; i++)
    {
        ans[i]=-1;
    }

    return fib_helper(n,ans);
}

int main(){
    int n;
    cout<<"Enter number: ";
    cin>>n;
    cout<<n<<"th fibonacci number is: "<<fib3(n);
    
    return 0;
}