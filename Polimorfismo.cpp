/*
Diego Alejandro Gamez
A01199125
ITC
20-mayo-2024
*/
#include "Polimorfismo.h"


//Constructores default - void
Polimorfismo::Polimorfismo(){
    for (int index = 0; index < MAX_VIDEOS; index++){
        arrPtrVideos[index] = nullptr;
    }

    for (int index = 0; index < MAX_SERIES; index++){
        arrPtrSeries[index] = nullptr;
    }

    for (int index = 0; index < MAX_PELICULAS; index++){
        arrPtrPeliculas[index] = nullptr;
    }


    //Inicializar la cantidad de videos
    cantidad = 0;
    cantidadSeries = 0;
    cantidadPeliculas = 0;
}

    void Polimorfismo::setPtrVideo(int index, Video *video){
        //Validar index - >=0 && < cantidad
        if (index >= 0 && index < cantidad){
            //cambiar el apuntador
            arrPtrVideos[index] = video;
        }
}

//cambia el valor del atributo cantidad
// debe ser entre 0 y max videos-1 de lo contrario no se modifica el valor de cantida
    void Polimorfismo::setCantidadVideos(int _cantidad){
        //validar el valor de cantidad
        if(_cantidad >=0 && _cantidad < MAX_VIDEOS){
            cantidad = _cantidad;

        }
}
    Video* Polimorfismo::getPtrVideo(int index){
        //Vaidad que exista el index, o sea la posicion
        if(index >= 0 && index < cantidad){
            return arrPtrVideos[index];
        }

        // SI no existe:
        return nullptr;
    }

    int Polimorfismo::getCantidad(){
        return cantidad;
    }


    void Polimorfismo::reporteInventario(){
        //Declaracion de contadores
        int contPeliculas, contSeries;

        //inicializamos
        contPeliculas = 0;
        contSeries = 0;

        //Recorrer todo el arreglo de ptr usando un for
       for (int index = 0; index < cantidad; index++){
           cout<< arrPtrVideos[index]->str() << endl;
             //* indireccion (ptr) genera el objeto
           if (typeid(*arrPtrVideos[index]) == typeid(Pelicula)){
                contPeliculas++;
            }  
            else if (typeid(*arrPtrVideos[index]) == typeid(Serie)){
                contSeries++;
            }
        }

        //Desplegamos los totales duera del for
        cout << "Peliculas = " << contPeliculas << endl;
        cout << "Series = " << contSeries << endl;
    }

    void Polimorfismo::reporteCalificacion(double _calificacion){
        // contador total
        int total;

        //inicializar el contador
        total = 0;

        for(int index = 0; index < cantidad; index++){
            //Verificar si tiene la calificacion == _calificacion
            //Si es un apuntador se usa la notacion flecha ->
            if (arrPtrVideos[index]->getCalificacion() == _calificacion){
                cout << arrPtrVideos[index]->str() << endl;
                total++;
            }

        }
        //Despelgamos el gtotal fuera del for
        cout << "Total = " << total << endl;

    }

    void Polimorfismo::reporteGenero(string _genero){
        int total;

        total = 0;

        for (int index = 0; index < cantidad; index++){
            if(arrPtrVideos[index]->getGenero() == _genero){
                cout << arrPtrVideos[index]->str() << endl;
                total++;
            }
        }

        cout << "Total = " << total << endl;

    }

    void Polimorfismo::reportePeliculas(){
        int contPeliculas;

        contPeliculas = 0;
        
        for(int index = 0; index < cantidadPeliculas; index++){
            if (typeid(*arrPtrVideos[index]) == typeid(Pelicula)){
                contPeliculas++;
            cout << arrPtrVideos[index]->str() << endl;
                //contPeliculas++;
            }
        }

        if(contPeliculas > 0){
        cout << "Total Peliculas = " << contPeliculas << endl;
        } else{
        cout << "No Peliculas" << endl;
        }
    }

    void Polimorfismo::reporteSeries(){
        int contSeries;

        contSeries = 0;

        for(int index = 0; index < cantidad; index++){
            if (typeid(*arrPtrVideos[index]) == typeid(Serie)){
                contSeries++;
            cout << arrPtrVideos[index]->str() << endl;
                //contSeries++;
            }

        }
        if (contSeries > 0){
        cout << "Total Series = " << contSeries << endl;
        }else{
        cout << "No series" << endl;
        }
    }
    

void Polimorfismo::leerArchivo(string nombre ){
    Serie *arrPtrSeries[MAX_SERIES];
    Pelicula *arrPtrPeliculas[MAX_PELICULAS];
    Episodio episodio;
    fstream entrada;
    string row[7];
    string line, word;
    int iR = 0, index;
    double promedio;

    entrada.open(nombre, ios::in);

    while (getline(entrada, line)) {
        stringstream s(line);
        iR = 0;

        while (getline(s, word, ',')) {
            row[iR++] = word;
        }

        if (row[0] == "P"){
            arrPtrPeliculas[cantidadPeliculas] = new Pelicula(row[1], row[2], stoi(row[3]), row[4], stod(row[5]), stoi(row[6]));
            //cout << "Pelicula" << arrPtrPeliculas[cantidadPeliculas]->str() << endl;
            cantidadPeliculas++;
        }
        else if(row[0] == "S"){
            arrPtrSeries[cantidadSeries] = new Serie(row[1], row[2], stoi(row[3]), row[4], stod(row[5]));
            //cout << "Serie" << arrPtrSeries[cantidadSeries]->str() << endl;
            cantidadSeries++;
        }
        else if (row[0] == "E"){
            index = stoi(row[1]) - 500;
            
            arrPtrSeries [index]->agregaEpisodio (*(new Episodio (row[2], stoi(row[3]), stoi(row[4]))));
            //cout << "Episodio" << arrPtrSeries[index]->str() << endl;
        }
    }

    for (int index = 0; index < cantidadSeries; index++){
        promedio = arrPtrSeries[index]->calculaPromedio();
        arrPtrSeries[index]->setCalificacion(promedio);
        arrPtrVideos[cantidad++] = arrPtrSeries[index];
    }

    for(int index = 0; index< cantidadPeliculas; index++){
        arrPtrVideos[cantidad++] = arrPtrPeliculas[index];
    }

//    for(int index = 0; index< cantidadVideos; index++){
  //      cout<< index << " " << arrPtrVideos[index]->str() << endl;
    //}

    entrada.close();
}
