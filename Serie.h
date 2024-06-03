/*
Diego Alejandro Gamez
A01199125
ITC
20-mayo-2024
En esta clase aprendi de composicion, 
pues de esta clase sacamos la clase episodio, entonces el mezclar
composicion con herencia fue algo nuevo para mi
*/

#ifndef Serie_h
#define Serie_h
//Herencia
#include "Video.h"
//Composicion
#include "Episodio.h"
#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>
#include <string>
using namespace std;

class Serie: public Video{
    private:
    Episodio episodios[5];
    int cantidad;

    public:
//Metodos Constructores
    Serie();
    Serie(string _iD, string _titulo, int _duracion, string _genero, double _calificacion);
    void calculaDuracion();

//Metodos Modificadores
    void setEpisodio(int posicion, Episodio episodio);
    void setCantidad(int _cantidad);

//Metodos de acceso
    Episodio getEpisodio(int posicion);
    int getCantidad();

//Otros metodos
    double calculaPromedio();
    string str();
    void agregaEpisodio(Episodio);
};
#endif /* Serie_h */