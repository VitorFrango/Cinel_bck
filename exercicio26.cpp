#include<iostream>

using namespace std;

// definicao da classe 
class Cancao{

    public:

        // atributos
        string nome;
        string artista;
        int ano;

        // constutor 
        Cancao(){}

        Cancao (string name, string art, int year)
                : nome(name), artista(art), ano(year){}

        

};

int main(){

    // criar instancias 
    Cancao c1;
    c1.nome = "Amish Paradise ";
    c1.artista = " Weird <Al";
    c1.ano = 1996;


    Cancao c2;
    c2.nome = "Sete Mares ";
    c2.artista = "Setima legião";
    c2.ano = 1997;

    Cancao c3("Siga a malta", "Estou a testar", 2015);

    cout << c1.nome << endl;
    cout << c1.artista << endl;
    cout << c1.ano << endl;

    cout << c2.nome << endl;
    cout << c2.artista << endl;
    cout << c2.ano << endl;

    cout << c3.nome << endl;
    cout << c3.artista << endl;
    cout << c3.ano << endl;



}
