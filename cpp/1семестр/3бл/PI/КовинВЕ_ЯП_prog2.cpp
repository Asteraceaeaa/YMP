#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

double Leibnizs (int N) {

    double d = 1, pi = 0;

    for (int i = 0; i < N; i++) 
    { pi += pow(-1, i) / d; d+=2;}

    return abs(M_PI / 4 - pi);
}

int main()
{
    ofstream out;
    out.open("out2.txt");

    for (int N = 1; N <= 25888; N++) 
    {
        out << setw(4) << N << " " << setprecision(2) << Leibnizs(N) << endl;
    }

    out.close();

    return 0;
}