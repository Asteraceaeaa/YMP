#include <iostream>
#include <cmath>

class Complex 
{
private:
    double a;
    double b;
    double b_bar;
    // float mod = 0;

public:
    void repr() {
        std::cout << a << (b < 0 ? " - i" : " + i")  << std::abs(b) << std::endl;
    }



    Complex(int k, int j) : a(k), b(j), b_bar(-j) {};

    Complex operator+(const Complex n) { return Complex(a + n.a, b + n.b); }

    Complex operator-(const Complex n) { return Complex(a - n.a, b - n.b); }

    Complex operator*(const Complex n) { return Complex(a*n.a - b*n.b, a*n.b - n.a*b); }

    Complex operator/(const Complex n) {
        if (n.a != 0 || n.b != 0) {
            return Complex(a * n.a - b * n.b, a * n.b - n.a * b);
        }
        return Complex(nan, nan);
    }
};



int main() {
    Complex a = Complex(12, -21);
    Complex b = Complex(12, -21);
    Complex c = a + b;
    c.repr();
    return 0;
}