#include "./include/matrix.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;


void utils::PrintMatrix(pInt* Matrix, int N, int M, int w) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout.width(w);
            cout << Matrix[i][j];
        }
        cout << endl;
    }
}

pInt* utils::GenMatrix(int N, int M, bool random) {
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