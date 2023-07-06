#include<iostream>
using namespace std;

void reverse(string s)
{
    if(s.length()==0) return ;

    string smalloutput= s.substr(1); //take input starting from the first index of the string
    reverse(smalloutput);
    cout<<s[0];
}

int main(){
    string s;
    cout<<"Enter a string: ";
    cin>>s;
    reverse(s);
    return 0;
}