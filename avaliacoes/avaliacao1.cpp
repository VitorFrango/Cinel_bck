
/*/
Exercicio de avaliação 1 
Vitor Frango
*/
#include <iostream>

int main() {


    float num1, num2; 
    int opcao;

    // pedir para introduzir dois valores e guardar em duas variaveis 
    std::cout << "Introduza dois numeros e carregue em 'ENTER':" << std::endl;
    std::cin >> num1;
    std::cin >> num2; 

    // Escolher qual a operação a efectuar 
    std::cout << " Selecione a operação que deseja efectuar sobre os numeros introduzidos" << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::cout << " 1 -> SOMA\n 2 -> SUBTRAÇÂO\n 3 -> MULTIPLICAÇÃO\n 4 -> DIVISÃO" << std::endl;
    std::cout << "------------------------------" << std::endl;
    std:: cin >> opcao; 

    // switch para seleçao de operação e impressao de resultado
    switch (opcao) {
        case 1:
            std::cout << "O resultado da soma dos numeros introduzidos é:  " << num1+num2 << std::endl; 
        break;

        case 2:
            std::cout << "O resultado da subtração dos numeros introduzidos é:  " << num1-num2 << std::endl;
        break;

        case 3:
            std::cout << "O resultado da multiplicação dos numeros introduzidos  é:  " << num1*num2 << std::endl;
        break;

        case 4:
            std::cout << " O resultado da divisão  dos numeros introduzidos é:  " << num1/num2 << std::endl;
        break; 


    default:
        std::cout << " A opção não é valida  "; 
   }


    

    return 0;
}