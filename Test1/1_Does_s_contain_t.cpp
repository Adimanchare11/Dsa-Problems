// Given two string s and t, write a function to check if s contains all characters of t (in the same order as they are in string t).
// Return true or false.
// Do it recursively.
// E.g. : s = “abchjsgsuohhdhyrikkknddg” contains all characters of t=”coding” in the same order. So function will return true.

#include<iostream>
using namespace std;

bool checksequence(char large[], char small[])
{
    if(large[0]=='\0') return;

}

int main(){
    char large[1000];
    char small[1000];
    cin>>large;
    cin>>small;
    bool x=checksequence(large, small);

    if(x)
        cout<<"true";
    else
        cout<<"false";
    return 0;
}