#pragma once

class Vector {
private:
    double m_x = 0.0;
    double m_y = 0.0;
    double m_z = 0.0;

public:
    /* Конструкторы */
    Vector() = default;
    Vector(double x, double y, double z);

    /* Операторы */
    Vector operator+(const Vector& vec_2) const;
    Vector operator-(const Vector& vec_2) const;
    double operator*(const Vector& vec_2) const;

    /* Операции с векторами */
    double getModule();

    friend Vector vectorAdd(const Vector& vec_1, const Vector& vec_2);
    friend double getCos(Vector vec_1, Vector vec_2);
};

