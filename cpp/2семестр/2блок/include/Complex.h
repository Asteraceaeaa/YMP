#pragma once

class Complex {

public:
    Complex() = default;
    Complex(double real, double imag);


    void print();

    Complex operator+(const Complex& x);
    Complex operator-(const Complex& x);
    Complex operator*(const Complex& x);
    Complex operator/(const Complex& x);
private: 
    double m_real = 0.0;
    double m_imag = 0.0;
};