#pragma once

class VectorR2
{
private:
        double m_x1;
        double m_x2;
public:
    VectorR2();
    VectorR2(double x1, double x2);

    void rotateRad(const double& angleInRad);
    void rotateAngle(const double& angleInDeg);

    void print() const;
};