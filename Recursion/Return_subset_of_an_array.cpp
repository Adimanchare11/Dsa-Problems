// Given an integer array (of length n), find and return all the subsets of input array.
// Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.


// Note : The order of subsets are not important.


// Input format :

// Line 1 : Size of array

// Line 2 : Array elements (separated by space)

#include <iostream>
using namespace std;

#include<iostream>
using namespace std;

int subset(int input[], int n, int output[][20]) {
if(n==0)
{
    output[0][0]=0;
    return 1;
}
int smalloutput=subset(input+1,n-1,output);
for(int i=0;i<smalloutput;i++)
{
    output[i+smalloutput][0]=output[i][0]+1;
    output[i+smalloutput][1]=input[0];
    for(int j=0;j<output[i][0];j++)
    {
        output[i+smalloutput][j+2]=output[i][j+1];
    }
}
return 2*smalloutput;
}


int main() {
  int input[20],length, output[35000][20];
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  
  int size = subset(input, length, output);

  for( int i = 0; i < size; i++) { 
	for( int j = 1; j <= output[i][0]; j++) { 
		cout << output[i][j] << " ";
    }
    cout << endl;
  }
}