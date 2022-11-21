#include<iostream>

using namespace std;

char matriz[3][3] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };

char Jogarers[2][15] = { "Jogador 1", "Jogador 2" };

int isJogarer = 0;


void MostraJogo()
{


    cout << "- - - - - - -" << endl;
    cout << "| " << matriz[0][0] << " | " << matriz[0][1] << " | " << matriz[0][2] << " |" << endl;
    cout << "|- - - - - -|" << endl;
    cout << "| " << matriz[1][0] << " | " << matriz[1][1] << " | " << matriz[1][2] << " |" << endl;
    cout << "|- - - - - -|" << endl;
    cout << "| " << matriz[2][0] << " | " << matriz[2][1] << " | " << matriz[2][2] << " |" << endl;
    cout << "- - - - - - -" << endl;
       }


void Jogar()
{
    int a;

    cout << "Escolhe um número para jogares:";
    cin >> a;

    switch (a) {
        case 1: {
            if (matriz[0][0] != '1'){
                cout << "Esta casa ja esta ocupada, escolhe outro número!" << endl;
                Jogar();
                break;
            }
            matriz[0][0] = isJogarer == 1 ? 'O' : 'X';
            break;
        }
        case 2: {
            if (matriz[0][1] != '2'){
                cout << "Esta casa ja esta ocupada, escolhe outro número!" << endl;
                Jogar();
                break;
            }
            matriz[0][1] = isJogarer == 1 ? 'O' : 'X';
            break;
        }
        case 3: {
            if (matriz[0][2] != '3'){
                cout << "Esta casa ja esta ocupada, escolhe outro número!" << endl;
                Jogar();
                break;
            }
            matriz[0][2] = isJogarer == 1 ? 'O' : 'X';
            break;
        }
        case 4: {
            if (matriz[1][0] != '4'){
                cout << "Esta casa ja esta ocupada, escolhe outro número!" << endl;
                Jogar();
                break;
            }
            matriz[1][0] = isJogarer == 1 ? 'O' : 'X';
            break;
        }
        case 5: {
            if (matriz[1][1] != '5'){
                cout << "Esta casa ja esta ocupada, escolhe outro número!" << endl;
                Jogar();
                break;
            }
            matriz[1][1] = isJogarer == 1 ? 'O' : 'X';
            break;
        }
        case 6: {
            if (matriz[1][2] != '6'){
                cout << "Esta casa ja esta ocupada, escolhe outro número!" << endl;
                Jogar();
                break;
            }
            matriz[1][2] = isJogarer == 1 ? 'O' : 'X';
            break;
        }
        case 7: {
            if (matriz[2][0] != '7'){
                cout << "Esta casa ja esta ocupada, escolhe outro número!" << endl;
                Jogar();
                break;
            }
            matriz[2][0] = isJogarer == 1 ? 'O' : 'X';
            break;
        }
        case 8: {
            if (matriz[2][1] != '8'){
                cout << "Esta casa ja esta ocupada, escolhe outro número!" << endl;
                Jogar();
                break;
            }
            matriz[2][1] = isJogarer == 1 ? 'O' : 'X';
            break;
        }
        case 9: {
            if (matriz[2][2] != '9'){
                cout << "Esta casa ja esta ocupada, escolhe outro número!" << endl;
                Jogar();
                break;
            }
            matriz[2][2] = isJogarer == 1 ? 'O' : 'X';
            break;
        }
    }

}

void ChangeJogarer(){

    isJogarer = (isJogarer == 0 ? 1 : 0);
}

char Win()
{

    //linha 1
    if (matriz[0][0] == matriz[0][1] && matriz[0][2] == matriz[0][1])
        return matriz[0][0];
        //linha 2
    else if (matriz[1][0] == matriz[1][1] && matriz[1][2] == matriz[1][1])
        return matriz[1][0];
        //linha 3
    else if (matriz[2][0] == matriz[2][1] && matriz[2][2] == matriz[2][1])
        return matriz[2][0];
        //coluna 1
    else if (matriz[0][0] == matriz[1][0] && matriz[2][0] == matriz[1][0])
        return matriz[0][0];
        //coluna 2
    else if (matriz[0][1] == matriz[1][1] && matriz[2][1] == matriz[1][1])
        return matriz[0][1];
        //coluna 3
    else if (matriz[0][2] == matriz[1][2] && matriz[2][2] == matriz[1][2])
        return matriz[0][2];
        // Diagonal cima -  e->d
    else if (matriz[0][0] == matriz[1][1] && matriz[2][2] == matriz[1][1])
        return matriz[0][0];
        // Diagonal cima - d->e
    else if (matriz[0][2] == matriz[1][1] && matriz[2][0] == matriz[1][1])
        return matriz[0][0];
    else if (matriz[0][0] == '1' && matriz[0][1] == '2' && matriz[0][2] == '3' && matriz[1][0] == '4' &&
             matriz[1][1] == '5' && matriz[1][2] == '6' && matriz[2][0] == '7' && matriz[2][1] == '8' &&
             matriz[3][2] == '9')
        return 'e';
    else
        return false;


}

void clearWithHeader(){
    system("clear");
    cout << "-------------------------------------------------------------" << endl;
    cout << "                                                             " << endl;
    cout << "                 BEM VINDO AO JOGO DO GALO "                   << endl;
    cout << "                                                             " << endl;
    cout << "               Cada jogador deverá selecionar                " << endl;
    cout <<"        o numero correspondente à casa onde quer jogar        " << endl;
    cout << "                                                             " << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << endl;
}

int main()
{
    clearWithHeader();

    MostraJogo();
    while (true) {

        Jogar();
        clearWithHeader();
        MostraJogo();
        char ed = Win();

        if (ed != false){
            cout << endl;
            cout << "-------------------------------------------------------------" << endl;
            cout << "|                                                           |" << endl;
            cout << "|                        Fim do jogo                        |" << endl;
            cout << " - Vencedor:  ";
            if (ed == 'e')
                cout << "Empate" << endl;
            else
                cout << Jogarers[isJogarer] << endl;
            cout << "|                                                           |" << endl;
            cout << "-------------------------------------------------------------" << endl;

            char js;
            cout << "Digita 'S' se quiseres jogar outra vez:";
            cin >> js;
            if (js == 'S' || js == 's'){

                matriz[0][0] = '1';
                matriz[0][1] = '2';
                matriz[0][2] = '3';
                matriz[1][0] = '4';
                matriz[1][1] = '5';
                matriz[1][2] = '6';
                matriz[2][0] = '7';
                matriz[2][1] = '8';
                matriz[2][2] = '9';
                clearWithHeader();
                return main();
            }
            break;
        }
        ChangeJogarer();

    }

    system("pause");
    return 0;
}