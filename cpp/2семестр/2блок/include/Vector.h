#pragma once
#include <string>

class Vector {
private:
    double m_x = 0.0;
    double m_y = 0.0;
    double m_z = 0.0;

public:
    /* Конструкторы */
    Vector() = default;
    Vector(double x, double y, double z=0);

    /* Операторы */
    Vector operator+(const Vector& vec_2) const;
    Vector operator-(const Vector& vec_2) const;
    double operator*(const Vector& vec_2) const;

    /* Операции с векторами */
    double getModule() const;

    friend Vector crossProduct(const Vector& vec_1, const Vector& vec_2);
    friend double getCos(const Vector& vec_1, const Vector& vec_2);

    std::string toString();
    double getX();
    double getY();
};

