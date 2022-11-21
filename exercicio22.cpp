#include <iostream>
#include <string>
using namespace std;


string palindrome ( string palavra);

reverse(palavra1.begin(), palavra1.end());{

if (palavra1!=palavra){
    return  "Não é palindrome";

}
else{
    return "È Palindrome";
}
}

string tamanho (string palavra){

    if (palavra.length()>5){
        return "Palavra superior a 5 "
    }
    else{
        return " Palavra inferior a 6"
    }

}

string letrapalavra (string palavra){
    int onde = palavra.find

}

int main(){

    string palavra;
    string l;

    cout << "Por favor introduza as palavras" ;
    cin >> palavra;

    cout << "por favor introduza as letras" ;
    cin >> l;


    cout << palindrome(palavra) << endl;
    cout << tamanho(palavra) << endl;
    cout << letrapalavra(palavra, l) << endl;

    return 0;
}
