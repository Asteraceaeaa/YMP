#include "./include/files.h"
#include "./include/matrix.h"
#include <fstream>  
#include <iostream>

using namespace std;


pInt* utils::ReadMatrixFromFile(const string& filename, int N, int M) {

    ifstream input(filename);
    if (!input.is_open()) {
        cerr << "Ошибка: не удалось открыть файл input.txt\n";
        return nullptr;
    }

    if (N <= 0 || M <= 0) {
        cerr << "Ошибка: некорректные размеры матрицы " << N << "x" << M << endl;
        input.close();
        return nullptr;
    }

    pInt* Matrix = utils::GenMatrix(N, M, false);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!(input >> Matrix[i][j])) {
                cerr << "Не удалось прочесть элемент " << i << j << endl;
                input.close();
                return nullptr;
            } 
        }
    }

    input.close();

    return Matrix;
}
