#include "./include/Complex.h"
#include <iostream>


int main() {
    Complex a(12, -21);
    Complex b(12, -21);
    Complex c = a + b;
    c.print();
    return 0;
}