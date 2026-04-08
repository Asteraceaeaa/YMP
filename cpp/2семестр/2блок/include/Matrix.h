#pragma once
#include <vector>


class Matrix {
public:

    Matrix();

private:
    std::vector<std::vector<double>> data;
    size_t m_rows;
    size_t m_cols;

};