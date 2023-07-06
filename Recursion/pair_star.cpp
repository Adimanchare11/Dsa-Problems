// Given a string S, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".

#include<iostream>
using namespace std;

int length(char input[]) //function to calculate the length of the string
{
int len=0;
for(int i=0; input[i]!='\0'; i++)
{
    len++;
}
return len;
}

void pairStar(char input[], int start)
{
    if(input[start]=='\0') return;  //Base case
    pairStar(input, start+1);  //recursive call

    if(input[start]==input[start+1])  
    {
        int l= length(input);
        input[l+1]='\0'; //shifting null character by 1 index
        int i;
        for(i=l-1; i>start; i--)  //shifting all characters by 1 index
        {
            input[i+1]=input[i];
        }
    input[start+1]='*';
    }

}

void pairStar(char input[])
{
    pairStar(input, 0);
}

int main(){
    char input[100];
    cout<<"Enter a string : ";
    cin.getline(input,100);
    pairStar(input);
    cout<<input<<endl;
    return 0;
}