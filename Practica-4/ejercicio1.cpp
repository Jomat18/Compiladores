#include <stdio.h>
#include <iostream>

using namespace std;
//#include <conio.h>

int preanalisis;
void parea(int);
void A();
void B();
void error();

void S()
{
	if (preanalisis == 'x')
	{ parea('x'); S(); 
	}
	else if (preanalisis == 'a')
	{ A(); B(); parea('c'); 
//		cout<<"Cadena aceptada\n";
	}
	else
	error();
}

void A()
{
	if (preanalisis == 'a')
		parea('a');
	else
		error();
}

void B()
{
	if (preanalisis == 'b')
		parea('b');
	else
		error();
}

void error()
{
	printf("Error de sintaxis\n");
}

void parea(int t)
{
	if (preanalisis==t)
		preanalisis=getchar();
	else
		error();
}

int main()
{
	preanalisis=getchar(); //lee un carácter
 	//de la entrada
	S();

	return 0;
}

//xabc
// xad xb error
//xxxxxxxabc

