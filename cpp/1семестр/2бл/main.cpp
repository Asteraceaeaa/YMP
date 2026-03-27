#include <iostream>
#include <cmath>

using namespace std;

namespace serviceBlock2 {
    float area(float p1[2], float p2[2], float p3[2]) {
        return abs((p2[0]-p1[0])*(p3[1]-p1[1]) - (p3[0]-p1[0])*(p2[1]-p1[1])) / 2.0f;
    }

    bool isInCircle(float x, float y) {
        return ((pow(x - 1, 2) + pow(y, 2)) <= 1) || (((x + 1, 2) + pow(y, 2)) <= 1);
    }
}

//1
void y() {
    int x;
    cout << "Enter the x -> ";
    cin >> x;

    if (x < -5) cout << x + 1;
    else if (-5 <= x && x < 5) cout << pow(x, 2) + 2;
    else cout << pow(x, 3) + 3;
}
// Тесты:
// -10 -> -9
// 0 -> 2

//2
void circle_square () {
    int P, S;

    cout << "Enter P: ";
    cin >> P;
    cout << "Enter S: ";
    cin >> S;

    float a_of_square = sqrt(P);
    float d_of_square = a_of_square * sqrt(2); // P = a^2; d = a*(2^0.5)
    float d_of_circle = sqrt(S / M_PI) * 2; // S = (d/2)^2/Pi

    // The centre of circle and square is same =>
    // if d_of_square <= d_of_circle => square in circle.
    // if a_of_square >= d_of_circle => circle in square.
    // else => No

    if (d_of_square <= d_of_circle) cout << "Square is in circle";
    else if (a_of_square >= d_of_circle) cout << "Circle is in square";
    else cout << "No";
}
// Тесты:
// 4 12 -> Square is in circle
// 16 12 -> Circle is in square

//3
void triangle() {
    float A[2], B[2], C[2], P[2];

    cin >> A[0] >> A[1];
    cin >> B[0] >> B[1];
    cin >> C[0] >> C[1];
    cin >> P[0] >> P[1];

    float areaABC = serviceBlock2::area(A, B, C);
    if (round(serviceBlock2::area(A, B, C) * 10) == round((serviceBlock2::area(A, B, P) + serviceBlock2::area(A, P, C) + serviceBlock2::area(B, P, C)) * 10)) {
        cout << "Yes";
    } else cout << "No";
}
// Тесты:
// 0 0 0 1 1 0 0.5 0.5 -> Yes
// 0 0 0 1 1 0 2 2 -> No

//4
void triangle1 () {
    int a, b, c;

    cout << "Enter a ->";
    cin >> a;
    cout << "Enter b ->";
    cin >> b;
    cout << "Enter c ->";
    cin >> c;

    if ((a + b) > c) {
        if ((a + c) > b) {
            if ((c + b) > a) cout << "Yes";
            else cout << "No";
        } else cout << "No";
    } else cout << "No";
}
// Тесты:
// 3 4 5 -> Yes
// 1 2 4 -> No

//5
void shot () {
    float P[2];

    cout << "Enter x, y:" << endl;
    cin >> P[0] >> P[1];

    if ((P[0] < 0 && P[1] < 0) && (P[0] >= -2 && P[1] >= -2) && (P[1] >= -2 - P[0])) {
        cout << "Yes";
    } else if ((pow(P[0], 2) + pow(P[1], 2)) == 1){
        cout << "Yes";
    } else cout << "No";
}
// Тесты:
// -1 -1 -> Yes
// 0 -1 -> Yes

//6
void shot2 () {
    float P[2];

    cin >> P[0] >> P[1];

    if ((P[1] <= 0) && serviceBlock2::isInCircle(P[0], P[1])) {
        cout << "Yes";
    } else cout << "No";
}
// Тесты:
// 0 -0.5 -> Yes
// 2 0 -> No

//7
void deviders () {
    float x, y;

    cin >> x >> y;

    if ( (2 >= (pow(x, 2) - y)) && (0 <= (abs(x) - y)) ) {
        cout << "Yes";
    } else cout << "No";
}
// Тесты:
// 0 0 -> Yes
// 2 4 -> No

//8
void shot4 () {
    float x, y;

    cin >> x >> y;

    if ( ((pow(x, 2) + pow(y, 2)) >= 4) && (x <= 2) && (y <= x) ) {
        cout << "Yes";
    } else cout << "No";
}
// Тесты:
// 1 0 -> Yes
// 0 1 -> No

//9
void luckyTicket () {
    int num;

    cout << "Enter the number ->";
    cin >> num;

    int a = num / 1000 + num / 100 % 10;
    int b = num / 100 % 10 + num / 10 % 10;
    int c = num / 10 % 10 + num % 10;
    cout << a << " " << b << " " << c << endl;
    cout << max(min(a, b), min(b, c)) << max(max(a, b), max(b, c));
}
// Тесты:
// 1234 -> 3 5 7 -> 57
// 1111 -> 2 2 2 -> 22

//10
void cosinus () {
    int a, b, c;

    cout << "Enter a numbers:" << endl;
    cin >> a;
    cin >> b;
    cin >> c;

    if (a % 2 == 0 || b % 2 == 0 || c % 2 == 0) {
        cout << "Yes";
    } else cout << "No";
}
// Тесты:
// 1 3 5 -> No
// 1 2 3 -> Yes

//11
void sinus () {
    int a;

    cout << "Enter a num:" << endl;
    cin >> a;

    if((( a / 100) <= (a / 10 % 10)) && ((a / 10 % 10) <= (a % 10))) {
        cout << "Yes";
    } else cout << "No";
}
// Тесты:
// 123 -> Yes
// 321 -> No

//12
void Wallis () {
    int a;

    cout << "Enter a num:" << endl;
    cin >> a;

    if(((a / 100) == (a / 10 % 10)) || ((a / 10 % 10) == (a % 10)) || ((a / 100) == (a % 10))) {
        cout << "Yes";
    } else cout << "No";
}
// Тесты:
// 112 -> Yes
// 123 -> No

//13
void isThreeDigit () {
    int a;

    cout << "Enter a num:" << endl;
    cin >> a;

    if((a < 1000) && (a > 99)) {
        cout << "Yes";
    } else cout << "No";
}
// Тесты:
// 999 -> Yes
// 1000 -> No

//14
void isPalindrome () {
    int a;

    cout << "Enter a num:" << endl;
    cin >> a;

    if(((a / 1000) == (a % 10)) && ((a / 100 % 10) == (a / 10 % 10))) {
        cout << "Yes";
    } else cout << "No";
}
// Тесты:
// 1221 -> Yes
// 1234 -> No

//15
void isPhifagorsThree () {
    int a, b, c;

    cout << "Enter a nums:" << endl;
    cin >> a;
    cin >> b;
    cin >> c;


    if (((c*c + a*c) == b*b) || ((b*b + c*c) == a*a) || ((a*a + b*b) == c*c)) {
        cout << "Yes";
    } else cout << "No";
}
// Тесты:
// 3 4 5 -> Yes
// 1 2 3 -> No

int main () {
    int number_of_task;

    cout << "Enter the num of task: ";
    cin >> number_of_task;

    switch (number_of_task) {
        case 1: y(); break;
        case 2: circle_square(); break;
        case 3: triangle(); break; // Isn't completed
        case 4: triangle1(); break;
        case 5: shot(); break; // Isn't completed
        case 6: shot2(); break;
        case 7: deviders(); break;
        case 8: shot4(); break;
        case 9: luckyTicket(); break;
        case 10: cosinus(); break; // Isn't completed
        case 11: sinus(); break;
        case 12: Wallis(); break; // Isn't completed
        case 13: isThreeDigit(); break;
        case 14: isPalindrome(); break;
        case 15: isPhifagorsThree(); break;
        default: 0;
    }
}









//
// #include <iostream>
// #include <cmath>
//
//
// using namespace std;
//
// namespace serviceBlock2 {
//     float area(float p1[2], float p2[2], float p3[2]) {
//         return abs((p2[0]-p1[0])*(p3[1]-p1[1]) - (p3[0]-p1[0])*(p2[1]-p1[1])) / 2.0f;
//     }
//
//     bool isInCircle(float x, float y) {
//         return ((pow(x - 1, 2) + pow(y, 2)) <= 1) || (((x + 1, 2) + pow(y, 2)) <= 1);
//     }
// }
//
//
// //1
// void y() {
//     int x;
//     cout << "Enter the x -> ";
//     cin >> x;
//
//     if (x < -5) cout << x + 1;
//     else if (-5 <= x && x < 5) cout << pow(x, 2) + 2;
//     else cout << pow(x, 3) + 3;
// }
// //2
// void circle_square () {
//     int P, S;
//
//     cout << "Enter P: ";
//     cin >> P;
//     cout << "Enter S: ";
//     cin >> S;
//
//     float a_of_square = sqrt(P);
//     float d_of_square = a_of_square * sqrt(2); // P = a^2; d = a*(2^0.5)
//     float d_of_circle = sqrt(S / M_PI) * 2; // S = (d/2)^2/Pi
//
//     // The centre of circle and square is same =>
//     // if d_of_square <= d_of_circle => square in circle.
//     // if a_of_square >= d_of_circle => circle in square.
//     // else => No
//
//     if (d_of_square <= d_of_circle) cout << "Square is in circle";
//     else if (a_of_square >= d_of_circle) cout << "Circle is in square";
//     else cout << "No";
// }
// //3
// void triangle() {
//     float A[2], B[2], C[2], P[2];
//
//     cin >> A[0] >> A[1];
//     cin >> B[0] >> B[1];
//     cin >> C[0] >> C[1];
//     cin >> P[0] >> P[1];
//
//     float areaABC = serviceBlock2::area(A, B, C);
//     if (round(serviceBlock2::area(A, B, C) * 10) == round((serviceBlock2::area(A, B, P) + serviceBlock2::area(A, P, C) + serviceBlock2::area(B, P, C)) * 10)) {
//         cout << "Yes";
//     } else cout << "No";
//
//
// }
// //4
// void triangle1 () {
//
//     int a, b, c;
//
//     cout << "Enter a ->";
//     cin >> a;
//     cout << "Enter b ->";
//     cin >> b;
//     cout << "Enter c ->";
//     cin >> c;
//
//     if ((a + b) > c) {
//         if ((a + c) > b) {
//             if ((c + b) > a) cout << "Yes";
//             else cout << "No";
//         } else cout << "No";
//     } else cout << "No";
//
// }
// //5
// void shot () {
//
//     float P[2];
//
//     cout << "Enter x, y:" << endl;
//     cin >> P[0] >> P[1];
//
//     if ((P[0] < 0 && P[1] < 0) && (P[0] >= -2 && P[1] >= -2)) {
//
//         if ((P[1] >= -2 - P[0])) {
//             cout << "Yes";
//         }
//     } else if ((pow(P[0], 2) + pow(P[1], 2)) == 1)
//         {
//             cout << "Yes";
//         } else cout << "No";
// }
// //6
// void shot2 () {
//     float P[2];
//
//     cin >> P[0] >> P[1];
//
//     if ((P[1] <= 0) && serviceBlock2::isInCircle(P[0], P[1])) {
//         cout << "Yes";
//     } else cout << "No";
// }
// //7
// void deviders () {
//     float x, y;
//
//     cin >> x >> y;
//
//     if ( (2 >= (pow(x, 2) - y)) && (0 <= (abs(x) - y)) ) {
//         cout << "Yes";
//     } else cout << "No";
// }
// //8
// void shot4 () {
//     float x, y;
//
//     cin >> x >> y;
//
//     if ( ((pow(x, 2) + pow(y, 2)) >= 4) && (x <= 2) && (y <= x) ) {
//         cout << "Yes";
//     } else cout << "No";
// }
// //9
// void luckyTicket () {
//
//     int num;
//
//     cout << "Enter the number ->";
//     cin >> num;
//
//     int a = num / 1000 + num / 100 % 10;
//     int b = num / 100 % 10 + num / 10 % 10;
//     int c = num / 10 % 10 + num % 10;
//     cout << a << " " << b << " " << c << endl;
//     cout << max(min(a, b), min(b, c)) << max(max(a, b), max(b, c));
// }
// //10
// void cosinus () {
//     int a, b, c;
//
//     cout << "Enter a numbers:" << endl;
//     cin >> a;
//     cin >> b;
//     cin >> c;
//
//     if (a % 2 == 0 || b % 2 == 0 || c % 2 == 0) {
//         cout << "Yes";
//     } else cout << "No";
// }
// //11
// void isIncrease () {
//     int a;
//
//     cout << "Enter a num:" << endl;
//     cin >> a;
//
//     if((( a / 100) <= (a / 10 % 10)) && ((a / 10 % 10) <= (a % 10))) {
//         cout << "Yes";
//     } else cout << "No";
// }
// //12
// void existSame () {
//     int a;
//
//     cout << "Enter a num:" << endl;
//     cin >> a;
//
//     if(((a / 100) == (a / 10 % 10)) || ((a / 10 % 10) == (a % 10)) || ((a / 100) == (a % 10))) {
//         cout << "Yes";
//     } else cout << "No";
// }
// //13
// void isThreeDigit () {
//     int a;
//
//     cout << "Enter a num:" << endl;
//     cin >> a;
//
//     if((a < 1000) && (a > 99)) {
//         cout << "Yes";
//     } else cout << "No";
// }
// //14
// void isPalindrome () {
//     int a;
//
//     cout << "Enter a num:" << endl;
//     cin >> a;
//
//     if(((a / 1000) == (a % 10)) && ((a / 100 % 10) == (a / 10 % 10))) {
//         cout << "Yes";
//     } else cout << "No";
// }
// //15
// void isPifagorsThree () {
//     int a, b, c;
//
//     cout << "Enter a nums:" << endl;
//     cin >> a;
//     cin >> b;
//     cin >> c;
//
//     a *= a;
//     b *= b;
//     c *= c;
//
//     if (((c + a) == b) || ((b + c) == a) || ((a + b) == c)) {
//         cout << "Yes";
//     } else cout << "No";
// }
//
//
// int main () {
//
//     int number_of_task;
//
//     cout << "Enter the num of task: ";
//     cin >> number_of_task;
//
//     switch (number_of_task) {
//         case 1: y(); break;
//         case 2: circle_square(); break;
//         case 3: triangle(); break; // Isn't completed
//         case 4: triangle1(); break;
//         case 5: shot(); break; // Isn't completed
//         case 6: shot2(); break;
//         case 7: deviders(); break;
//         case 8: shot4(); break;
//         case 9: luckyTicket(); break;
//         case 10: cosinus(); break; // Isn't completed
//         case 11: isIncrease(); break;
//         case 12: existSame(); break; // Isn't completed
//         case 13: isThreeDigit(); break;
//         case 14: isPalindrome(); break;
//         case 15: isPifagorsThree(); break;
//         default: 0;
//     }
//
//
//
// }
//
//
//
