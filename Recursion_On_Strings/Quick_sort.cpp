// Sort an array A using Quick Sort.
// Change in the input array itself. So no need to return or print anything.#include<iostream>
#include <iostream>
using namespace std;

// void swap(int i, int j)
// {
//     int temp= i;
//     i=j;
//     j=temp;
// }

int partition(int input[],int si, int ei)
{
    int pivot = input[si];
    int cnt=0;
    for(int i=si+1; i<=ei; i++)
    {
        if(input[i]<=pivot)
        cnt++;
    }

    //place pivot element at it's right position
    int pi= si+cnt;
    input[si]= input[pi];
    input[pi]= pivot;

    //swap(input[pi], input[si]);


    int i=si;
    int j=ei;
    while( i<pi && j>pi)
    {
        if(input[i]<=input[pi])
        {
            i++;
        }

        else if(input[j]>input[pi])
        {
            j--;
        }

        else
        {
            int temp= input[i];
            input[i]=input[j];
            input[j]=temp;
            //swap(input[i],input[j]);
            i++; j--;
        }
    }
    return pi;

}

void quickSorthelper(int input[], int si, int ei)
{
    if(si>=ei) return;
    int pi= partition(input,si,ei);
    quickSorthelper(input,si,pi-1);
    quickSorthelper(input,pi+1,ei);
}

void quickSort(int input[], int size)
{
    quickSorthelper(input,0,size-1);
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
}