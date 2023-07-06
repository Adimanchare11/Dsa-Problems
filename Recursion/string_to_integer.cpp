// Write a recursive function to convert a given string into the number it represents. That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.

#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;

int string_to_integer(char input[])
{
    if(strlen(input)==1) return input[0]-48;
    
    int a = string_to_integer(input+1);
    int b= input[0]-48;

    return b*pow(10,strlen(input)-1)+a;

    
}
int main()
{
    char input[100];
    cout<<"Enter a string: ";
    cin>>input;
    cout<<string_to_integer(input)<<endl;
}