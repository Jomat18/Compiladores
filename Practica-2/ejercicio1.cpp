#include <iostream>

using namespace std;

int main() {

	string entrada;
	cout<<"Ingrese entrada: ";
	cin>>entrada;

	int i = 0;
	int estado = 1;
	char simbolo = entrada[i];

    while (simbolo!='\0') {
    	switch (estado) {
    		case 1: 
    			if (simbolo>47 && simbolo<58) {
    				estado = 2;
    			}
    			else if ((simbolo>64 && simbolo<91) || (simbolo>96 && simbolo<123)) {
    				estado = 3;
    			}
    			else {
					cout<<"Error\n";
					return 0;
    			}
    			break;

    		case 2:
    			cout<<"Error\n";
				return 0;

    		case 3:
    			if ((simbolo>64 && simbolo<91) || (simbolo>96 && simbolo<123)) {
    				estado = 3;
    			}
    			else if (simbolo>47 && simbolo<58) {
    				estado = 3;
    			}
    			else {
					cout<<"Error\n";
					return 0;
    			}
    			break;
    	}	
    	simbolo = entrada[++i];
    }

    if (estado!=3) {
		cout<<estado;
    	cout<<"Error\n";
    }
    else {
		cout<<"Dato valido\n";
	}

	return 0;
}