//
// Created by q1nvy on 05.09.2025.
//

#include  <iostream>
// #include <cmath>
// #include <iomanip>

#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

void first () {
    int userInput;

    cout << "Enter a Number";
    cin >> userInput;
    cout << userInput % 10;
    // Test 1: 123 -> 3
    // Test 2: 100 -> 0
}


void second () {

    float a, b;

    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin>>b;

    cout << round((pow((pow(a, 2) + pow(b, 2)), 0.5))* 100) / 100 << endl;

    cout << fixed << setprecision(2) << pow((pow(a, 2) + pow(b, 2)), 0.5) << endl;

    // Test 1: 5 12 -> 13.00
    // Test 2: 8 15 -> 17.00
    // Test 3: 1 2 -> 2.24


}

void third () {
    int num;
    cout << "Enter a Number: ";
    cin >> num;
    cout << num / 10 % 10;

    // Test 1: 1234 -> 3
    // Test 2: 100 -> 0
}

void fourth () {
    int num;
    cout << "Enter a num: ";
    cin >> num;
    cout << num / 100 + (num / 10) % 10 + num % 10;
    // Test 1: 123 -> 6
    // Test 2: 999 -> 27
}

void fifth () {
    int num;

    cin >> num;

    cout << num + 2 - num % 2;
    // Test 1: 10 -> 12
    // Test 2: 15 -> 16
}

void sixth () {
    int a, b;

    cin >> a;
    cin >> b;
    b = a + b;
    a = b - a;
    b = b - a;

    cout << a << endl << b;

    // Test 1: 1 2 -> 2 1
    // Test 2: -5 10 -> 10 -5
}

void seventh () {

    int input;
    cin >> input;
    int h = input / 3600;
    int m = (input - 3600 * h) / 60;
    int s = (input - 60 * m) % 60;

    string ms = to_string(m);
    string ss = to_string(s);

    while (h > 12) h -= 12;
    if (to_string(m).length() < 2) ms = "0" + ms;
    if (ss.length() < 2) ss = "0" + ss;
    cout << h << ":" << ms << ":" << ss;

    // Test 1: 3661 -> 1:01:01
    // Test 2: 86399 -> 11:59:59

}

void eighth () {

    float A[3], B[3], C[3];

    cout << "Enter coordinates of a first point\n";
    cin >> A[0] >> A[1] >> A[2];

    cout << "Enter coordinates of a second point\n";
    cin >> B[0] >> B[1] >> B[2];

    cout << "Enter coordinates of a third point\n";
    cin >> C[0] >> C[1] >> C[2];

    double AB = sqrt(pow((B[0] - A[0]), 2) + pow((B[1] - A[1]), 2) + pow((B[2] - A[2]), 2));
    double BC = sqrt(pow((C[0] - B[0]), 2) + pow((C[1] - B[1]), 2) + pow((C[2] - B[2]), 2));
    double CA = sqrt(pow((A[0] - C[0]), 2) + pow((A[1] - C[1]), 2) + pow((A[2] - C[2]), 2));

    if ((AB + BC) > CA) {
        if ((AB + CA) > BC) {
            if ((BC + CA) > AB) {
                double P = AB + BC + CA;
                double p = P/2;
                double S = sqrt(p*(p-AB)*(p-BC)*(p-CA));

                cout << fixed << setprecision(3);
                cout << P << " " << S;

            } else cout << "Triangle is not exist";
        } else cout << "Triangle is not exist";
    } else cout << "Triangle is not exist";


    // Test 1: 0 0 0 3 0 0 0 4 0 -> 12.000 6.000
    // Test 2: 1 1 1 4 5 6 7 8 9 -> 22.045 0.000
}

void ninth () {

    int num;

    cin >> num;
    cout << num % 10 << ", " << num / 10 % 10 << ", " << num / 100;

    // Test 1: 123 -> 3, 2, 1
    // Test 2: 900 -> 0, 0, 9
}

void tenth () {

    int num;

    cin >> num;
    cout << num / 100 % 10 << num / 10 % 10;

    // Test 1: 1001 -> 00
    // Test 2: 9999 -> 99
}

void eleventh () {

    short int num, c = 0, res = 0;

    cout << "Enter the num " << endl;
    cin >> num;

    while (num > 0) {
        res += (num % 10) * pow(2, c);
        c++;
        num /= 10;
    }

    cout << "Result: " << res;

    // Test 1: 1010 -> 10
    // Test 2: 10000 -> 16
}

void tvelvth () {

    int num;
    string eightnum = "";
    cin >> num;
    int ost;
    while (num > 0) {
        eightnum = to_string(num % 8) + eightnum;

        num /= 8;
    }
    cout << eightnum;
    // Test 1: 100 -> 144
    // Test 2: 511 -> 777
}

int main () {

    int n;
    cout << "Enter a num of task";
    cin >> n;


    switch (n) {

        case 1: first(); break;
        case 2: second(); break;
        case 3: third(); break;
        case 4: fourth(); break;
        case 5: fifth(); break;
        case 6: sixth(); break;
        case 7: seventh(); break;
        case 8: eighth(); break;
        case 9: ninth(); break;
        case 10: tenth(); break;
        case 11: eleventh(); break;
        case 12: tvelvth(); break;
        default: 0;
    }





    // #1

    // int userInput;
    //
    // cout << "Enter a Number";
    // cin >> userInput;
    // cout << userInput % 10;


    // #2
    // float a, b;
    //
    // cout << "Enter a: ";
    // cin >> a;
    // cout << "Enter b: ";
    // cin>>b;
    //
    // cout << round((pow((pow(a, 2) + pow(b, 2)), 0.5))* 100) / 100 << endl;
    //
    // cout << fixed << setprecision(2) << pow((pow(a, 2) + pow(b, 2)), 0.5) << endl;



    // #3

    // int num;
    // cout << "Enter a Number: "
    // cin >> num;
    // cout << num / 10 % 10;

    // #4

    // int num;
    // cout << "Enter a num: ";
    // cin >> num;
    // cout << num / 100 + (num / 10) % 10 + num % 10;

    // #5

    // int num;
    //
    // cin >> num;
    //
    // cout << num + 2 - num % 2;

    // #6
    // int a, b;
    //
    // cin >> a;
    // cin >> b;
    // b = a + b;
    // a = b - a;
    // b = b - a;
    //
    // cout << a << endl << b;

    // #7

    // int input;
    // cin >> input;
    // int h = input / 3600;
    // int m = (input - 3600 * h) / 60;
    // int s = (input - 60 * m) % 60;
    //
    // string ms = to_string(m);
    // string ss = to_string(s);
    //
    // while (h > 12) h -= 12;
    // if (to_string(m).length() < 2) ms = "0" + ms;
    // if (ss.length() < 2) ss = "0" + ss;
    // cout << h << ":" << ms << ":" << ss;



    // #8

    // float A[3], B[3], C[3];
    //
    // cout << "Enter coordinates of a first point\n";
    // cin >> A[0] >> A[1] >> A[2];
    //
    // cout << "Enter coordinates of a second point\n";
    // cin >> B[0] >> B[1] >> B[2];
    //
    // cout << "Enter coordinates of a third point\n";
    // cin >> C[0] >> C[1] >> C[2];
    //
    // double AB = sqrt(pow((B[0] - A[0]), 2) + pow((B[1] - A[1]), 2) + pow((B[2] - A[2]), 2));
    // double BC = sqrt(pow((C[0] - B[0]), 2) + pow((C[1] - B[1]), 2) + pow((C[2] - B[2]), 2));
    // double CA = sqrt(pow((A[0] - C[0]), 2) + pow((A[1] - C[1]), 2) + pow((A[2] - C[2]), 2));
    //
    // double P = AB + BC + CA;
    // double p = P/2;
    // double S = sqrt(p*(p-AB)*(p-BC)*(p-CA));
    //
    // cout << fixed << setprecision(3);
    // cout << P << " " << S;

    // #9

    // int num;
    //
    // cin >> num;
    // cout << num % 10 << ", " << num / 10 % 10 << ", " << num / 100;

    // #10

    // int num;
    //
    // cin >> num;
    // cout << num / 100 % 10 << num / 10 % 10;


    // #11

    // int num;
    // int res = 0;
    // int mp = 1;
    //
    // cin >> num;
    //
    // while (num > 0) {
    //
    //     res = (num % 2)*mp + res;
    //     num /= 2;
    //     mp *= 10;
    // }
    //
    // cout << res;

    // #12

    // int num;
    // string eightnum = "";
    // cin >> num;
    // int ost;
    // while (num > 0) {
    //     eightnum = to_string(num % 8) + eightnum;
    //
    //     num /= 8;
    // }

    // int num;
    //
    // cin >> num;
    // int mp = 1;
    // int res = 0;
    //
    // while (num > 0) {
    //     res += (num % 8) * mp;
    //     num /= 8;
    //     mp *= 10;
    // }
    //
    // cout << res;


}