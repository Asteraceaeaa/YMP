#include <cmath>
#include <fstream>
#include <iostream>
#include <random>
#include <climits>


using namespace std;

void print_matrix(int** Matrix, int N, int M, int w = 4) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout.width(w);
            cout << Matrix[i][j];
        }
        cout << endl;
    }
}

void print_matrix_double(double** Matrix, int N, int M, int w = 10, int prec = 4) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout.width(w);
            cout.precision(prec);
            cout << fixed << Matrix[i][j];
        }
        cout << endl;
    }
}

void write_matrix_to_file(ofstream& file, double** Matrix, int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            file << Matrix[i][j] << " ";
        }
        file << endl;
    }
}

int** gen_matrix(int N, int M) {
    int** Matrix = new int*[N];

    // a)
    // Generate the lines
    for (int i = 0; i < N; i++) {
        Matrix[i] = new int[M];
    }

    // Fill by zeros
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            Matrix[i][j] = 0;
        }
    }

    return Matrix;
}

double** gen_matrix_double(int N, int M) {
    double** Matrix = new double*[N];
    for (int i = 0; i < N; i++) {
        Matrix[i] = new double[M];
        for (int j = 0; j < M; j++) {
            Matrix[i][j] = 0.0;
        }
    }
    return Matrix;
}



int** fill_rand_matrix(int** Matrix, int N, int M) {

}

double** fill_rand_matrix_double(double** Matrix, int N, int M) {
    for (int n = 0; n < N; n++) {
        for (int m = 0; m < M; m++) {
            Matrix[n][m] = (rand() % 100) / 10.0;
        }
    }
    return Matrix;
}

int** matrix_transposition(int** Matrix, int N, int M) {
    int** TMatrix = gen_matrix(N, M);

    for (int n = 0; n < N; n++) {
        for (int m = 0; m < M; m++) {
            TMatrix[m][n] = Matrix[n][m];
        }
    }

    return TMatrix;
}

int** p_m_v(int** v, int** Matrix, int N, int M) {
    int** res = gen_matrix(N, 1);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            res[i][0] += Matrix[i][j] * v[j][0];
        }
    }
    return res;
}

// 1
void prog41() {
    int N, mx_index = 0, mn_index = 0, count = 0, interval;
    double *s, sum, minn = INT_MAX, maxx = INT_MIN, avg;

    cout << "Enter count of nums: " << endl;
    cin >> N;

    s = new double[N];

    // Заполняем массив с числами
    for (int i = 0; i < N; i++) {
        double n;
        cin >> n;
        s[i] = n;
    }

    for (int i = 0; i < N; i++) {
        double cur = s[i];  // то же что и int cur =  *(s + i);


        // Считаем сумму
        sum += cur;

        // Находим максимальный элемент
        if (maxx <= cur) {
            maxx = cur;
            mx_index = i;

        }

        // Находим минимальный элемент и его индекс
        if (minn >= cur) {
            minn = cur;
            mn_index = i;

        }

    }

    interval = abs(mn_index - mx_index) == 0
                   ? 0
                   : abs(mn_index - mx_index) - 1;  // Находим интервал между min и max
    avg = sum / N; // Находим avg

    // Находим количество элементов массива, отличающихся от среднего арифметического не более, чем на 10%
    for (int i = 0; i < N; i++) {
        double cur = *(s + i); // Текущий элемент

        if (abs(avg - cur) <= 0.1) {
            count++;
            cout << *(s + i) << endl;
        }
    }

    delete[] s;
    s = NULL;

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
    print_matrix(Matrix, N, N);
    delete[] Matrix;

    // b)
    Matrix = gen_matrix(N, N);

    for (int i = 0, j = N - 1; i < N; i++, j--) {
        Matrix[i][j] = 1;
    }

    cout << endl << "b)" << endl;
    print_matrix(Matrix, N, N);
    delete[] Matrix;

    // c)
    Matrix = gen_matrix(N, N);
    cout << endl << "c)" << endl;

    if (N % 2 != 0) {
        for (int i = 0; i <= (N / 2); i++) {
            Matrix[i][(N / 2) - i] = Matrix[i][(N / 2) + i] = 1;
        }

        int i = N - 1;
        for (int j = 0; j <= (N / 2); j++) {
            Matrix[i - j][(N / 2) - j] = Matrix[i - j][(N / 2) + j] = 1;
        }

        print_matrix(Matrix, N, N);
    } else {
        cout << "Matrix is not exist";
    }

    delete[] Matrix;
    Matrix = NULL;
}

// 3
void prog43() {
    int N;
    cout << "Enter dim: " << endl;
    cin >> N;

    int** A = fill_rand_matrix(gen_matrix(N, N), N, N);

    print_matrix(A, N, N);
    print_matrix(matrix_transposition(A, N, N), N, N);
}

// 4
void prog44() {
    int N = 3, M = 3;

    int** Matrix = fill_rand_matrix(gen_matrix(N, M), N, M);
    int** Vector = fill_rand_matrix(gen_matrix(N, 1), N, 1);
    cout << "MATRIX: " << endl;
    print_matrix(Matrix, N, M);
    cout << "VECTOR: " << endl;
    print_matrix(Vector, N, 1);

    int** res = p_m_v(Vector, Matrix, N, M);

    cout << "RESULT: " << endl;
    print_matrix(res, N, 1);
}

int** m_times_m(int** M1, int** M2, int N, int M) {
    int** MR = gen_matrix(N, M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                MR[i][j] += M1[i][k] * M2[k][j];
            }
        }
    }

    return MR;
}

// 5
void prog45() {
    int N = 3;
    int **M1 = fill_rand_matrix(gen_matrix(N, N), N, N),
        **M2 = fill_rand_matrix(gen_matrix(N, N), N, N);
    print_matrix(M1, N, N);
    cout << endl;
    print_matrix((M2), N, N);
    cout << endl;
    print_matrix(m_times_m(M1, M2, N, N), N, N, 7);
}



// 6

// Скалярное произведение векторов 
int v_p_scalar(int** v1, int** v2, int N = 3) {
    int res = 0;
    for (int i = 0; i < N; i++) {
        res += v1[i][0] * v2[i][0];
    }
    return res;
}

// Векторное произведение 
int** v_p_vector(int** v1, int** v2) {
    int** res = gen_matrix(3, 1);

    // Формула векторного произведения для 3D:
    // res_x = v1_y * v2_z - v1_z * v2_y
    // res_y = v1_z * v2_x - v1_x * v2_z
    // res_z = v1_x * v2_y - v1_y * v2_x

    res[0][0] = v1[1][0] * v2[2][0] - v1[2][0] * v2[1][0];  // x
    res[1][0] = v1[2][0] * v2[0][0] - v1[0][0] * v2[2][0];  // y
    res[2][0] = v1[0][0] * v2[1][0] - v1[1][0] * v2[0][0];  // z

    return res;
}

int mixed_product(int** a, int** b, int** c) {
    // Вычисляем векторное произведение a × b
    int** cross = v_p_vector(a, b);

    // Вычисляем скалярное произведение (a × b) · c
    int result = v_p_scalar(cross, c, 3);

    // Освобождаем память
    for (int i = 0; i < 3; i++) {
        delete[] cross[i];
    }
    delete[] cross;

    return result;
}


    void prog46() {
        cout << "=== Задание 4.6: Векторные операции ===" << endl;

        

        // Создаем три вектора
        int** v1 = gen_matrix(3, 1);
        int** v2 = gen_matrix(3, 1);
        int** v3 = gen_matrix(3, 1);

        // Заполняем векторы случайными значениями
        v1 = fill_rand_matrix(v1, 3, 1);
        v2 = fill_rand_matrix(v2, 3, 1);
        v3 = fill_rand_matrix(v3, 3, 1);

        cout << "Вектор 1: ";
        print_matrix(v1, 3, 1, 6);

        cout << "Вектор 2: ";
        print_matrix(v2, 3, 1, 6);

        cout << "Вектор 3: ";
        print_matrix(v3, 3, 1, 6);

        // 1. Скалярное произведение векторов 1 и 2
        int scalar_result = v_p_scalar(v1, v2, 3);
        cout << "\n1. Скалярное произведение: " << scalar_result << endl;

        // 2. Векторное произведение векторов 1 и 2
        int** vector_result = v_p_vector(v1, v2);
        cout << "2. Векторное произведение: ";
        print_matrix(vector_result, 3, 1, 6);

        // 3. Смешанное произведение трех векторов
        int mixed_result = mixed_product(v1, v2, v3);
        cout << "3. Смешанное произведение: " << mixed_result << endl;
    }

// 7
double determinant(double** A, int N) {
    if (N == 1)
        return A[0][0];
    if (N == 2)
        return A[0][0] * A[1][1] - A[0][1] * A[1][0];

    double det = 0.0;
    int sign = 1;

    for (int col = 0; col < N; col++) {
        double** minor = gen_matrix_double(N - 1, N - 1);

        for (int i = 1; i < N; i++) {
            int minor_col = 0;
            for (int j = 0; j < N; j++) {
                if (j == col)
                    continue;
                minor[i - 1][minor_col] = A[i][j];
                minor_col++;
            }
        }

        det += sign * A[0][col] * determinant(minor, N - 1);
        sign = -sign;

        for (int i = 0; i < N - 1; i++)
            delete[] minor[i];
        delete[] minor;
    }

    return det;
}

void prog47() {
    ifstream infile("infile.txt");
    ofstream outfile("outfile.txt");

    if (!infile.is_open()) {
        cout << "Не удалось открыть файл infile.txt" << endl;
        return;
    }

    int N;
    infile >> N;

    if (N >= 10) {
        cout << "N должно быть < 10" << endl;
        return;
    }

    double** A = gen_matrix_double(N, N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            infile >> A[i][j];
        }
    }

    infile.close();

    cout << "Матрица A (" << N << "x" << N << "):" << endl;
    print_matrix_double(A, N, N);

    double det = determinant(A, N);

    cout << "\nОпределитель матрицы A: " << det << endl;

    outfile << "Определитель матрицы A: " << det << endl;

    for (int i = 0; i < N; i++)
        delete[] A[i];
    delete[] A;

    outfile.close();
}

// 8
double** adjugate(double** A, int N) {
    double** adj = gen_matrix_double(N, N);

    if (N == 1) {
        adj[0][0] = 1.0;
        return adj;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            double** minor = gen_matrix_double(N - 1, N - 1);

            int minor_row = 0;
            for (int row = 0; row < N; row++) {
                if (row == i)
                    continue;
                int minor_col = 0;
                for (int col = 0; col < N; col++) {
                    if (col == j)
                        continue;
                    minor[minor_row][minor_col] = A[row][col];
                    minor_col++;
                }
                minor_row++;
            }

            double minor_det = determinant(minor, N - 1);
            adj[j][i] = (((i + j) % 2 == 0) ? 1 : -1) * minor_det;

            for (int k = 0; k < N - 1; k++)
                delete[] minor[k];
            delete[] minor;
        }
    }

    return adj;
}

void prog48() {
    ifstream infile("infile.txt");
    ofstream outfile("outfile.txt", ios::app);

    if (!infile.is_open()) {
        cout << "Не удалось открыть файл infile.txt" << endl;
        return;
    }

    int N;
    infile >> N;

    if (N >= 10) {
        cout << "N должно быть < 10" << endl;
        return;
    }

    double** A = gen_matrix_double(N, N);

    infile.seekg(0);
    infile >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            infile >> A[i][j];
        }
    }

    infile.close();

    cout << "\nМатрица A (" << N << "x" << N << "):" << endl;
    print_matrix_double(A, N, N);

    double det = determinant(A, N);

    if (fabs(det) < 1e-10) {
        cout << "\nОбратная матрица не существует (определитель = 0)" << endl;
        outfile << "\nОбратная матрица не существует (определитель = 0)" << endl;
        return;
    }

    double** adj = adjugate(A, N);
    double** inverse = gen_matrix_double(N, N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            inverse[i][j] = adj[i][j] / det;
        }
    }

    cout << "\nОбратная матрица A^(-1):" << endl;
    print_matrix_double(inverse, N, N);

    outfile << "\nОбратная матрица A^(-1):" << endl;
    write_matrix_to_file(outfile, inverse, N, N);

    for (int i = 0; i < N; i++) {
        delete[] A[i];
        delete[] adj[i];
        delete[] inverse[i];
    }
    delete[] A;
    delete[] adj;
    delete[] inverse;

    outfile.close();
}

int main() {
    // srand(time(NULL));



    int n;
    cout << "Введите номер задачи: ";
    cin >> n;
    switch (n){
    case 1:
        cout << "\n=== Задание 4.1 ===" << endl;
    prog41(); break;
        case 2:
        cout << "\n=== Задание 4.2 ===" << endl;
    prog42(); break;
        case 3:
            cout << "\n=== Задание 4.3 ===" << endl;
            prog43();
            break;
        case 4:
            cout << "\n=== Задание 4.4 ===" << endl;
            prog44();
            break;
            case 5:
                cout << "\n=== Задание 4.5===" << endl;
                prog45();
                break;
            case 6:
                cout << "\n=== Задание 4.6===" << endl;
                prog46();
                break;
            case 7:
                cout << "\n=== Задание 4.7===" << endl;
                prog47();
                break;
    }

    return 0;
}