#include<iostream>
using namespace std;

int main(){
    int firstvalue=5;
    int secondvalue=15;
    char thirdvalue= 'a';

    int *p1, *p2;
    char *p3;
    p1= &firstvalue;
    p2= &secondvalue;
    p3 = &thirdvalue;
    *p1= 10;
    *p1=*p2;
    p1=p2;
    cout<<"The First value becomes: "<<firstvalue;
    cout<<"The Second value becomes: "<<secondvalue;
    return 0;
}