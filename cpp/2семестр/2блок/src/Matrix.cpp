#include "Matrix.h"
#include <iomanip>
#include <iostream>
#include <cmath>

const double eps = 1e-12;

/* Конструкторы */
Matrix::Matrix()
    : m_rows(0)
    , m_cols(0)
    , data() {};

Matrix::Matrix(std::size_t rows, std::size_t cols, double init)
    : m_rows(rows)
    , m_cols(cols)
    , data() 
{
    if (rows == 0 || cols == 0) {
        throw std::invalid_argument("Size of matrix must be positive.");
    }

    data.resize(rows, std::vector<double>(cols, init));
}

/* Вспомогательные методы */

void Matrix::resize(std::size_t r, std::size_t c)
{
    m_rows = r; m_cols = c;
    data.resize(r);

    for (auto& row : data) { row.resize(c); }
}

void Matrix::autotestSingle()
{

    std::cout << "Даная матрица:\n";
    std::cout << (isSquare() ? "" : "не ") << "квадратная\n";
    std::cout << (isDiagonal() ? "" : "не ") << "диагональная\n";
    std::cout << (isZero() ? "" : "не ") << "нулевая\n";
    std::cout << (isIdentity() ? "" : "не ") << "единичная\n";
    std::cout << (isSymmetrical() ? "" : "не ") << "симметричная\n";
    std::cout << (isUpTriangle() ? "" : "не ") << "верхняя треугольная\n";
    std::cout << (isDownTriangle() ? "" : "не ") << "нижняя треугольная\n";
    
}

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
    if (col >= m_cols || row >= m_rows) {
        throw std::invalid_argument("Row or col out of range.");
    }

    if (m_cols == 1 || m_rows == 1) {
        throw std::logic_error("Cannot get minor for matrix 1x1.");
    }

    Matrix res(m_rows - 1, m_cols - 1);
    std::size_t cur_row = 0;

    for (std::size_t i = 0; i < m_rows; i++) {
        std::size_t cur_col = 0;
        if (i == row)
            continue;

        for (std::size_t j = 0; j < m_cols; j++) {
            if (j == col)
                continue;
            res.data[cur_row][cur_col] = data[i][j];
            cur_col++;
        }

        cur_row++;
    }

    return res;
}
Matrix Matrix::algebraicalAddition() const
{
    Matrix res(m_rows, m_cols);

    for (std::size_t i = 0; i < m_rows; i++)
    {
        for (std::size_t j = 0; j < m_cols; j++)
        {
            res.data[i][j] = std::pow(-1, i+j) * getMinor(i, j).det();
        }
    }

    return res;
}

/* Операции с матрицами */

double Matrix::det() const
{   
    if (!isSquare()) { throw std::logic_error("Matrix must by square.");}
    if (m_rows == 1) return data[0][0];
    if (m_rows == 2) return data[0][0] * data[1][1] - data[0][1] * data [1][0];
    double d = 0;

    for (size_t i = 0; i < m_cols; i++)
    {
        Matrix minor = getMinor(0, i);
        d += std::pow(-1, i) * data[0][i] * minor.det();
    }

    return d;
}

Matrix Matrix::transpose() const
{
    Matrix res(m_cols, m_rows);

    for (std::size_t i = 0; i < m_rows; i++) 
    {
        for (std::size_t j = 0; j < m_cols; j++)
        {
            res.data[j][i] = data[i][j];
        }
    }

    return res;
}

Matrix Matrix::invert() const
{
    if (!isSquare()) { throw std::logic_error("Matrix must be square."); }
    double d = det();
    if (std::abs(d) < eps) { throw std::invalid_argument("Matrix have zero determinant."); }

    return algebraicalAddition().transpose() * (1 / d);
}

/* Проверки типов матриц */

bool Matrix::isSquare() const
{
    return m_rows == m_cols;
}
bool Matrix::isDiagonal() const
{
    if (!isSquare()) return false;

    for (std::size_t i = 0; i < m_rows; i++)
    {
        for (std::size_t j = 0; j < m_cols; j++)
        {
            if (i != j && std::abs(data[i][j]) > eps) return false;
        }
    }

    return true;
}
bool Matrix::isZero() const
{

    for (std::size_t i = 0; i < m_rows; i++)
    {
        for (std::size_t j = 0; j < m_cols; j++)
        {
            if (std::abs(data[i][j]) > eps) return false;
        }
    }

    return true;
}

bool Matrix::isIdentity() const 
{
    if (!isDiagonal()) return false;

    for (std::size_t i = 0; i < m_rows; i++)
    {
        if (std::abs(data[i][i] - 1.0) > eps)
            return false;
    }

    return true;
}
bool Matrix::isSymmetrical() const
{
    if (!isSquare()) return false;
    Matrix transposed = transpose();
    return transposed == *(this);
}
bool Matrix::isUpTriangle() const
{
    if (!isSquare()) { return false; }

    for (std::size_t i = 1; i < m_rows; i++) {
        for (std::size_t j = 0; j < i; j++) {
            if (std::abs(data[i][j]) > eps) {
                return false;
            }
        }
    }
 
    return true;
}
bool Matrix::isDownTriangle() const
{
    if (!isSquare()) { return false; }

    for (std::size_t i = 0; i < m_rows - 1; i++) 
    {
        for (std::size_t j = 1 + i; j < m_cols; j++) 
        {
            if (std::abs(data[i][j]) > eps) return false;
        }
    }

    return true;
}

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

Matrix& Matrix::operator*=(const double& alpha) {
    Matrix temp = *this * alpha;
    *this = temp;
    return *this;
}

bool Matrix::operator==(const Matrix& othr) const {
    if (!validateSameSizeBool(othr)) {
        return false;
    }

    for (std::size_t i = 0; i < m_rows; ++i) {
        for (std::size_t j = 0; j < m_cols; ++j) {
            if (data[i][j] != othr.data[i][j]) {
                return false;  
            }
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix& othr) const {
    return !(*this == othr); 
}
std::ostream& operator<<(std::ostream& os, const Matrix& m)
{

    int w = 0;
    for (std::size_t i = 0; i < m.m_rows; i++)
    {
        
        for (std::size_t j = 0; j < m.m_cols; j++)
        {
            int cur = std::to_string(m.data[i][j]).length();
            if (cur > w) { w = cur; }
        }

    }

    w += 2;
    for (std::size_t i = 0; i < m.m_rows; i++)
    {
        os << "|";
        for (std::size_t j = 0; j < m.m_cols; j++)
        {
            os << std::setw(w) << (std::abs(m.data[i][j]) < eps ? 0 : m.data[i][j]);
        }
        os << "|\n";
    }

    return os;
}

std::istream& operator>>(std::istream& is, Matrix& m)
{ 
    for (std::size_t i = 0; i < m.m_rows; i++)
    {
        for (std::size_t j = 0; j < m.m_cols; j++)
        {
            is >> m.data[i][j];
        }
    }
    return is; // Нужно для последовательного вызова >>
}

Matrix& Matrix::operator=(const Matrix& othr) 
{
    
    if (this == &othr) 
    {
        return *this;
    }

    m_rows = othr.m_rows;
    m_cols = othr.m_cols;
    data = othr.data;

    return *this;
}

void Matrix::defEl(const std::size_t& r, const std::size_t& c, const double& alpha)
{
    data[r-1][c-1] = alpha;
}