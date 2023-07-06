// Given a string, compute recursively a new string where all 'x' chars have been removed.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// void removeX(string s)
// {
//     if(s.length()==0) return ;
//     if(s[0]=='x')
//     {cout<<"";}
//     else{
//         cout<<s[0];
//     }
//     removeX(s.substr(1));
// }

// int main()
// {
//     string s;
//     cout<<"Enter a string: ";
//     cin>>s;
//     removeX(s);
// }

//*******USING CHARACTER ARRAY*******

void removeX(char input[])
{
    if(input[0]=='\0')
        return;
    if(input[0]!='x')
    {
        removeX(input+1);
    }
    else{
        int i=1;
        for(;input[i]!='\0';i++)
        {
            input[i-1]=input[i];
        }
        input[i-1]=input[i];
        removeX(input);
    }
}

int main()
{
    char input[100];
    cout<<"Enter the string: ";
    cin.getline(input,100);
    removeX(input);
    cout<<input<<endl;
}