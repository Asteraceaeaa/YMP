#pragma once

class Complex {
private:
    double m_real = 0.0;
    double m_imag = 0.0;
public:
    Complex() = default;
    Complex(double real, double imag);


    
    void print();


};