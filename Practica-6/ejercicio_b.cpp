#include <fstream>
#include <sstream>
#include <stack> 
#include <queue>
#include <string>
#include <vector>
#include "Estado.h"

#define grafo_entrada "entrada.dot"  //Para dibujar el grafo de in.txt
#define grafo_salida "salida.dot"    //Para dibujar el grafo de out.txt
#define N 100

using namespace std;

//Variables para el archivo in.txt
int num_estados;
vector<string> estados;

int num_est_aceptacion;
vector<string> estados_aceptacion;  

int num_entradas;	
vector<string> entradas;

int num_transiciones;    

//Variables para el archivo out.txt
vector<string> est_acep_final;  

// Dibujando grafo con Graphviz DOT
void dibujando_grafo(string transiciones[][3], string nombre, int n_t, vector<string> estados_aceptacion){

	ofstream grafo(nombre);  // Creando archivo .dot

	grafo<<"digraph G {"<<endl;		
	grafo<<'\t'<<"node [shape=circle]"<<endl;	//Circulos
	grafo<<'\t'<<"rankdir=LR"<<endl;	//Orientacion de izquierda a derecha

	for (int i = 0; i<estados_aceptacion.size(); i++) {
		grafo<<'\t'<<estados_aceptacion[i]<<" [peripheries=2];"<<endl;  //Doble circulo
	}

	for (int i = 0; i<n_t; i++) {
		grafo<<'\t'<<transiciones[i][0]<<" -> "<<transiciones[i][2]<<" [label= "<<transiciones[i][1]<<"];"<<endl;
	}

	grafo<<"}"<<endl;
}

bool buscar(vector<string> clausura, string s){

	for(int i=0;i<clausura.size();i++) {
		if(clausura[i]==s) {
			return true;
    	}
    }	

    return false;
}

bool ya_conocido(vector<Estado> est, vector<string> c, string &e) {
	int size, s;

	for (int i=0; i<est.size(); i++) {
		size = est[i].estados.size();

		if (size == c.size()) {
			for (s=0; s<size; s++) {
				if (est[i].estados[s] != c[s]) 
					break;
			}

			if (s==size) {
				e = est[i].etiqueta;
				return true;
			}
		}
	}

	return false;
}

vector<string> calcular_clausura(vector<string> R, string transiciones[][3]) {

	vector<string> clausura;
    stack<string> pila; 

    for(int i=0;i<R.size();i++) {
    	pila.push(R[i]); //1 apilar R
    	clausura.push_back(R[i]); //2
    }
    
    string e;
    //3
    while (!pila.empty()) { 
    	e = pila.top(); //3.a
    	pila.pop(); 

    	// 3.b
    	for(int i=0;i<num_transiciones;i++) {
    		if (transiciones[i][0]==e) {
    			if (transiciones[i][1]=="-1") {
    				if (!buscar(clausura, transiciones[i][2])){
    					clausura.push_back(transiciones[i][2]);					
    					pila.push(transiciones[i][2]);
    				}
    			}
    		}
    	}
    }

    return clausura;
}

vector<string> transita(vector<string> clausura, string entrada, string transiciones[][3]) {

	vector<string> conjunto;

	for(int c=0;c<clausura.size();c++) {
		for(int t=0;t<num_transiciones;t++) {
    		if (transiciones[t][0]==clausura[c]) {
    			if (transiciones[t][1]==entrada) {
    				if(!buscar(conjunto, transiciones[t][2]))
    					conjunto.push_back(transiciones[t][2]);				
    			}
    		}
		}
	}

	return conjunto;
    
}

int main(int argc, char ** argv){

    ifstream archivo;
    ofstream salida;
    
    archivo.open(argv[1],ios::in);
    salida.open(argv[2]);

    // Variables
	vector<string> R;
    string linea;
    
    // Cargando automata a partir del archivo
    getline(archivo, linea); // Saltar primera linea Estados

    archivo >> num_estados;

    getline(archivo, linea); 
    getline(archivo, linea); // Fila de estados

    istringstream fila_estados(linea);

    for (string estado; getline(fila_estados, estado, ' '); ) {
        estados.push_back(estado);
    }

    getline(archivo, linea); // Linea en blanco
    getline(archivo, linea); 

    archivo >> num_est_aceptacion; 
    getline(archivo, linea); 
    getline(archivo, linea); // Fila de estados de aceptacion

    istringstream fila_est_aceptacion(linea);

    for (string estado; getline(fila_est_aceptacion, estado, ' '); ) {
        estados_aceptacion.push_back(estado);
    }

    getline(archivo, linea); //Linea en blanco  
    getline(archivo, linea); 

    archivo >> num_entradas; 
    getline(archivo, linea);  
    getline(archivo, linea); // Fila de entradas

    istringstream fila_entradas(linea);

    for (string entrada; getline(fila_entradas, entrada, ' '); ) {
        entradas.push_back(entrada);
    }

    getline(archivo, linea); //Linea en blanco  
    getline(archivo, linea); 

    archivo >> num_transiciones; 
    string transiciones[num_transiciones][3]; //transiciones del automata de entrada
    string trans_finales[N][3]; //transiciones del automata final out.txt

    int i = 0;    
    while(!archivo.eof()) {

        archivo >> transiciones[i][0] >>transiciones[i][1] >>transiciones[i][2];     
        i++;
    }

    archivo.close();

    //Dibujando grafo de entrada
    dibujando_grafo(transiciones, grafo_entrada, num_transiciones, estados_aceptacion);
    
    // Variables para out.txt
    vector<Estado> aut_final; //automata
    queue<Estado> marcados;

    vector<string> temp; 
    Estado inicio;
    int est_finales = 0; // Cantidad de estados para out.txt
    R.push_back(estados[est_finales]);  //Estado inicial

    inicio.etiqueta = estados[est_finales++];  //Se agrega el primer estado inicio
    inicio.estados = calcular_clausura(R, transiciones);

    aut_final.push_back(inicio);
    marcados.push(inicio);
    Estado evaluar;

    int t = 0;  //Numero de transiciones
    string e=""; //saber a que estado apuntar para las transiciones
    
    while(!marcados.empty()) {

    	evaluar = marcados.front(); 
    	marcados.pop(); 

    	for (int i=0; i<num_entradas; i++) {  //Alfabeto
	    	Estado nuevo_est;

	    	nuevo_est.estados = transita(evaluar.estados, entradas[i], transiciones);	
			nuevo_est.estados = calcular_clausura(nuevo_est.estados, transiciones);    	

			if(!ya_conocido(aut_final, nuevo_est.estados, e)) {     
				nuevo_est.etiqueta = estados[est_finales++]; 
				aut_final.push_back(nuevo_est);			
				marcados.push(nuevo_est);
				trans_finales[t][0] = evaluar.etiqueta;
				trans_finales[t][1] = entradas[i];
				trans_finales[t][2] = nuevo_est.etiqueta;	
				t++;
			}

			else {
				trans_finales[t][0] = evaluar.etiqueta;
				trans_finales[t][1] = entradas[i];
				trans_finales[t][2] = e;
				t++;
			}		
			
    	}        
    }
	
	bool es_aceptacion;

	// Calcular que estados seran de aceptacion

	for (int i=0 ; i<aut_final.size(); i++) {
    	es_aceptacion = false;

    	for (int k=0; k<estados_aceptacion.size(); k++) {
    		for (int j=0; j<aut_final[i].estados.size(); j++) {
    			if (aut_final[i].estados[j] == estados_aceptacion[k])
    				es_aceptacion = true;			
    		}
    	}	

    	if (es_aceptacion)
    			est_acep_final.push_back(aut_final[i].etiqueta);		
    }


    // Escribiendo archivo out.txt

	salida<<"Estados\n";
    for (int i=0 ; i<aut_final.size(); i++) {
    	salida<<aut_final[i].etiqueta<<"={ ";
    	
    	for (int j=0; j<aut_final[i].estados.size(); j++) {
    		salida<<aut_final[i].estados[j]<<" ";
    	}
    	salida<<"}\n";
    }

    salida<<"Estados de Aceptacion\n";

    for (int i=0 ; i<est_acep_final.size(); i++) 
    	salida<<est_acep_final[i]<<" ";

    salida<<"\nTransicion de Estados(x,y,z)\n";
    
    for (int i=0 ; i<t; i++) {    	
    	salida<<trans_finales[i][0]<<" "<<trans_finales[i][1]<<" "<<trans_finales[i][2]<<'\n';
    }   
    

	salida.close();

	// Dibujando grafo de salida salida.dot
	dibujando_grafo(trans_finales, grafo_salida, t, est_acep_final);

	
	return 0;
}

// Comandos para crear los graficos a partir del archivo .dot
//dot -Tps entrada.dot -o entrada.ps // crear archivo pdf
//dot -Tpng entrada.dot -o entrada.png  //crear archivo imagen