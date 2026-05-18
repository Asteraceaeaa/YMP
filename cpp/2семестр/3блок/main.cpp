#include "include/1/Circle.h"
#include "include/1/Point.h"
#include "include/2/Line2D.h"
#include "include/3/VectorR2.h"
#include "include/4/VectorR3.h"
#include "include/5/Line.h"

#include "../2блок/include/Vector.h"

#include <iostream>
#include <cmath>

    const double eps = 1e-9;

#ifdef _WIN32
    #include <windows.h>
    #define CLEAR "cls"
#else
    #include <unistd.h>
    #define CLEAR "clear"
#endif

void clearConsole()
{
    std::system(CLEAR);
}

void waitingForEnter()
{
    std::cin.clear();
    std::cin.ignore();
    std::cout << "\n\nНажмите любую клавишу, чтобы продолжить...";
    std::cin.get();
}

int main()
{
    // std::cout << "1a):\n\n";

    // Point P(-1.53, 3.61);
    // Circle circle(1.3, 0.78, 4);

    // std::cout << "Мы имеем:\n";

    // P.print();
    // circle.print();

    // if (P.distTo(circle) - circle.getR() < eps)
    // {
    //     std::cout << "\nТочка лежит в окружности\n";
    // } 
    // else if (P.distTo(circle) - circle.getR() > eps)
    // {
    //     std::cout << "\n\nТочка не лежит в окружности\n";
    // } 

    // waitingForEnter();
    // clearConsole();

    // std::cout << "1б):\n\n";
    // Circle c1(4, 3.2, 5);
    // Circle c2(2, 4, 2);

    // double R1 = c1.getR();
    // double R2 = c2.getR();
    // double O1O2 = c1.distTo(c2);

    // std::cout << "Есть две окружности: \n";

    // c1.print();
    // c2.print();

    // if ((R1 + R2) + eps < O1O2) 
    // {
    //     std::cout <<  "\n\nЭти окружности не имеют общих точек и не лежат одна в другой.";
    // } 
    // else if (std::max(R1, R2) > O1O2 + std::min(R1, R2) + eps) {
    //     std::cout << "\n\nОкружность " << (R1 > R2 ? "2" : "1") << " лежит внутри "
    //               << (R1 > R2 ? "1" : "2") << ".";
    // } 
    // else if ((R1 + R2) > O1O2 + eps) {
    //     std::cout << "\n\nЭти окpужности пересекаются.";
    // }

    // waitingForEnter();
    
    // std::cout << "№2\n\n";

    // Point M(1, 4);
    // Line2D L(1, 1, 2, 2);
    // std::cout << "Точка M: " <<  M.toStr();
    // L.print();

    // Vector p(L.getX1() - L.getX1P2(), L.getX2() - L.getX2P2(), 0);
    // Vector P2M(M.getX1() - L.getX1P2(), M.getX2() - L.getX2P2());

    // double d = (crossProduct(p, P2M).getModule()) / (2 * p.getModule());

    // std::cout << "\n\nРасстояние d от точки M до прямой равно" << d;

    // std::cout << "№3\n\n";

    // VectorR2 v(1, 1);
    // double alphaDeg = 45;

    // v.print();
    
    // v.rotateAngle(alphaDeg);

    // std::cout << "\n\nПовернув на " << alphaDeg << " градусов, получим: ";

    // v.print();

    // std::cout << "№4\n\n";

    // VectorR3 v1(1, 1, 0);
    // VectorR3 v2(1, 1, 0);
    // VectorR3 v3(0, 0, 1);

    // std::cout << "У нас есть:\n";
    // v1.print(); std::cout << "\n";
    // v2.print(); std::cout << "\n";
    // v3.print(); std::cout << "\n";

    // std::cout << "\nЭти векторы " << (isBasis(v1, v2, v3) ? "" : "не ") << "образуют базис\n";

    std::cout << "№5\n\n";

    Line l1(1, 4, -2), l2(1, 4, -2), l3(1, 4, -2), l4(4, -1, 1);
    std::cout << "У нас есть: \n\n";
    
    l1.print(); std::cout << "\n";
    l4.print();
    std::cout << "\n\na) Параллельный перенос в направлении ";
    double a = 2, b = 1, dist = 3;

    std::cout << "(" << a << ", " << b << ") " << "на расстояни" << dist << " даст: \n";
    l1.transferParall(dist, a, b); l1.print();

    std::cout << "\n\nб) Поворот на угол  ";
    double alpha = 90;

    std::cout << alpha << " градусов даст: \n";
    l2.rotateAngle(alpha); l2.print();

    std::cout << "\n\nв) Угол между прямыми: " << getAngle(l3, l4) << " градусов.\n";

}