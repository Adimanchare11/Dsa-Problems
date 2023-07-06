#include<iostream>
#include<vector>
using namespace std;

vector<int> intersection(int arr1[], int arr2[], int n, int m){
    vector<int> ans;

    for(int i=0; i<n; i++){

        int element = arr1[i];
        for(int j=0; j<m; j++){

            if(element<arr2[j]) break;

            if(element==arr2[j]){
                ans.push_back(arr1[i]);
                arr2[j]= INT_MIN;
                break;
            }
        }
    }
    return ans;
}

//Optimal soln with TC- O(n*n)
//Two pointer approach
vector<int> intersection_opt(int arr1[], int arr2[], int n, int m){
    int i=0, j=0;
    vector<int> ans;

    while(i<n && j<m){
        if(arr1[i]==arr2[j]){
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
        else if(arr1[i]<arr2[j]) i++;
        else j++;
    }
    return ans;
}

int main(){
    
    int arr1[10]={1,2,3,4,5,9,10,15,19,20};
    int arr2[6]={3,5,9,11,15,19};

    cout<<"Common elements between two arrays are: ";
    vector<int> ans = intersection_opt(arr1,arr2,10,6);

    for(int i=0; i<ans.size(); i++ ){
        cout<<ans[i]<<" ";
    }

    return 0;
}