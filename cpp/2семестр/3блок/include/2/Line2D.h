#pragma once
#include "../1/Point.h"
#include <string>

class Line2D : public Point 
{
private:
    Point m_p2;

public:
    Line2D();
    Line2D(double p1_x1, double p1_x2, double p2_x1, double p2_x2);

    double getX1() const override;
    double getX2() const override;

    void setX1(double val) override;
    void setX2(double val) override;

    void print() const override;

    // std::string toStr() const override;
};