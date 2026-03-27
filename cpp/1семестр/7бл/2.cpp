#include <iostream>
#include <fstream>
#include <string>
typedef int* pInt;

class Matrix {
private:
    int rows;
    int cols;
    pInt* data;
public:
    Matrix(int r, int c, pInt* InitialData=nullptr) : rows(r), cols(c), data(nullptr) {       
        data = new int*[rows];

        for (int row = 0; row < rows; row++) {
            data[row] = new int[cols];

            if (InitialData != nullptr && InitialData[row] != nullptr) {
                std::cout << "";
            } else {
                for (int col = 0; col < cols; col++) {
                    data[row][col] = 0;
                }
            }
        }
    }

    ~Matrix() {
        clear();
    }

    void clear() {
        if (data != nullptr) {
            for (int p = 0; p < rows; p++) {
                if (data[p] != nullptr) {
                    delete[] data[p];
                    data[p] = nullptr;
                }
            }
            delete[] data;
            data = nullptr;
        }
    }
    
    int gcols() const {return cols;}
    int grows() const {return rows;}

    pInt gelem(int i, int j) {
        if (i < 0 || j < 0 || i >= rows || j >= cols)
        {
            throw std::out_of_range("Индексы неверны");
        }
        return *(data + i) + j;
    }

    void print(int w=3) {
        // std::cout << std::endl;
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                std::cout.width(w);
                std::cout << data[row][col];
            }
            std::cout << std::endl;
        }
    }

    void CopyFromFile(std::string path) {
        std::ofstream in(path);

        if (!in.is_open()) { std::cerr << "Не удалось открыть файл " << path;}

        int num;
        while (true) {
            
        }


    }

};



int main() {
    Matrix m(3, 3);
    m.print();
    std::cout << *(m.gelem(1, 2));
}





