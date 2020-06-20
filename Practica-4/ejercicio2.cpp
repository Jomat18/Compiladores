
#include <stdio.h>
#include <iostream>

using namespace std;

int preanalisis;
void parea(int);
void error();
void Resto();
void Term();


void Exp()
{
	if (preanalisis=='0') { 
		Term();
		Resto(); 
	}
	else if (preanalisis=='1') { 
		Term();
		Resto(); 
	}
	else if (preanalisis=='2') { 
		Term();
		Resto(); 
	}
	else if (preanalisis=='3') { 
		Term();
		Resto(); 
	}
	else if (preanalisis=='4') { 
		Term();
		Resto(); 
	}
	else if (preanalisis=='5') { 
		Term();
		Resto(); 
	}
	else if (preanalisis=='6') { 
		Term();
		Resto(); 
	}
	else if (preanalisis=='7') { 
		Term();
		Resto(); 
	}
	else if (preanalisis=='8') { 
		Term();
		Resto(); 
	}
	else if (preanalisis=='9') { 
		Term();
		Resto(); 
	}
	else
		error();
}

void Resto()
{
	if (preanalisis == '+') { 
		parea('+');
		Term();
		printf("+");
		Resto();
 	}
	else if (preanalisis == '-') { 
		parea('-');
		Term();
		printf("-");
		Resto();
 	}
	else //cadena vacia
 		;
}

void Term()
{
	if (preanalisis=='0') { 
 		printf("0");
 		parea('0'); 
 	}
 	else if (preanalisis=='1') { 
 		printf("1");
 		parea('1'); 
 	}
 	else if (preanalisis=='2') { 
 		printf("2");
 		parea('2'); 
 	}
 	else if (preanalisis=='3') { 
 		printf("3");
 		parea('3'); 
 	}
 	else if (preanalisis=='4') { 
 		printf("4");
 		parea('4'); 
 	}
 	else if (preanalisis=='5') { 
 		printf("5");
 		parea('5'); 
 	}
 	else if (preanalisis=='6') { 
 		printf("6");
 		parea('6'); 
 	}
 	else if (preanalisis=='7') { 
 		printf("7");
 		parea('7'); 
 	}
 	else if (preanalisis=='8') { 
 		printf("8");
 		parea('8'); 
 	}
 	else if (preanalisis=='9') { 
 		printf("9");
 		parea('9'); 
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
	if (preanalisis==t)
		preanalisis=getchar();
	else
		error();
}

int main()
{
	preanalisis=getchar(); 
 	Exp();
	cout<<endl;

	return 0;
}