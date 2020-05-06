#include <iostream>
#include <fstream>

using namespace std;
int main()
{
  ifstream archivo;
  ofstream cifrado;
  string palabra;
  archivo.open("codigo.cpp",ios::in);
  cifrado.open("cifrado.cpp",ios::out);

  if (archivo.fail())
  {
    cout<<"no se pudo abrir el archivo ";
    exit(1);      
  }

  if (cifrado.fail())
  {
    cout<<"no se pudo abrir el archivo ";
    exit(1);      
  }

  while(!archivo.eof()) {
    palabra = (char)archivo.get();

    for (int i=0;i< palabra.size();i++) {
      if (!isblank(palabra[i]) && palabra[i]!='\n') {
        cifrado<<(char)((int)palabra[i]+3);
      }
      else {
        if (isblank(palabra[i])) {
            cifrado<<' ';
        }
        else {
            cifrado<<'\n';
        }
      }
    }
  }
   
   return 0;
}
