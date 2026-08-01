#include <iostream>
#include <string>
using namespace std;

// operator overloading
class Complex
{
    int real, img;

public:
    Complex(int r, int i)
    {
        real = r;
        img = i;
    }

    void showNum()
    {
        cout << real << " + " << img << "i" << endl;
    }

    Complex operator+(Complex &c2)
    {
        int resReal = this->real + c2.real;
        int resImg = this->img + c2.img;

        Complex c3(resReal, resImg);
        return c3;
    }

    Complex operator-(Complex &c2)
    {
        int resReal = this->real - c2.real;
        int resImg = this->img - c2.img;

        Complex c3(resReal, resImg);
        return c3;
    }
};

int main()
{
    Complex c1(2, 4);
    Complex c2(1, 3);

    Complex c3 = c1 - c2;
    c3.showNum();

    return 0;
}
