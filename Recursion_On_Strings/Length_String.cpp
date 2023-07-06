//Find the length of an string using recursion

#include<iostream>
using namespace std;

int length(char s[])
{
    if(s[0]=='\0') return 0;

    int smallstringlength= length(s+1);
    return 1+smallstringlength;
}

int main(){
    char s[100];
    cout<<"Enter a string: ";
    cin>>s;
    int l= length(s);
    cout<<l;
    return 0;
}