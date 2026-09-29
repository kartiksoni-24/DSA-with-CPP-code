// Problem:
// Subtract two complex numbers using the minus operator.
//
// Approach:
// Overload operator- to subtract the real and imaginary parts separately.
//
// Complexity:
// Time: O(1)
// Space: O(1)
#include<iostream>
using namespace std;

class Complex{
    public:
        int real, img;
        Complex(int real,int img){
            this->real = real;
            this->img = img;
        }
};

Complex operator - (Complex& a, Complex& b){
   int realRes = a.real - b.real;
   int imgRes = a.img - b.img;

   return Complex(realRes, imgRes);
}

int main(){
    Complex c1(2,5);
    Complex c2(1,4);

    Complex c3 = c1 - c2;

    cout  << c3.real << " + " << c3.img << "i"<< endl;

    return 0;
}
