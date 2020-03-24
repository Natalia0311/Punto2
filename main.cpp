#include "Circulo.h"
#include "Cuadrado.h"
#include "Triangulo.h"
#include "Pentagono.h"
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc,char* argv[],char *envp[]){
    string path = argv[3];
    ifstream archivo;
    archivo.open(path);
    cout << "Se abrirá el archivo: " << path << endl;
    if(archivo.is_open()){
        // Aquí va el codigo que se va a hacer para leer el archivo
        ofstream archSal;
        archSal.open("Figuras.txt");
        if( archSal.is_open() ){
          size_t datoC=0,posC,posCD, datoC2=0;
            float s[10];
            int contador;
            do{
              getline(archivo, path);
              string tipo1;
              int tip,contaux=0;
              tipo1 = path.substr(0, 1 );
              tip=atoi(tipo1.c_str());
              if (tip==1){
                  while( datoC != string::npos ){
                      string term;
                      posC= path.find(",", datoC2 + 1 );
                      posCD= path.find(",", datoC + 4 );
                      term = path.substr( posC, posCD-posC );
                      s[contador]= atof(term.c_str());
                      contador++;
                      datoC = posC;
                  }
                  Circulo a= Circulo( s[0],s[1],s[2] );
                  archSal <<"Círculo"<< a.Perimetro() <<", "<<a.Area()<<", "<<a.getCoordX()<<", "<<a.getCoordX()<< endl;
              }
              if(tip==2){
                  while( datoC != string::npos ){
                      string term;
                      posC= path.find(",", datoC2 + 1 );
                      posCD= path.find(",", datoC + 4 );
                      term = path.substr( posC, posCD-posC );
                      s[contador]= atof(term.c_str());
                      contador++;
                      datoC = posC;
                  }
                  Cuadrado b= Cuadrado( s[0],s[1],s[2] );
                  archSal <<"Cuadrado"<< b.Perimetro() <<", "<<b.Area()<<", "<<b.getCoordX()<<", "<<b.getCoordX()<< endl;
              }
              if(tip==3){
                  while( datoC != string::npos ){
                      string term;
                      posC= path.find(",", datoC2 + 1 );
                      posCD= path.find(",", datoC + 4 );
                      term = path.substr( posC, posCD-posC );
                      s[contador]= atof(term.c_str());
                      contador++;
                      datoC = posC;
                  }
                  Triangulo c= Triangulo( s[0],s[1],s[2],s[3] );
                   archSal <<"Triangulo"<< c.Perimetro() <<", "<<c.Area()<<", "<<c.getCoordX()<<", "<<c.getCoordX()<< endl;
                  }
              if(tip== 4){
                  while( datoC != string::npos ){
                      string term;
                      posC= path.find(",", datoC2 + 1 );
                      posCD= path.find(",", datoC + 4 );
                      term = path.substr( posC, posCD-posC );
                      s[contador]= atof(term.c_str());
                      contador++;
                      datoC = posC;

                  }

                  Pentagono d=Pentagono( s[0],s[1],s[2] );
                   archSal <<"Pentágono"<< d.Perimetro() <<", "<<d.Area()<<", "<<d.getCoordX()<<", "<<d.getCoordX()<< endl;
                  }
              contaux++;

            }while(!archivo.eof());
            archSal.close();
        }
    }
    return 0;

}
