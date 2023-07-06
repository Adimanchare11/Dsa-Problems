#include<iostream>
using namespace std;

int partition(int input[], int si, int ei)
{
	int pivot= input[si];
    int count=0;
    
    for(int i=si+1; i<=ei; i++)
    {
		if(input[i]<=pivot)
            count++;
    }
    
    int pi= count+si;
    input[si]=input[pi];
    input[pi]=pivot;
    
    int i=si;
    int j=ei;
    
    while(i<=pi && j>pi)
    {
		if(input[i]<=input[pi]) i++;
        else if(input[j]<= input[pi]) j--;
        else 
        {
            int temp= input[i];
            input[i]=input [j];
            input[j]= temp;
            i++;
            j--;
        }
    }
    return pi;
}

void quickSort(int input[], int si, int ei)
{
	if(si>=ei) return;
    int pi= partition(input,si,ei);
    quickSort(input,si,pi-1);
    quickSort(input,pi+1,ei);
}

void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
    quickSort(input,0,size-1);

}

int main(){
     int size;
    cout<<"Enter size of the array: ";
    cin>>size;
    int *input= new int[size];
    for(int i=0; i<size; i++)
    {
        cin>>input[i];
    }
    quickSort(input, size);
    for(int i=0; i<size; i++)
    {
        cout<<input[i]<<" ";
    }
    delete []input;
    return 0;
}