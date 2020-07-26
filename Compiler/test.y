%{
#include <stdio.h> /* printf */
#include <ctype.h> /* isdigit, isalpha*/ 
#include <stdlib.h> /* exit */
#include <string.h>

/* Tabla de simbolos */
typedef union 
{	
	int entero;
	float real;	
} tipovalor;

typedef struct
{
	char nombre[30];
	int a1; /* tipo dato */
	int a2; /* var/func */
	int direccion; /*en memoria*/
	int size; 
	int retorno; /*retorno funcion*/
	tipovalor a3;  /* guardar valor int/float */
} tipoTablaSimbolo;

tipoTablaSimbolo TS[100], *pTS;
int nTS = 0;

char lexema[80];
int tipoVar;

int yylex();
void yyerror(char *m);

%}
%start prog

%token ID IF ELSE NUM REAL WHILE
%token INT FLOAT
%token VAR FUNCION
%token NOT

%left '+' '-'
%left '*' '/'
%left IGUAL NOIGUAL MENORIGUAL '<' '>'
%right '^' '='

%%
	prog	: exp { printf("%d\n", $1);}; 

	exp		: exp '+' term {$$=$1+$3;};
			| exp '-' term {$$=$1-$3;};
			| term 		   {{$$=$1;};};

	term    : term '*' factor {$$=$1*$3;};
			| term '/' factor {$$=$1/$3;};
			| factor 		  {{$$=$1;};};

	factor	: '(' exp ')'  {{$$=$2;};};
			| NUM		   {{$$=$1;};};
%%

int yylex()
{
	int c;
	do c=getchar(); while (c==' '|| c=='\t');
	if (c=='\n') return EOF;

	if (isdigit(c))
	{	
		ungetc(c, stdin);
		scanf("%d", &yylval); 
		return NUM;
	}

	if(c=='(' || c==')' || c==';' || c==',' || c=='{' || c=='}') return c;
	if(c=='+' || c=='-' || c=='*' || c=='/') return c;
	if(c=='=') return c;

	yyerror("token no valido");
}

void yyerror(char *m)
{
	printf("%s\n",m);
	exit(0);
}

int main()
{
	yyparse();

	return 0;
}