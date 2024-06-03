/*
Diego Alejandro Gamez
A01199125
ITC
20-mayo-2024
Aqui aprendi de la herencia, 
de la clase video directamente a la clase pelicula
Ademas, aprendi a diferenciar entre dos clases 
que usan herencia, entre pelicula y serie
*/

#ifndef Pelicula_h
#define Pelicula_h
#include <string>
using namespace std;
#include "Video.h" 
#include <iostream>

//Clase Pelicula es derivada de Video
class Pelicula : public Video{
    private:
    int oscares;

    public:
//Constructores vacio y con parametros
    Pelicula();
    Pelicula(string _iD, string _titulo, int _duracion, 
    string _genero, double _calificacion, int _oscares);

//Metodos modificadores
    void setOscares(int _oscares);

//Metodos de acceso
    int getOscares();

//Otros metodos
    string str();

};

#endif /* Pelicula_h */