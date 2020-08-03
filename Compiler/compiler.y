%{

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define YYDEBUG 1   /* Depurador */

#include "datos.h"  /* Tabla de simbolos y operaciones */

int yylex(void);
void yyerror(char *m);
%}

%start programaC

%token INT FLOAT BOOL STRING NUM REAL BOOLEANO LETRAS FORMATO ID IF ELSE WHILE DO FOR TEMP
%token LEENUM IMPRINUM COMENTARIO
%token CENTERO	CFLOAT VAR FUNCION ARREGLO

/*Operadores asociativos por la derecha */
%right '=' NOT
%right '^'

/*Operadores asociativos por la izquierda */
%left '|'
%left '&'
%left '?'
%left OR AND	
%left IGUAL NOIGUAL MENORIGUAL MAYORIGUAL '<' '>'
%left '+' '-'
%left '*' '/' '%'

%%
	/* Reglas de la Gramatica y acciones */

	programaC : listaDeclC ;

	listaDeclC : listaDeclC declC | listComent |;

	declC : Tipo listaVar ';' comentario;
	declC : Tipo ID '(' { IS(lexema,$1,FUNCION);}	listaPar ')' bloque ;

	listComent: listComent comentario |;
	comentario: COMENTARIO | ;

	Tipo : INT  | FLOAT | BOOL | STRING;
	
	listaVar : ID ',' { IS(lexema,tipoVar,VAR); }	listaVar | ID { IS(lexema,tipoVar,VAR); } | ID { IS(lexema,tipoVar,ARREGLO); } '[' NUM ']' ;
	listaPar : Tipo ID { IS(lexema,$1,VAR); }',' listaPar   | Tipo ID { IS(lexema,$1,VAR); };

	bloque : '{' comentario listaVarLoc listaProp '}';
	listaVarLoc : Tipo listaVar ';' listaVarLoc comentario | ;
	listaProp : listaProp prop comentario | ;

	prop : ';' ;
	prop : bloque ;
    prop : IF '(' expr ')' { genCodigo(SALTARF,$3,0,$$); $$ = cx; } prop  { TABCOD[$5].a3 = cx + 1;  } ;
	/*prop : IF '(' expr ')' prop ELSE prop ;*/
	prop : WHILE '(' {$$ = cx + 1;}  expr    ')' 	{genCodigo(SALTARF,$4,0,-1); /* Destino no resuelto */
	   						                         $$ = cx; /* Falta llenar cuarto componente de este salto */} 
				                                 prop	
				                                 	{genCodigo(SALTAR,0,0,$3); /* Ir al comienzo de la expresión */
							                         TABCOD[$6].a3 = cx + 1; /* Llenando destino de sltar falso */
				                                    } ;
	prop : FOR '(' expr ';' expr ';' expr ')' prop ;
	prop : IMPRINUM '(' expr ')' {genCodigo(IMPRINUM,$3,0,0);};

	prop : expr ;
	expr : expr OR expr {int p = localizaSimbolo(lexema); int n = genvartemp(p); genCodigo(OPER_OR,n,$1,$3);  $$=n;} ;
	expr : expr AND expr {int p = localizaSimbolo(lexema); int n = genvartemp(p); genCodigo(OPER_AND,n,$1,$3);  $$=n;} ;
	expr : NOT expr {int p = localizaSimbolo(lexema); int n = genvartemp(p); genCodigo(NEGACION,n,$2,0); $$=n;};
	expr : expr IGUAL expr {int n = genvartemp(0);	genCodigo(IGUAL,n,$1,$3);  $$=n;} ;
	expr : expr NOIGUAL expr {int n = genvartemp(0);	genCodigo(NOIGUAL,n,$1,$3);  $$=n;} ;

	expr : expr '<' expr {int n = genvartemp(0);	genCodigo(MENOR,n,$1,$3);  $$=n;} ;
	expr : expr '>' expr {int n = genvartemp(0);	genCodigo(MAYOR,n,$1,$3);  $$=n;} ;
	expr : expr MENORIGUAL expr {int n = genvartemp(0);	genCodigo(MENOR_IGUAL,n,$1,$3);  $$=n;} ;
	expr : expr MAYORIGUAL expr {int n = genvartemp(0);	genCodigo(MAYOR_IGUAL,n,$1,$3);  $$=n;} ;

	expr : expr '+' expr {int p = localizaSimbolo(lexema); int n = genvartemp(p); genCodigo(SUMAR,n,$1,$3);  $$=n;};
    expr : expr '-' expr {int p = localizaSimbolo(lexema); int n = genvartemp(p); genCodigo(RESTAR,n,$1,$3);$$=n;}; 
    expr : expr '*' expr {int p = localizaSimbolo(lexema); int n = genvartemp(p); genCodigo(MULTIPLICAR,n,$1,$3);$$=n;};
    expr : expr '/' expr {int p = localizaSimbolo(lexema); int n = genvartemp(p); genCodigo(DIVIDIR,n,$1,$3);$$=n;} ; 
    expr : expr '%' expr {int p = localizaSimbolo(lexema); int n = genvartemp(p); genCodigo(MODULO,n,$1,$3);$$=n;} ; 
    expr : expr '^' expr {int p = localizaSimbolo(lexema); int n = genvartemp(p); genCodigo(POTENCIA,n,$1,$3);$$=n;} ; 

	expr : expr '?' expr ':' expr ;
	expr : ID {$$ = localizaSimbolo(lexema);};
	expr : NUM  {IS(lexema,INT,NUM);$$ = localizaSimbolo(lexema);TS[$$].a3.entero = atoi(lexema);};	
	expr : BOOLEANO {IS(lexema,BOOL,BOOLEANO);$$ = localizaSimbolo(lexema);strcpy(TS[$$].a3.booleano,lexema);};

	expr : LETRAS {IS(lexema,STRING,LETRAS);$$ = localizaSimbolo(lexema);strcpy(TS[$$].a3.cadena,lexema);};
	
	expr : REAL	{float v; IS(lexema,FLOAT,REAL);$$ = localizaSimbolo(lexema);	sscanf(lexema,"%f",&v);TS[$$].a3.real = v;};	
	expr : ID '=' { $$ = localizaSimbolo(lexema); }	expr {genCodigo(MOVER,$3,$4,0);} ; 
	expr : ID '[' expr ']' ;
	expr : ID '[' expr ']' '=' expr;
	expr : '(' expr ')' {$$=$2;} ; 

%%

void genCodigo(int op,int a1,int a2,int a3)
{
	tipoCodigo *p;

	p = &TABCOD[cx++];
	p->op = op;
	p->a1 = a1;
	p->a2 = a2;
	p->a3 = a3;

}

int genvartemp(int pos)
{	
	char t[30];
	sprintf(t,"T%-2d",indicevartemp++);
	strcpy(TS[nTS].nombre,t);
	TS[nTS].a1 = TS[pos].a1;
	TS[nTS].a2 = TEMP;
	TS[nTS].linea = numeroLinea+1;
	if (TS[nTS].a1==INT)
		strcpy(TS[nTS].tipo,"int");
	else if (TS[nTS].a1==FLOAT)
		strcpy(TS[nTS].tipo,"float");
	else if (TS[nTS].a1==STRING)
		strcpy(TS[nTS].tipo,"string");	
	else {
		if (pos!=-1)
			strcpy(TS[nTS].tipo,"bool");	
	}

	if (TS[nTS].a2==VAR)
		strcpy(TS[nTS].clase,"var");
	else if (TS[nTS].a2==FUNCION)
		strcpy(TS[nTS].clase,"func");
	else if (TS[nTS].a2==ARREGLO)
		strcpy(TS[nTS].clase,"array");	
	else 
		strcpy(TS[nTS].clase,"temp");		

	return nTS++;
}

void muestraCodigo()
{
	int i,op,a1,a2,a3;
	for(i=0;i<=cx;i++) {
		op = TABCOD[i].op; a1 = TABCOD[i].a1;
		a2 = TABCOD[i].a2; a3 = TABCOD[i].a3;
		printf("%2d) ",i);

		if (a1==-1 || a2==-1 || a3==-1) {
			printf("Error: variable no declarada linea ");
			if (a2!=-1)
				printf("%d\n",TS[a2].linea);
			else {
				if (a3!=-1)
					printf("%d\n",TS[a3].linea);			
			}	
			exit(0);
		}

		switch(op)
		{
		case SUMAR: if(TS[a3].a1 == INT && TS[a2].a1 == INT)
						printf("SUMAR %s = %s + %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);
					else if(TS[a3].a1 == FLOAT && TS[a2].a1 == FLOAT)
						printf("SUMAR %s = %s + %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);
					else {
						printf("Error: asignando tipo diferente %s linea %d\n", TS[a1].nombre,TS[a2].linea);
						exit(0);		
					}		
	 				break;	
		
		case MENOR: printf("MENOR %s = %s < %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);break;
		case MENOR_IGUAL: printf("MENOR_IGUAL %s = %s <= %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);break;
		case MAYOR: printf("MAYOR %s = %s > %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);break;
		case MAYOR_IGUAL: printf("MAYOR_IGUAL %s = %s >= %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);break;
		case SALTAR: printf("SALTAR %d \n",a3);break;
		case SALTARV: printf("SALTARV %s %d \n",TS[a1].nombre,a3);break;
		case SALTARF: printf("SALTARF %s %d \n",TS[a1].nombre,a3);break;
		case MOVER: 
					if(TS[a1].a1 == INT && TS[a2].a1 == INT)
						printf("MOVER %s %s \n",TS[a1].nombre,TS[a2].nombre);
					else if(TS[a1].a1 == FLOAT && TS[a2].a1 == FLOAT)
						printf("MOVER %s %s \n",TS[a1].nombre,TS[a2].nombre);
					else if(TS[a1].a1 == BOOL && TS[a2].a1 == BOOL)
						printf("MOVER %s %s \n",TS[a1].nombre,TS[a2].nombre);	
					else if(TS[a1].a1 == STRING && TS[a2].a1 == STRING)
						printf("MOVER %s %s \n",TS[a1].nombre,TS[a2].nombre);		
					else if(TS[a1].a1 == BOOL && TS[a2].a1 == INT)
						printf("MOVER %s %s \n",TS[a1].nombre,TS[a2].nombre);			
					else {
						printf("Error: asignando tipo diferente %s linea %d\n", TS[a1].nombre, TS[a2].linea);
						exit(0);		
					}		
	 				break;
		case IMPRINUM: printf("IMPRINUM %s \n",TS[a1].nombre);break;
		
        case RESTAR      : if(TS[a3].a1 == INT && TS[a2].a1 == INT)
								printf("RESTAR %s = %s - %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);
							else if(TS[a3].a1 == FLOAT && TS[a2].a1 == FLOAT)
								printf("RESTAR %s = %s - %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);
							else {
								printf("Error: asignando tipo diferente %s linea %d\n", TS[a1].nombre,TS[a2].linea);
								exit(0);		
							}		
			 				break;	
        case MULTIPLICAR : 
        				if(TS[a3].a1 == INT && TS[a2].a1 == INT)
							printf("MULTIPLICAR %s = %s * %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);
						else if(TS[a3].a1 == FLOAT && TS[a2].a1 == FLOAT)
							printf("MULTIPLICAR %s = %s * %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);
						else {
							printf("Error: asignando tipo diferente %s linea %d\n", TS[a1].nombre, TS[a2].linea);
							exit(0);		
						}		
		 				break;	
        case DIVIDIR : 
        				if(TS[a3].a1 == INT && TS[a2].a1 == INT)
							printf("DIVIDIR %s = %s / %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);
						else if(TS[a3].a1 == FLOAT && TS[a2].a1 == FLOAT)
							printf("DIVIDIR %s = %s / %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);
						else {
							printf("Error: asignando tipo diferente %s linea %d\n", TS[a1].nombre, TS[a2].linea);
							exit(0);		
						}		
		 				break;	
		case MODULO : 
        				if(TS[a3].a1 == INT && TS[a2].a1 == INT)
							printf("MODULO %s = %s %% %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);
						else {
							printf("Error: asignando tipo diferente %s linea %d\n", TS[a1].nombre, TS[a2].linea);
							exit(0);		
						}		
		 				break;	 				
        case POTENCIA : 
        				if(TS[a3].a1 == INT && TS[a2].a1 == INT)
							printf("POTENCIA %s = %s ^ %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);
						else {
							printf("Error: asignando tipo diferente %s linea %d\n", TS[a1].nombre, TS[a2].linea);
							exit(0);		
						}		
		 				break;


		case OPER_OR: printf("OR %s = %s || %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);break;
		case OPER_AND: printf("AND %s = %s && %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);break;

		case NEGACION: 
						if (TS[a2].a1 == BOOL)
							printf("NOT %s = ! %s\n",TS[a1].nombre, TS[a2].nombre);
						else {
							printf("Error: operacion invalida %s linea %d\n", TS[a1].nombre,TS[a2].linea);
							exit(0);			
						}		
		 				break;		
		case IGUAL: printf("IGUAL %s = %s == %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);break;
		case NOIGUAL: printf("NOIGUAL %s = %s != %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);break;

		}
	}
	return;
}


int localizaSimbolo(char *n)
{
	int i;
	for(i=0;i<nTS;i++) 
		if(strcmp(n,TS[i].nombre) == 0) 
			return i;

	return -1;
}

void IS(char *lexema, int tipo, int clase)
{
	int posicion;
	posicion = localizaSimbolo(lexema);

	if(posicion>=0) {
		if(TS[posicion].a2==VAR) {
			if(TS[posicion].a1==tipo)
				printf("Error: redeclaracion de %s %s linea %d\n",TS[posicion].tipo,lexema,numeroLinea+1);
			else	
				printf("Error: conflicto declaracion %s %s linea %d\n",TS[posicion].tipo,lexema,numeroLinea+1);
			exit(0);
		}
	}

	else 
	{
		strcpy(TS[nTS].nombre,lexema);
		TS[nTS].a1 = tipo;
		TS[nTS].a2 = clase;
		TS[nTS].linea = numeroLinea+1;
		if (TS[nTS].a1==INT)
			strcpy(TS[nTS].tipo,"int");
		else if (TS[nTS].a1==FLOAT)
			strcpy(TS[nTS].tipo,"float");
		else if (TS[nTS].a1==STRING)
			strcpy(TS[nTS].tipo,"string");	
		else		
			strcpy(TS[nTS].tipo,"bool");

		if (TS[nTS].a2==VAR)
			strcpy(TS[nTS].clase,"var");
		else if (TS[nTS].a2==FUNCION)
			strcpy(TS[nTS].clase,"func");
		else if (TS[nTS].a2==ARREGLO)
			strcpy(TS[nTS].clase,"array");	
		else 
			strcpy(TS[nTS].clase,"temp");		

		nTS++;
	}	
}

void muestraSimbolo()
{
	int i;
	printf("\t\t\tTabla de Simbolos \n");
	for(i=0,pTS=TS;i<nTS;i++,pTS++) {
		if (pTS->a1==INT)
			printf("%20s \t%s \t%s \t%d\n",pTS->nombre,pTS->tipo,pTS->clase,pTS->a3.entero);
		else if (pTS->a1==FLOAT)
			printf("%20s \t%s \t%s \t%g\n",pTS->nombre,pTS->tipo,pTS->clase,pTS->a3.real);
		else if (pTS->a1==BOOL)
			printf("%20s \t%s \t%s \t%s\n",pTS->nombre,pTS->tipo,pTS->clase,pTS->a3.booleano);		
		else
			printf("%20s \t%s \t%s \t%s\n",pTS->nombre,pTS->tipo,pTS->clase,pTS->a3.cadena);	
	}
} 

void tabla_codigo()
{
	int i;
	printf("\t\t\tTabla de Codigos \n");
	for(i=0;i<cx;i++) 
			printf("%d %20d \t%d \t%d \t%d\n",i+1,TABCOD[i].op,TABCOD[i].a1,TABCOD[i].a2,TABCOD[i].a3);
} 

// Generacion de codigo intermedio: (3AC) codigo de 3 direcciones

void interprete(){
	int icx,op,a1,a2,a3;
	float v;
	printf("Programa en ejecución: \n");
	icx = 0;

	while(1)
	{
		if(icx==cx+1) break;
		op = TABCOD[icx].op;
		a1 = TABCOD[icx].a1;
		a2 = TABCOD[icx].a2;
		a3 = TABCOD[icx].a3;
		switch(op)
		{
			case SALTAR : icx = a3; continue;
			case SALTARF : 
						   if(TS[a1].a3.entero==0) { icx = a3; continue;}
						   else break;

			case IMPRINUM : 
							if(TS[a1].a1 == INT)
								printf("    %s %d\n",TS[a1].nombre,TS[a1].a3.entero); 
							else if(TS[a1].a1 == BOOL)
								printf("    %s %s\n",TS[a1].nombre,TS[a1].a3.booleano); 	
							else if(TS[a1].a1 == STRING)
								printf("    %s %s\n",TS[a1].nombre,TS[a1].a3.cadena); 		
							else	
								printf("    %s %8.2f\n",TS[a1].nombre,TS[a1].a3.real);
							break;

			case MOVER : 	if(TS[a1].a1 == INT)
								TS[a1].a3.entero = TS[a2].a3.entero;
							else if(TS[a1].a1 == FLOAT)
								TS[a1].a3.real = TS[a2].a3.real;
							else if(TS[a1].a1 == STRING) 
								strcpy(TS[a1].a3.cadena,TS[a2].a3.cadena);	
							else {
								strcpy(TS[a1].a3.booleano,TS[a2].a3.booleano);
								TS[a2].a3.entero = 0;	
							}
			 				break;

			case MENOR :    {  int t;
								t = (TS[a2].a3.entero < TS[a3].a3.entero);
								strcpy(TS[a1].a3.booleano,"false");
								if (t==1)
									strcpy(TS[a1].a3.booleano,"true");								
							}	
						 	break;
			case MENOR_IGUAL :  {  int t;
								t = (TS[a2].a3.entero <= TS[a3].a3.entero);
								strcpy(TS[a1].a3.booleano,"false");
								if (t==1)
									strcpy(TS[a1].a3.booleano,"true");								
								}	
						 		break;
			case MAYOR : {  int t;
								t = (TS[a2].a3.entero > TS[a3].a3.entero);
								strcpy(TS[a1].a3.booleano,"false");
								if (t==1)
									strcpy(TS[a1].a3.booleano,"true");								
							}	
						 	break;
			case MAYOR_IGUAL : {  int t;
								t = (TS[a2].a3.entero >= TS[a3].a3.entero);
								strcpy(TS[a1].a3.booleano,"false");
								if (t==1)
									strcpy(TS[a1].a3.booleano,"true");								
							}	
						 	break;

			case SUMAR : if(TS[a1].a1 == INT)
							TS[a1].a3.entero = TS[a2].a3.entero + TS[a3].a3.entero;
						 else	
							TS[a1].a3.real = TS[a2].a3.real + TS[a3].a3.real;
						 break;
		
            case RESTAR :   if(TS[a1].a1 == INT)
								TS[a1].a3.entero = TS[a2].a3.entero - TS[a3].a3.entero;
							else	
								TS[a1].a3.real = TS[a2].a3.real - TS[a3].a3.real;
							break;
            case MULTIPLICAR :  if(TS[a1].a1 == INT)
									TS[a1].a3.entero = TS[a2].a3.entero * TS[a3].a3.entero;
								else	
									TS[a1].a3.real = TS[a2].a3.real * TS[a3].a3.real;
								break;
            case DIVIDIR     :  if(TS[a1].a1 == INT)
									TS[a1].a3.entero = TS[a2].a3.entero / TS[a3].a3.entero;
								else	
									TS[a1].a3.real = TS[a2].a3.real / TS[a3].a3.real;
								break;
			case MODULO     :  if(TS[a1].a1 == INT)
									TS[a1].a3.entero = TS[a2].a3.entero % TS[a3].a3.entero;
								break;					
			case POTENCIA   :  if(TS[a1].a1 == INT)
									TS[a1].a3.entero =  (int) pow((double) TS[a2].a3.entero,TS[a3].a3.entero);
								break;					


            case OPER_OR :  {
	            				int t1 = 0, t2 = 0, t3;
	            				if (strcmp(TS[a2].a3.booleano,"true")==0) 
	            					t1 = 1;

	            				if (strcmp(TS[a3].a3.booleano,"true")==0)
	            					t2 = 1;	

	            				t3 = t1 || t2; 
	            				strcpy(TS[a1].a3.booleano,"false");
	            				if (t3==1)
	            					strcpy(TS[a1].a3.booleano,"true");
            				}
            				break;		
            case OPER_AND : {
	            				int t1 = 0, t2 = 0, t3;
	            				if (strcmp(TS[a2].a3.booleano,"true")==0) 
	            					t1 = 1;

	            				if (strcmp(TS[a3].a3.booleano,"true")==0)
	            					t2 = 1;	

	            				t3 = t1 && t2; 
	            				strcpy(TS[a1].a3.booleano,"false");
	            				if (t3==1)
	            					strcpy(TS[a1].a3.booleano,"true");
            				}
            				break;		
            case NEGACION: 
            				if (strcmp(TS[a2].a3.booleano,"true")==0)
            			   		strcpy(TS[a1].a3.booleano,"false");
            			   	else	
            				 	strcpy(TS[a1].a3.booleano,"true");
            				break;

            case IGUAL : {  int t;
								t = (TS[a2].a3.entero == TS[a3].a3.entero);
								strcpy(TS[a1].a3.booleano,"false");
								if (t==1)
									strcpy(TS[a1].a3.booleano,"true");								
							}	
						 	break;
            case NOIGUAL : {  int t;
								t = (TS[a2].a3.entero != TS[a3].a3.entero);
								strcpy(TS[a1].a3.booleano,"false");
								if (t==1)
									strcpy(TS[a1].a3.booleano,"true");								
							}	
						 	break;
		}
		icx++;
	}  
}  


// Analizador lexico
int yylex()
{
	int c;  
	char *p;

	do {
		c=getchar(); 
		if (c=='\n')
    		++numeroLinea;
	}while(isspace(c));
  
  	if (isalpha(c))
    { 
    	p=lexema;
		do  { *p++=c; c=getchar(); } while (isalpha(c));

		ungetc(c,stdin); *p=0;

		if (strcmp(lexema,"if")==0) return IF;
		if (strcmp(lexema,"else")==0) return ELSE;
		if (strcmp(lexema,"int")==0) return tipoVar=yylval=INT;
		if (strcmp(lexema,"float")==0) return tipoVar=yylval=FLOAT;
		if (strcmp(lexema,"while")==0) return WHILE;
		if (strcmp(lexema,"for")==0) return FOR;
		if (strcmp(lexema,"do")==0) return DO;
		if (strcmp(lexema,"print")==0) return IMPRINUM;
		if (strcmp(lexema,"bool")==0) return tipoVar=yylval=BOOL;
		if (strcmp(lexema,"true")==0) return yylval=BOOLEANO;
		if (strcmp(lexema,"false")==0) return yylval=BOOLEANO;
		if (strcmp(lexema,"string")==0) return tipoVar=yylval=STRING;
      
      	return yylval=ID;
    }

    if (c==EOF) 
    	return EOF;
  
    if ( c=='(' || c==')' || c==';' || c==',' || c=='{' || c=='}' ||
         c==',' || c=='*' || c=='+' || c=='-' || c=='?' ||
         c=='[' || c==']' || c=='%' || c=='^') return yylval=c;

	if(c=='/') 
	{	c=getchar();
    	if(c=='/') 
    	{
			do c=getchar(); while(c!='\n');
			if (c=='\n')
    			++numeroLinea;
			return COMENTARIO;
    	}

		if(c=='*') 
		{ 
			do {
				c=getchar();
				if (c=='\n')
    				++numeroLinea; 
			}while(c!='*');

			c=getchar();
		 	return COMENTARIO;
		}

		ungetc(c,stdin); return '/';
	}     

    if ( c=='!') 
    { 
    	c=getchar();
    	if(c=='=') return NOIGUAL;
    	ungetc(c,stdin); return NOT;
    }
    	
    if ( c=='=' ) 
    {
    	c=getchar();
    	if(c=='=') return IGUAL;
    	ungetc(c,stdin); return '=';
    }
    	
    if ( c=='>' ) 
    {
    	c=getchar();
    	if(c=='=') return MAYORIGUAL;
    	ungetc(c,stdin); return '>';
    }
    	
    if ( c=='<' ) 
    {
    	c=getchar();
    	if(c=='=') return MENORIGUAL;
    	ungetc(c,stdin); return '<';
    }

    if ( c=='&' ) 
    {
    	c=getchar();
    	if(c=='&') return AND;
    	ungetc(c,stdin); return '&';
    }

    if ( c=='|' ) 
    {
    	c=getchar();
    	if(c=='|') return OR;
    	ungetc(c,stdin); return '|';
    }

    if (c=='\"')
    {	
    	p=lexema;
    	c=getchar();
		do  { *p++=c; c=getchar(); } while (c!='\"');

		*p=0;
		c=getchar();
		return yylval=LETRAS;
    }

    if (isdigit(c)) 
    { 
    	p=lexema;
      	do  { *p++=c; c=getchar(); } while (isdigit(c));

      	if(c=='.') 
      	{	do  { *p++=c; c=getchar(); } while (isdigit(c));
      		ungetc(c,stdin); 
      		*p=0; 
      		return yylval=REAL;
      	}

      	ungetc(c,stdin); *p=0;
    	return yylval=NUM;
    }
    	
    yyerror("caracter no valido\n");
}

void yyerror(char *m)  { 
	printf("%s\n",m); 
	exit(0);
}
	
int main()  
{
	yyparse(); // llama automáticamente a yylex para obtener cada token
	printf("\n");
	muestraSimbolo();
	printf("\n");
	muestraCodigo();
	interprete();
	printf("\n");
	muestraSimbolo();
	return 0;
}