#include <iostream>

using namespace std;

int main() {

	string cadena;
    string tabla [3][3];
    int entrada;
    
    tabla[0][0] = "2";
    tabla[0][1] = "3";
    tabla[0][2] = "error";
    tabla[1][0] = "error";
    tabla[1][1] = "error";
    tabla[1][2] = "error";
    tabla[2][0] = "3";
    tabla[2][1] = "3";
    tabla[2][2] = "aceptar";
       
	cout<<"Ingrese identificador: ";
	cin>>cadena;

	int i=0;
    char simbolo;
	string estado = "1";
 
    do {
        simbolo = cadena[i++];

        if (simbolo>47 && simbolo<58) {
            entrada = 0;    // 0 -> digito
        }
        else if ((simbolo>64 && simbolo<91) || (simbolo>96 && simbolo<123)) {
            entrada = 1;    // 1 -> letra
        }
        else if (simbolo=='\0') {
            entrada = 2;    // 2 -> FDC 
        }
        else {
            cout<<"error\n";
            return 0;
        }

        estado = tabla[stoi(estado)-1][entrada];

        if (estado == "error") {
            cout<<estado<<endl;
            return 0;
        }

    }while(estado!="aceptar");  

    cout<<"Dato valido\n";   
 
	return 0;
}