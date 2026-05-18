#pragma once
#include <vector>
#include <iostream>

class Polynom 
{
private:
    std::size_t m_deg;
    std::vector<double> m_coefs;
public:

    Polynom();
    Polynom(const std::size_t& n, const std::vector<double>& coefs);

    Polynom(const std::size_t& n);
    Polynom(const std::size_t& n, const double& initVal);

    double operator()(const double& x);
    Polynom operator+(const Polynom& p);
    Polynom operator-(const Polynom& p);
    Polynom operator*(const Polynom& p);

    Polynom operator=(const Polynom& p);

    friend std::ostream& operator<<(std::ostream& os, const Polynom& p);
    friend std::istream& operator>>(std::istream& is, Polynom& m);


};

// std::ostream& operator<<(std::ostream& os, const Polynom& p);
// std::istream& operator>>(std::istream& is, Polynom& m);