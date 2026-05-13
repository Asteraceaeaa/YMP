#pragma once
#include <iostream>

class Triangle 
{
private:
    double m_x1;
    double m_y1;
    double m_x2;
    double m_y2;
    double m_x3;
    double m_y3;

    double getAreaOriented() const;

public:
    Triangle();
    Triangle(double x1, double y1, double x2, double y2, double x3, double y3);

    void relocate(const double& x, const double& y);

    bool includes(const Triangle& t) const;

    bool operator>(const Triangle& t) const;

    double getArea() const;

    friend std::istream& operator>>(std::istream& is, Triangle& t);
    friend std::ostream& operator<<(std::ostream& os, Triangle t);
};

std::istream& operator>>(std::istream& is, Triangle& t);
std::ostream& operator<<(std::ostream& os, Triangle t);
bool pointIsInside(double a, double b, double g);