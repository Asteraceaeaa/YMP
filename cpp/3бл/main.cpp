
#include <iostream>
#include <cmath>
#include <vector>
#include <numeric>

using namespace std;


//1
void factorial () {
    int n;

    cout << "#1" << endl << "Enter the n -> ";
    cin >> n;

    long int res = 1;
    for (int i = 1; i <= n; i++) {
        res *= i;
    }

    cout << "The factorial of " << n << " is " << res;
}

//2
void theSum () {
    int n;
    short int c = 0;

    cout << "#2" << endl << "Enter the n -> ";
    cin >> n;

    if (n > 27) {
        cout << "Not exist";
    } else {
        for (int i = 100; i <= 999; i++) {
            if (((i / 100) + (i / 10 % 10) + (i % 10)) == n) {
                cout << i << endl;
                c++;
            }
        }
    }

    if (c == 0) cout << "Not exist";
}


//3
void LCD_Euclid() {
    int n, m;

    cout << "#3" << endl << "Enter the n -> ";
    cin >> n >> m;

    while (n > 0) {
        int r = n % m;
        if (r == 0) {
            r = m;
            cout << "LCD is " << r;
            break;
        }
        n = m;
        m = r;
    }
}
//4
void primeNums () {

    int m;
    cout << "Enter M:" << endl;
    cin >> m;

    bool* a = new bool[m]; // Задаем динамический массив длины m
    a[0] = a[1] = 0; // 0 и 1 - не простые числа, поэтому по их индексу ставим "0" == false

    // Заполняем его значениями "1" == true, для всех чисел > 1 (то есть для всех индексов > 1)
    for (int i = 2; i < m; i++) {
        a[i] = 1;
    }

    for (int i = 2; i < m; i++) { // Первый цикл(с i) перебирает каждое число/делитель(определяемое индексом) по одному разу.
        for (int j = 2; j <= m; j++) { // Второй цикл(с j) во время каждой итерации первого цикла перебирает все числа(индексы) от j до m.
            if (a[i] && a[j]) { // Проверяем, являются ли эти числа i и j простыми.
                if (j % i == 0 && i != j) { // Если оба простые, то проверяем, делится ли число j на число i. При этом, учитываем, что j != i.
                    a[j] = 0; // Если делится, значит j не простое.
                }
            }
        }
    }

    cout << m << (a[m] ? " Is prime" : " Isn't prime") << endl; // Проверяем, является ли последнее число в списке простым(тернарный оператор)

    for (int i = 2; i <= m; i++) { // Перебираем все числа i от 2 до m
        if (a[i]) cout << i << ", "; // Если i - простое, то выводим
    }

    delete a;
}

//5
void toPrimes() {
    int n;
    cin >> n;
    int *a = new int[n];

    if (n > 1) {
        for (int i = 0; i < n; i++) {
            a[i] = true;
        }

        for (int i = 2; i < n; i++) {
            for (int j = 2; j <= n; j++) {
                if (a[i] && a[j]) {
                    if (j % i == 0 && i != j) {
                        a[j] = false;
                    }
                }
            }
        }

        int c = 0;
        for (int i = 2; i <= n / 2; i++) {
            if (n == 0) break;
            if (a[i]) {
                while (n % i == 0) {
                    n /= i;
                    cout << i << endl;
                    c++;
                }
            }
        }
    if (!c) cout << "Have no prime dividers";
    }


    delete[] a;
}

//6
void qandr () {
    int a, b;
    cin >> a >> b;

    if (b != 0) {
        int r, q = 0;
        int sign_a = (a > 0) ? 1 : -1;
        int sign_b = (b > 0) ? 1 : -1;

        a = abs(a); b = abs(b);
            while (true) {
                if (a - b >= 0) {
                    q++;
                    a -= b;
                } else {
                    r = a;
                    break;
                }
            }

        cout << "r = " << r*sign_a << endl;
        cout << "q = " << q*sign_a*sign_b << endl;
    } else {cout << "Error!";}
}
// a=10, b=3: q=3, r=1
// a=-10, b=3: q=-3, r=-1
// a=10, b=-3: q=-3, r=1
// a=-10, b=-3: q=3, r=-1



//7
void deviders () {
    int n;
    cin >> n;

    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) cout << i << endl;
    }

    cout << n;
}

//8
void sumDvd () {
    int N;
    cout << "Enter N" << endl;
    cin >> N;

    for (int num = 2; num <= N; num++) {
        int sum = 0;

        for (int j = 1; j <= num / 2; j++) {
            if (num % j == 0) sum+=j;
        }

        if (sum == num) cout << num << endl;
    }

}

//9
// void LuckyTickets() {
//     int len;
//     int s1,s2,count;
//     cin >> len;
//     if (len % 2 == 0) {
//         int c = len / 2;
//         for (double j = pow(10,len-1); j < pow(10,len); j ++) {
//             string str = to_string(j);
//             for (int i = 0; i<c; i ++) {
//                 s1+=(int)str[i];
//                 s2+=(int)str[c+i];
//             }
//             if (s1==s2) {
//                 cout << j << endl;
//                 count++;
//             }
//             s1 = 0;
//             s2 = 0;
//         }
//         cout << "Count of lucky tickets: " << count << endl;
//     }
// }




bool isLucky(int number, int n) {
    int half = n / 2;
    int d = pow(10, half);

    int right = number % d;
    int left = number / d;

    int sl = 0, sr = 0;

    for (int i = 0; i < half; i++) {
        sl += left % 10;
        left /= 10;
    }

    for (int i = 0; i < half; i++) {
        sr += right % 10;
        right /= 10;
    }

    return sl == sr;
}

void LuckyTickets() {
    int n;
    cout << "Enter length: ";
    cin >> n;

    if (n % 2 != 0) {
        cout << "Error! " << endl;

    } else {
        long long total = 0;
        long long max_number = pow(10, n) - 1;

        cout << endl << "First ten lucky tickets: " << endl;
        int countp = 0;
        for (int num = 0; num <= max_number; num++) {
            if (isLucky(num, n)) {
                total++;
                // if (countp < 10) {
                //     cout.width(n);
                //     cout.fill('0');
                //     cout << num << " ";
                //     countp++;
                // }
                cout.width(n);
                cout.fill('0');
                cout << num << " ";
            }
        }

        cout << endl <<"Count of lucky tickets: " << total << endl;

    }
}
//10
void cosinus () {

    int N;
    cin >> N;
    double x[] = {-3, 0, 1, 2};

    for (int k = 0; k < sizeof(x) / sizeof(x[0]); k++) {
        double fact = 1, sum = 0, xk = x[k];

        for (int i = 0; i <= N; i++) {
            for (int j = 1; j<=2*i; j++) {
                fact *= j;
            }
            sum += (i%2 == 0 ? 1 : -1) * pow(xk, 2*i) / fact;
            fact = 1;
        }

        cout << "Cos(" << xk << "): " << cos(xk) << ". SumCos(" << xk << "): " << sum << endl;
    }
}

//11
double sumsin(int x, float n) {
    float sum = 0, term = x;

    for (int i = 1; i <= n; i++) {
        sum += term;
        term = -(term*x*x) / ((2*i)*(2*i + 1));
    }

    return sum;
}

void sinus () {
    int n, x[] = {-10, -7, -6, -5, -3, 0, 1, 2, 5, 7, 10};

    cin >> n;

    for (int i = 0; i < sizeof(x) / sizeof(x[0]); i++) {
        cout << "x = " << x[i] << endl;
        cout << "sum: " << sumsin(x[i], n) << endl;
        cout << "sin(x) " << sin(x[i]) << endl;
    }


}

//12
void Wallis () {
    int N = 50;
    float pi = 1, n = 0, m = 1;

    for (int i = 0; i <= N; i++) {
        if (i % 2 == 0) {
            n += 2;
        } else if (i % 2 != 0) { m += 2; }
        pi *= (n/m);
    }


    cout << "PI/4 with " << N << " terms: " << pi << endl;
    cout << "PI/4 from cmath " << M_PI / 2 << endl;
    cout << "Accuracy: " << abs(M_PI / 2 - pi) << endl;

}


void Leibnizs () {
    int n = 100;
    float d = 1, pi = 0;


    for (int i = 0; i < n; i++) { pi += pow(-1, i) / d; d+=2;}

    cout << "PI/4 " << n << " terms: " << pi << endl;
    cout << "PI/4 from cmath " << M_PI / 4 << endl;
    cout << "Accuracy: " << abs(M_PI / 4 - pi) << endl;
}


void Factor () {
    int n = 20;
    float c = 1.0f, pi = 0.0f;

    for (int k = 0; k < n; k++) {
        if (k > 0) {
            c *= k;
            c /= (2*k + 1);
        }
        pi += c;
    }



    cout << "PI with " << n << " terms: " << 2*pi << endl;
    cout << "PI from cmath " << M_PI << endl;
    cout << "Accuracy: " << abs(M_PI - 2*pi) << endl;
}

void Srinivasa () {
    int n = 11, m = 1;
    long double c = 1.0, pi = 0.0;

    for (int k = 0; k < n; k++) {
        if (k > 0) {
            c *= pow((2*k - 1), 3);
            c /= pow(2*k, 3);
        }
        pi += m*pow(-1, k)*c; m += 4;
    }

    cout << "2/PI " << n << " terms: " << pi << endl;
    cout << "2/PI from cmath " << 2/M_PI << endl;
    cout << "Accuracy: " << abs(2/M_PI - pi) << endl;

}

void Nilacanta () {
    int n = 20;
    float pi = 3.0f;

    for (int k = 1; k < n; k++) {
        pi += 4*(pow(-1, k+1)) / (2*k*(2*k+1)*(2*k+2));
    }

    cout << "PI " << n << " terms: " << pi << endl;
    cout << "PI from cmath " << M_PI << endl;
    cout << "Accuracy: " << abs(M_PI - pi) << endl;

}





int main () {

    int number_of_task;

    setlocale(LC_ALL, "Russian");


    cout << "Enter the num of task:" << endl;
    cin >> number_of_task;

    switch (number_of_task) {
        case 1: factorial(); break;
        case 2: theSum(); break;
        case 3: LCD_Euclid(); break; // LCD(451, 287) => 41
        case 4: primeNums(); break;
        case 5: toPrimes(); break; // Isn't completed
        case 6: qandr(); break;
        case 7: deviders(); break;
        case 8: sumDvd(); break;
        case 9: LuckyTickets(); break;
        case 10: cosinus(); break; // Isn't completed
        case 11: sinus(); break;
        case 12:
            cout << "With Wallis's formula: " << endl; Wallis();
            cout << "\n\n" << "With Leibniz's formula: " << endl; Leibnizs();
            cout << "\n\n" << "With double factorial formula: " << endl; Factor();
            cout << "\n\n" << "With Srinivasa's formula: " << endl; Srinivasa();
            cout << "\n\n" << "With Nilacanta's formula: " << endl; Nilacanta();
            break; // Isn't completed
        default: 0;
    }



}



