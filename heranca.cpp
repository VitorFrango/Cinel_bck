//
// Created by Vitor Frango on 29/11/2022.
//
#include <iostream>

using namespace std;


class A {
private:
    int x;

public:
    A(int x) : x(x){
    }

    int getX() {
        return this->x;
    }

    void setX(int x) {
        this->x = x;
    }
};

class B : public A {
private:
    int z;

public:
    B(int z, int x): A(x), z(z) {}

    int getZ() {
        return this->z;
    }

    void setZ(int z) {
        this->z = z;
    }
};


int main() {
    B b(1,2);
    A a(3);

    cout << "B x:" << b.getX() << endl;
}