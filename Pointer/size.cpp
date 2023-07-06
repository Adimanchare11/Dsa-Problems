#include<iostream>
using namespace std;

int main(){
    int a[5]= {1,2,3,4,5};
    int *b= &a[0];
    cout<<sizeof(b)<<endl;
    cout<<sizeof(a);

    return 0;
}