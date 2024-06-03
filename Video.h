/*
Diego Alejandro Gamez
A01199125
ITC
20-mayo-2024
En esta clase tuve mi primera experiencia de una clase padre o base, de la cual sacamos
otras dos clases
*/


#ifndef Video_h
#define Video_h

#include <stdio.h>
#include <string>
using namespace std;
class Video{
//Atributos    
protected:
    string iD;
    string titulo;
    int duracion;
    string genero;
    double calificacion;
    
//Metodos 
public:
    //Constructores
    Video();
    Video(string _iD, string _titulo, int _duracion, 
    string _genero, double _calificacion);
    
    //Metodos modificadores
    void setId(string _iD);
    void setTitulo(string _titulo);
    void setDuracion(int _duracion);
    void setGenero(string _genero);
    void setCalificacion(double _calificacion);
    
    //Metodos de acceso
    string getId();
    string getNombre();
    int getDuracion();
    string getGenero();
    double getCalificacion();
    
    // Otros Metodos
    string virtual str();
};




#endif /* Video_h */

