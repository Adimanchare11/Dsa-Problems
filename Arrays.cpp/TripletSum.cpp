#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> TripletSum(int arr[], int n, int key){

    vector<vector<int>> ans;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(arr[i]+arr[j]+arr[k]==key){
                vector<int> temp;
                temp.push_back(arr[i]);
                temp.push_back(arr[j]);
                temp.push_back(arr[k]);
                ans.push_back(temp);
                }
                }
        }
    }
    return ans;
}

int main(){
    int arr[7] = {0,1,2,3,4,5,6};
    int key;
    cout<<"Enter a Key: ";
    cin>>key;

    vector<vector<int>> ans = TripletSum(arr,7,key);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}