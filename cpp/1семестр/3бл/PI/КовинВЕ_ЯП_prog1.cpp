#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

double Wallis(int N) 
{

    double pi = 1, n = 0, m = 1;

    for (int i = 0; i <= N; i++) {
        if (i % 2 == 0) {
            n += 2;

        } else {
            m += 2;
        }
        pi *= (n / m);

    }

    return abs(M_PI / 2 - pi);
}

int main() {

    ofstream out;
    out.open("out1.txt");

    for (int N = 1; N <= 8000; N++) 
    {
        out << setw(4) << N << " " << setprecision(2) << Wallis(N) << endl;
    }

    out.close();

    return 0;
}