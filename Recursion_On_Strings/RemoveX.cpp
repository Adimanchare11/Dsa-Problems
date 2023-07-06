#include<iostream>
using namespace std;

void removeX(char s[])
{
    if(s[0]=='\0') return;

    if(s[0]!='x')
    {
        removeX(s+1);
    }
    else
    {
        int i;
        for(i=1;s[i]!='\0'; i++)
        {
            s[i-1]=s[i];
            removeX(s);
        }
        s[i-1]=s[i];

    }
}

int length(char s[])
{
    if(s[0]=='\0') return 0;

    int smallstringlength= length(s+1);
    return 1+smallstringlength;
}

int main(){
    char str[100];
    cout<<"Enter a string: ";
    cin>>str;
    int l=length(str);
    cout<<l<<endl;
    removeX(str);
    cout<<str<<endl;
    l=length(str);
    cout<<l;
    return 0;
}