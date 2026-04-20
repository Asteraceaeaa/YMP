#include "./include/Complex.h"
#include "./include/Vector.h"
#include "./include/Matrix.h"
#include <iostream>

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

void testComplex();

void testVector();


int main() 
{
    while (true) 
    {
        clearConsole();
        std::cout << "=============МЕНЮ=============\n\n";
        std::cout << "1. Complex\n2. Vector\n3. Matrix\n4. \n5. \n\n";
        std::cout << "Выберите, что будем тестировать(1-5) или введите -1: ";

        int enter;
        std::cin >> enter;

        if (enter == -1) { break; }

        switch (enter) {
            case 1: {
                testComplex();
                break;
            }
        
            case 2:
                testVector();
                break;
            case 3:
                std::cout << "Введите a и b через пробел, если z1 = a + ib";
                break;
                break;
            case 4:
                std::cout << "Введите a и b через пробел, если z1 = a + ib";
                break;
                break;
            case 5:
                std::cout << "Введите a и b через пробел, если z1 = a + ib";
                break;
                break;
            default:
                std::cout << "Непон, че за дела? Давай нормальный ввод";
                break;
        }
    }   
    return 0;

}

void testComplex()
{
    clearConsole();
    double a, b, x, y;

    std::cout << "Введите a и b через пробел, если z1 = a + ib: ";
    std::cin >> a >> b;
    std::cout << "Введите x и y через пробел, если z2 = x + iy: ";
    std::cin >> x >> y;

    Complex z1(a, b);
    Complex z2(x, y);

    std::cout << "\nz1 = " << z1.toString();
    std::cout << "\nz2 = " << z2.toString();

    std::cout << "\n\nz1 + z2 = " << (z1 + z2).toString();
    std::cout << "\nz1 - z2 = " << (z1 - z2).toString();
    std::cout << "\nz1 * z2 = " << (z1 * z2).toString();
    std::cout << "\nz1 / z2 = " << (z1 / z2).toString();

    waitingForEnter();
}

void testVector()
{
    clearConsole();
    double x1, y1, z1, x2, y2, z2;
    std::cout << "Введите координаты конца первого вектора через пробел: ";
    std::cin >> x1 >> y1 >> z1;
    std::cout << "Введите координаты конца первого вектора через пробел: ";
    std::cin >> x2 >> y2>> z2;

    Vector v1(x1, y1, z1), v2(x2, y2, z2);
    std::cout << "\nv1 = " << v1.toString();
    std::cout << "\nv2 = " << v2.toString();

    std::cout << "\n\nv1 + v2 = " << (v1 + v2).toString();
    std::cout << "\nv1 - v2 = " << (v1 - v2).toString();
    std::cout << "\n(v1, v2) = " << v1 * v2;
    std::cout << "\n[v1 x v2] = " << crossProduct(v1, v2).toString();
    std::cout << "\n|v1| = " << v1.getModule();
    std::cout << "\n|v2| = " << v1.getModule();
    std::cout << "\nCos(v1, v2) = " << getCos(v1, v2);

    waitingForEnter();
}