#include "Vector.h"
#include <iostream>
#include <cmath>

/* Конструкторы */

Vector::Vector(double x, double y, double z) : m_x(x), m_y(y), m_z(z) {};

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

double Vector::getModule()
{
    double module2 = std::pow(m_x, 2) + std::pow(m_y, 2) + std::pow(m_z, 2);
    return std::pow(module2, 0.5);
}

Vector vectorAdd(const Vector& vec_1, const Vector& vec_2) 
{
    double x = vec_1.m_y * vec_2.m_z - vec_1.m_z * vec_2.m_y;
    double y = vec_1.m_z * vec_2.m_x - vec_1.m_x * vec_2.m_z;
    double z = vec_1.m_x * vec_2.m_y - vec_1.m_y * vec_2.m_x;

    return Vector(x, y, z);
}

double getCos(Vector vec_1, Vector vec_2)
{
    double scalar = vec_1 * vec_2;
    double modules = vec_1.getModule() * vec_2.getModule();

    return scalar / modules;
}