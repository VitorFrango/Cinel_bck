#include <iostream>
#include <math.h>

using namespace std; 

int soma(int nume1, int nume2){
    
    return nume1 + nume2;
}

int incrementar(int num1){

    return num1 + 1;
}



int main(){

    int input; 
    int input2;

    cout << "Insira o numnero que pretende" << endl;
    cin >> input;

    cout << "Insira o numnero que pretende" << endl;
    cin >> input2;

    cout << sqrt(input) << endl;

    cout << incrementar(input) << endl;

    cout << soma(input, input2) << endl;

    cout << incrementar(input) + soma(input, input) + sqrt(input) << endl;

    return 0 ; 
}
