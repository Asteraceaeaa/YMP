
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    // char raw_data[100];

    // FILE* f = fopen("in.txt", "r");

    // if (!f) {
    //     cerr << "Error";
    //     exit(1);
    // }


    // fgets(raw_data, in)
    // int c = 3;
    // auto add = [c] (int a, int b) -> int {return a + b + c;};

    // const int n = 12;
    // int arr[n];
    // int *p = arr;
    // *(p + 2) = 12;

    // cout << add(1, 2) << *(p + 2)  << "\n";

    // int b = 12;
    // int &s = b;
    // cout << &s;

    enum Weekday {
        MONDAY,     // 0
        TUESDAY,    // 1
        WEDNESDAY,  // 2
        THURSDAY,   // 3
        FRIDAY,     // 4
        SATURDAY,   // 5
        SUNDAY      // 6

    };

    Weekday today = MONDAY;
    cout << today;

    
}
