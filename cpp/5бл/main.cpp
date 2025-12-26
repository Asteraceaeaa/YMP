

#include <iostream>
#include <random>

using namespace std;


void print_matrix(int **Matrix, int N, int M, int w=4) {

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout.width(w);
            cout << Matrix[i][j];
        }
        cout << endl;
    }
}

int **gen_matrix(int N, int M) {

    int **Matrix = new int*[N];

    // a)
    // Generate the lines
    for (int i = 0; i < N; i++) {
        Matrix[i] = new int[M];
    }

    // Fill by zeros
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Matrix[i][j] = 0;
        }
    }

    return Matrix;
}

// int *gen_rand_vector(int N) {
//     int *Vector = new int[N];
//
//     for (int i = 0; i < N; i++) {
//         Vector[i] = rand();
//     }
//
//     return Vector;
// }

int **fill_rand_matrix(int **Matrix, int N, int M) {
     for (int n = 0; n < N; n++) {
         for (int m = 0; m < M; m++) {
             Matrix[n][m] = rand() % 100;
         }
     }

    return Matrix;
}

int **matrix_transposition(int **Matrix, int N, int M) {
    int **TMatrix = gen_matrix(N, M);

    for (int n = 0; n < N; n++) {
        for (int m = 0; m < M; m++) {
            TMatrix[m][n] = Matrix[n][m];
        }
    }

    return TMatrix;
}


int **p_m_v(int **v, int **Matrix, int N, int M) {
    int **res = gen_matrix(N, 1);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            res[i][0] += Matrix[i][j] * v[j][0];
        }
    }
    return res;
}


// 1
void prog41 () {

    int N, mx_index, mn_index, count = 0;
    double *s, sum, minn = INT_MAX, maxx = INT_MIN, interval, avg;

    cout << "Enter count of nums: " << endl;
    cin >> N;

    s = new double[N];

    for (int i = 0; i < N; i++) {
        double n;
        cin >> n;
        s[i] = n;
    }

    for (int i = 0; i < N; i++) {
        double cur = *(s + i); // то же что и int cur = s[i];

        cout << cur << " "; sum += cur;
        if (maxx <= cur) {maxx = cur; mx_index = i;}
        if (minn >= cur) {minn = cur; mn_index = i;}
    }

    interval = abs(mn_index - mx_index) - 1;
    avg = sum / N;

    for (int i = 0; i < N; i++) {
        double cur = *(s + i);

        if (abs(avg - cur) <= 0.1) {count++; cout << *(s+i) << endl;}
    }
    delete[] s; s = NULL;

    cout << "Sum: " << sum << endl;
    cout << "AVG: " << avg << endl;
    cout << "Interval between max and min " << interval << endl;
    cout << "Count of 10%: " << count << endl;
}

// 6
// 5.0 1.0 2.0 1.0 4.0 5.0

// 7
// -3.0 -1.0 0.0 2.5 4.0 6.0 -2.0


// 2
void prog42() {
    int N, **Matrix;
    cout << "Enter dim of Matrix:" << endl;
    cin >> N;

    // a)
    Matrix = gen_matrix(N, N);

    for (int i = 0; i < N; i++) {
        Matrix[i][i] = 1;
    }

    cout << endl << "a)" << endl;
    print_matrix(Matrix, N, N); delete[] Matrix;


    // b)
    Matrix = gen_matrix(N, N);

    for (int i = 0, j = N-1; i < N; i++, j--) {
        Matrix[i][j] = 1;
    }

    cout << endl << "b)" << endl;
    print_matrix(Matrix, N, N); delete[] Matrix;

    // c)
    Matrix = gen_matrix(N, N);
    cout << endl << "c)" << endl;

    if (N % 2 != 0) {

        for (int i = 0; i <= (N / 2); i++) {
            Matrix[i][(N / 2) - i] = Matrix[i][(N / 2) + i] = 1;
        }

        int i = N-1;
        for (int j = 0; j <= (N / 2); j++) {
            Matrix[i-j][(N / 2) - j] = Matrix[i-j][(N / 2) + j] = 1;
        }

        print_matrix(Matrix, N, N);
    } else {cout << "Matrix is not exist";}

    delete[] Matrix; Matrix = NULL;
}

// 3
void prog43() {
    int N;
    cout << "Enter dim: " << endl;
    cin >> N;

    int **A = fill_rand_matrix(gen_matrix(N, N), N, N);

    print_matrix(A, N, N);
    print_matrix(matrix_transposition(A, N, N), N, N);
}


// 4
void prog44() {
    int N = 3, M = 3;

    int **Matrix = fill_rand_matrix(gen_matrix(N, M), N, M);
    int **Vector = fill_rand_matrix(gen_matrix(N, 1), N, 1);
    cout << "MATRIX: " << endl;
    print_matrix(Matrix, N, M);
    cout << "VECTOR: " << endl;
    print_matrix(Vector, N, 1);

    int **res = p_m_v(Vector, Matrix, N, M);

    cout << "RESULT: " << endl;
    print_matrix(res, N, 1);
}


int **m_times_m(int **M1, int **M2, int N, int M) {
    int **MR = gen_matrix(N, M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N;j++) {
            for (int k = 0; k < N; k++) {
                MR[i][j] += M1[i][k] * M2[k][j];
            }
        }
    }


    return MR;
}

// 5
void prog45() {
    int N = 5;
    int **M1 = fill_rand_matrix(gen_matrix(N, N), N, N), **M2 = fill_rand_matrix(gen_matrix(N, N), N, N);
    print_matrix(M1, N, N); cout << endl;
    print_matrix((M2), N, N); cout << endl;
    print_matrix(m_times_m(M1, M2, N, N), N, N, 7);
}
// C[i][j] = Σ (A[i][k] * B[k][j]) для k от 0 до K-1

int v_p_scalar(int **v1, int **v2, int N=3) {
    int res = 0;

    for (int i = 0; i < N; i++) {res += v1[i][0] * v2[i][0];}
    return res;
}

int **v_p_vector(int **v1, int **v2) {
    int **res = gen_matrix(3, 1), *nv = new int[1, 1, 1];
return 0;
}

int find_det(int **A) {

}



int main() {
    // prog43();
    prog41();
    return 0;
}



