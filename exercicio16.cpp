/*

pedir 5 numeros 
guardar 5 numeros
imprmir 5 numeros 
*/

#include <iostream>
using namespace std; 

int main(){

int numeros[5] ;

for (int i = 0; i < 5; i++){
    cout << " Insira o " << (i + 1) << "º nº " << endl; 
    cin >> numeros[i];
}

for (int i = 0; i < 5; i++){
    cout << numeros[i]; 
    
}

cout << endl;

return 0;
}
