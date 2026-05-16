#include "../../include/2/Line2D.h"
#include <iostream>

Line2D::Line2D() : Point(), m_p2() {};
Line2D::Line2D(double p1_x1, double p1_x2, double p2_x1, double p2_x2) : Point(p1_x1, p1_x2), m_p2(p2_x1, p2_x2) {}

double Line2D::getX1() const 
{
    return m_p2.getX1();
}
double Line2D::getX2() const 
{
    return m_p2.getX2();
}

void Line2D::setX1(double val) 
{
    m_p2.setX2(val);
}

void Line2D::setX2(double val) 
{
    m_p2.setX2(val);
}

void Line2D::print() const
{
    std::cout << "Прямая проходит через точки" << toStr() << m_p2.toStr();
}