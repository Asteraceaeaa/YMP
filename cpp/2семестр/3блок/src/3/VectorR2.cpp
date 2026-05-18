#include "../../include/3/VectorR2.h"
#include <iostream>
#include <cmath>

const double eps = 1e-12;

VectorR2::VectorR2() : m_x1(0.0), m_x2(0.0) {}
VectorR2::VectorR2(double x1, double x2) : m_x1(x1), m_x2(x2) {}

void VectorR2::rotateRad(const double& alpha)
{
    double x1New = m_x1 * std::cos(alpha) - m_x2 * std::sin(alpha);
    double x2New = m_x1 * std::sin(alpha) + m_x2 * std::cos(alpha);

    m_x1 = x1New;
    m_x2 = x2New;
}

void VectorR2::rotateAngle(const double& alpha) {

    double alphaRad = M_PI * alpha / 180;

    double x1New = m_x1 * std::cos(alphaRad) - m_x2 * std::sin(alphaRad);
    double x2New = m_x1 * std::sin(alphaRad) + m_x2 * std::cos(alphaRad);

    m_x1 = x1New;
    m_x2 = x2New;
}

void VectorR2::print() const
{
    std::cout << "Вектор с координатами " << "(" << (m_x1 < eps ? 0 : m_x1) << "; "
              << (m_x2 < eps ? 0 : m_x2) << ").";
}