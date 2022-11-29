//
// Created by Vitor Frango on 29/11/2022.
//
#include <iostream>
#include <vector>

using namespace std;

class Conta {
private:
    int id;
    double saldo;
    double descobertoMaximo;

public:
    Conta(int novoId, double novoSaldo, double novoDescoberto)
            : id(novoId), saldo(novoSaldo), descobertoMaximo(novoDescoberto) {}


    int getId() {
        return this->id;
    }

    double getSaldo() {
        return this->saldo;
    }

    double getDescoberto() {
        return this->descobertoMaximo;
    }


    void setId(int novoId) {
        this->id = novoId;
    }

    void setSaldo(double novoSaldo) {
        this->saldo = novoSaldo;
    }

    void setDescoberto(double novoDescoberto) {
        this->descobertoMaximo = novoDescoberto;
    }

    virtual void actualizacaoMensal() {
        cout << "Actualização da conta" << endl;
    }
};


class ContaPoupanca : public Conta {
private:
    double juro;

public:
    ContaPoupanca(int id, double saldo, double descoberto, double novoJuro)
            : Conta(id, saldo, descoberto), juro(novoJuro) {}

    double getJuro() {
        return this->juro;
    }

    void setJuro(double novoJuro) {
        this->juro = novoJuro;
    }

    virtual void actualizacaoMensal() override {
        double novoSaldo = 0;
        novoSaldo = this->getSaldo() * (1 + this->getJuro() / 12);
        cout << novoSaldo << endl;

        this->setSaldo(novoSaldo);
    }
};

class ContaOrdenado : public Conta {
private:
    double juroCredito;

public:
    ContaOrdenado(int id, double saldo, double descoberto, double novoJuro)
            : Conta(id, saldo, descoberto), juroCredito(novoJuro) {}


    double getJuro() {
        return this->juroCredito;
    }

    void setJuro(double novoJuro) {
        this->juroCredito = novoJuro;
    }

    virtual void actualizacaoMensal() override {
        if (this->getSaldo() < 0) {
            double novoSaldo = 0;
            novoSaldo = this->getSaldo() * (1 + this->getJuro() / 12);

            this->setSaldo(novoSaldo);
        }
    }
};

int main() {
    vector<Conta*> contas = {};
    vector<Conta*> contasPremium = {};
    vector<Conta*> contasDefaults = {};

    Conta* co1 = new ContaOrdenado(1, 100, 100, 0.12);
    Conta* co2 = new ContaOrdenado(2, 500, 200, 0.12);
    Conta* cp1 = new ContaPoupanca(3, 100, 0, 0.01);

    contas.push_back(co1);
    contas.push_back(co2);
    contas.push_back(cp1);

    contasPremium.push_back(cp1);

    for (Conta* item : contas) {
        item->actualizacaoMensal();
    }

    cout << endl << endl << "Contas premium:" << endl;
    for (Conta* item : contasPremium) {
        cout << "Conta " << item->getId() << " Saldo: " << item->getSaldo() << endl;
    }

    return 0;
}