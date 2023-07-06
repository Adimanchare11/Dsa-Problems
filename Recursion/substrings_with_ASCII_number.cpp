#include<iostream>
using namespace std;

void substringAscii(string s, string sub)
{
    if(s.length()==0) 
    {
        cout<<sub<<endl;
        return;
    }
    char ch= s[0];
    int code =ch;
    string ros= s.substr(1);

    substringAscii(ros,sub);
    substringAscii(ros,sub+ch);
    substringAscii(ros, to_string(code)); //to_stirng: to convert int to string

}

int main(){
    string s ;
    cout<<"Enter a string: ";
    cin>>s;
    substringAscii(s,"");
    return 0;
}