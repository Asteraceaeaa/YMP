#include "./include/Complex.h"
#include "./include/Matrix.h"
#include "./include/Polynom.h"
#include "./include/Triangle.h"
#include "./include/Vector.h"
#include <fstream>
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#define CLEAR "cls"
#else
#include <unistd.h>
#define CLEAR "clear"
#endif

void clearConsole() {
    std::system(CLEAR);
}

void waitingForEnter() {
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

void testPolynom();

void testTriangle();

int main() {
    Polynom a(3, 1), b(6, -2.2);
    std::cout << (a - b) << std::endl;
    std::cout << (a + b) << std::endl;
    std::cout << (a * b) << std::endl;

    while (true) {
        clearConsole();
        std::cout << "=============МЕНЮ=============\n\n";
        std::cout << "1. Complex\n2. Vector\n3. Matrix\n4. Polynom\n5. Triangle\n\n";
        std::cout << "Выберите, что будем тестировать(1-5) или введите -1: ";

        int enter;
        std::cin >> enter;

        if (enter == -1) {
            break;
        }

        switch (enter) {
            case 1:
                testComplex();
                break;
            case 2:
                testVector();
                break;
            case 3:
                std::noshowpos(std::cout);
                testMatrix();
                break;
            case 4:
                testPolynom();
                break;
            case 5:
                testTriangle();
                break;
            default:
                std::cout << "Непон, че за дела? Давай нормальный ввод";
                break;
        }
    }
    return 0;
}

void testComplex() {
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

void testVector() {
    clearConsole();
    double x1, y1, z1, x2, y2, z2;
    std::cout << "Введите координаты конца первого вектора через пробел: ";
    std::cin >> x1 >> y1 >> z1;
    std::cout << "Введите координаты конца первого вектора через пробел: ";
    std::cin >> x2 >> y2 >> z2;

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

void testMatrix() {
    clearConsole();
    while (true) {
        std::cout << "Доступные режимы:\n\n";
        std::cout << "1. Автотесты\n2. Ручные тесты\n\n";
        std::cout << "Выберите режим или -1 для выхода: ";

        int ch;
        std::cin >> ch;
        if (ch == -1) {
            break;
        }

        switch (ch) {
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
    }
    waitingForEnter();
    clearConsole();
}

void autotestMatrix() {
    clearConsole();
    std::vector<Matrix> matrices;
    int r, c, ch;

    std::ifstream f("./tests/sf.txt");
    std::istream& fi = f;

    while (f >> r >> c) {
        Matrix m(r, c);
        fi >> m;
        matrices.push_back(m);
    }

    while (true) {
        std::cout << "===Режим автоматического тестирования===\n";
        std::cout << "Доступные тесты: \n\n";
        std::cout
            << "1. Тест на типы матриц.\n2. Тесты на выполнение бинарных операций.\n3. Тесты на "
               "выполнение унарных операций.\n";
        std::cout << "\nВыберите тест или введите -1 для выхода: \n\n\n";

        std::cin >> ch;

        if (ch == -1) {
            break;
        }

        switch (ch) {
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
                        clearConsole();
                        break;
                    }

                    if (inp >= n) {
                        std::cout << "\nНепон, че за дела? Давай нормальный ввод\n";
                        waitingForEnter();
                        continue;
                    }

                    clearConsole();
                    std::cout << "\nВыбранная матрица:\n"
                              << matrices[inp - 1] << std::endl
                              << std::endl;
                    matrices[inp - 1].autotestSingle();

                    waitingForEnter();
                    clearConsole();
                }
                clearConsole();
                break;
            case 2:
                while (true) {
                    std::cout << "Матрицы для проверки: \n\n";
                    int inp, n = 1;
                    for (Matrix m : matrices) {
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

                    if (inp == -1) {
                        break;
                    }

                    if (inp >= n) {
                        std::cout << "\nНепон, че за дела? Давай нормальный ввод\n";
                        waitingForEnter();
                        continue;
                    }

                    Matrix M = matrices[inp - 1];
                    clearConsole();
                    std::cout << "\nВыбранная матрица:\n" << M << std::endl << std::endl;

                    std::cout << "M транспонированная:\n\n" << M.transpose() << std::endl;

                    try {
                        Matrix M_inv = M.invert();
                        std::cout << "det(M) = " << M.det() << std::endl;
                        std::cout << "\nM^(-1):\n" << M_inv << std::endl;
                        std::cout << "\nM*M^-1:\n";
                        std::cout << M_inv * M;
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
void manualtestMatrix() {
    while (true) {
        clearConsole();
        std::cout << "===Режим ручного тестирования===\n\n";
        std::cout << "Доступные тесты: \n\n";
        std::cout
            << "1. Тест на типы матриц.\n2. Тесты на выполнение бинарных операций.\n3. Тесты на "
               "выполнение унарных операций.\n";
        std::cout << "\nВыберите тест или введите -1 для выхода: \n\n\n";
        int ch;
        std::cin >> ch;

        if (ch == -1) {
            break;
        }

        switch (ch) {
            case 1: {
                while (true) {
                    clearConsole();
                    int r, c;
                    Matrix A;
                    std::cout << "Введите размеры матрицы: ";
                    try {
                        std::cin >> r >> c;
                        A.resize(r, c);
                        std::cout << "\n\nВведите матрицу A построчно:\n";
                        std::cin >> A;
                    } catch (const std::exception& e) {
                        std::cerr << "Error: " << e.what() << std::endl;
                        waitingForEnter();
                        continue;
                    }

                    std::cout << "Введенная матрица A:\n";
                    std::cout << A;
                    waitingForEnter();

                    // Внутренний цикл для проверки типов
                    while (true) {
                        clearConsole();
                        int ch1;

                        std::cout << "Что нужно проверить?\n\n";
                        std::cout << "1. Квадратная\n2. Диагональная\n3. Нулевая\n4. Единичная\n5. "
                                     "Симметричная\n6. Верхняя треугольная\n7. Нижняя "
                                     "треугольная\n\n8. Показать матрицу";
                        std::cout << "\n\nВыберите пункт (1–8) или введите -1 для выхода: ";
                        std::cin >> ch1;

                        if (ch1 == -1) {
                            break;
                        }

                        switch (ch1) {
                            case 1: {
                                std::cout << "Данная матрица:\n";
                                std::cout << A << std::endl;
                                std::cout << (A.isSquare() ? "" : "не ") << "квадратная\n";
                                waitingForEnter();
                                break;
                            }
                            case 2: {
                                std::cout << "Данная матрица:\n";
                                std::cout << A << std::endl;
                                std::cout << (A.isDiagonal() ? "" : "не ") << "диагональная\n";
                                waitingForEnter();
                                break;
                            }
                            case 3: {
                                std::cout << "Данная матрица:\n";
                                std::cout << A << std::endl;
                                std::cout << (A.isZero() ? "" : "не ") << "нулевая\n";
                                waitingForEnter();
                                break;
                            }
                            case 4: {
                                std::cout << "Данная матрица:\n";
                                std::cout << A << std::endl;
                                std::cout << (A.isIdentity() ? "" : "не ") << "единичная\n";
                                waitingForEnter();
                                break;
                            }
                            case 5: {
                                std::cout << "Данная матрица:\n";
                                std::cout << A << std::endl;
                                std::cout << (A.isSymmetrical() ? "" : "не ") << "симметричная\n";
                                waitingForEnter();
                                break;
                            }
                            case 6: {
                                std::cout << "Данная матрица:\n";
                                std::cout << A << std::endl;
                                std::cout << (A.isUpTriangle() ? "" : "не ")
                                          << "верхняя треугольная\n";
                                waitingForEnter();
                                break;
                            }
                            case 7: {
                                std::cout << "Данная матрица:\n";
                                std::cout << A << std::endl;
                                std::cout << (A.isDownTriangle() ? "" : "не ")
                                          << "нижняя треугольная\n";
                                waitingForEnter();
                                break;
                            }
                            case 8: {
                                std::cout << "Текущая матрица:\n" << A << "\n";
                                waitingForEnter();
                                break;
                            }
                            default: {
                                std::cout << "Неверный выбор. Пожалуйста, введите число от 1 до 8 "
                                             "или -1 для выхода.\n";
                                waitingForEnter();
                                break;
                            }
                        }
                    }
                }
                waitingForEnter();
                clearConsole();
                break;
            }

            case 2: {
                // Binary operations test
                while (true) {
                    clearConsole();
                    int r1, c1, r2, c2;
                    Matrix A, B;

                    std::cout << "===Тестирование бинарных операций===\n\n";

                    std::cout << "Введите размеры первой матрицы (A): ";
                    try {
                        std::cin >> r1 >> c1;
                        A.resize(r1, c1);
                        std::cout << "\nВведите матрицу A построчно:\n";
                        std::cin >> A;
                    } catch (const std::exception& e) {
                        std::cerr << "Error: " << e.what() << std::endl;
                        waitingForEnter();
                        continue;
                    }

                    std::cout << "\nВведите размеры второй матрицы (B): ";
                    try {
                        std::cin >> r2 >> c2;
                        B.resize(r2, c2);
                        std::cout << "\nВведите матрицу B построчно:\n";
                        std::cin >> B;
                    } catch (const std::exception& e) {
                        std::cerr << "Error: " << e.what() << std::endl;
                        waitingForEnter();
                        continue;
                    }

                    clearConsole();
                    std::cout << "Введенные матрицы:\n";
                    std::cout << "A:\n" << A << std::endl;
                    std::cout << "B:\n" << B << std::endl;

                    std::cout << "\nКакие операции проверить?\n";
                    std::cout << "1. Сложение (A + B и A += B)\n";
                    std::cout << "2. Вычитание (A - B и A -= B)\n";
                    std::cout << "3. Умножение (A * B и A *= B)\n";
                    std::cout << "4. Сравнение (A == B и A != B)\n";
                    std::cout << "\nВыберите операцию (1-4) или -1 для выхода: ";

                    int ch2;
                    std::cin >> ch2;

                    if (ch2 == -1)
                        break;

                    Matrix tmp_A = A, tmp_B = B, C;

                    switch (ch2) {
                        case 1: {
                            std::cout << "\n===Сложение===\n";
                            try {
                                C = A + B;
                                std::cout << "A + B:\n" << C;
                                tmp_A += tmp_B;
                                std::cout << "A += B => A:\n" << tmp_A;
                            } catch (const std::exception& e) {
                                std::cerr << "Error: " << e.what() << std::endl;
                            }
                            break;
                        }
                        case 2: {
                            std::cout << "\n===Вычитание===\n";
                            try {
                                C = A - B;
                                std::cout << "A - B:\n" << C;
                                tmp_A -= tmp_B;
                                std::cout << "A -= B => A:\n" << tmp_A;
                            } catch (const std::exception& e) {
                                std::cerr << "Error: " << e.what() << std::endl;
                            }
                            break;
                        }
                        case 3: {
                            std::cout << "\n===Умножение===\n";
                            try {
                                C = A * B;
                                std::cout << "A * B:\n" << C;
                                tmp_A *= tmp_B;
                                std::cout << "A *= B => A:\n" << tmp_A;
                            } catch (const std::exception& e) {
                                std::cerr << "Error: " << e.what() << std::endl;
                            }
                            break;
                        }
                        case 4: {
                            std::cout << "\n===Сравнение===\n";
                            std::cout << "A == B: " << (A == B) << std::endl;
                            std::cout << "A != B: " << (A != B) << std::endl;
                            break;
                        }
                        default: {
                            std::cout << "Непон, че за дела? Давай нормальный ввод\n";
                            break;
                        }
                    }

                    waitingForEnter();
                }
                waitingForEnter();
                clearConsole();
                break;
            }

            case 3: {
                // Unary operations test
                while (true) {
                    clearConsole();
                    int r, c;
                    Matrix M;

                    std::cout << "===Тестирование унарных операций===\n\n";

                    std::cout << "Введите размеры матрицы: ";
                    try {
                        std::cin >> r >> c;
                        M.resize(r, c);
                        std::cout << "\nВведите матрицу M построчно:\n";
                        std::cin >> M;
                    } catch (const std::exception& e) {
                        std::cerr << "Error: " << e.what() << std::endl;
                        waitingForEnter();
                        continue;
                    }

                    clearConsole();
                    std::cout << "Введенная матрица:\n" << M << std::endl;

                    std::cout << "\nКакие операции проверить?\n";
                    std::cout << "1. Транспонирование\n";
                    std::cout << "2. Определитель\n";
                    std::cout << "3. Обратная матрица\n";
                    std::cout << "\nВыберите операцию (1-3) или -1 для выхода: ";

                    int ch3;
                    std::cin >> ch3;

                    if (ch3 == -1)
                        break;

                    switch (ch3) {
                        case 1: {
                            std::cout << "\n===Транспонирование===\n";
                            std::cout << "M транспонированная:\n" << M.transpose() << std::endl;
                            break;
                        }
                        case 2: {
                            std::cout << "\n===Определитель===\n";
                            try {
                                std::cout << "det(M) = " << M.det() << std::endl;
                            } catch (const std::exception& e) {
                                std::cerr << "Error: " << e.what() << std::endl;
                            }
                            break;
                        }
                        case 3: {
                            std::cout << "\n===Обратная матрица===\n";
                            try {
                                std::cout << "M^(-1):\n" << M.invert() << std::endl;
                            } catch (const std::exception& e) {
                                std::cerr << "Error: " << e.what() << std::endl;
                            }
                            break;
                        }
                        default: {
                            std::cout << "Непон, че за дела? Давай нормальный ввод\n";
                            break;
                        }
                    }

                    waitingForEnter();
                }
                waitingForEnter();
                clearConsole();
                break;
            }

            default:
                std::cout << "Непон, че за дела? Давай нормальный ввод";
                waitingForEnter();
                break;
        }
    }
    waitingForEnter();
    clearConsole();
}

void testPolynom() {
    clearConsole();

    int n1, n2;

    std::cout << "Введите степень n первого многочлена: ";
    std::cin >> n1;

    Polynom p1(n1);
    std::cout << "Введите коэффициенты первого многочлена в строку, начиная со старшей степени:\n";
    std::cin >> p1;

    std::cin.ignore(100, '\n');

    std::cout << "Введите степень n второго многочлена: ";
    std::cin >> n2;

    Polynom p2(n2);
    std::cout << "Введите коэффициентs второго многочлена в строку, начиная со страшей степени:\n";
    std::cin >> p2;

    std::cin.ignore(100, '\n');

    Polynom p_sum = p1 + p2;
    Polynom p_diff = p1 - p2;
    Polynom p_mult = p1 * p2;

    while (true) {
        clearConsole();
        int op1 = 0;
        std::cout << "======МНОГОЧЛЕНЫ======\n\n";

        std::cout << "1. Найти сумму\n";
        std::cout << "2. Найти разность\n";
        std::cout << "3. Найти произведение\n";
        std::cout << "4. Найти значение многочлена для заданного аргумента\n\n";

        std::cout << "Выберите операцию или введите -1 для выхода: ";
        std::cin >> op1;

        if (op1 == -1) {
            break;
        }
        clearConsole();
        switch (op1) {
            case 1:

                std::cout << "p1 = " << p1 << std::endl;
                std::cout << "p2 = " << p2 << std::endl;

                std::cout << "p1 + p2 = " << p_sum;

                waitingForEnter();
                break;
            case 2:

                std::cout << "p1 = " << p1 << std::endl;
                std::cout << "p2 = " << p2 << std::endl;

                std::cout << "p1 - p2 = " << p_diff;

                waitingForEnter();
                break;
            case 3:

                std::cout << "p1 = " << p1 << std::endl;
                std::cout << "p2 = " << p2 << std::endl;

                std::cout << "p1 * p2 = " << p_mult;

                waitingForEnter();
                break;
            case 4:

                while (true) {
                    clearConsole();

                    double c;
                    int num;

                    std::cout << "Доступные многочлены:\n\n";

                    std::cout << "1. p1 = " << p1 << std::endl;
                    std::cout << "2. p2 = " << p2 << std::endl;
                    std::cout << "3. p1 + p2 = " << p_sum << std::endl;
                    std::cout << "4. p1 - p2 = " << p_diff << std::endl;
                    std::cout << "5. p1 * p2 = " << p_mult << std::endl << std::endl;

                    std::cout << "Выберите многочлен или введите -1 для выхода: ";
                    std::cin >> num;

                    if (num == -1) {
                        break;
                    }
                    clearConsole();
                    switch (num) {
                        case 1:
                            std::cout << "Введите аргумент c: ";
                            std::cin >> c;

                            std::cout << "\np1 = " << p1 << std::endl;
                            std::noshowpos(std::cout);
                            std::cout << "p1(" << c << ") = " << p1(c);
                            waitingForEnter();
                            break;
                        case 2:
                            std::cout << "Введите аргумент c: ";
                            std::cin >> c;

                            std::cout << "\np2 = " << p2 << std::endl;
                            std::noshowpos(std::cout);
                            std::cout << "p2(" << c << ") = " << p2(c);
                            waitingForEnter();
                            break;

                        case 3:
                            std::cout << "Введите аргумент c: ";
                            std::cin >> c;

                            std::cout << "\np1 + p2 = " << p_sum << std::endl;
                            std::noshowpos(std::cout);
                            std::cout << "p_sum(" << c << ") = " << p_sum(c);
                            waitingForEnter();
                            break;
                        case 4:
                            std::cout << "Введите аргумент c: ";
                            std::cin >> c;

                            std::cout << "\np1 - p2 = " << p_diff << std::endl;
                            std::noshowpos(std::cout);
                            std::cout << "p_diff(" << c << ") = " << p_diff(c);
                            waitingForEnter();
                            break;
                        case 5:
                            std::cout << "Введите аргумент: ";
                            std::cin >> c;

                            std::cout << "\np1 * p2 = " << p_mult << std::endl;
                            std::noshowpos(std::cout);
                            std::cout << "\np_mult(" << c << ") = " << p_mult(c);
                            waitingForEnter();
                            break;
                        default:
                            break;
                    }

                    break;
                    default:
                        break;
                }
        }
    }
    waitingForEnter();
    clearConsole();
}

void testTriangle()
{
    std::noshowpos(std::cout);


    while (true)
    {
        clearConsole();

        std::cout << "=====Тестирование класса Треугольник на плоскости=====\n\n";

        std::cout << "1. Переместить треугольник.\n";
        std::cout << "2. Сравнить треугольники через отношение площадейю\n";
        std::cout << "3. Определить тип отношения.\n";
        std::cout << "4. Отыскать треугольник с максмальной площадью.\n\n";

        std::cout << "Выберите действие или нвберите -1 для выхода: ";

        int n;
        std::cin >> n;

        if (n == -1) {
            break;
        }

        switch (n)
        {
            case 1:
            {
                clearConsole();

                Triangle t;
                std::cout << "Введите координаты вершин в строку через пробел:\n";
                std::cin >> t;

                std::cout << "Введенные вершины:\n";
                std::cout << t;

                std::cout << "\n\nВыберите смещение по x и по y:\n";
                double x, y;
                std::cin >> x >> y;
                t.relocate(x, y);

                std::cout << "Вершины смещенного треугольника:\n";
                std::cout << t;

                waitingForEnter();
                break;
            }
            case 2:
            {
                clearConsole();

                Triangle t1;
                std::cout << "Введите координаты вершин t1 в строку через пробел:\n";
                std::cin >> t1;  // 0.2 0.2 0.8 0.2 0.5 0.8

                std::cout << "Введенные вершины:\n";
                std::cout << t1;


                Triangle t2;
                std::cout << "\nВведите координаты вершин t2 в строку через пробел:\n";
                std::cin >> t2; // 0.3 0.25 0.5 0.3 0.5 0.6
                                // 0.3 0.25 0.9 0.5 0.5 0.6
                std::cout << "Введенные вершины:\n";
                std::cout << t2;

                bool greater7 = (t1 > t2);
                 std::cout << "\n\nt1 " << (greater7 ? "больше" : "меньше") << " t2";

                waitingForEnter();
                break;
            }
            case 3:
            {
                clearConsole();

                Triangle t1;
                std::cout << "Введите координаты вершин t1 в строку через пробел:\n";
                std::cin >> t1;  // 0.2 0.2 0.8 0.2 0.5 0.8

                std::cout << "Введенные вершины:\n";
                std::cout << t1;

                Triangle t2;
                std::cout << "\nВведите координаты вершин t2 в строку через пробел:\n";
                std::cin >> t2;  // 0.3 0.25 0.5 0.3 0.5 0.6
                                 // 0.3 0.25 0.9 0.5 0.5 0.6

                std::cout << "Введенные вершины:\n";
                std::cout << t2;

                bool include7 = t1.includes(t2);
                std::cout << "\n\nt2 " << (include7 ? "входит" : "не входит") << " в t1";

                waitingForEnter();
                break;
            }
            case 4:
            {
                clearConsole();

                Triangle triangles[] = {Triangle(0.2, 0.2, 0.8, 0.2, 0.5, 0.8),
                                        Triangle(0.3, 0.25, 0.5, 0.3, 0.5, 0.6),
                                        Triangle(0.3, 0.25, 0.9, 0.5, 0.5, 0.6)};

                std::cout << "Для треугольников с веришнами";

                double maxArea = 0;
                int maxI = 0;
                for (int i = 0; i < 3; i++) 
                {
                    std::cout << "\n" << triangles[i];
                    double area = triangles[i].getArea();
                    if (maxArea < area) { maxArea = area; maxI = i; }
                }

                std::cout << "\nМаксимальная площадь равна " << maxArea << " у треугольника с вершинами\n" << triangles[maxI];
                waitingForEnter();
                break;
            }
            default:
            {
                clearConsole();

                std::cout << "Нормальный ввод пжпж.";
                waitingForEnter();
            }
                
        }

    }
    waitingForEnter();
    clearConsole();
}