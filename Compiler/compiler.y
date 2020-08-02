%{

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "datos.h"

int yylex();
void yyerror(char *m);
%}

%token INT FLOAT NUM REAL FORMATO ID IF ELSE WHILE DO FOR 
%token LEENUM IMPRINUM COMENTARIO
%token CENTERO	CFLOAT VAR FUNCION ARREGLO
%right '=' NOT
%left '?'
%left OR AND	
%left IGUAL NOIGUAL MENORIGUAL MAYORIGUAL '<' '>'
%left '+' '-'
%left '*' '/'

%%

	programaC : listaDeclC ;

	listaDeclC : listaDeclC declC | listComent |;

	declC : Tipo listaVar ';' comentario;
	declC : Tipo ID '(' { IS(lexema,$1,FUNCION);}	listaPar ')' bloque ;

	listComent: listComent comentario |;
	comentario: COMENTARIO | ;

	Tipo : INT  | FLOAT;
	
	listaVar : ID ',' { IS(lexema,tipoVar,VAR); }	listaVar | ID { IS(lexema,tipoVar,VAR); } | ID { IS(lexema,tipoVar,ARREGLO); } '[' NUM ']' ;
	listaPar : Tipo ID { IS(lexema,$1,VAR); }',' listaPar   | Tipo ID { IS(lexema,$1,VAR); };

	bloque : '{' listaVarLoc listaProp '}';
	listaVarLoc : Tipo listaVar ';' listaVarLoc comentario | ;
	listaProp : listaProp prop | ;

	prop : ';' ;
	prop : bloque ;
    prop : IF '(' expr ')' {genCodigo(SALTARF,$3,0,-1); $$ = cx; } prop  { TABCOD[$5].a3 = cx + 1;  } ;
	/*prop : IF '(' expr ')' prop ELSE prop ;*/
	prop : WHILE '(' {$$ = cx + 1;}  expr    ')' 	{genCodigo(SALTARF,$4,0,-1); /* Destino no resuelto */
	   						                         $$ = cx; /* Falta llenar cuarto componente de este salto */} 
				                                 prop	
				                                 	{genCodigo(SALTAR,0,0,$3); /* Ir al comienzo de la expresión */
							                         TABCOD[$6].a3 = cx + 1; /* Llenando destino de sltar falso */
				                                    } ;
	prop : FOR '(' expr ';' expr ';' expr ')' prop ;
	prop : IMPRINUM '(' /*FORMATO	{ $$ = nTS; IS(lexema,FORMATO,0); printf(lexema);} ','*/  expr ')'	{genCodigo(IMPRINUM,$3,0,0);};

	prop : expr ;
	expr : expr OR expr {int n = genvartemp(0);	genCodigo(OPER_OR,n,$1,$3);  $$=n;} ;
	expr : expr AND expr {int n = genvartemp(0);	genCodigo(OPER_AND,n,$1,$3);  $$=n;} ;
	expr : NOT expr {int n = genvartemp(0); genCodigo(NEGACION,n,$2,0); $$=n;};
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

	expr : expr '?' expr ':' expr ;
	expr : ID {$$ = localizaSimbolo(lexema);};
	expr : NUM  {IS(lexema,INT,NUM);$$ = localizaSimbolo(lexema);TS[$$].a3.entero = atoi(lexema);};	
	/*expr : BOOLEANO {IS(lexema,$1,BOOLEANO);$$ = localizaSimbolo(lexema);TS[$$].a3.booleano = lexema;};*/
	
	expr : REAL	{float v; IS(lexema,FLOAT,REAL);$$ = localizaSimbolo(lexema);	sscanf(lexema,"%f",&v);TS[$$].a3.real = v;};	
	expr : ID '=' { $$ = localizaSimbolo(lexema); }	expr {genCodigo(MOVER,$3,$4,0);} ; 
	expr : ID '[' expr ']' ;
	expr : ID '[' expr ']' '=' expr;

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
	TS[nTS].a2 = VAR;
	return nTS++;
}

void muestraCodigo()
{
	int i,op,a1,a2,a3;
	for(i=0;i<=cx;i++) {
		op = TABCOD[i].op; a1 = TABCOD[i].a1;
		a2 = TABCOD[i].a2; a3 = TABCOD[i].a3;
		printf("%2d) ",i);
		switch(op)
		{
		case SUMAR: if(TS[a3].a1 == INT && TS[a2].a1 == INT)
						printf("SUMAR %s = %s + %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);
					else if(TS[a3].a1 == FLOAT && TS[a2].a1 == FLOAT)
						printf("SUMAR %s = %s + %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);
					else {
						printf("Error asignando tipo diferente\n");
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
		case MOVER: if(TS[a1].a1 == INT && TS[a2].a1 == INT)
						printf("MOVER %s %s \n",TS[a1].nombre,TS[a2].nombre);
					else if(TS[a1].a1 == FLOAT && TS[a2].a1 == FLOAT)
						printf("MOVER %s %s \n",TS[a1].nombre,TS[a2].nombre);
					else {
						printf("Error asignando tipo diferente\n");
						exit(0);		
					}		
	 				break;
		case IMPRINUM: printf("IMPRINUM %s \n",TS[a1].nombre);break;
		
        case RESTAR      : if(TS[a3].a1 == INT && TS[a2].a1 == INT)
								printf("RESTAR %s = %s - %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);
							else if(TS[a3].a1 == FLOAT && TS[a2].a1 == FLOAT)
								printf("RESTAR %s = %s - %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);
							else {
								printf("Error asignando tipo diferente\n");
								exit(0);		
							}		
			 				break;	
        case MULTIPLICAR : 
        				if(TS[a3].a1 == INT && TS[a2].a1 == INT)
							printf("MULTIPLICAR %s = %s * %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);
						else if(TS[a3].a1 == FLOAT && TS[a2].a1 == FLOAT)
							printf("MULTIPLICAR %s = %s * %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);
						else {
							printf("Error asignando tipo diferente\n");
							exit(0);		
						}		
		 				break;	
        case DIVIDIR : 
        				if(TS[a3].a1 == INT && TS[a2].a1 == INT)
							printf("DIVIDIR %s = %s / %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);
						else if(TS[a3].a1 == FLOAT && TS[a2].a1 == FLOAT)
							printf("DIVIDIR %s = %s / %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);
						else {
							printf("Error asignando tipo diferente\n");
							exit(0);		
						}		
		 				break;	
		case OPER_OR: printf("OR %s = %s || %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);break;
		case OPER_AND: printf("AND %s = %s && %s\n",TS[a1].nombre,TS[a2].nombre,TS[a3].nombre);break;

		case NEGACION: printf("NOT %s = ! %s\n",TS[a1].nombre, TS[a2].nombre);break;

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
	if(localizaSimbolo(lexema)>=0) 
		;
		//printf("actualizar, ya declarado\n");

	else 
	{
		strcpy(TS[nTS].nombre,lexema);
		TS[nTS].a1 = tipo;
		TS[nTS].a2 = clase;
		nTS++;
	}	
}

void muestraSimbolo()
{
	int i;
	for(i=0,pTS=TS;i<nTS;i++,pTS++)
		printf("%20s %d %d %g\n",pTS->nombre,pTS->a1,pTS->a2,pTS->a3.real);
} 

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
			case SALTARF : if(TS[a1].a3.entero==0) { icx = a3; continue;}
						   else break;

			case IMPRINUM : 
							if(TS[a1].a1 == INT)
								printf("    %d\n",TS[a1].a3.entero); 
							/*else if(TS[a1].a1 == BOOLEANO)
								printf("    %s\n",TS[a1].a3.booleano); 	*/
							else	
								printf("%8.2f\n",TS[a1].a3.real);
							break;

			case MOVER : 	if(TS[a1].a1 == INT)
								TS[a1].a3.entero = TS[a2].a3.entero;
							else if(TS[a1].a1 == FLOAT)
								TS[a1].a3.real = TS[a2].a3.real;
			 				break;

			case MENOR : TS[a1].a3.real = (TS[a2].a3.real < TS[a3].a3.real); break;
			case MENOR_IGUAL : TS[a1].a3.real = (TS[a2].a3.real <= TS[a3].a3.real); break;
			case MAYOR : TS[a1].a3.real = (TS[a2].a3.real > TS[a3].a3.real); break;
			case MAYOR_IGUAL : TS[a1].a3.real = (TS[a2].a3.real >= TS[a3].a3.real); break;

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

            case OPER_OR : TS[a1].a3.real = (TS[a2].a3.real || TS[a3].a3.real); break;
            case OPER_AND : TS[a1].a3.real = (TS[a2].a3.real && TS[a3].a3.real); break;

            case NEGACION: TS[a1].a3.entero = ! TS[a2].a3.entero; break;
            				/*TS[a1].a3.booleano = ! TS[a2].a3.booleano ;break;*/

            case IGUAL : TS[a1].a3.real = (TS[a2].a3.real == TS[a3].a3.real); break;
            case NOIGUAL : TS[a1].a3.real = (TS[a2].a3.real != TS[a3].a3.real); break;
		}
		icx++;
	}  
}  



int yylex()
{
	int c;  
	char *p;

	do  c=getchar(); while(isspace(c));
  
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
		/*if (strcmp(lexema,"true")==0) return BOOLEANO;*/
		/*if (strcmp(lexema,"false")==0) return BOOLEANO;*/
      
      	return yylval=ID;
    }

    if (c==EOF) return EOF;
  
    if ( c=='(' || c==')' || c==';' || c==',' || c=='{' || c=='}' ||
         c==',' || c=='*' || c=='+' || c=='-' || c=='?' ||
         c=='[' || c==']' ) return yylval=c;

	if(c=='/') 
	{	c=getchar();
    	if(c=='/') 
    	{
			do c=getchar(); while(c!='\n');
			return COMENTARIO;
    	}

		if(c=='*') 
		{ 
			do c=getchar(); while(c!='*');
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
	yyparse();
	muestraSimbolo();
	muestraCodigo();
	interprete();

	return 0;
}