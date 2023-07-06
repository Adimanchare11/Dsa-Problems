#include<iostream>
#include<unordered_map>
using namespace std;

string uniqueChar(string str)
{
    unordered_map<char,int> m;
    string s;

    for(int i=0; i<str.length(); i++)
    {
        if(m.count(str[i])==0)
        {
            m[str[i]]++;
            s+=str[i];
        }
    }
    
    return s;
}

int main(){
    string str;
    cout<<"Enter a string: ";
    cin >> str;
    cout<<endl;
    cout <<"unique characters from string are: "<<uniqueChar(str);
    
    return 0;
}