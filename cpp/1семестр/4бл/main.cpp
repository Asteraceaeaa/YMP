
#include <iostream>
#include <cmath>

using namespace std;

// 1
double RingS(double R1, double R2) {
    if (R1 > R2) {
        return M_PI*R1*R1 - M_PI*R2*R2;
    } else return 0;
}

// 2
int SumRange(float A, float B) {
    int res = 0;

    if (A < B) {
    for (int i = ceil(A); i <= floor(B); i++) {
        res += i;
    }
    } else return 0;

    return res;
}


// 3
int ChangeBase(int n, int N) {

    if (N <= 1 || N >= 11) return 0;
    int res = 0, i = 0;
    while (n > 0) {
        res += (n % 10) * pow(N, i);
        n /= 10; i++;
    }

    return res;
}
// 4
int i_to_b(int n) {
    int res = 0, i = 0;

    while (n > 0) {
        res += (n % 2) * pow(10, i);
        n /= 2; i++;
    }

    return res;
}

// 5
int DigitCount(long long unsigned K) {
    int n = 0;
    while (K > 0) {n++; K /= 10;}
    return n;
}

int DigitNR(int K, int N) {
    int len = DigitCount(K), res;
    if (len < N) {
        return -1;
    }

    for (int i = 0; i < N; i++) {
        res = K % 10;
        K /= 10;
    }
    return res;
}

int DigitNL(int K, int N) {
    int len = DigitCount(K), res;

    if (len < N) {
        return -1;
    }

    for (int i = len; i >= N; i--) {
        res = K % 10;
        K /= 10;
    }
    return res;
}

// 6
string IsPalindrom(int K) {
    bool f = 1;
    int len = DigitCount(K);

    if (K <= 0) {return "FALSE";}

    for (int i = 1; i <= len / 2; i++) {
        f *= DigitNR(K, i) == DigitNL(K, i);
    }

    return f?"TRUE":"FALSE";
}

int Calc8_sum (int A, int B) {
    int res = 0;
    int p = 0;
    int pos = 0;
    int maxL = max(DigitCount(A), DigitCount(B));

    for (int i = 1; i <= maxL || p > 0; i++) {
        int digitA = (i <= DigitCount(A)) ? DigitNR(A, i) : 0;
        int digitB = (i <= DigitCount(B)) ? DigitNR(B, i) : 0;

        int sum = digitA + digitB + p;
        p = sum / 8;
        int curDigit = sum % 8;

        res += curDigit * pow(10, pos);
        pos++;
    }

    return res;
}

int Calc8_difference(int A, int B) {
    int res = 0;
    int borrw = 0;
    int pos = 0;
    int maxL = DigitCount(A);

    for (int i = 1; i <= maxL; i++) {
        int digitA = DigitNR(A, i) - borrw;
        int digitB = (i <= DigitCount(B)) ? DigitNR(B, i) : 0;

        if (digitA < digitB) {
            digitA += 8;
            borrw = 1;
        } else {
            borrw = 0;
        }

        int diff = digitA - digitB;
        res += diff * pow(10, pos);
        pos++;
    }

    return res;
}

int Calc8_multiply(int A, int B) {
    int res = 0;
    int posB = 0;
    int curB = B;

    while (curB > 0) {
        int digitB = curB % 10;
        curB /= 10;

        int cur = 0;
        int p = 0;
        int posA = 0;
        int curA = A;

        while (curA > 0 || p > 0) {
            int digitA = (curA > 0) ? curA % 10 : 0;
            curA /= 10;

            int product = digitA * digitB + p;
            p = product / 8;
            int currentDigit = product % 8;

            cur += pow(10, posA) * currentDigit;
            posA++;
        }

        // Сдвигаем промежуточный результат в соответствии с позицией
        cur *= pow(10, posB);
        // Складываем промежуточный результат с общим результатом
        res = Calc8_sum(res, cur);

        posB++;
    }

    return res;
}

// 7
int Calc8(int A, int B, int Op) {
    int res = 0;

    switch (Op) {
        case 0:
            res = Calc8_sum(A, B);
            break;
        case 1:
            if (A > B) res = Calc8_difference(A, B);
            else res = -Calc8_difference(B, A);
            break;
        case 2:
            res = Calc8_multiply(A, B);
            break;
        default:
            cout << "Error operation" << endl;
            return -1;
    }

   return res;
}
// 12312 и 423
// 12312 + 423 = 12735
// 12312 - 423 = 11667
// 12312 * 423 = 5452376



// 8
long long prog8(int N) {
    if (N == 0) return 1;
    return N * prog8(N - 1);
}

// 9
int prog9(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return prog9(n - 1) + prog9(n - 2);
}

// 10
int prog10(int num, int mun = 0) {
    if (num == 0) return mun;
    return prog10(num / 10, mun * 10 + num % 10);
}

int main () {

    cout << "Enter the num of task" << endl;

    int n, input; cin >> n;

    switch (n) {
        case 1:
            cout << "R1, R2 = 12, 4; S = " << RingS(12.0f, 4.0f) << endl;
            cout << "R1, R2 = 4, 12; S = " << RingS(4.0f, 12.0f) << endl;
            cout << "R1, R2 = 3, 0.5; S = " << RingS(3.0f, 0.5f) << endl;
            break;
        case 2:
            cout << "A = 0.5, B = 3.45; S = " << SumRange(0.5, 3.45) << endl;
            cout << "B = 2.45, C = 10.2; S = " << SumRange(2.45, 10.2) << endl;
            break;
        case 3:
            cout << "n = " << ChangeBase(1010,2) << endl;
            cout << "n = " << ChangeBase(54,8) << endl;
            break;
        case 4:
            cout << "n = " << i_to_b(10) << endl;
            cout << "n = " << i_to_b(12) << endl;
            break;
        case 5:

            cout << "n = " << DigitCount(1234567890) << endl;
            cout << "n = " << DigitCount(60) << endl;
            cout << "n = " << DigitCount(11000) << endl;

            cout << endl << "DigitN right-to-left-ordered:" << endl;
            for (int i = 0; i < 5; i++) {
                int K = rand();

                for (int N = 1; N <= 5; N++) {
                    cout <<"K = " << K <<", " << N << " digit. " << "DigitNR(K, N): " << DigitNR(K, N) << endl;
                }
                cout << endl;
            }

            cout << endl << "DigitN left-to-right-ordered:" << endl;
            for (int i = 0; i < 5; i++) {
                int K = rand();
                for (int N = 1; N <= 5; N++) {
                    cout <<"K = " << K / 100 <<", " << N << " digit. " << "DigitNR(K, N): " << DigitNL(K, N) << endl;
                }
                cout << endl;
            }
            break;
        case 6:
            cout << "Enter the number" << endl;
            cin >> input;

            cout << IsPalindrom(input);
            break;
        case 7:
            cout << Calc8(303, 70,2);
            break;
        case 8:
            cout << "Enter the number" << endl;
            cin >> input;

            cout << prog8(input) << endl;
            break;
        case 9:

            cout << "Enter number of member of Fibonacci sequance" << endl;
            cin >> input;
            for (int i = 0; i < input; i++)
            {
                int cur = prog9(i);
                // cout.width(3);
                if (cur > input) break;
                cout << prog9(i) << " ";
            }
            break;
        case 10:
            cout << "Enter the number" << endl;
            cin >> input;

            cout << prog10(input);
            break;
    }



    return 0;
}