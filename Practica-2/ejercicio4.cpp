#include <iostream>
#include <fstream>

using namespace std;
int main()
{
    ifstream archivo;
    string tabla [5][4];
    string numero;
    int entrada;

    archivo.open("tabla.txt",ios::in);

    int i = 0;

    while(!archivo.eof()) {

        archivo >> tabla[i][0] >>tabla[i][1] >>tabla[i][2] >>tabla[i][3];  
        i++;
    }

    archivo.close();

    cout<<"Ingrese identificador: ";
	cin>>numero;

    char simbolo;
	string estado = "1";
    i = 0;
 
    do {
        simbolo = numero[i++];

        if (simbolo>47 && simbolo<58) {
            entrada = 0;    // 0 -> digito
        }
        else if (simbolo == '.') {
            entrada = 1;    // 1 -> .
        }
        else if (simbolo == '-') {
            entrada = 2;    // 2 -> -
        }
        else if (simbolo=='\0') {
            entrada = 3;    // 3 -> FDC 
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