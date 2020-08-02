#ifndef DATOS_H
#define DATOS_H

//#include <stdbool.h>

//#include <string.h>

// Definición de las operaciones de lenguaje intermedio

#define MOVER	1
#define SUMAR	2
#define SALTAR	3
#define SALTARV	4
#define SALTARF	5
#define MENOR	6
#define MAYOR 7
#define RESTAR       8 
#define MULTIPLICAR  9
#define DIVIDIR      10
#define MENOR_IGUAL 11 
#define MAYOR_IGUAL 12
#define OPER_OR 13
#define OPER_AND 14
#define NEGACION 15

/* Tabla de simbolos */

typedef union 
{
	int entero;
	float real;
//	bool booleano;
//	string cadena;

} tipovalor;

typedef struct 
{
	char nombre[30];
	int a1,a2, linea;  	// a1: INT/FLOAT	a2: FUN/VAR/ARREGLO
	tipovalor a3; 	// guarda valor
} tipoTablaSimbolo;

//printf("%d\n", sizeof(a3));

/* Tabla de código */

typedef struct 
{
 	int op,a1,a2,a3, linea;
} tipoCodigo;

tipoCodigo TABCOD[100];
int cx = 0; 		// indice de código actual
int indicevartemp = 0;  	//número de variables temporales

char lexema[80];
tipoTablaSimbolo TS[100], *pTS;
int nTS = 0;
int tipoVar;

void IS(char *, int , int);
int localizaSimbolo(char *);
void muestraSimbolo();

void genCodigo(int ,int ,int ,int );
int genvartemp(int);
void muestraCodigo();

void interprete();

#endif