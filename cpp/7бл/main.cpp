
// #include "./include/files.h"
#include "./include/matrix.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>

using namespace std;
typedef int* pInt;

void PrintMatrix(pInt* Matrix, int N, int M = 1, int w = 4) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout.width(w);
            cout << Matrix[i][j];
        }
        cout << endl;
    }
}

void WriteMatrixToFile(const string& filename,pInt* Matrix, int N, int M) {

    ofstream output("out.txt");
    output << "Результат:\n\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            output << Matrix[i][j] << " ";
        }
        output << "\n";
    }
    output << "\n";
    output.close();
}

pInt* GenMatrix(int N, int M = 1, bool random = true) {
    pInt* Matrix = new pInt[N];

    // Generate the lines
    for (int i = 0; i < N; i++) {
        Matrix[i] = new int[M];
    }

    if (!random) {
        // Fill by zeros
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                Matrix[i][j] = 0;
            }
        }
    } else {
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                Matrix[n][m] = rand() % 100;
            }
        }
    }

    return Matrix;
}

pInt* ReadMatrixFromFile(const string& filename, int N, int M) {
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

    pInt* Matrix = GenMatrix(N, M, false);

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

// Сортировка

int SumRow(pInt* Matrix, int row, int M) {
    int summ = 0;

    for (int j = 0; j < M; j++) {
        summ += Matrix[row][j];
    }

    return summ;
}

pInt* SortBySum(pInt* Matrix, int N, int M) {
    pInt sums = new int[N];

    for (int i = 0; i < N; i++) {
        sums[i] = SumRow(Matrix, i, M);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (sums[j] > sums[j + 1]) {
                swap(sums[j], sums[j + 1]);
                swap(Matrix[j], Matrix[j + 1]);
            }
        }
    }

    return Matrix;
}




int main() {


    int N = 3, M = 4;

    pInt* Matrix = SortBySum(ReadMatrixFromFile("in.txt", N, M), N, M);
    WriteMatrixToFile("out.txt", Matrix, N, M);

    cout << "Матрица отсортирована!" << endl;

    utils::PrintMatrix(Matrix, N, M);

    return 0;
}
