#pragma once
#include <cmath>

class Plane {
private:
    double m_A, m_B, m_C, m_D; 

public:

    Plane(double A = 0, double B = 0, double C = 1, double D = 0);

    bool isParallel(const Plane& other) const;


    friend double getAngleBetweenPlanes(const Plane& p1, const Plane& p2);

    void print() const;
};