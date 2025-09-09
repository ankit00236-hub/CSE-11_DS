#include<iostream>
using namespace std;
struct complex{
    float real;
    float imag;
};
int main()
{
    complex c1, c2, sum;
    cout << "Enter first complex number (real imag): ";
    cin >> c1.real >> c1.imag;
    cout << "Enter second complex number (real imag): ";
    cin >> c2.real >> c2.imag;
    sum.real = c1.real + c2.real;
    sum.imag = c1.imag + c2.imag;
    cout << "Sum of complex numbers: " << sum.real << " + " << sum.imag << "i" << endl;
    
    sum.real = c1.real * c2.real - c1.imag * c2.imag;
    sum.imag = c1.real * c2.imag + c1.imag * c2.real;
    cout << "Product of complex numbers: " << sum.real << " + " << sum.imag << "i" << endl; 
    
    return 0;
}