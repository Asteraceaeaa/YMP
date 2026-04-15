#include "Matrix.h"
#include <iostream>

/* Конструкторы */
Matrix::Matrix()
    : m_rows(0)
    , m_cols(0) {};
Matrix::Matrix(std::size_t rows, std::size_t cols)
    : m_rows(rows)
    , m_cols(cols) {
    if (rows == 0 || cols == 0) {
        throw std::invalid_argument("Size of matrix should be positive.");
    }
}

/* Вспомогательные методы */
void Matrix::validateSameSize(const Matrix& othr) const {
    if (othr.m_rows != m_rows || othr.m_cols != m_cols) {
        throw std::invalid_argument("Matrices should have same sizes.");
    }
}
void Matrix::validateSizeMult(const Matrix& othr) const {
    if (m_cols != othr.m_rows) {
        throw std::invalid_argument("Count of rows of A should be equal count of cols of B.");
    }
}
bool Matrix::validateSameSizeBool(const Matrix& othr) const {
    return (m_rows == othr.m_rows && m_cols == othr.m_cols);
}
Matrix Matrix::getMinor(std::size_t row, std::size_t col) const {
    Matrix res(m_rows - 1, m_cols - 1);
    for (std::size_t i = 0; i < m_rows; i++) {
        for (std::size_t j = 0; j < m_cols; j++) {
            if (i == row) {
                break;
            }

            if (j != col) {
                res.data[i][j] = data[i][j];
            }
        }
    }
}
/* Операции с матрицами */

/* Проверки типов матриц */

/* Операторы */
Matrix Matrix::operator+(const Matrix& othr) const {
    validateSameSize(othr);

    Matrix res(m_rows, m_cols);
    for (std::size_t i = 0; i < m_rows; i++) {
        for (std::size_t j = 0; j < m_cols; j++) {
            res.data[i][j] = data[i][j] + othr.data[i][j];
        }
    }

    return res;
}
Matrix Matrix::operator-(const Matrix& othr) const {
    validateSameSize(othr);

    Matrix res(m_rows, m_cols);
    for (std::size_t i = 0; i < m_rows; i++) {
        for (std::size_t j = 0; j < m_cols; j++) {
            res.data[i][j] = data[i][j] - othr.data[i][j];
        }
    }

    return res;
}
Matrix Matrix::operator*(const Matrix& othr) const {
    validateSizeMult(othr);

    Matrix res(m_rows, othr.m_cols);

    for (std::size_t i = 0; i < m_rows; i++) {
        for (std::size_t j = 0; j < othr.m_cols; j++) {
            double sum = 0.0;
            for (std::size_t k = 0; k < m_cols; k++) {
                sum += data[i][k] * othr.data[k][j];
            }
            res.data[i][j] = sum;
        }
    }

    return res;
}
Matrix Matrix::operator*(const double& scalar) const {
    Matrix res(m_rows, m_cols);

    for (std::size_t i = 0; i < m_rows; i++) {
        for (std::size_t j = 0; j < m_cols; j++) {
            res.data[i][j] = data[i][j] * scalar;
        }
    }

    return res;
}
Matrix operator*(const double& scalar, const Matrix& othr) {
    return othr * scalar;
}

Matrix& Matrix::operator+=(const Matrix& othr) {
    Matrix temp = *this + othr;
    *this = temp;
    return *this;
}
Matrix& Matrix::operator-=(const Matrix& othr) {
    Matrix temp = *this - othr;
    *this = temp;
    return *this;
}
Matrix& Matrix::operator*=(const Matrix& othr) {
    Matrix temp = *this * othr;
    *this = temp;
    return *this;
}

bool Matrix::operator==(const Matrix& othr) const {
    bool f = validateSameSizeBool(othr);
    for (std::size_t i = 0; i < m_rows && f; i++) {
        for (std::size_t j = 0; j < m_cols && f; j++) {
            f *= data[i][j] == othr.data[i][j];
        }
    }

    return f;
}
bool Matrix::operator!=(const Matrix& othr) const {
    bool f = validateSameSizeBool(othr);
    for (std::size_t i = 0; i < m_rows && f; i++) {
        for (std::size_t j = 0; j < m_cols && f; j++) {
            f *= data[i][j] != othr.data[i][j];
        }
    }

    return f;
}
