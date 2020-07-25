#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAYOR '>'
#define MENOR '<'
#define IGUAL '='
#define PUNTOYCOMA ';'
#define COMA ','
#define PARI '('
#define PARD ')'
#define CORI '{'
#define CORD '}'
#define LLAVI '['
#define LLAVD ']'
#define MAS '+'
#define MENOS '-'
#define MULT '*'
#define DIV '/'
#define ID 256
#define NUM 257
#define MAYORIGUAL 258
#define MENORIGUAL 259
#define DOBLEIGUAL 260
#define DIFERENTE 261
#define WHILE 262
#define IF 263
#define MAIN 264
#define ELSE 265
#define INT_ 266
#define RETURN 267

int scaner();
void mostrar(int);
int espalres();


using namespace std;   

FILE *f;
 
char lexema[80];

int main(int n, char** pal) 
{ 
	int token;

	f=fopen(pal[1],"rt"); //lectura modo texto
	
	while(1)
	{
		
		token=scaner();
		if(token==EOF) break;
		mostrar(token);
	}

	fclose(f); // entonces cerrar el archivo.
	
	return 0;
}//fin del main

int scaner()
{
	int c;
	int i;
	do c=fgetc(f); while(isspace(c)); //ignora blancos
	if(c==EOF) return EOF;

	if(isalpha(c)) //regla del ID
	{
		i=0;

		do{
			lexema[i++]=c;
			c=fgetc(f);
		} while(isalnum(c)||c=='_');

		lexema[i]=0;
		ungetc(c,f); //se devuelve c al flujo de entrada
		i=espalres(); // verifica si es palabra reservada
		 // WHILE , IF
		if(i>=0)
		 return i;
		return ID; // se trata de un ID
	}

	if(isdigit(c)) //regla del NUM
	{
		i=0;
		do{
		 lexema[i++]=c;
		 c=fgetc(f);
		}while(isdigit(c));

		lexema[i]=0;
		ungetc(c,f);
		return NUM;
	}

	//regla de PUNTOYCOMA y PARI, MAS, MENOS, COR, ETC
	if((c==';') || (c=='(') || (c==')') || (c==',') || (c=='*') 
		|| (c=='+') || (c=='-') || (c=='{') || (c=='}') || (c=='[') || (c==']')) 
		return c; //regla del ";" y "("

	if(c=='>') //regla de ">" o ">="
	{
		c=fgetc(f);
		if(c=='=') //return MAYORIGUAL
		{ lexema[0]='>'; lexema[1]='='; lexema[2]=0;
		 return MAYORIGUAL;
		}
		ungetc(c,f);
		return MAYOR; //return MAYOR
	}

	if(c=='<') //regla de "<" o "<="
	{
		c=fgetc(f);
		if(c=='=') //return MENORIGUAL
		{ lexema[0]='<'; lexema[1]='='; lexema[2]=0;
		 return MENORIGUAL;
		}
		ungetc(c,f);
		return MENOR; //return MENOR
	}

	if(c=='=') //regla de "=" o "=="
	{
		c=fgetc(f);
		if(c=='=') //return DOBLEIGUAL
		{ lexema[0]='='; lexema[1]='='; lexema[2]=0;
		 return DOBLEIGUAL;
		}
		ungetc(c,f);
		return IGUAL; //return IGUAL
	}

	if(c=='!') //regla de ">" o ">="
	{
		c=fgetc(f);
		if(c=='=') //return DIFERENTE
		{ lexema[0]='!'; lexema[1]='='; lexema[2]=0;
		 return DIFERENTE;
		}
		ungetc(c,f);
		return 0; //return 0
	}

	if(c=='/') 
	{
		c=fgetc(f);
		if(c=='/') 
		{ 
			do c=fgetc(f); while(c!='\n');

		 	return 0;
		}

		if(c=='*') 
		{ 
			do c=fgetc(f); while(c!='*');
			c=fgetc(f);
			
		 	return 0;
		}

		ungetc(c,f);
		return DIV; 
	}


}//fin de scaner


int espalres()
{
	if(strcmp(lexema,"while")==0) return WHILE;
	if(strcmp(lexema,"if")==0) return IF;
	if(strcmp(lexema,"main")==0) return MAIN;
	if(strcmp(lexema,"else")==0) return ELSE;
	if(strcmp(lexema,"int")==0) return INT_;
	if(strcmp(lexema,"return")==0) return RETURN;
	return -1;
}

void mostrar(int token)
{

	switch(token)
	{
		case ID: printf("token = ID [%s] \n",lexema); break;
		case NUM: printf("token = NUM [%s] \n",lexema); break;
		case MAYORIGUAL: printf("token = MAYORIGUAL [%s]\n",lexema); break;
		case MENORIGUAL: printf("token = MENORIGUAL [%s]\n",lexema); break;
		case DOBLEIGUAL: printf("token = DOBLEIGUAL [%s]\n",lexema); break;
		case DIFERENTE: printf("token = DIFERENTE [%s]\n",lexema); break;
		case WHILE: printf("token = WHILE [%s] \n",lexema); break; 
		case IF: printf("token = IF [%s] \n",lexema); break;
		case MAIN: printf("token = MAIN [%s] \n",lexema); break;
		case ELSE: printf("token = ELSE [%s] \n",lexema); break;
		case INT_: printf("token = INT [%s] \n",lexema); break;
		case RETURN: printf("token = RETURN [%s] \n",lexema); break;
		case PARI: printf("token = PARI [%c] \n",token); break;
		case PARD: printf("token = PARD [%c] \n",token); break;
		case MAYOR: printf("token = MAYOR [%c] \n",token); break;
		case MENOR: printf("token = MENOR [%c] \n",token); break;
		case IGUAL: printf("token = IGUAL [%c] \n",token); break;
		case PUNTOYCOMA: printf("token = PUNTOYCOMA [%c] \n",token); break; 
		case COMA: printf("token = COMA [%c] \n",token); break; 
		case CORD: printf("token = CORD [%c] \n",token); break; 
		case CORI: printf("token = CORI [%c] \n",token); break; 
		case LLAVD: printf("token = LLAVD [%c] \n",token); break; 
		case LLAVI: printf("token = LLAVI [%c] \n",token); break; 
		case MAS: printf("token = MAS [%c] \n",token); break; 
		case MENOS: printf("token = MENOS [%c] \n",token); break; 
		case MULT: printf("token = MULT [%c] \n",token); break; 
		case DIV: printf("token = DIV [%c] \n",token); break; 
	}
}