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
Polynom::Polynom(const std::size_t& n)
    : m_deg(n)
    , m_coefs() {
        m_coefs.resize(n + 1);
    }
Polynom::Polynom(const std::size_t& n, const double& initVal) : m_deg(n), m_coefs()
{
    m_coefs.resize(n + 1);
    std::fill(m_coefs.begin(), m_coefs.end(), initVal);
}

double Polynom::operator()(const double& c) {
        double bk = m_coefs[m_deg];
        for (int k = m_deg - 1; k >= 0; k--) {
            double ak = m_coefs[k];
            bk = ak + bk * c;
        }

        return bk;
    }

Polynom Polynom::operator+(const Polynom& p)
{
    std::size_t deg = std::max(static_cast<int>(m_deg), static_cast<int>(p.m_deg));

    Polynom res(deg, 0.0);

    // for (int i = static_cast<int>(deg); i >= 0; i--) {
    //     res.m_coefs[i] = m_coefs[i];
    // }

    // for (int i = static_cast<int>(deg); i >= 0; i--) {
    //     res.m_coefs[i] += p.m_coefs[i];
    // }

    // return res;
}

Polynom Polynom::operator-(const Polynom& p)
{
    std::size_t deg = std::max(static_cast<int>(m_deg), static_cast<int>(p.m_deg));

    Polynom res(deg, 0.0);

    for (int i = static_cast<int>(m_deg); i >= 0; i--) {
        res.m_coefs[i] = m_coefs[i];
    }

    for (int i = static_cast<int>(p.m_deg); i >= 0; i--) {
        res.m_coefs[i] -= p.m_coefs[i];
    }

    return res;
}

Polynom Polynom::operator*(const Polynom& p)
{
    std::size_t deg = m_deg + p.m_deg;
    Polynom res(deg, 0.0);

    for (std::size_t i = 0; i <= m_deg; i++)
    {
        for (std::size_t j = 0; j <= p.m_deg; j++)
        {
            res.m_coefs[i+j] += m_coefs[i] * p.m_coefs[j];
        }
    }

    return res;
}

std::ostream& operator<<(std::ostream& os, const Polynom& p)
{
    
    for (std::size_t i = 0; i <= p.m_deg; i++)
    {
        double cur_coef = p.m_coefs[i];
         if (cur_coef == 0) {
            continue;
        }

        int cur_deg = p.m_deg - i;
        std::string cur_degs = "^" + std::to_string(cur_deg);
        std::string sign = cur_coef >= 0 ? " + ": " - "; 
        if (i == 0) { sign = ""; }
        if (cur_deg != 1)
        {
            os << (sign != "" ? sign : "") << ((sign == " + " || sign == "") ? cur_coef : -cur_coef) << (cur_deg != 0 ? "x" : "") << ((cur_deg != 0 && cur_deg != 1) ? cur_degs : "");
        } else
        {
            os << (sign != "" ? sign : "") << (cur_deg != 0 ? "x" : "") << ((cur_deg != 0 && cur_deg != 1) ? cur_degs : "");
        }
    }

    return os;
}
std::istream& operator>>(std::istream& is, Polynom& p)
{

    for (std::size_t i = 0; i < p.m_deg; i++)
    {
        double cur_coef;
        is >> cur_coef;
        p.m_coefs[i] = cur_coef;
    }

    return is;
}