#include "Triangle.h"
#include "Matrix.h"
#include "Vector.h"
#include <cmath>

const double eps = 1e-12;

Triangle::Triangle() {};

Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3) : m_x1(x1), m_y1(y1), m_x2(x2), m_y2(y2), m_x3(x3), m_y3(y3) {};

double Triangle::getAreaOriented() const {
    double s;

    Matrix A(2, 2);
    Vector AB(m_x2 - m_x1, m_y2 - m_y1, 0);
    Vector AC(m_x3 - m_x1, m_y3 - m_y1, 0);

    A.defEl(1, 1, AB.getX());
    A.defEl(1, 2, AB.getY());
    A.defEl(2, 1, AC.getX());
    A.defEl(2, 2, AC.getY());

    s = A.det();

    return s / 2;
}

void Triangle::relocate(const double& x, const double& y)
{
    m_x1 += x;
    m_x2 += x;
    m_x3 += x;
    m_y1 += y;
    m_y2 += y;
    m_y3 += y;
}

bool Triangle::includes(const Triangle& t) const
{
    // Вершины первого треугольника - A, B, C; 
    // Вершины второго треугольника - P1, P2, P3
    Vector AB(m_x2 - m_x1, m_y2 - m_y1);
    Vector AC(m_x3 - m_x1, m_y3 - m_y1);

    double areaABC = getAreaOriented();

    Triangle ABP1(m_x1, m_y1, m_x2, m_y2, t.m_x1, t.m_y1);
    Triangle AP1C(m_x1, m_y1, t.m_x1, t.m_y1, m_x3, m_y3);
    Triangle P1BC(t.m_x1, t.m_y1, m_x2, m_y2, m_x3, m_y3);

    double areaABP1 = ABP1.getAreaOriented();
    double areaAP1C = AP1C.getAreaOriented();
    double areaP1BC = P1BC.getAreaOriented();

    double alphaP1 = areaABP1 / areaABC;
    double betaP1 = areaAP1C / areaABC;
    double gammaP1 = areaP1BC / areaABC;

    if (!pointIsInside(alphaP1, betaP1, gammaP1)) return false;

    Triangle ABP2(m_x1, m_y1, m_x2, m_y2, t.m_x2, t.m_y2);
    Triangle AP2C(m_x1, m_y1, t.m_x2, t.m_y2, m_x3, m_y3);
    Triangle P2BC(t.m_x2, t.m_y2, m_x2, m_y2, m_x3, m_y3);

    double areaABP2 = ABP2.getAreaOriented();
    double areaAP2C = AP2C.getAreaOriented();
    double areaP2BC = P2BC.getAreaOriented();

    double alphaP2 = areaABP2 / areaABC;
    double betaP2 = areaAP2C / areaABC;
    double gammaP2 = areaP2BC / areaABC;

    if (!pointIsInside(alphaP2, betaP2, gammaP2))
        return false;

    Triangle ABP3(m_x1, m_y1, m_x2, m_y2, t.m_x3, t.m_y3);
    Triangle AP3C(m_x1, m_y1, t.m_x3, t.m_y3, m_x3, m_y3);
    Triangle P3BC(t.m_x3, t.m_y3, m_x2, m_y2, m_x3, m_y3);

    double areaABP3 = ABP3.getAreaOriented();
    double areaAP3C = AP3C.getAreaOriented();
    double areaP3BC = P3BC.getAreaOriented();

    double alphaP3 = areaABP3 / areaABC;
    double betaP3 = areaAP3C / areaABC;
    double gammaP3 = areaP3BC / areaABC;

    if (!pointIsInside(alphaP3, betaP3, gammaP3))
        return false;

    return true;
}

double Triangle::getArea() const
{
    double s;

    Matrix A(2, 2);
    Vector AB(m_x2 - m_x1, m_x2 - m_y1, 0);
    Vector AC(m_x3 - m_x1, m_y3 - m_y1, 0);

    A.defEl(1, 1, AB.getX());
    A.defEl(1, 2, AB.getY());
    A.defEl(2, 1, AC.getX());
    A.defEl(2, 2, AC.getY());

    s = std::abs(A.det());

    return s / 2;
}

bool Triangle::operator>(const Triangle& t) const {
    return getArea() > t.getArea();
}

bool pointIsInside(double a, double b, double g)
{
    return (a >= eps && b >= eps && g >= eps);
}

std::istream& operator>>(std::istream& is, Triangle& t) {
    is >> t.m_x1 >> t.m_y1 >> t.m_x2 >> t.m_y2 >> t.m_x3 >> t.m_y3;
    
    return is;
}

std::ostream& operator<<(std::ostream& os, Triangle t)
{
    os << "(" << t.m_x1 << ", " << t.m_y1 << ")" << ", " << "(" << t.m_x2 << ", " << t.m_y2 << ")"
       << ", " << "(" << t.m_x3 << ", " << t.m_y3 << ")";

    return os;
}