#include <iostream>
#include <queue>
using namespace std;

bool isMaxHeap(int input[], int n)
{

    for(int i=0; i<n; i++)
    {
        int leftchildIndex= 2*i +1;
        int rightchildIndex= 2*i +1;

        if(leftchildIndex<n && rightchildIndex<n)
        {
            if(input[i]<input[leftchildIndex] || input[i]< input[rightchildIndex])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n;
    cout<<"Enter size of array: ";
    cin >> n;
    int *arr = new int[n];

    cout<<"Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout<<"IsMaxHeap: ";
    cout << (isMaxHeap(arr, n) ? "true\n" : "false\n");

    delete[] arr;

    return 0;
}