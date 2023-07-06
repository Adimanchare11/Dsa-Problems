// Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// void replace_pi(string s)
// {
//     if(s.length()==0) return;

//     if(s[0]=='p' && s[1]=='i')
//     {
//         cout<<"3.14";
//         replace_pi(s.substr(2));
//     }
//     else{
//         cout<<s[0];
//         replace_pi(s.substr(1));
//     }
// }

// int main(){
//     string s;
//     cout<<"Enter a string: ";
//     cin>>s;
//     replace_pi(s);
//     return 0;
// }


//*******USING CHARACTER ARRAY*******

void replacePi(char input[]) {
    
    if(input[0]=='\0') return;
    if(input[0]=='p' && input[1]=='i')
    {
        input[0]='3';
        input[1]='.';

        int size=strlen(input);
        for(int i=size+2;i>1;i--){
            input[i]=input[i-2];
        }
        input[2]='1';
        input[3]='4';
    }
    
    replacePi(input+1);

}

int main() {
    char input[10000];
    cout<<"Enter a string: ";
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}
