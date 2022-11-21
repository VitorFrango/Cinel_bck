#include <iostream>
#include <vector>
#include <string>
#include <limits> // Alteração
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

void menuEditora(Editora &editora) {
    int input;
    string inputString;
    cout << endl << endl << "Menu da Editora " << editora.getNome() << ": " << endl;
    cout << "Escolha uma das seguintes opções:" << endl;
    cout << "\t[1] - Adicionar uma canção" << endl;
    cout << "\t[2] - Remover uma canção" << endl;
    cout << "\t[3] - Listar as canções" << endl; // alterações
    cout << endl << "\t[0] - Sair do Menu" << endl;
    cin >> input;
    cin.ignore (numeric_limits<streamsize>::max(), '\n');


    switch (input) {
        case 0:
            break;
        case 1:
            cout << "Por favor, escreva o nome da canção a adicionar:" << endl;
            getline(cin, inputString);
            // cin.ignore (numeric_limits<streamsize>::max(), '\n');
            editora.adicionarCancao(inputString);
            break;
        case 2:
            cout << "Por favor, escreva o nome da canção a remover:" << endl;
            getline(cin, inputString);
            editora.removerCancao(inputString);
            break;

        case 3:
            cout << "Lista de canções da editora " << editora.getNome() << ":" << endl;
            cout << editora.listaCancoes();
            break;
    }
}


int main() {
    string  nomeSony = "Sony";
    int     anoSony = 1950;
    vector<string> listaCancoes = { "Sete Mares", "Amish Paradise", "Siga a malta" };
    vector<Editora> editoras = {};

    Editora sony(nomeSony, anoSony, listaCancoes);
    editoras.push_back(sony);

    bool continuar = true;
    int input;
    string inputString; // alterações

    while (continuar) {
        // system("cls");
        // MAC => system("clear");
        cout << endl << endl << "Menu das editoras: " << endl;
        cout << "Escolha uma das seguintes opções:" << endl;
        cout << "\t[1] - Adicionar uma editora:" << endl;
        cout << "\t[2] - Remove uma editora:" << endl;
        cout << "\t[3] - Ver uma editora:" << endl;
        cout << "\t[4] - Listar as editoras:" << endl;
        cout << endl << "\t[0] - Sair" << endl;



        cin >> input;
        cin.ignore (numeric_limits<streamsize>::max(), '\n');

        switch (input) {
            case 0:
            {
                continuar = false;
                break;
            }
            case 1:
            {
                string nomeNovaEditora;
                int anoNovaEditora;
                vector<string> listaCancoesNovaEditora = {};

                cout << "Adicione o nome da editora:" << endl;
                cin >> nomeNovaEditora;

                cout << "Adicione o ano de fundação da editora:" << endl;
                cin >> anoNovaEditora;

                cout << "Adicione a lista de canções separadas por vírgulas:" << endl;
                cin.ignore (numeric_limits<streamsize>::max(), '\n');
                getline(cin, inputString);
                cout << inputString << endl;

                stringstream streamMusicas(inputString);

                while(streamMusicas.good()) {
                    string token;
                    getline(streamMusicas, token, ',');
                    listaCancoesNovaEditora.push_back(token);
                }


                Editora novaEditora(nomeNovaEditora, anoNovaEditora, listaCancoesNovaEditora);

                editoras.push_back(novaEditora);

                break;
            }

            case 2:
            {
                cout << "Por favor, escreva o nome da editora a remover:" << endl;
                getline(cin, inputString);

                for (int i = 0; i < editoras.size(); i++) {
                    Editora item = editoras[i];

                    if (item.getNome() == inputString) {
                        editoras.erase(editoras.begin() + i);
                        break;
                    }
                }

                break;
            }

            case 3:
            {
                cout << "Por favor, escreva o nome da editora a ver:" << endl;
                getline(cin, inputString);

                bool existe = false;

                for (int i = 0; i < editoras.size(); i++) {
                    Editora item = editoras[i];

                    if (item.getNome() == inputString) {
                        existe = true;
                        menuEditora(item);
                        break;
                    }
                }

                if (!existe) {
                    cout << "A editora " << inputString << " não existe!" << endl;
                }

                break;
            }
            case 4:
            {
                cout << endl << "Lista de editoras: " << endl;
                for (Editora item : editoras) {
                    cout << item.getNome() << endl;
                }

                break;
            }
        }
    }

    return 0;
}