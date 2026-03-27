#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

double Factor (int n) {

    long double c = 1.0, pi = 0.0;

    for (int k = 0; k < n; k++) {
        if (k > 0) {
            c *= k;
            c /= (2*k + 1);
        }
        pi += c;
    }

    return abs(M_PI - 2 * pi);
}

int main() {

    ofstream out;
    out.open("out5.txt");

    for (int N = 1; N <= 100; N++) 
    {
        out << setw(4) << N << " " << setprecision(2) << Factor(N) << endl;
    }

    out.close();

    return 0;
}