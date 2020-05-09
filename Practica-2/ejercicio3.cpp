#include <iostream>

using namespace std;

int main() {

    string numero;
    char simbolo;

    cout<<"Ingrese un numero: ";
    cin>>numero;

    int i = 0;
    int estado = 1;
    simbolo = numero[i];

    while (simbolo != '\0') {
        switch (estado) {
            case 1: 
                if (simbolo == '-') {
                    estado = 2;
                }
                else if (simbolo>47 && simbolo<58) {
                    estado = 3;        
                }
                else if (simbolo == '.') {
                    estado = 4;
                }
                else {
                    cout<<"Error\n";
                    return 0;
                }
                break;

            case 2:
                if (simbolo>47 && simbolo<58) { 
                    estado = 3;
                }
                else if (simbolo == '.') {
                    estado = 4;
                }
                else {
                    cout<<"Error\n";
                    return 0;
                }        
                break;

            case 3:    
                if (simbolo>47 && simbolo<58) { 
                    estado = 3;
                }
                else if (simbolo=='.') {
                    estado = 4;
                }
                else {
                    cout<<"Error\n";
                    return 0;
                }     
                break;

            case 4:
                if (simbolo>47 && simbolo<58) { 
                    estado = 5;
                }
                else {
                    cout<<"Error\n";
                    return 0;
                }
                break;

            case 5:
                if (simbolo>47 && simbolo<58) { 
                    estado = 5;
                }    
                else {
                    cout<<"Error\n";
                    return 0;
                }
                break;
        }
        simbolo = numero[++i];
    }

    if (estado!=5 && estado!=3) {
        cout<<"Error\n";
    }
    else {
        cout<<"Dato valido\n";
    }

    return 0;
}