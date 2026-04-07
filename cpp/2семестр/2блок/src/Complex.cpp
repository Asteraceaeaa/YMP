#include "Complex.h"
#include <iostream>

Complex::Complex(double real, double imag)
    : m_real(real)
    , m_imag(imag) {}

void Complex::print() {
    std::cout << m_real << " + i" << m_imag << "\n";
}


