#include "../../include/4/VectorR3.h"
#include <iostream>
#include <cmath>
const double eps = 1e-12;

VectorR3::VectorR3() : m_x1(0), m_x2(0), m_x3(0) {}
VectorR3::VectorR3(double x1, double x2, double x3) : m_x1(x1), m_x2(x2), m_x3(x3) {}

double scalarProduct(const VectorR3& v1, const VectorR3& v2)
{
    return v1.m_x1 * v2.m_x1 + v1.m_x2 * v2.m_x2 + v1.m_x3 * v2.m_x3;
}

VectorR3 crossProduct(const VectorR3& v1, const VectorR3& v2)
{
    double x1 = v1.m_x2 * v2.m_x3 - v1.m_x3 * v2.m_x2;
    double x2 = -v1.m_x1 * v2.m_x3 + v1.m_x3 * v2.m_x1;
    double x3 = v1.m_x1 * v2.m_x2 - v1.m_x2 * v2.m_x1;

    VectorR3 res(x1, x2, x3);

    return res;
}

bool isBasis(const VectorR3& v1, const VectorR3& v2, const VectorR3& v3)
{
    VectorR3 cross_v1v2 = crossProduct(v1, v2);
    double mixed_product = scalarProduct(cross_v1v2, v3);

    if (std::abs(mixed_product) < eps) { return false; }

    return true;
}

void VectorR3::print() const 
{
    std::cout << "Вектор с координатами " << "(" << (m_x1 < eps ? 0 : m_x1) << "; "
              << (m_x2 < eps ? 0 : m_x2) << "; " << (m_x3 < eps ? 0 : m_x3) << ").";
}