//
// Created by Vitor Frango on 30/11/2022.
//

#include <iostream>
#include <vector>

using namespace std;

class Escola {
private:
    int             idEscola;
    char            localidade;
    vector<string>  nomeEscola;
    vector<string>  turmas;

public:

    Escola(int novoIdEscola, char novoNomeEscola, char novaLocalidade, vector<string> novasTurmas)
            : idEscola(novoIdEscola), nomeEscola(novoNomeEscola), localidade(novaLocalidade), turmas(novasTurmas) {}


    int getIdEscola() {
        return this->idEscola;
    }

    char getLocalidade() {
        return this->localidade;
    }

    void setIdEscola(int novoIdEscola) {
        this->idEscola = novoIdEscola;
    }


    void setLocalidade(char novaLocalidade) {
        this->localidade = novaLocalidade;
    }

    void setTurmas(vector<string>novasTurmas){
        this-> turmas = novasTurmas;
    }

    void setnomeEscola(vector<string>novonomeEscola){
        this-> nomeEscola = novonomeEscola;
    }

    vector<string>getTurmas(){
        return  this -> turmas;
    }

    void adicionarTurma(string novaTurma){
        this -> turmas.push_back(novaTurma);
    }

    bool removerTurma(string turma) {
        int tamanho = this->turmas.size();

        for (int i = 0; i < tamanho; i++) {
            if (this->turmas[i] == turma) {
                this->turmas.erase(this->turmas.begin() + i);
                return true;
            }
        }

        return false;
    }

    vector<string>getnomeEscola(){
        return  this -> nomeEscola;
    }

    void adicionarnomeEscola(string novonomeEscola){
        this -> nomeEscola.push_back(novonomeEscola);
    }

    bool removenomeEscola(string nomeEscola) {
        int tamanho = this->nomeEscola.size();

        for (int i = 0; i < tamanho; i++) {
            if (this->nomeEscola[i] == nomeEscola) {
                this->nomeEscola.erase(this->nomeEscola.begin() + i);
                return true;
            }
        }

        return false;
    }

    string listaTurmas() {
        int tamanho = this->turmas.size();
        string turmasString = "";

        for (int i = 0; i < tamanho; i++) {
            turmasString += this->turmas[i] + ", ";
        }

        return turmasString;
        }

        string listanomeEscola() {
            int tamanho = this->nomeEscola.size();
            string nomeEscolaString = "";

            for (int i = 0; i < tamanho; i++) {
                nomeEscolaString += this->nomeEscola[i] + ", ";
            }

            return nomeEscolaString;
        }


};

class Turma {
private:
    int             IdTurma;
    int             ano;
    vector<string>  aluno;

public:

    Turma(int novoIdTurma, int novoAno, vector<string> novoAluno)
            : IdTurma(novoIdTurma), ano(novoAno), aluno(novoAluno) {}


    int getidturma() {
        return this->IdTurma;
    }

    char getAno() {
        return this->ano;
    }


    void setIdTurma(int novoIdTurma) {
        this->IdTurma = novoIdTurma;
    }

    void setAno(char novoAno) {
        this->ano = novoAno;
    }

    void setAluno(vector<string>novoAluno){
        this-> aluno = novoAluno;
    }

    vector<string>getAluno(){
        return  this -> aluno;
    }

    void adicionarAluno(string novoAluno){
        this -> aluno.push_back(novoAluno);
    }

    bool removerAluno(string aluno) {
        int tamanho = this->aluno.size();

        for (int i = 0; i < tamanho; i++) {
            if (this->aluno[i] == aluno) {
                this->aluno.erase(this->aluno.begin() + i);
                return true;
            }
        }

        return false;
    }

    string listaAluno() {
        int tamanho = this->listaAluno().size();
        string alunoString = "";

        for (int i = 0; i < tamanho; i++) {
            alunoString += this->listaAluno()[i] + ", ";
        }

        return alunoString;
    }

};

class Aluno {
public:
    string nome;
    int Cc ;

    Aluno(string nome, int Cc) {
        this->setNome(nome);
        this->setCc(Cc);
    }


    void setNome(string nome) {
        this->nome = nome;
    }

    string getNome() {
        return this->nome;
    }


    void setCc(int Cc) {
        this->Cc = Cc;
    }

    int getCc() {
        return this->Cc;


    void menuEscola(Escola escola) {
        int input;
        string inputString;
        cout << "Escolha uma Opção:" <<                             endl;
        cout << "\t[1] -    Adicionar uma escola" <<                endl;
        cout << "\t[2] -    Eliminar  uma escola" <<                endl;
        cout << "\t[3] -    Editar os atributos de uma escola" <<   endl;
        cout << "\t[4] -    Listar as turmas de uma escola" <<      endl;
        cout << "\t[5] -    Criar uma nova turma" <<                endl;
        cout << "\t[6] -    Eliminar uma turma" <<                  endl;
        cout << "\t[7] -    Editar uma turma" <<                    endl;
        cout << "\t[8] -    Listar os alunos de uma turma" <<       endl;
        cout << "\t[9] -    Criar um novo aluno" <<                 endl;
        cout << "\t[10] -   Eliminar um aluno" <<                   endl;
        cout << "\t[11] -   Editar um aluno" <<                     endl;
        cout << endl << "\t[0] - Sair do Menu" <<                   endl;
        cin >> input;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');


        switch (input) {
            case 0:
                break;
            case 1:
                cout << "Por favor, escreva o nome da escola a adicionar:" << endl;
                getline(cin, inputString);
                escola.adicionarnomeEscola(inputString);
                break;
            case 2:
                cout << "Por favor, escreva o nome da escola a eliminar:" << endl;
                getline(cin, inputString);
                escola.removenomeEscola(inputString);
                break;

            case 3:
                cout << "Editar os atributos de uma escola:" << endl;
                break;

            case 4:
                cout << "Lista de turmas de uma escols" << escola.listaTurmas() << ":" << endl;
                //getline(cin, inputString);
                cout << escola.listaTurmas();
                break;

            case 5:
                cout << "Criar uma nova turma" << ":" << endl;
                getline(cin, inputString);
                escola.adicionarTurma(inputString);

                break;

            case 6:
                cout << "Eliminar uma  turma " << ":" << endl;
                getline(cin, inputString);
                escola.removerTurma(inputString);
                break;

            case 7:
                cout << "Editar uma  turma " << ":" << endl;
                
                break;

            case 8:
                cout << "Listar os alunos de uma turma" << ":" << endl;

                break;

            case 9:
                cout << "Criar um novo aluno" << ":" << endl;
                getline(cin, inputString);


                break;

            case 10:
                cout << "Eliminar um aluno " << ":" << endl;
                getline(cin, inputString);

                break;

            case 11:
                cout << "Editar uma aluno " << ":" << endl;

                break;

        }

    };

int main (){


}