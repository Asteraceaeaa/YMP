#pragma once

class VectorR3
{
private:
    double m_x1;
    double m_x2;
    double m_x3;
public:
    VectorR3();
    VectorR3(double x1, double x2, double x3);

    friend double scalarProduct(const VectorR3& v1, const VectorR3& v2);
    friend VectorR3 crossProduct(const VectorR3& v1, const VectorR3& v2);
    friend bool isBasis(const VectorR3& v1, const VectorR3& v2, const VectorR3& v3);

    void print() const;
};
