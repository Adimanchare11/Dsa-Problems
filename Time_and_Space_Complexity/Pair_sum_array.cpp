// You have been given an integer array/list(ARR) and a number 'num'. Find and return the total number of pairs in the array/list which sum to 'num'.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int pairSum(int arr[], int n , int num)
{
    sort(arr, arr+n);

    int startindex=0;
    int endindex= n-1;
    int numPairs= 0;

    while(startindex< endindex)
    {
        if(arr[startindex] + arr[endindex]< num)
        {
            startindex++;
        }
        else if(arr[startindex]+ arr[endindex]> num)
        {
            endindex--;
        }
        else
        {
            int elementAtstart= arr[startindex];
            int elementAtend = arr[endindex];

            if(elementAtstart == elementAtend)
            {
                int totalElementsFromStartToEnd = (endindex- startindex) +1;
                num+= (totalElementsFromStartToEnd *(totalElementsFromStartToEnd-1));

                return numPairs;
            }

            int tempStartIndex = startindex+1;
            int tempEndIndex = endindex-1;

            while(tempStartIndex<=tempEndIndex && arr[tempStartIndex]== elementAtstart)
            {
                tempStartIndex +=1;
            }

            while (tempEndIndex >= tempStartIndex && arr[tempEndIndex]== elementAtend)
            {
                tempEndIndex -=1;
            }

            int totalElementFromStart = (tempStartIndex - startindex);
            int totalElemmtsfromEnd = (endindex- tempEndIndex);

            numPairs += (totalElementFromStart * totalElemmtsfromEnd);

            startindex= tempStartIndex;
            endindex = tempEndIndex;
        }
    }

    return numPairs;
}

int main()
{
    int size;
    int x;

    cout << "Enter the size of the array: ";
    cin >> size;
    int *input = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> input[i];
    }

    cout<<"Enter the number whose sum is to found: ";
    cin>>x;
    cout<<pairSum(input, size, x)<<endl;
    return 0;
}