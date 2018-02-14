#ifndef VIDEOJUEGOS_H
#define VIDEOJUEGOS_H

#include <iostream>
#include <cstring>
#include <cstdlib>

#define TAM_NOMBRE 15
#define TAM_CONSOLA 15
#define ARCH_DATOS "Datos_videojuegos.dat"

using namespace std;

class Videojuego{
    char nombre[TAM_NOMBRE+1];
    char consola[TAM_CONSOLA+1];
    int precio;
public:
    void setNombre(string nombreAux);
    void setConsola(string consolaAux);
    void setPrecio(int precioAux);

    char *getNombre();
    char *getConsola();
    int getPrecio();
};

void Videojuego :: setNombre(string nombreAux){
    strcpy(nombre,nombreAux.c_str());
}

void Videojuego :: setConsola(string consolaAux){
    strcpy(consola,consolaAux.c_str());
}

void Videojuego :: setPrecio(int precioAux){
    precio = precioAux;
}

char* Videojuego :: getNombre(){
    return nombre;
}

char* Videojuego :: getConsola(){
    return consola;
}

int Videojuego :: getPrecio(){
    return precio;
}

#endif
