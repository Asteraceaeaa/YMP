#include "include/Point.h"
#include "include/Circle.h"
#include <iostream>

const double eps = 1e-12;

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

    std::cout << "1a):\n\n";

    Point P(0.34, 0.32);
    Circle circle(1.3, 0.78, 1);

    std::cout << "Мы имеем:\n";

    P.print();
    circle.print();

    if (P.distTo(circle) - circle.getR() < eps)
    {
        std::cout << "\nТочка лежит в окружности\n";
    } 
    else if (P.distTo(circle) - circle.getR() > eps)
    {
        std::cout << "\nТочка не лежит в окружности\n";
    } 
    else
    {
        std::cout << "\nТочка лежит на окружности\n";
    }

    waitingForEnter();
    clearConsole();

    Circle c1(4, 3.2, 5);
    Circle c2(2, 7.4, 2);

    


    return 0;
}