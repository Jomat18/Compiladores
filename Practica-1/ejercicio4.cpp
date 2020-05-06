#include <iostream>
#include <fstream>

using namespace std;
int main()
{
  ifstream archivo;
  string palabra;
  string evaluar = "";
  bool iniciar = true;
  int es_numero = 0;
  int es_letra = 0;
  int es_especial = 0;
  archivo.open("codigo.cpp",ios::in);

  while(!archivo.eof()) {
    palabra = (char)archivo.get();

    for (int i=0;i< palabra.size();i++) {

      if (palabra[i]==' ' || palabra[i]=='\t' || palabra[i]=='\n') {
        if (palabra[i]!='\n') {

          if (es_letra) {
              cout<<evaluar<<" ";
              cout<<"Es una palabra\n";
          }
          if (es_numero) {
              cout<<evaluar<<" ";
              cout<<"Es un numero\n";
          }
          if (es_especial) {
              cout<<evaluar<<" ";
              cout<<"Es un caracter especial\n";
          }
          evaluar = "";
          iniciar = true;
        }
      }
      else {
        evaluar+=palabra[i];  

        if (iniciar) {
          es_numero = 1;
          es_letra = 1;
          es_especial = 1;
          iniciar = false;
        }
        
        if ((palabra[i]>64 && palabra[i]<91) || (palabra[i]>96 && palabra[i]<123)) {
            es_letra *= 1;    
        }
        else {
            es_letra *= 0;    
        }  
        if (palabra[i]>47 && palabra[i]<58) {
            es_numero *= 1;  
            
        }
        else {
            es_numero *= 0;    
        }
        if ( palabra[i]=='+' || palabra[i]=='-' || palabra[i]=='*' || palabra[i]=='\\') {
            es_especial *= 1;  
            
        }
        else {
            es_especial *= 0;    
        }
 
      }
    }
    /*  
    for (int i=0;i< palabra.size();i++) {
      
      evaluar+=palabra[i];  

      if (palabra[i]==' ' || palabra[i]=='\t' || palabra[i]=='\n') {
        evaluar.pop_back();
        
        
        if (es_letra) {
            cout<<evaluar<<" ";
            cout<<"Es una palabra\n";
        }
        if (es_numero) {
            cout<<evaluar<<" ";
            cout<<"Es un numero\n";
        }
        if (es_especial) {
            cout<<evaluar<<" ";
            cout<<"Es un caracter especial\n";
        }

        es_numero=1;
        es_letra=1;
        es_especial=1;
        evaluar = "";
        
      }  
      else {
        
        if ((palabra[i]>64 && palabra[i]<91) || (palabra[i]>96 && palabra[i]<123)) {
            es_letra *= 1;    
        }
        else {
            es_letra *= 0;    
        }  
        if (palabra[i]>47 && palabra[i]<58) {
            es_numero *= 1;  
            
        }
        else {
            es_numero *= 0;    
        }
        if ( palabra[i]=='+' || palabra[i]=='-' || palabra[i]=='*' || palabra[i]=='\\') {
            es_especial *= 1;  
            
        }
        else {
            es_especial *= 0;    
        }
        
      }  
    }*/
  }
   
   return 0;
}