// Given an input string S and two characters c1 and c2, you need to replace every occurrence of character c1 with character c2 in the given string.
// Do this recursively.

#include<iostream>
using namespace std;

void replaceCharacter(char s[], char c1, char c2)
{
    if(s[0]=='\0') return;
    replaceCharacter(s+1,c1,c2);
    if(s[0]==c1)
    {
        s[0]=c2;
    }
}

int main(){
    char str[1000];
    cout<<"Enter a string: ";
    cin>>str;
    char c1,c2;
    cin>>c1>>c2;
    replaceCharacter(str,c1,c2);
    cout<<str<<endl;
    return 0;
}