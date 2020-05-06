#include <iostream>
#include <fstream>

using namespace std;
int main()
{
  ifstream archivo;
  ofstream descifrado;
  string palabra;
  archivo.open("cifrado.cpp",ios::in);
  descifrado.open("descifrado.cpp",ios::out);

  if (archivo.fail())
  {
    cout<<"no se pudo abrir el archivo ";
    exit(1);      
  }

  if (descifrado.fail())
  {
    cout<<"no se pudo abrir el archivo ";
    exit(1);      
  }

  while(!archivo.eof()) {
    palabra = (char)archivo.get();

    for (int i=0;i< palabra.size();i++) {
      if (!isblank(palabra[i]) && palabra[i]!='\n') {
        descifrado<<(char)((int)palabra[i]-3);
      }
      else {
        if (isblank(palabra[i])) {
            descifrado<<' ';
        }
        else {
            descifrado<<'\n';
        }
      }
    }
  }
   
   return 0;
}
