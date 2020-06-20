#include <stdio.h>
#include <iostream>
#include <ctype.h>
#include <stack> 
#include <vector>
#include <string>
#include <bits/stdc++.h> 

#define MAS '+'
#define MENOS '-'
#define MULT '*'
#define DIV '/'
#define PARIZ '('
#define PARDER ')'
#define COMA ';'
#define NUM 256
#define FIN -1

using namespace std;


char lexema[80];
int tok;
void parea(int);
void error();
void Resto();
void Term();
int scanner();

FILE *f;
string postfija;

void Exp()
{
	if (tok==NUM || tok==PARIZ) { 
		Term();
		Resto(); 
	}

	else
		error();
}

void Resto()
{
	if (tok == MAS) { 
		parea(MAS);
		Term();
		postfija = postfija + "+ ";
		Resto();
 	}
	else if (tok == MENOS) { 
		parea(MENOS);
		Term();
		postfija = postfija + "- ";
		Resto();
 	}
 	else if (tok == MULT) { 
		parea(MULT);
		Term();
		postfija = postfija + "* ";
		Resto();
 	}
 	else if (tok == DIV) { 
		parea(DIV);
		Term();
		postfija = postfija + "/ ";
		Resto();
 	}
 	else if (tok == COMA) {
 		parea(COMA);
 	}
 	else if (tok == PARDER) { 
		parea(PARDER);
 	}
	else //cadena vacia
 		;
}

void Term()
{
 	if (tok==NUM) { 
 		postfija = postfija + lexema + " ";
 		parea(NUM); 
 	}
 	else if(tok==PARIZ) {
 		parea(PARIZ); 
 		Term();
 		Resto();
 	}
 	else
 		error();
}

void error()
{
	printf("Error de sintaxis");
}


void parea(int t)
{
	if (tok==t)
		tok=scanner();
	else
		error();
}

int scanner()
{
 	int c,i;
 	do c=fgetc(f); while(c==' ');
 	if(c==EOF) return EOF;

 	if (c=='\n')
		return FIN;

	if (c==';')
		return COMA;

 	if (c==MAS || c==MENOS || c==MULT || c==DIV)
		return c;

	if (c==PARIZ || c==PARDER)
		return c;

 	if(isdigit(c)) {
 		i=0;
 		do { lexema[i++]=c; c=fgetc(f);
		}while(isdigit(c));

 		lexema[i]=0;
 		ungetc(c,f);
 		return NUM;
 	}
}

void calcular_operacion(stack<double> &mystack, string &entrada) {  	

  	double num1, num2;
  	int argc;

  	vector<string> argv;

    istringstream ss(entrada); 
  
    do { 

        string word; 
        ss >> word; 
  
        argv.push_back(word); 
  
    } while (ss); 
	
    argc = argv.size()-1;

	for (int i=0; i<argc; i++) {

		entrada = argv[i];
		
		if (entrada=="+") {
				num1 = mystack.top(); 
				mystack.pop(); 

				num2 = mystack.top(); 
				mystack.pop(); 

				num1 = num2 + num1;

				mystack.push(num1); 
		}
		else if (entrada=="-") {
				num1 = mystack.top(); 
				mystack.pop(); 

				num2 = mystack.top(); 
				mystack.pop(); 

				num1 = num2 - num1;

				mystack.push(num1); 
		}
		else if (entrada=="*") {
				num1 = mystack.top(); 
				mystack.pop(); 

				num2 = mystack.top(); 
				mystack.pop(); 

				num1 = num2 * num1;

				mystack.push(num1); 
		}
		else if (entrada=="/") {
				num1 = mystack.top(); 
				mystack.pop(); 

				num2 = mystack.top(); 
				mystack.pop(); 

				num1 = num2 / num1;

				mystack.push(num1); 
		}
		else 
			mystack.push(stod(entrada)); 
		
	}

    cout << mystack.top()<<endl; 
    mystack.pop(); 
    
}


int main(int n, char** pal) 
{ 

	stack<double> mystack; 

	f=fopen(pal[1],"rt"); 
	
	while(1)
	{
		postfija = "";

		tok=scanner();
		if(tok==EOF) break;
		Exp();
		cout<<postfija<<" = ";
		calcular_operacion(mystack, postfija);

	}

	fclose(f); // entonces cerrar el archivo.

	return 0;
}