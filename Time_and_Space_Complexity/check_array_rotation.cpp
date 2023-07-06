// You have been given an integer array/list(ARR) of size N. It has been sorted(in increasing order) and then rotated by some number 'K' in the right hand direction.
// Your task is to write a function that returns the value of 'K', that means, the index from which the array/list has been rotated.

#include <iostream>
using namespace std;

int arrayRotateCheck(int arr[], int n)
{
    int index = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            index = i;
        }
    }
    return index;
}

int main()
{
    int t;
    cout << "Enter number of test cases: ";
    cin >> t;

    while (t--)
    {
        int size;
        cout << "Enter the size of the array: ";
        cin >> size;

        int *input = new int[size];
        for (int i = 0; i < size; i++)
        {
            cin >> input[i];
        }
        cout << "The index by which array is rotated is: " << arrayRotateCheck(input, size)<<endl;

        delete[] input;
    }
    return 0;
}