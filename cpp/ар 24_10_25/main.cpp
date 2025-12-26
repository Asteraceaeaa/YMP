
#include <iostream>
#include <cmath>
#include <complex>

using namespace std;

void F() {
    float a, res;
    cout << "Enter a:";
    cin >> a;

    if ( a < 1 ) { res = -1 / a; }
    else if ( a < 2 ) { res = a * a; }
    else { res = 4; }


    cout << "f(a) = " << res << endl;
}

void triangle () {
    float a, b, c;
    cout << "Enter a b c" << endl;
    cin >> a >> b >> c;

    // cosA = (b^2 + c^2 - a^2) / 2bc > 0;
    bool usl1 = ((a + b) >=  c) && ((c + a) >= b) && ((b + c) >= a); // Triangle is existing?
    bool usl2 = cos((b*b + c*c - a*a) / 2*b*c) > 0 && cos( (a*a + b*b - c*c) / 2*a*b) > 0 && cos((a*a + c*c - b*b) / 2*a*c) > 0; // Triangle is sharp-angled?

    cout << ( (usl1 && usl2) ? "Triangle is sharp-angled" : "Triangle isn't sharp-angled" ) << endl;
}

void sr () {
    // int nn;

    // cout << "Enter n: ";
    // cin >> nn;
    float r = 0;
    int ns[] = {124, 100,4000, 591, 73};

    cout << "ln2: " << log(2) << endl;


    for (int i = -6; i <= -2; i++) {
        r = 0;
        for (int k = 1; k <= ns[i + 6]; k++) {
            r += pow(-1, k-1) / k;
        }
        cout << "Result with accuracy 1e" << i <<": " << r << endl << endl;
    }


}

void e () {
    int nn; float r = 1;
    cout << "Enter n: ";
    cin >> nn;

    for (int n = 0; n <= nn; n++) {
        r *= 1 + pow(0.5, 2*n);
    }

    cout << "Result: " << r;
}

void PIMonteCarlo () {

}

void tst () {
    float r = 0;
    // int ns[] = {124, 100, 75, 54, 28};

    float ln2 = log(2);


    for (int i = 1; i <= 10000; i += 2) {
        r = 0;
        for (int k = 1; k <= i; k++) {
            r += pow(-1, k-1) / k;
        }
        if ( ((ln2 - r < 0.01)|| (ln2 - r < 0.001) || (ln2 - r < 0.0001)|| (ln2 - r < 0.00001) || (ln2 - r < 0.000001)) && ((ln2 - r > 0) || (ln2 - r > 0) || (ln2 - r > 0)|| (ln2 - r > 0) || (ln2 - r > 0))) {
            cout << "i = " << i <<": " << r  << " " << ln2 - r << endl;
        }
    }
    cout << "ln2: " << log(2) << endl;

}



int main () {
    int n;
    cout << "Enter the num of task:";
    cin >> n;

    switch (n) {
        case 1: F(); break;
        case 2: triangle(); break;
        case 3: sr(); break;
        case 4: e(); break;
        case 6: tst(); break;
    }

    return 0;
}


