#pragma once

class Line
{
private:

    double m_A;
    double m_B;
    double m_C;

public:

    Line(double A = 0, double B = 1, double C = 0);

    void transferParall(const double& length, const double& v_x1, const double& v_x2);
    void rotateAngle(const double alpha);
    friend double getAngle(const Line& l1, const Line& l2);

    void print() const;
};

