#include "../../include/1/Circle.h"
#include <cmath>
#include <iostream>

Circle::Circle() : Point(0, 0), m_R(1) {};
Circle::Circle(double x1, double x2, double R) : Point(x1, x2), m_R(R) {};

double Circle::getR() const
{
    return m_R;
}

void Circle::setR(double val)
{
    m_R = val;
}

void Circle::print() const
{
    std::cout << "\nОкружность радиуса " << m_R << " с центром в точке " << "(" << m_x1 << ", " << m_x2 << ")";
}