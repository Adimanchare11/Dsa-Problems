#include<iostream>
using namespace std;

void substring(string s, string sub)
{
    if(s.length()==0) 
    {
        cout<<sub<<endl;
        return;
    }
    char ch= s[0];
    string smalloutput= s.substr(1);
    substring(smalloutput,sub);
    substring(smalloutput,sub+ch);

}

int main(){
    string s;
    cout<<"Enter a string: ";
    cin>>s;
    substring(s,"");
    return 0;
}