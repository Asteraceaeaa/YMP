#pragma once
#include <iostream>
#include <vector>

class Matrix {
public:
    /* Конструкторы */
    Matrix();
    Matrix(std::size_t rows, std::size_t cols, double InitValue = 0.0);

    void resize(std::size_t r, std::size_t c);

    /* Операции с матрицами */

    double det() const;
    Matrix invert() const;
    Matrix transpose() const;

    Matrix algebraicalAddition() const;
    Matrix getMinor(std::size_t row, std::size_t col) const;

    /* Проверки типов матриц */

    bool isSquare() const;
    bool isDiagonal() const;
    bool isZero() const;
    bool isIdentity() const;
    bool isSymmetrical() const;
    bool isUpTriangle() const;
    bool isDownTriangle() const;

    /* Операторы */

    Matrix operator+(const Matrix& othr) const;
    Matrix operator-(const Matrix& othr) const ;
    Matrix operator*(const Matrix& othr) const;
    Matrix operator*(const double& scalar) const;

    Matrix& operator+=(const Matrix& othr);
    Matrix& operator-=(const Matrix& othr);
    Matrix& operator*=(const Matrix& othr);
    Matrix& operator*=(const double& alpha);
    bool operator==(const Matrix& othr) const;
    bool operator!=(const Matrix& othr) const;

    friend std::ostream& operator<<(std::ostream& os, const Matrix& m);
    friend std::istream& operator>>(std::istream& is, Matrix& m);

    Matrix& operator=(const Matrix& othr);
    /* Вспомогательные методы */

    void autotestSingle();
    void defEl(const std::size_t& r, const std::size_t& c, const double& alpha);
private:
    std::vector<std::vector<double>> data;
    size_t m_rows;
    size_t m_cols;

    /* Вспомогательные методы */
    void validateSameSize(const Matrix& othr) const;
    bool validateSameSizeBool(const Matrix& othr) const;
    void validateSizeMult(const Matrix& othr) const;

};

Matrix operator*(const double& scalar, const Matrix& othr);
std::ostream& operator<<(std::ostream& os, const Matrix& m);
std::istream& operator>>(std::istream& is, Matrix& m);
