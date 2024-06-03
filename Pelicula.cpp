/*
Diego Alejandro Gamez
A01199125
ITC
20-mayo-2024
*/


#include "Pelicula.h"



//Constructores vacio y con parametros
    Pelicula::Pelicula():Video(){
        oscares = 100;
    }

    Pelicula::Pelicula(string _iD, string _titulo, int _duracion, 
    string _genero, double _calificacion, int _oscares):Video(_iD, _titulo, _duracion, 
    _genero, _calificacion){
        oscares = _oscares;
    }

//Metodos modificadores
    void Pelicula::setOscares(int _oscares){
        oscares = _oscares;
    }

//Metodos de acceso
    int Pelicula::getOscares(){
        return oscares;
    }

//Otros metodos
    string Pelicula::str(){
        //Tenemos acceso directo a los atributos de la clase Padre porque son Protected
        return iD + ' ' + titulo + ' ' + to_string(duracion) + ' ' + genero +
        ' ' + to_string(calificacion) + ' ' + to_string(oscares);
    }
