// You have been given two integer arrays/list(ARR1 and ARR2) of size N and M, respectively. You need to print their intersection; An intersection for this problem can be defined when both the arrays/lists contain a particular value or to put it in other words, when there is a common value that exists in both the arrays/lists.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void intersection(int *arr1, int *arr2, int n, int m)
{
    // We have discussed qsort() in C. C++ STL provides a similar function sort that sorts a vector or array (items with random access)
    // It generally takes two parameters, the first one being the point of the array/vector from where the sorting needs to begin and the second parameter being the length up to which we want the array/vector to get sorted. The third parameter is optional and can be used in cases such as if we want to sort the elements lexicographically.
    // By default, the sort() function sorts the elements in ascending order.
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);

    int i = 0, j = 0;

    while (i < n && j < m)
    {
        if (arr1[i] == arr2[j])
        {
            cout << arr1[i] << " ";
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
            j++;
    }
}

int main()
{
    int t;
    cout << "Enter number of test cases: ";
    cin >> t;

    while (t--)
    {
        int size1, size2;
        cout << "Enter size for the first array: ";
        cin >> size1;

        int *input1 = new int[size1];
        for (int i = 0; i < size1; i++)
        {
            cin >> input1[i];
        }

        cout << "Enter size for the second array: ";
        cin >> size2;

        int *input2 = new int[size2];
        for (int i = 0; i < size2; i++)
        {
            cin >> input2[i];
        }

        cout << "Intersection of two arrays is: ";
        intersection(input1, input2, size1, size2);
        delete[] input1;
        delete[] input2;

        cout << endl;
    }
    return 0;
}