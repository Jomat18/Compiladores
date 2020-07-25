#ifndef DATOS_H
#define DATOS_H

typedef union { 
    int entero;
	float real; 
} tipovalor;

typedef struct {
    char  nombre[30];
    int       a1;  /* a1: INT/FLOAT/NUM/   */
    int       a2;  /* a2: FUN/VAR */
    tipovalor a3;  
} tipoTablaSimbolo;

tipoTablaSimbolo TS[100], *pTS;
int nTS = 0; //numero de simbolos que hay en la tabla

char lexema[80];
int tipoVar;

#endif