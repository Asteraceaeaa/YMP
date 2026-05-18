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

    double getX1P2() const;
    double getX2P2() const;

    void setX1P2(double val);
    void setX2P2(double val);

    void print() const override;

    // std::string toStr() const override;
};