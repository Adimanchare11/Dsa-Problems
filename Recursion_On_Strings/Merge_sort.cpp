// Sort an array A using Merge Sort.
// Change in the input array itself. So no need to return or print anything.

#include <iostream>
using namespace std;

void merge(int input[] , int lo, int hi)
{
    int size= hi-lo+1;
    int *temp= new int[size];
    int mid= (hi+lo)/2;
    int i = lo;
    int j = mid + 1;
    int k = 0;

    while (i <=mid && j <= hi)
    {
        if (input[i] < input[j])
        {   
            temp[k] = input[i];
            k++;
            i++;
        }
        else
        {
            temp[k]= input[j];
            k++;
            j++;
        }
    }

    while(i<=mid)
    {
        temp[k]=input[i];    //copy all the remaining elements from input1 to temp
        k++; i++;
    }

    while(j<=hi)
    {
        temp[k]=input[j];    // copy all the remaining elements from input2 to temp
        k++; j++;
    }

    int m=0;
    for(int i=lo; i<=hi; i++)
    { input[i]= temp[m];  // again copying all the elements of  temp array to merge sorted array input
      m++;
    }

    delete [] temp;
}

void mergeSort(int input[], int si, int ei)
{
    if (si >= ei) return;
    int mid = (si+ ei) / 2; // If we use (start + end )/2 then it may happen that the sum will exceed the limit of integer hence we should use start + (end-start)/2
    mergeSort(input, si, mid);
    mergeSort(input, mid + 1, ei);
    merge(input ,si, ei);
}

void mergeSort(int input[], int length)
{
    mergeSort(input,0,length-1);
}


int main()
{
    int length;
    cout << "Enter length of the array: ";
    cin >> length;
    int *input = new int(length);
    for (int i = 0; i < length; i++)
        cin >> input[i];
    mergeSort(input, length);
    for (int i = 0; i < length; i++)
    {
        cout << input[i] << " ";
    }
}