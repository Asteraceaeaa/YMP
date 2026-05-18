#include "../../include/5/Line.h"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

const double eps = 1e-12;

Line::Line(double A, double B, double C) : m_A(A), m_B(B), m_C(C) {}

void Line::transferParall(const double& dist, const double& v_x1, const double& v_x2)
{
    double v_length = std::sqrt(std::pow(v_x1, 2) + std::pow(v_x2, 2));
    if (std::abs(v_length) < eps) {
        throw std::invalid_argument("Нулевой вектор направления");
    }

    double v_x1_norm = v_x1 / v_length;
    double v_x2_norm = v_x2 / v_length;

    double newC = m_C - m_A * (v_x1_norm * dist) - m_B * (v_x2_norm * dist);

    m_C = newC;
}

void Line::rotateAngle(const double alpha)
{
    double alphaRad = -alpha * M_PI / 180;

    double newA = m_A * std::cos(alphaRad) - m_B * std::sin(alphaRad);
    double newB = m_A * std::sin(alphaRad) + m_B * std::cos(alphaRad);

    m_A = newA;
    m_B = newB;
}

double getAngle(const Line& l1, const Line& l2)
{
    double scalar_product = l1.m_A * l2.m_A + l1.m_B * l2.m_B;
    double l_n1 = std::sqrt(std::pow(l1.m_A, 2)+ std::pow(l1.m_B, 2));
    double l_n2 = std::sqrt(std::pow(l2.m_A, 2) + std::pow(l2.m_B, 2));

    if (std::abs(l_n1 * l_n2) < eps) {
        throw std::invalid_argument("Нулевой вектор нормали");
    }

    double cosA = std::abs(scalar_product) / (l_n1 * l_n2);
    double A = std::acos(cosA);

    return A * 180 / M_PI;
}

void Line::print() const
{
    std::string A = (std::abs(m_A) > eps ? std::to_string(m_A) + "x" : "");
    std::string Bsign = A != "" ? (m_B > 0 ? " + " : " - ") : (m_B < 0 ? "-" : "");
    std::string B = (std::abs(m_B) > eps ? std::to_string(std::abs(m_B)) + "y" : "");
    std::string Csign = B != "" ? (m_C > 0 ? " + " : " - ") : (m_C < 0 ? "-" : "");
    std::string C = (std::abs(m_C) > eps ? std::to_string(std::abs(m_C)) : "");

    std::cout << "Прямая " << A << (B != "" ? Bsign : "") << B
              << (C != "" ? Csign : "") << (C != "" ? C : "0") << " = 0";
}