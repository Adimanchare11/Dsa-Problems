#include<iostream>
using namespace std;

string moveX(string s)
{
    if(s.length()==0) return "";
    char ch=s[0];
    string smalloutput = moveX(s.substr(1));
    if(ch=='x') return smalloutput+ch;
    return ch+smalloutput;
}
int main(){
    string s;
    cout<<"Enter a string: ";
    cin>>s;
    cout<<moveX(s);
    return 0;
}