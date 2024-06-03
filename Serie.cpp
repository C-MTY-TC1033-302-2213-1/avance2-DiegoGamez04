/*
Diego Alejandro Gamez
A01199125
ITC
20-mayo-2024
*/

#include "Serie.h"
#include "Episodio.h"

//Metodos Constructores
    Serie::Serie():Video(){
//Inicializamos una cantidad
    cantidad = 0;
    }
    Serie::Serie(string _iD, string _titulo, int _duracion, string _genero, double _calificacion){

    }
    void Serie::calculaDuracion(){

    }
    

//Metodos Modificadores
    void Serie::setEpisodio(int posicion, Episodio episodio){
//Primero validar que exista el episodio
    if (posicion >= 0 && posicion < cantidad){
        episodios[posicion] = episodio;
    }
}

//Cambiar el valor del atributo cantidad con el nuevo valor recibido en _cantidad
    void Serie::setCantidad(int _cantidad){
        cantidad = _cantidad;
    }

//Metodos de acceso
    Episodio Serie::getEpisodio(int posicion){

        //Crea un objeto tipo episodio y lo inicializa con el constructor default
        Episodio epi;

        //Primero validamos que exista el episodio solicitado (posicion)
        if (posicion >= 0 && posicion < cantidad){
            return episodios[posicion];
        }

        //Si no existe se retorna un default
        return epi;
    }

//Retorna el valor del atributo cantidad
    int Serie::getCantidad(){
        return cantidad;
    }


//Otros metodos
    double Serie::calculaPromedio(){
        double acum = 0;
    
        for (int index = 0; index < cantidad; index ++){
            acum = acum + episodios[index].getCalificacion();

    }


//Validar que tenga episodios
    if (cantidad > 0){  
        return acum / cantidad;
    }
    else{
        return 0;
    }

    }
    string Serie::str(){
        string infoserie = iD + ' ' + titulo + ' ' + to_string(duracion)
        + ' ' + genero + ' ' + to_string(calificacion);

        if (cantidad > 0) {
            for (int index = 0; index < cantidad; ++index){
                infoserie += '\n' + episodios[index].str();
            }
        }else{
            infoserie += '\n';
        }
        return infoserie;
    }
//Agrega un episodio solo si existe un espacio
    void Serie::agregaEpisodio(Episodio episodio){
        if (cantidad < 5){
            episodios[cantidad++] = episodio;

        }
    }
    