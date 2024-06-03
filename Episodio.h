/*
Diego Alejandro Gamez
ITC
A01199125
26 de mayo de 2024
Aqui fue donde aprendi por primera vez acerca de
la composicion, que fue para mi otro mundo, pues 
yo solo tenia conocimiento de la herencia
*/

#ifndef Episodio_h
#define Episodio_h
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
class Episodio{
//Atributos    
protected:
    string titulo;
    int temporada;
    int calificacion;
    
//Metodos 
public:
    //Constructores
    Episodio();
    Episodio(string _titulo, int _temporada, int _calificacion);
    
    //Metodos modificadores
    void setTitulo(string _titulo);
    void setTemporada(int _temporada);
    void setCalificacion(int _calificacion);
    
    //Metodos de acceso
    string getTitulo();
    int getTemporada();
    int getCalificacion();
    
    // Otros Metodos
    string str();
};

#endif /* Episodio_h */