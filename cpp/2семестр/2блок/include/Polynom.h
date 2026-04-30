#pragma once
#include <vector>
class Polynom 
{
private:
    std::size_t m_deg;
    std::vector<double> m_coefs;
public:

    Polynom();
    Polynom(const std::size_t& n, const std::vector<double>& coefs);

    double operator()(const double& x);
}
