#ifndef DATOS_H
#define DATOS_H

// Definición de las operaciones de lenguaje intermedio

#define MOVER	1
#define SUMAR	2
#define SALTAR	3
#define SALTARV	4
#define SALTARF	5
#define MENOR	6
#define RESTAR       7 
#define MULTIPLICAR  8
#define DIVIDIR      9

/* Tabla de simbolos */

typedef union 
{
	int entero;
	float real;
} tipovalor;

typedef struct 
{
	char nombre[30];
	int a1,a2;  	// a1: INT/FLOAT	a2: FUN/VAR
	tipovalor a3; 	// guarda valor
} tipoTablaSimbolo;

//printf("%d\n", sizeof(a3));

/* Tabla de código */

typedef struct 
{
 	int op,a1,a2,a3;
} tipoCodigo;

tipoCodigo TABCOD[100];
int cx = -1; 		// indice de código actual
int indicevartemp = 0;  	//número de variables temporales

char lexema[80];
tipoTablaSimbolo TS[100], *pTS;
int nTS = 0;
int tipoVar;

void IS(char *, int , int);
int localizaSimbolo(char *);
void muestraSimbolo();

void genCodigo(int ,int ,int ,int );
int genvartemp();
void muestraCodigo();

void interprete();

#endif