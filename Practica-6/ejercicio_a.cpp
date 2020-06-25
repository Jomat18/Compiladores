#include <iostream>
#include <fstream>
#include <stack> 
#include <string>
#include <vector>

using namespace std;

bool buscar(vector<int> clausura, int s){

	for(int i=0;i<clausura.size();i++) {
		if(clausura[i]==s) {
			return true;
    	}
    }	

    return false;
}

int main(int argc, char ** argv){

	ifstream archivo;
    int tabla [13][3]; //automata
    vector<int> R;
    vector<int> clausura;
    stack<int> pila; 

    // Cargando automata
    archivo.open("entrada.txt",ios::in);
    int i = 0;

    while(!archivo.eof()) {

        archivo >> tabla[i][0] >>tabla[i][1] >>tabla[i][2];     
        i++;
    }

    archivo.close();

    //Inicio

    R.push_back(0);

    //R.push_back(1);
    //R.push_back(7);

    for(int i=0;i<R.size();i++) {
    	pila.push(R[i]); //1 apilar R
    	clausura.push_back(R[i]); //2
    }
    
    int e;
    //3
    while (!pila.empty()) { 
    	e = pila.top(); //3.a
    	pila.pop(); 

    	// 3.b
    	for(int i=0;i<13;i++) {
    		if (tabla[i][0]==e) {
    			if (tabla[i][1]==-1) {
    				if (!buscar(clausura, tabla[i][2])){
    					clausura.push_back(tabla[i][2]);					
    					pila.push(tabla[i][2]);
    				}
    			}
    		}
    	}
    } 

    //Resultado
    cout<<"E_clausura({ ";
    for(int i=0;i<R.size();i++) {
    	cout<<R[i]<<" "; 
    }
    cout<<"}) ";

    cout<<"= { ";
    for(int i=0;i<clausura.size();i++) {
    	cout<<clausura[i]<<" "; 
    }

    cout<<"}"<<endl;

	return 0;
}