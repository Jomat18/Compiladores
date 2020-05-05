#include <iostream>
#include <string>

using namespace std;

//Hecho en linux
//g++ ejercicio1.cpp
//./a.out int main 
int main(int argc, char ** argv){
	string palabra;
	for (int i=1; i<argc; i++) {
		palabra = argv[i];
		for (int j=0;j< palabra.size();j++)	{
			cout<<palabra[j] <<"\n";		
		}
	}

	return 0;
}