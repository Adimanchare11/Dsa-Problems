#include<iostream>
using namespace std;

class ComplexNumbers {
    // Complete this class
    private:
    int real;
    int imaginary;
    
    public:
    ComplexNumbers(int real, int imaginary)
    {
		this-> real= real;
        this-> imaginary= imaginary;
    }
    
    void plus(ComplexNumbers &c2)
    {
		int x= real+c2.real;
        int y= imaginary+c2.imaginary;
        this->real=x;
        this->imaginary=y;
    }

    void multiply(ComplexNumbers &c2)
    {
        int x= real*c2.real - imaginary*c2.imaginary;
        int y= real*c2.imaginary + imaginary*c2.real;
        this->real = x;
        this->imaginary = y;
    }
    
    void print()
    {
		cout<<real<<"+"<<imaginary<<"i";
    }

    
};

int main(){
    int real1, real2, imaginary1, imaginary2,choice;
    cin>>real1>>imaginary1;
    cin>>real2>>imaginary2;
    cout<<"Enter Choice: ";
    cin>>choice;
    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2,imaginary2);
    
    if(choice==1)
    {
        c1.plus(c2);
        c1.print();
    }
    if(choice==2)
    {
        c1.multiply(c2);
        c1.print();
    }
    else return 0;
}