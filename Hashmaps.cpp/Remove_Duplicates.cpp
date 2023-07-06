#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

vector<int> reomveDuplicates(int * arr, int n)
{
    vector<int> output;
    unordered_map<int,bool> seen;

    for(int i=0; i<n; i++)
    {
        if(seen.count(arr[i])>0)
        {
            continue;
        }
        seen[arr[i]]=true;
        output.push_back(arr[i]);
    }
    return output;
}
int main(){
    int arr[]={1,2,2,1,3,2,4,5,3,4,1,5};
    vector<int> output= reomveDuplicates(arr,12);
    for(int i=0; i<output.size(); i++)
    {
        cout<<output[i]<<" ";
    }
    
    return 0;
}