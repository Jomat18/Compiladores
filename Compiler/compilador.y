%{

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

typedef union 
{   
    int entero;
		float real; 
} tipovalor;


typedef struct 
{
    char  nombre[30];
    int       a1;  /* a1: INT/FLOAT/NUM/   */
    int       a2;  /* a2: FUN/VAR */
    tipovalor a3;  /* guarda valor, sera entero o real ocupando una sola posicion de memoria */

}  tipoTablaSimbolo;

tipoTablaSimbolo TS[100], *pTS;
int nTS = 0; //numero de simbolos que hay en la tabla

char lexema[80];
int tipoVar;

int yylex();
void yyerror(char *m);

int localizaSimbolo(char *n);
int insertaSimbolo(char *n, int tipo, int clase);
void muestraSimbolo();

%}

%token ID IF ELSE NUM REAL WHILE /* ID=258 */
%token INT FLOAT  /*  INT=264 FLOAT=265 */
%token VAR FUNCION /* VAR=266 FUNCTION=267 */
%token NOT

%right '='  /* asignacion */
%left IGUAL NOIGUAL MENORIGUAL '<' '>'
%left '+' '-'
%left '*' '/'

%%

	programaC   : listaDeclC ;
	listaDeclC  : listaDeclC declC | ;
	declC       : Tipo listaVar ';';
	declC       : Tipo ID '(' { insertaSimbolo(lexema, $1,FUNCION);} listaPar ')' bloque;

	Tipo        : INT  | FLOAT ;
	listaVar    : ID ',' { insertaSimbolo(lexema, tipoVar,VAR); } listaVar | ID { insertaSimbolo(lexema, tipoVar,VAR); };
  listaPar    : Tipo ID { insertaSimbolo(lexema, $1,VAR); } ',' listaPar	| Tipo ID { insertaSimbolo(lexema, $1,VAR); };

	bloque      : '{' listaVarLoc listaProp '}';

	listaVarLoc : Tipo listaVar ';' listaVarLoc | ;

	listaProp   : listaProp prop | ;

	prop        : ';' ;
  prop        : IF '(' expr ')'  prop  ;
	prop        : WHILE '('  expr  ')'prop ;

	prop        : bloque ;
	prop        : ID '=' { $$ = localizaSimbolo(lexema); } expr ;   /* Codigo 3 */

	expr        : expr IGUAL expr ;
	expr        : expr NOIGUAL expr ;
  expr        : expr '<' expr ;  /* n = $1 < $3  */
  expr 	      : expr '+' expr ;  /*  sumar,a+b,a,b   */
  expr        : expr '-' expr ;  /*  restar,a-b,a,b   */;
  expr        : expr '*' expr ;  /*  multiplicar,a*b,a,b   */;
  expr        : expr '/' expr ;  /*  dividir,a/b,a,b   */;
	expr        : ID {$$ = localizaSimbolo(lexema);} ;

  expr        : NUM  {insertaSimbolo(lexema, $1,NUM); $$=localizaSimbolo(lexema);   TS[$$].a3.entero = atoi(lexema);}  ;  
	expr        : REAL {float v; insertaSimbolo(lexema, $1,REAL);$$ = localizaSimbolo(lexema); sscanf(lexema,"%f",&v);TS[$$].a3.real = v;};   /* Codigo 2 */


%%


int localizaSimbolo(char *n)
{
	int i;
	for(i=0;i<nTS;i++) 
          if(strcmp(n,TS[i].nombre) == 0) 
              return i;
	return -1;
}

int insertaSimbolo(char *n, int tipo, int clase)
{
	if(localizaSimbolo(n)>=0) 
              return -1;
	strcpy(TS[nTS].nombre,n);
	TS[nTS].a1 = tipo;
	TS[nTS].a2 = clase;
  TS[nTS].a3.real = 0;
  nTS++;
}

void muestraSimbolo()
{
	int i;
	for(i=0,pTS=TS;i<nTS;i++,pTS++)
		printf("%20s %d %d %g\n",pTS->nombre,pTS->a1,pTS->a2,pTS->a3.real);
} 


int yylex()

{
  int c;  
  char *p;

  do  c=getchar(); while(isspace(c)); //borra espacios en blanco 


  if (isalpha(c))  // ID o palabra reservada
    { p=lexema;
      do  { *p++=c; c=getchar(); } while (isalpha(c));

      ungetc(c,stdin); *p=0;

      /* verificando si es palabra reservada  */

      if (strcmp(lexema,"if")==0) return IF;
      if (strcmp(lexema,"else")==0) return ELSE;
      if (strcmp(lexema,"int")==0) return tipoVar=yylval=INT;
      if (strcmp(lexema,"float")==0) return tipoVar=yylval=FLOAT;
      if (strcmp(lexema,"while")==0) return WHILE;
      
      /* van otras palabras reservadas */
      
      return yylval=ID;
    }

    if(c==EOF) return EOF;
  
    if ( c=='(' || c==')' || c==';' || c==',' || c=='{' || c=='}' ||
         c=='*' || c=='/' || c=='+' || c=='-' )  return yylval=c;

    if ( c=='!') { 
    	c=getchar();
    	if(c=='=') return NOIGUAL;
    	ungetc(c,stdin); return NOT;
    	}
    	
    if ( c=='=' ) {
    	c=getchar();
    	if(c=='=') return IGUAL;
    	ungetc(c,stdin); return '=';
    	}
    	
    	
    if ( c=='<' ) {
    	c=getchar();
    	if(c=='=') return MENORIGUAL;
    	ungetc(c,stdin); return '<';
    	}


    if (isdigit(c)) {   // regla num
    	p=lexema;
      	do  { *p++=c; c=getchar(); } while (isdigit(c));

      	if(c=='.') { do  { *p++=c; c=getchar(); } while (isdigit(c));
      			 ungetc(c,stdin); *p=0; return yylval=REAL;}
      	ungetc(c,stdin); 
        *p=0;
    	return yylval=NUM;
    	}
    	
    yyerror("caracter no valido");
}

void yyerror(char *m)  { 
	printf("%s\n",m); 
	//getchar(); 
	exit(0);
}

int main()  {
	yyparse();
	muestraSimbolo();

  return 0;
}


