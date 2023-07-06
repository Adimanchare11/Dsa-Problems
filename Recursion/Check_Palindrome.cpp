// Check whether a given String S is a palindrome using recursion. Return true or false.
#include <iostream>
using namespace std;

bool helper( string s, int start, int end)
{
    if(start>=end) return true;
    if(s[start]!=s[end]) return false;
    return helper(s, start+1, end-1);
}

int is_palindrome(string s)
{
    int n= s.size()-1;
    return helper(s, 0, n);
}

int main()
{
    string s;
    cout<<"Enter a string: ";
    cin>>s;

    if(is_palindrome(s))
    {
        cout<<"string is palindrome";
    }
    else{
        cout<<"string is not palindrome";
    }
}