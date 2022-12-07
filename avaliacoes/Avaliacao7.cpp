//
// Created by Vitor Frango on 30/11/2022.
//

#include <iostream>
#include <vector>
#include <string>
#include <limits>


using namespace std;

class Escola {
private:
    string                  NomeEscola;
    int                     idEscola;
    string                  localidade;
    vector <string>         Turmas;

public:
    Escola(int novoIdEscola, string novoNomeEscola, string novaLocalidade, vector<string> novaTurma)
            : idEscola(novoIdEscola), NomeEscola(novoNomeEscola), localidade(novaLocalidade), Turmas(novaTurma) {}


    void setIdEscola(int novoIdEscola) {
        this->idEscola = novoIdEscola;
    }

    int getIdEscola() {
        return this->idEscola;
    }

    string getNomeEscola (){
        return this -> NomeEscola;
    }

    void setNomeEscola(string NomeEscola){
        this-> NomeEscola;
    }


    void setLocalidade(string novaLocalidade) {
        this->localidade = novaLocalidade;
    }

    string getLocalidade() {
        return this-> localidade;
    }

    void setTurmas(vector<string>novaTurma){
        this-> Turmas;
        Turmas = novaTurma;
    }
    vector<string>getTurma(){
        return  this -> Turmas;
    }


    void adicionarTurma(string novaTurma){
        this -> Turmas.push_back(novaTurma);
    }

    bool removerTurma(string turma) {
        int tamanho = this->Turmas.size();

        for (int i = 0; i < tamanho; i++) {
            if (this->Turmas[i] == turma) {
                this->Turmas.erase(this->Turmas.begin() + i);
                return true;
            }
        }

        return false;
    }



    string listaTurmas() {
        string TurmasString = "";

        for (int i = 0; i < Turmas.size(); i++) {
            TurmasString += this->Turmas[i] + ", ";
        }

        return TurmasString;
    }

    string listaNomeEscola() {
        int tamanho = this->NomeEscola.size();
        string NomeEscolaString = "";

        for (int i = 0; i < tamanho; i++) {
            NomeEscolaString += this->NomeEscola[i] + ", ";
        }

        return NomeEscolaString;
    }


};

class Turma {
private:
    int                 IdTurma;
    int                 ano;
    vector<string>      Aluno;

public:

    Turma(int novoIdTurma, int novoAno, vector<string> novoAluno)
            : IdTurma(novoIdTurma), ano(novoAno), Aluno(novoAluno) {}



    int getIdTurma() {
        return this->IdTurma;
    }

    void setAno(unsigned int  novoAno) {
        this->ano = novoAno;
    }
    int getAno() {
        return this->ano;
    }


    void setAluno(vector<string>novoAluno){
        this-> Aluno = novoAluno;
    }

    vector<string>getAluno(){
        return  this -> Aluno;
    }

    void adicionarAluno(string novoAluno){
        this -> Aluno.push_back(novoAluno);
    }

    bool removeAluno(string Aluno) {
        int tamanho = this->Aluno.size();

        for (int i = 0; i < tamanho; i++) {
            if (this->Aluno[i] == Aluno) {
                this->Aluno.erase(this->Aluno.begin() + i);
                return true;
            }
        }

        return false;
    }

    vector<string> getaluno(){
        return  this -> Aluno;
    }

    void adicionaAluno(string novoAluno){
        this -> Aluno.push_back(novoAluno);
    }

    bool removerAluno(string aluno) {
        int tamanho = this->Aluno.size();

        for (int i = 0; i < tamanho; i++) {
            if (this->Aluno[i] == aluno) {
                this->Aluno.erase(this->Aluno.begin() + i);
                return true;
            }
        }

        return false;
    }

    string listaAlunos() {
        int tamanho = this->Aluno.size();
        string AlunosString = "";

        for (int i = 0; i < tamanho; i++) {
            AlunosString += this->Aluno[i] + ", ";
        }

        return AlunosString;
    }

    string listanomeEscola() {
        int tamanho = this->Aluno.size();
        string AlunosString = "";

        for (int i = 0; i < tamanho; i++) {
            AlunosString += this->Aluno[i] + ", ";
        }

        return AlunosString;
    }


};

class Aluno {
private:
    string  nome;
    int     cc;


public:
    Aluno(string novoNome, int NovoCc)
            : nome(novoNome), cc(NovoCc) {}



    void setNome(string novoNome) {
        this->nome = novoNome;
    }

    string getNome() {
        return this->nome;
    }

    void setCc(int NovoCc) {
        this -> cc = NovoCc;
    }

    int getCc() {
        return this-> cc;
    }
};


int main () {

    vector<Escola> escolas;
    vector<Turma> turmas;
    vector<Aluno> alunos;

    bool continuar = true;
    int input;
    string inputString;

    while (continuar) {


        cout << "Escolha uma Opção:" << endl;
        cout << "\t[1] -    Adicionar uma escola" << endl;
        cout << "\t[2] -    Eliminar  uma escola" << endl;
        cout << "\t[3] -    Editar os atributos de uma escola" << endl;
        cout << "\t[4] -    Listar as turmas de uma escola" << endl;
        cout << "\t[5] -    Criar uma nova turma" << endl;
        cout << "\t[6] -    Eliminar uma turma" << endl;
        cout << "\t[7] -    Editar uma turma" << endl;
        cout << "\t[8] -    Listar os alunos de uma turma" << endl;
        cout << "\t[9] -    Criar um novo aluno" << endl;
        cout << "\t[10] -   Eliminar um aluno" << endl;
        cout << "\t[11] -   Editar um aluno" << endl;
        cout << endl << "\t[0] - Sair do Menu" << endl;
        cin >> input;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');


        switch (input) {
            case 0: {
                continuar = false;
                break;
            }

            case 1: {
                string novoNomeEscola;
                string novaLocalidade;
                vector<string> novaTurma;
                int novoIdEscola;

                cout << "Por favor, escreva o nome da escola a adicionar:" << endl;
                getline(cin, novoNomeEscola);

                cout << " Escreva a lovcalidae" << endl;
                getline(cin, novaLocalidade);

                cout << " introdza o Id da escola" << endl;
                cin >> novoIdEscola;


                Escola novaEscola(novoIdEscola, novoNomeEscola, novaLocalidade, novaTurma);
                escolas.push_back(novaEscola);

                break;
            }

            case 2: {
                cout << "Por favor, escreva o nome da escola a eliminar:" << endl;
                getline(cin, inputString);

                break;
            }

            case 3: {
                cout << "Editar os atributos de uma escola:" << endl;
                break;
            }

            case 4: {
                cout << "Lista de turmas de uma escola" << ":" << endl;
                string nomeescola;
                cout << "Qual é a escola " << endl;
                cin >> nomeescola;

                for (int i = 0; i < escolas.size(); i++) {
                    Escola item = escolas[i];
                    if (nomeescola == item.getNomeEscola()) {
                        cout << "Lista de turmas" << ":" << endl;
                        cout << item.listaTurmas();
                        break;
                    }
                }
                break;

            }
                case 5: {
                    int novoIdTurma;
                    int novoAno;
                    vector<string> novaTurma;

                    cout << "Escrva o Id  nova turma" << ":" << endl;
                    cin >> novoIdTurma;

                    cout << "Escreva o ano da turma " << ":" << endl;
                    cin >> novoAno;


                    Turma turmas(novoIdTurma, novoAno, novaTurma);

                    break;
                } // check

                case 6: {
                    cout << "Eliminar uma  turma " << ":" << endl;
                    getline(cin, inputString);
                    break;
                }

                case 7: {
                    cout << "Editar uma  turma " << ":" << endl;
                    break;
                }

                case 8: {
                    cout << "Listar os alunos de uma turma" << ":" << endl;

                    for (int i = 0; i < alunos.size(); i++) {
                        Aluno item = alunos[i];
                        if(Aluno == item.nome()) {
                            cout << "Lista de alunos" << ":" << endl;
                            cout << item.getNome();
                            break;
                        }
                    }
                    break;


                }

                case 9: {
                    int Cc;
                    string nome;

                    cout << "Escreva o Cartão de cidadão do aluno " << ":" << endl;
                    cin >> Cc;

                    cout << "Escreva o nome do aluno " << ":" << endl;
                    cin >> nome;

                    Aluno alunos(int Cc, string nome);
                    break;
                }

                case 10: {
                    cout << "Eliminar um aluno " << ":" << endl;
                    getline(cin, inputString);
                    break;
                }

                case 11: {
                    cout << "Editar uma aluno " << ":" << endl;
                    break;
                }


            }

        }

    }

