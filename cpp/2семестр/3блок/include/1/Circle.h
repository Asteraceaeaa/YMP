#pragma once
#include "Point.h"


class Circle : public Point
{
private:
    double m_R;

public:

    Circle();
    Circle(double x1, double x2, double R);
    
    double getR() const;
    
    void setR(double val);

    void print() const override;

};