#include "Complex.h"
#include <iostream>

Complex::Complex(double real, double imag)
    : m_real(real)
    , m_imag(imag) {}

void Complex::print() {

    if (m_real != 0 && m_imag == 0) {
        std::cout << m_real << "\n";
    } else if (m_real == 0 && m_imag != 0) {
        std::cout << m_imag << "\n";
    } else if (m_real == 0 && m_imag == 0) {
        std::cout << "0";
    } else {
        std::cout << m_real << (m_imag > 0 ? " + i" : " - i") << (m_imag > 0 ? m_imag : -m_imag) << "\n";
    }
}

/* ========== Операторы ===========*/

Complex Complex::operator+(const Complex& x) {
    
    double real = m_real + x.m_real;
    double imag = m_imag + x.m_imag;

    return Complex(real, imag);
}
Complex Complex::operator-(const Complex& x) {

    double real = m_real - x.m_real;
    double imag = m_imag - x.m_imag;

    return Complex(real, imag);
}
Complex Complex::operator*(const Complex& x) { 

    double real = m_real * x.m_real - m_imag*  x.m_imag;
    double imag = m_real * x.m_imag + x.m_real * m_imag;

    return Complex(real, imag);
}

Complex Complex::operator/(const Complex& x) {

    double dev = x.m_real * x.m_real + x.m_imag * x.m_imag;
    double real = (m_real * x.m_real + m_imag * x.m_imag) / dev;
    double imag = (m_imag * x.m_real - m_real * x.m_imag) / dev;

    return Complex(real, imag);
}