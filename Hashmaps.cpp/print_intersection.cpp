#include <iostream>
#include <unordered_map>
using namespace std;

void printIntersection(int *arr1, int* arr2, int n, int m)
{
    unordered_map<int,int> freq;
    for(int i=0; i<n; ++i)
    {
        ++freq[arr1[i]];
    }
    for(int i=0; i<m; ++i)
    {
        if(freq.find(arr2[i])!=freq.end())
        {
            cout<<arr2[i]<<endl;
        }
        if(freq[arr2[i]>1])
        {
            --freq[arr2[i]];
        }
        else
        {
            freq.erase(arr2[i]);
        }
    }
}
int main()
{
 int n;
    cin >> n;

    int* arr1 = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr1[i];
    }

    int m;
    cin >> m;

    int* arr2 = new int[m];

    for (int i = 0; i < m; ++i) {
        cin >> arr2[i];
    }

    printIntersection(arr1, arr2, n, m);

    delete[] arr1;
    delete[] arr2;
    return 0;
}