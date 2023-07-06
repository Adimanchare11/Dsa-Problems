#include<iostream>
#include<unordered_map>
using namespace std;

int getPairsWithDifferenceK(int* arr, int n, int k)
{
    unordered_map<int,int> freq;
    int paircount=0;

    for(int i=0; i<n; i++)
    {
        int compliment= arr[i]-k;
        paircount+= freq[compliment];

        if(k!=0)
        {
            int compliment= arr[i]+k;
            paircount+=freq[compliment];
        }

        ++freq[arr[i]];
    }
    return paircount;
}

int main(){
    int n;
    cin >> n;

    int *input = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int k;
    cin >> k;

    cout << getPairsWithDifferenceK(input, n, k);
    return 0;
}