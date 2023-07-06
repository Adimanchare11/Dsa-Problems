// Given a string S, remove consecutive duplicates from it recursively.
#include<iostream>
using namespace std;
void removeConsecutiveDuplicates(char input[])
{
    if(input[0]=='\0') return;
    removeConsecutiveDuplicates(input+1);
    if(input[0]==input[1])
    {
        int i;
        for(i=1; input[i]!='\0';i++)
        {
            input[i-1]=input[i];
        }
        input[i-1]=input[i];
    }

}

int main(){
    char s[1000];
    cout<<"Enter a string: ";
    cin>>s;
    removeConsecutiveDuplicates(s);
    cout<<s<<endl;
    return 0;
}