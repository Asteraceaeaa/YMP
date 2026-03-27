#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

double Nilacanta (int n) {
    double pi = 3.0f;

    for (int k = 1; k < n; k++) {
        pi += 4*(pow(-1, k+1)) / (2*k*(2*k+1)*(2*k+2));
    }

    return abs(M_PI - pi);
}

int main() {

    ofstream out;
    out.open("out4.txt");

    for (int N = 1; N <= 140; N++) 
    {
        out << setw(4) << N << " " << setprecision(2) << Nilacanta(N) << endl;
    }

    out.close();

    return 0;
}