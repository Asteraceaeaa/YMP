#pragma once
#include <vector>


class Matrix {
public:
    /* Конструкторы */
    Matrix();
    Matrix(std::size_t rows, std::size_t cols);

    /* Операции с матрицами */

    double det() const;
    Matrix invert() const;
    Matrix transpose() const;

    /* Операторы */

    Matrix operator+(const Matrix& othr) const;
    Matrix operator-(const Matrix& othr) const ;
    Matrix operator*(const Matrix& othr) const;
    Matrix operator*(const double& scalar) const;

    Matrix& operator+=(const Matrix& othr);
    Matrix& operator-=(const Matrix& othr);
    Matrix& operator*=(const Matrix& othr);

    bool operator==(const Matrix& othr) const;
    bool operator!=(const Matrix& othr) const;


private:
    std::vector<std::vector<double>> data;
    size_t m_rows;
    size_t m_cols;

    /* Вспомогательные методы */
    void validateSameSize(const Matrix& othr) const;
    bool validateSameSizeBool(const Matrix& othr) const;
    void validateSizeMult(const Matrix& othr) const;
    Matrix algerbraicalAddition() const;
    Matrix getMinor(std::size_t row, std::size_t col) const;
};

Matrix operator*(const double& scalar, const Matrix& othr);
