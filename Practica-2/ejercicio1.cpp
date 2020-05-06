#include <iostream>

using namespace std;

int main() {

	string entrada;
	cout<<"Ingrese entrada: ";
	cin>>entrada;
	bool salir = false;

	int i=0;
	int estado = 1;

    while (entrada[i]!='\0' and salir == false) {
    	switch (estado) {
    		case 1: 
    			if (entrada[i]>47 && entrada[i]<58) {
    				estado = 2;
    			}
    			else if ((entrada[i]>64 && entrada[i]<91) || (entrada[i]>96 && entrada[i]<123)) {
    				estado = 3;
    			}
    			else {
    				cout<<"Error\n";
    				salir = true;
    				break;
    			}
    			break;

    		case 2:
    			cout<<"Error\n";
    			salir = true;
    			break;

    		case 3:
    			if ((entrada[i]>64 && entrada[i]<91) || (entrada[i]>96 && entrada[i]<123)) {
    				estado = 3;
    			}
    			else if (entrada[i]>47 && entrada[i]<58) {
    				estado = 3;
    			}
    			else {
					cout<<"Error\n";    				
					salir = true;
					break;
    			}
    			break;
    	}	

    	i++;
    }

    if (estado!=3) {
    	cout<<"Error\n";
    }

    else {
    	cout<<"Dato valido\n";
    }

	return 0;
}