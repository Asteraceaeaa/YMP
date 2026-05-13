#include "../include/Circle.h"
#include <iostream>
#include <cmath>

Circle::Circle() : Point(0, 0), m_R(1) {};
Circle::Circle(double x1 = 0, double x2 = 0, double R) : Point(x1, x2), m_R(R) {};

double Circle::getR() const
{
    return m_R;
}

void Circle::setR(double val)
{
    m_R = val;
}

double Circle::getArea()
{

}

void Circle::print()
{
    std::cout << "\nОкружность радиуса " << m_R << " с центром в точке " << "(" << m_x1 << ", " << m_x2 << ")";
}