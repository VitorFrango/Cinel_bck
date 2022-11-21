//
// Created by Vitor Frango on 17/11/2022.
//
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <sstream>


using namespace std;

class Editora {
private:
    string          nome;
    int             ano;
    vector<string>  cancoes;

public:
    Editora() {};

    Editora(string novoNome, int novoAno, vector<string> novasCancoes)
            : nome(novoNome), ano(novoAno), cancoes(novasCancoes) {}


    void setNome(string novoNome) {
        this->nome = novoNome;
    }

    string getNome() {
        return this->nome;
    }

    void setAno(int novoAno) {
        this->ano = novoAno;
    }

    int getAno() {
        return this->ano;
    }

    void setCancoes(vector<string> novasCancoes) {
        this->cancoes = novasCancoes;
    }

    vector<string> getCancoes() {
        return this->cancoes;
    }

    void adicionarCancao(string novaCancao) {
        this->cancoes.push_back(novaCancao);
    }

    bool removerCancao(string cancao) {
        int tamanho = this->cancoes.size();

        for (int i = 0; i < tamanho; i++) {
            if (this->cancoes[i] == cancao) {
                this->cancoes.erase(this->cancoes.begin() + i);
                return true;
            }
        }

        return false;
    }

    string listaCancoes() {
        int tamanho = this->cancoes.size();
        string cancoesString = "";

        for (int i = 0; i < tamanho; i++) {
            cancoesString += this->cancoes[i] + ", ";
        }

        return cancoesString;
    }

};

int main() {
    string  nomeSony = "Sony";
    int     anoSony = 1950;
    vector<string> listaCancoes = { "Sete Mares", "Amish Paradise", "Siga a malta" };
    vector<Editora> editoras = {};

    Editora sony(nomeSony, anoSony, listaCancoes);
    editoras.push_back(sony);

    bool continuar = true ;
    int input;
    string  inputstring;

    while (continuar){

        cout << endl << " Menu das editoras" << endl;
        cout << "escolha uma das seguintes opção:" << endl;
        cout << "\t[1] adicionar uma editora" << endl;
        cout << "\t[2] Remove as editoras " << endl;
        cout << "\t[3] Ver editoras " << endl;
        cout << "\t[4] Listar as editoras " << endl;
        cout << "\t[0] SAIR " << endl;

        cin >> input;

        switch (input) {
            case 1:
                string nomeNovaEditora;
                int anoNovaEditora;
                vector<string> listaCancaoNovaEditora = {};

                cout << " Adicione o nome da nova editora" << endl;
                cin >> anoNovaEditora;

                cout << " Adicione o ano de fundação de editora " << endl;
                cin >> anoNovaEditora;

                cout << "Adicione a lista de canções separadas por virgulas" << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, inputstring);
                cout << inputstring << endl;

                stringstream streamMusicas(inputstring);

                while (streamMusicas.good()) {
                        string token;
                        getline(streamMusicas, token, ',');
                        listaCancaoNovaEditora.push_back(token);
                }

                Editora novaEditora(nomeNovaEditora, anoNovaEditora, listaCancaoNovaEditora);
                break;

            case 2:
                cout << "Por favor escreva i nome da editora a removar" << endl;
                getline(cin, inputstring);


                for (int i = 0 ; i < editoras.size(); i++){
                    Editora editora = editoras[i];

                    if (editora.getNome() == inputstring ){
                        editoras.erase(editoras.begin() + i );
                        break;
                    }




                    }


                }

                break;



        }


        cout << endl << endl << "\t:: Menu da editora :: " << endl;
        cout << "escolha uma opção:" << endl;
        cout << "\t[1] adicionar uma canção" << endl;
        cout << "\t[2] remover uma canção " << endl;
        cout << "\t[3] Listar as editoras " << endl;

        cout <<  endl << "\t[0] SAIR " << endl;
        cin >> input;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');


        switch (input) {
            case 0:
                continuar = false;
                break;
            case 1:
                cout << " Por favor escreva o nome da canção" << endl;
                getline(cin, inputstring);
               //cin.ignore(numeric_limits<streamsize>::max() , '\n');
                sony.adicionarCancao(inputstring);
                break;

            case 2:
                cout << " Qual a canção  quer remover" << endl;
                getline(cin, inputstring);
                sony.removerCancao(inputstring);
                cout << inputstring << flush;
                break;

            case 3:
                cout << "Lista de canções da editora" << sony.getNome() << ":" << endl;
                cout << sony.listaCancoes();

                break;

        }
    }



    sony.setAno(1902);

    cout << "Sony: " << sony.getAno() << endl;

    bool removeuCancao = sony.removerCancao("Sete Mares");

    if (removeuCancao) {
        cout << "Removeu a canção: " << "Sete Mares" << endl;
    } else {
        cout << "A canção: " << "Sete Mares" << " Não está na lista de cancões da editora:";
        cout << sony.getNome() << endl;
    }

    cout << "Lista de canções da editora: " << sony.getNome() << endl;
    cout << sony.listaCancoes() << endl << endl;


    for (int i = 0; i < listaCancoes.size(); i++) {
        cout << "Musica [" << (i+1) << "]"  << listaCancoes[i] <<  endl;
    }

}