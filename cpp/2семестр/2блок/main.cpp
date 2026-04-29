#include "./include/Complex.h"
#include "./include/Vector.h"
#include "./include/Matrix.h"
#include <iostream>
#include <fstream>

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

void testMatrix();

void autotestMatrix();

void manualtestMatrix();
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
            case 1:
                testComplex();
                break;      
            case 2:
                testVector();
                break;
            case 3:
                testMatrix();
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

void testMatrix()
{
    clearConsole();
    while (true) 
    {

        std::cout << "Доступные режимы:\n\n";
        std::cout << "1. Автотесты\n2. Ручные тесты\n\n";
        std::cout << "Выберите режим или -1 для выхода: ";
        
        int ch;
        std::cin >> ch;
        if (ch == -1) { break; }

        switch(ch)
        {
            case 1:
                autotestMatrix();
                break;
            case 2:
                manualtestMatrix();
                break;
            default:
                std::cout << "Непон, че за дела? Давай нормальный ввод";
                break;
        }

        waitingForEnter();
    }
    waitingForEnter();
    clearConsole();
}

void autotestMatrix()
{
    clearConsole();
    std::vector<Matrix> matrices;
    int r, c, ch;

    std::ifstream f("./tests/sf.txt");
    std::istream& fi = f;

    while (f >> r >> c) 
    {
        Matrix m(r, c);
        fi >> m;
        matrices.push_back(m);
    }    

    while (true)
    {

        std::cout << "Доступные тесты: \n\n";
        std::cout << "1. Тест на типы матриц.\n2. Тесты на выполнение бинарных операций.\n3. Тесты на "
                    "выполнение унарных операций.\n";
        std::cout << "\nВыберите тест или введите -1 для выхода: \n\n\n";

        std::cin >> ch;

        if (ch == -1) { break; }

        switch (ch)
        {
            case 1:

                while (true) {
                    clearConsole();
                    std::cout << "Матрицы для проверки: \n\n";
                    int inp, n = 1;
                    for (Matrix m : matrices) {
                        std::cout << "Матрица №" << n++ << ":" << std::endl << m << std::endl;
                    }

                    std::cout << "Введите номер матрицы для проверки или -1 для выхода: ";
                    std::cin >> inp;

                    if (inp == -1) {
                        break;
                    }

                    if (inp >= n) {
                        std::cout << "\nНепон, че за дела? Давай нормальный ввод\n";
                        waitingForEnter();
                        continue;
                    }

                    clearConsole();
                    std::cout << "\nВыбранная матрица:\n" << matrices[inp - 1] << std::endl << std::endl;
                    matrices[inp - 1].autotestSingle();

                    waitingForEnter();
                    clearConsole();
                }
                clearConsole();
                break;
            case 2:
                while (true) 
                {
                    std::cout << "Матрицы для проверки: \n\n";
                    int inp, n = 1;
                    for (Matrix m : matrices) 
                    {
                        std::cout << "Матрица №" << n++ << ":" << std::endl << m << std::endl;
                    }

                    std::cout << "Введите номер первой матрицы (A) или -1 для выхода: ";
                    std::cin >> inp;

                    if (inp == -1) {
                        break;
                    }

                    if (inp >= n) {
                        std::cout << "\nНепон, че за дела? Давай нормальный ввод\n";
                        waitingForEnter();
                        continue;
                    }
                    
                    Matrix A = matrices[inp - 1];
                    std::cout << "Введите номер второй матрицы (B) или -1 для выхода: ";
                    std::cin >> inp;

                    if (inp == -1) {
                        break;
                    }

                    if (inp >= n) {
                        std::cout << "\nНепон, че за дела? Давай нормальный ввод\n";
                        waitingForEnter();
                        continue;
                    }

                    Matrix B = matrices[inp - 1];

                    Matrix tmp_A = A, tmp_B = B, C;

                    clearConsole();
                    std::cout << "\nВыбранные матрицы:\n"
                              << "A:\n\n"
                              << A << std::endl
                              << "B:\n\n"
                              << B << std::endl;

                    try {
                        C = A + B;
                        std::cout << "A + B:\n" << C;
                        tmp_A += tmp_B;
                        std::cout << "A += B => A:\n" << tmp_A;
                        tmp_A = A;
                        C = A - B;
                        std::cout << "A - B:\n" << C;
                        tmp_A -= tmp_B;
                        std::cout << "A -= B => A:\n" << tmp_A;
                        tmp_A = A;
                    } catch (const std::exception& e) {
                        std::cerr << "Error: " << e.what() << std::endl;
                    }

                    try {
                        C = A * B;
                        std::cout << "A * B:\n" << C;
                        tmp_A *= tmp_B;
                        std::cout << "A *= B => A:\n" << tmp_A;
                        tmp_A = A;
                    } catch (const std::exception& e) {
                        std::cerr << "Error: " << e.what() << std::endl;
                    }

                    std::cout << "\nA == B: " << (A == B);
                    std::cout << "\nA != B: " << (A != B);

                    waitingForEnter();
                    clearConsole();
                }
                break;
            case 3:

                while (true) {
                    clearConsole();
                    std::cout << "Матрицы для проверки: \n\n";
                    int inp, n = 1;
                    for (Matrix m : matrices) {
                        std::cout << "Матрица №" << n++ << ":" << std::endl << m << std::endl;
                    }

                    std::cout << "Введите номер матрицы (M) для проверки или -1 для выхода: ";
                    std::cin >> inp;

                    if (inp == -1) { break; }

                    if (inp >= n) 
                    {
                        std::cout << "\nНепон, че за дела? Давай нормальный ввод\n";
                        waitingForEnter();
                        continue;
                    }

                    Matrix M = matrices[inp - 1];
                    clearConsole();
                    std::cout << "\nВыбранная матрица:\n"
                              << M << std::endl
                              << std::endl;

                    std::cout << "M транспонированная:\n\n" << M.transpose() << std::endl;

                    try {
                        std::cout << "det(M) = " << M.det() << std::endl;
                        std::cout << "\nM^(-1):\n" << M.invert() << std::endl;
                    } catch (const std::exception& e) {
                        std::cerr << "Error: " << e.what() << std::endl;
                    }
                    waitingForEnter();
                    clearConsole();
                }
                clearConsole();
                break;
        
            default:
                std::cout << "Непон, че за дела? Давай нормальный ввод";
                break;
        }
    }
    waitingForEnter();
    clearConsole();
}

void manualtestMatrix()
{
    std::cout << "\nComing soon...\n";
}