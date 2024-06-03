/*
Diego Alejandro Gamez
A01199125
ITC
20-mayo-2024
Esta clase me ayudo a aprender como tener una clase que vaya dentro de otra clase que tenga
herencia de una clase padre, como lo es la clase serie y la clase video
Creo que esta clase fue la que mas me dejo, pues es la que mas se me hizo complicada
*/

#ifndef Polimorfismo_h
#define Polimorfismo_h

#include <stdio.h>
#include <typeinfo>
#include <sstream>
#include <fstream>
#include "Pelicula.h"
#include "Serie.h"
#include <string>
#include "Video.h" 
#include <iostream>
const int MAX_VIDEOS = 100;
const int MAX_SERIES = 50;
const int MAX_PELICULAS = 50;

using namespace std;

class Polimorfismo{

//Atributos 
    private:
    Video* arrPtrVideos[MAX_VIDEOS];
    Serie* arrPtrSeries[MAX_SERIES];
    Pelicula* arrPtrPeliculas[MAX_PELICULAS];

    int cantidad;
    int cantidadSeries;
    int cantidadPeliculas;

public: 
    Polimorfismo();
    void leerArchivo(string _nombre);


    void setPtrVideo(int index, Video *video);
    void setCantidadVideos(int _cantidad);


    Video* getPtrVideo(int _index);
    int getCantidad();


    void reporteInventario();
    void reporteCalificacion(double _calificacion);
    void reporteGenero(string _genero);
    void reportePeliculas();
    void reporteSeries();


};

#endif /* Polimorfismo_h */