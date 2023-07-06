//Longest Subsequence String
#include<iostream>
using namespace std;

int lcs(string s , string t)
{
    //base case
    if(s.length()==0 || t.length()==0)
    {
        return 0;
    }

    //recursive calls
    if(s[0]==t[0])
    {
        return 1+lcs(s.substr(1), t.substr(1));
    }

    else{
        int a= lcs(s,t.substr(1));
        int b= lcs(s.substr(1),t);
        int c= lcs(s.substr(1), s.substr(1));
        return max(a,max(b,c));
    }
}

int lcshelper(string s, string t, int** output)
{
    int m= s.length();
    int n= t.length();
    int ans;

    if(s.length()==0 || t.length()==0)
    {
        return 0;
    }

    if(output[m][n]!=-1)
    {
        return output[m][n];
    }

    if(s[0]==t[0])
    {
        ans= 1+ lcshelper(s.substr(1),t.substr(1),output);
    }

    else{
        int a = lcshelper(s,t.substr(1),output);
        int b = lcshelper(s.substr(1),t,output);
        int c= lcshelper(s.substr(1), t.substr(1),output);
        ans= max(a,max(b,c));
    }
    output[m][n]= ans;
    return ans;
}

//Memoisation
int lcs2(string s, string t)
{
    int m= s.length();
    int n= t.length();
    int** output= new int*[m+1];
    for(int i=0; i<=m; i++)
    {
        output[i]= new int[n+1];
        for(int j=0; j<=n; j++)
        {
            output[i][j]=-1;
        }
    }
   //return lcshelper(s,t,output);
}

int main(){
    string s,t;
    cout<<"Enter two strings: ";
    cin>>s>>t;
    
    cout<<lcs(s,t)<<endl;
    cout<<lcs2(s,t);
    return 0;
}