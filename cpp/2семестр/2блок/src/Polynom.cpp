#include "../include/Polynom.h"
#include <vector>
#include <iostream>
#include <cmath>

const double eps = 1e-12;

Polynom::Polynom() : m_deg(0), m_coefs(1, 0.0) {};
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
Polynom::Polynom(const std::size_t& n) : m_deg(n), m_coefs(n + 1, 0.0) {}
Polynom::Polynom(const std::size_t& n, const double& initVal) : m_deg(n), m_coefs(n + 1, initVal) {}

double Polynom::operator()(const double& c) {

    double bk = m_coefs[0];

    for (int k = 1; k <= static_cast<int>(m_deg); k++) {
        double ak = m_coefs[k];
        bk = ak + bk * c;
    }   

    return bk;
}

Polynom Polynom::operator+(const Polynom& p)
{
    std::size_t deg = std::max(static_cast<int>(m_deg), static_cast<int>(p.m_deg));

    Polynom res(deg, 0.0);

    for (int i = static_cast<int>(m_deg); i >= 0; i--) 
    {
        res.m_coefs[i + (deg - m_deg)] = m_coefs[i];
    }

    for (int i = static_cast<int>(p.m_deg); i >= 0; i--) 
    {
        res.m_coefs[i + (deg - p.m_deg)] += p.m_coefs[i];
    }

    return res;
}

Polynom Polynom::operator-(const Polynom& p)
{
    std::size_t deg = std::max(static_cast<int>(m_deg), static_cast<int>(p.m_deg));

    Polynom res(deg, 0.0);

    
    for (int i = static_cast<int>(m_deg); i >= 0; i--) 
    {
        res.m_coefs[i + (deg - m_deg)] = m_coefs[i];
    }

    for (int i = static_cast<int>(p.m_deg); i >= 0; i--) 
    {
        res.m_coefs[i + (deg - p.m_deg)] -= p.m_coefs[i];
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

Polynom Polynom::operator=(const Polynom& p)
{
    m_deg = p.m_deg;
    m_coefs = p.m_coefs;

    return *this;
}

std::ostream& operator<<(std::ostream& os, const Polynom& p)
{

    for (std::size_t i = 0; i <= p.m_deg; i++)
    {
        int cur_deg = static_cast<int>(p.m_deg) - i;
    
        if (static_cast<int>(i) == 0)
        {
            bool f = cur_deg != 0;
            std::string out = f ? "x^" + std::to_string(cur_deg) : "";
            std::noshowpos(os);
            os << p.m_coefs[i];
            os << out;
            i++;
            cur_deg--;
        }

        bool f = cur_deg != 0;
        std::string out = f ? "x^" + std::to_string(cur_deg) : "";

        std::showpos(os);
        os << p.m_coefs[i];
        os << out;
    }

    return os;
}
std::istream& operator>>(std::istream& is, Polynom& p)
{

    for (std::size_t i = 0; i <= p.m_deg; i++)
    {
        double cur_coef;
        is >> cur_coef;
        p.m_coefs[i] = cur_coef;
    }

    return is;
}