#include "../../include/1/Point.h"
#include <cmath>
#include <iostream>

Point::Point() : m_x1(0), m_x2(0) {};
Point::Point(double x1, double x2) : m_x1(x1), m_x2(x2) {};

double Point::getX1() const
{
    return m_x1;
}
double Point::getX2() const
{
    return m_x2;
}

void Point::setX1(double val)
{
    m_x1 = val;
}

void Point::setX2(double val)
{
    m_x2 = val;
}

double Point::distTo(Point& p) const
{
    return std::sqrt(std::pow(m_x1 - p.m_x1, 2) + std::pow(m_x2 - p.m_x2, 2));
}

void Point::print() const
{
    std::cout << "\nКоординаты точки: " << "(" << m_x1 << ", " << m_x2 << ")"; 
}

std::string Point::toStr() const
{
    return "(" + std::to_string(m_x1) + ", " + std::to_string(m_x2) + ")";
}