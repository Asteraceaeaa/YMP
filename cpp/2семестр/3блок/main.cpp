#include "include/1/Point.h"
#include "include/1/Circle.h"
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
    return 0;
}