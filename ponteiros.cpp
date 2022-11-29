//
// Created by Vitor Frango on 29/11/2022.
//
#include <iostream>

using namespace std;

int main() {
    int x = 27;
    int w = 42;

    int* y = &w;
    int* z = &x;

    int a[4] = {1, 2, 3, 4};
    bool b[4] = {true, false, false, true};


    cout << a << endl;
    cout << a + 1 << endl;
    cout << *(a+0) << endl;
    cout << *(a+1) << endl;
    cout << *(a+2) << endl;
    cout << *(a+3) << endl;
    cout << a[0] << endl;
    cout << a[1] << endl;
    cout << a[2] << endl;
    cout << a[3] << endl;

    cout << b << endl;
    cout << (b + 1) << endl;
    cout << *(b+0) << endl;
    cout << *(b+1) << endl;
    cout << *(b+2) << endl;
    cout << *(b+3) << endl;


    cout << "X: " << x << endl;
    cout << "&X: " << &x << endl << endl;

    cout << "W: " << w << endl;
    cout << "&W: " << &w << endl << endl;

    // Ox: 0, 1, 2 ... 9, A,   B,  C,  D,  E,  F
    // 10: 0, 1, 2, ...9, 10, 11, 12, 13, 14, 15

    cout << "Y: " << y << endl;
    cout << "Y: " << y + 1 << endl;
    cout << "*Y: " << *y << endl << endl;
    cout << "*Y: " << *(y+1) << endl << endl;

    y = &x;



    cout << "Y: " << y << endl;
    cout << "*Y: " << *y << endl;

    cout << "Soma Z + Y: " << *y + *z << endl;
    // cout << "Soma Z + Y: " << y + z << endl;
}