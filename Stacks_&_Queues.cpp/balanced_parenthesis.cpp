// For a given a string expression containing only round brackets or parentheses, check if they are balanced or not. Brackets are said to be balanced if the bracket which opens last, closes first.

#include<iostream>
#include<bits\stdc++.h>
using namespace std;

bool isBalanced(string expression)
{
    stack<char> s;
    for(int i=0; i<expression.length(); i++)
    {
        if(s.empty()&& expression[i]==')') return false;
        else if(s.empty())
        {
            s.push(expression[i]);
        }
        else if(expression[i]==')' && s.top()=='(') 
        {
            s.pop();
        }
        else
        {
            s.push(expression[i]);
        }
    }
    if(s.empty()) return true;
    else return false;
}

int main(){

    string input;
    cout<<"Enter a string: ";
    cin>>input;
    cout<<(isBalanced(input)? "true": "false");

    return 0;
}