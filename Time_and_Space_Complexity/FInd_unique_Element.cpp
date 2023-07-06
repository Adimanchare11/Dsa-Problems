// You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1].
// Now, in the given array/list, 'M' numbers are present twice and one number is present only once.
// You need to find and return that number which is unique in the array/list.

// There are three approachs to solve this problem
// 1. to check duplicate form each element by scaning the array || Time complexity= O(n^2)
// 2. to sort the the array and check if i==i+1 or not || Time complexity= O(nlogn);
// 3. By using XOR operation. XOR=> gives output as 0 for same elements || O(n)

#include <iostream>
using namespace std;

int findUnique(int arr[], int size)
{
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;
}

int main()
{
    int t; // The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.
    cout<<"Enter the number of test cases: ";
    cin >> t;

    while (t--)
    {
        int size; // First line of each test case or query contains an integer 'N' representing the size of the array/list.
        cout << "Enter the size of the array: ";
        cin >> size;
        int *input = new int[size];

        for (int i = 0; i < size; i++)
        {
            cin >> input[i];
        }

        cout <<"The Unique Element is: "<<findUnique(input, size);
    }
    return 0;
}