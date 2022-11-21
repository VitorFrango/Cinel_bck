#include<iostream>

using namespace std;


string rega(int dias, bool sucu = true){

    if ((!sucu)&&(dias > 3)) {
        return " É tempo de regar as plantas";
    }

        else if ((sucu)&&(dias < 12 )){
            return "Não regue as plantas "; 
        }

        else if ((sucu)&&(dias > 12 )){
            return "Por favor  regue as plantas!" ;
    }
    else
        return " Não regue as plantas "; 

}
int main(){

    int d;
    char s; 

    cout << "Quantos dias? " << endl;
    cin >> d;
    cout << " É suculenta? ";
    cin >> s;

    cout << rega(d, s);

    return 0;
}
