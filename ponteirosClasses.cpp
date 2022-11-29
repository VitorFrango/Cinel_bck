//
// Created by Vitor Frango on 29/11/2022.
//


#include <iostream>

using namespace std;

class Pessoa {
public:
    int idade;
    string nome;

    Pessoa(int initIdade, string initNome)
            : idade(initIdade), nome(initNome) {}
};

int main() {
    Pessoa* p1 = new Pessoa(50, "António");
    Pessoa* p2 = new Pessoa(27, "Manuel");
    Pessoa* p3 = new Pessoa(60, "Maria");
    Pessoa* p4 = new Pessoa(25, "Diana");

    // Primeiro Ministro
    Pessoa* pm;

    pm = p4;

    cout << "PM: " << pm->nome << endl;

    pm = p3;

    cout << "PM: " << pm->nome << endl;

}