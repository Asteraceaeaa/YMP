#include "../include/Polynom.h"
#include <vector>
#include <iostream>
Polynom::Polynom() : m_deg(0), m_coefs() {};
Polynom::Polynom(const std::size_t& n, const std::vector<double>& coefs) : m_deg(n), m_coefs(coefs) {

    if (coefs.empty())
        throw std::invalid_argument("Коэффициенты не могут быть пустыми");
    std::size_t l = coefs.size();
    if ((l - 1) != n) 
    {
        std::cerr << "Степень не соответсвует колву коэффициентов. Степень автоматически изменена и равна " << l - 1 << std::endl;
        m_deg = l - 1;
    }

};




double Polynom::operator()(const double& c)
{
    double bk = m_coefs[m_deg];
    for (int k = m_deg - 1; k >= 0; k--)
    {
        double ak = m_coefs[k];
        bk = ak + bk * c;
    }

    return bk;
}