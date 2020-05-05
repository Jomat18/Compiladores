#include <iostream>
#include <fstream>

using namespace std;
int main()
{
  ifstream archivo;
  string palabra;
  archivo.open("texto.txt",ios::in);

  while(!archivo.eof()) {
    palabra = (char)archivo.get();

    for (int i=0;i< palabra.size();i++) {
      if (!isblank(palabra[i])) {
        cout<<palabra[i] <<"\n";        
      }
    }
  }
   
   return 0;
}