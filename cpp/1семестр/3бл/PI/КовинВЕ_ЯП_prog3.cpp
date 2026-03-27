#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

double Srinivasa (int N) {

    int m = 1;
    long double c = 1.0, pi = 0.0;

    for (int k = 0; k < N; k++) {
        if (k > 0) {
            c *= pow((2*k - 1), 3);
            c /= pow(2*k, 3);
        }
        pi += m*pow(-1, k)*c; m += 4;
    }

    return abs(2 / M_PI - pi);
}

int main() 
{

    ofstream out;
    out.open("out3.txt");

    for (int N = 1; N <= 50000; N++) 
    {
        out << setw(4) << N << " " << setprecision(2) << Srinivasa(N) << endl;
    }

    out.close();

    return 0;
}