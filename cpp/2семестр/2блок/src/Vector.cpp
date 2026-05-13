#include "Vector.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>



/* Конструкторы */

Vector::Vector(double x, double y, double z) : m_x(x), m_y(y), m_z(z) {};

/*  */

std::string Vector::toString()
{
    std::ostringstream oss;
    oss << "(" << m_x << ", " << m_y << ", " << m_z << ")";
    std::string res = oss.str();
    return res;
}

double Vector::getX()
{
    return m_x;
}
double Vector::getY()
{
    return m_y;
}

/* Операторы */

Vector Vector::operator+(const Vector& vec_2) const
{
    return Vector(m_x + vec_2.m_x, m_y + vec_2.m_y, m_z + vec_2.m_z);
}

Vector Vector::operator-(const Vector& vec_2) const {
    return Vector(m_x - vec_2.m_x, m_y - vec_2.m_y, m_z - vec_2.m_z);
}

double Vector::operator*(const Vector& vec_2) const {
    return m_x * vec_2.m_x + m_y * vec_2.m_y + m_z * vec_2.m_z;
}

/* Операции с векторами */

double Vector::getModule() const
{
    double module2 = std::pow(m_x, 2) + std::pow(m_y, 2) + std::pow(m_z, 2);
    return std::sqrt(module2);
}

Vector crossProduct(const Vector& vec_1, const Vector& vec_2) {
    double x = vec_1.m_y * vec_2.m_z - vec_1.m_z * vec_2.m_y;
    double y = vec_1.m_z * vec_2.m_x - vec_1.m_x * vec_2.m_z;
    double z = vec_1.m_x * vec_2.m_y - vec_1.m_y * vec_2.m_x;

    return Vector(x, y, z);
}

double getCos(const Vector& vec_1, const Vector& vec_2)
{
    double scalar = vec_1 * vec_2;
    double modules = vec_1.getModule() * vec_2.getModule();
    if (modules == 0) {
        return 0;
    }
    return scalar / modules;
}