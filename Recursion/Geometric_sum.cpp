//Given k, find the geometric sum i.e.
// 1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k) 

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

double geometricSum(int k)
{
    if(k==0) return 1;

    double smalloutput = (1/(pow(2,k)));
    return geometricSum(k-1)+ smalloutput;
}

int main() {
    int k;
    cout<<"enter a  number: ";
    cin >> k;
    cout << fixed << setprecision(5);
    cout <<"Geometric sum is: "<< geometricSum(k) << endl;   
}
