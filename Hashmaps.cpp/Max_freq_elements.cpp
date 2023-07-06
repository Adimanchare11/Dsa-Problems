#include<iostream>
#include<unordered_map>
#include<cmath>
using namespace std;

int maxfreq(int* arr, int n)
{
    unordered_map<int, int> freq;
    int maxfreq=0;

    for(int i=0; i<n; i++)
    {
        ++freq[arr[i]];
        maxfreq= max(freq[arr[i]], maxfreq);
    }
    int maxfreqelement;
    for(int i=0; i<n; i++)
    {
        if(maxfreq==freq[arr[i]])
        {
            maxfreqelement= arr[i];
            break;
        }
    }
    return maxfreqelement;

}


int main(){
    
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << maxfreq(arr, n);

    delete[] arr;
    return 0;
}