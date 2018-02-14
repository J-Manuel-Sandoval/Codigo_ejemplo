#ifndef INDICES_H
#define INDICES_H

#include <iostream>
#include <cstring>
#include <cstdlib>

#define ARCH_INDICES "Indices.dat"
#define TAM_INDICE 20

using namespace std;

class Indices{
    char indiceVideojuego[TAM_INDICE+1];
    long int posicionRegistro;
public:
    void setIndice(string indiceAux);
    void setPosicion(long int posicionAux);

    char *getIndice();
    long int getPosicion();
};

void Indices :: setIndice(string indiceAux){
    strcpy(indiceVideojuego,indiceAux.c_str());
}

void Indices :: setPosicion(long int posicionAux){
    posicionRegistro = posicionAux;
}

char* Indices :: getIndice(){
    return indiceVideojuego;
}

long int Indices :: getPosicion(){
    return posicionRegistro;
}

#endif
