#ifndef ADMINCATALOGO_H
#define ADMINCATALOGO_H

#ifdef _WIN32
    #define LIMPIAR "cls"
#else
    #define LIMPIAR "clear"
#endif

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <sstream>
#include "Indices.h"
#include "Videojuegos.h"
// Se agrega comentario 
class AdminCatalogo{
    Indices indices;
    Videojuego videojuego;
    int contadorIndices;
    string cadenaEntrada;
public:
    void ingresaVideojuego();
    void buscaNombreRepetido(string nombreAux);
    void guardarVideojuego();
    void guardarIndice();

    void mostrarIndices();
    void cargaVideojuegos();
    void buscaVideojuego(long int posVideojuego);
};

void AdminCatalogo :: ingresaVideojuego(){
    int precioAux;;
    do{
        cout<<"Ingrese el nombre (Max. "<<TAM_NOMBRE<<" caracteres): ";
        getline(cin,cadenaEntrada);
    }while(!(cadenaEntrada.size() < TAM_NOMBRE+1));
    buscaNombreRepetido(cadenaEntrada);
    stringstream flujo;
    flujo << cadenaEntrada;
    flujo << contadorIndices;
    flujo >> cadenaEntrada;
    videojuego.setNombre(cadenaEntrada);
    indices.setIndice(cadenaEntrada);

    do{
        cout<<"Ingrese la consola (Max. "<<TAM_CONSOLA<<" caracteres): ";
        getline(cin,cadenaEntrada);
    }while(!(cadenaEntrada.size() < TAM_CONSOLA+1));
    videojuego.setConsola(cadenaEntrada);

    cout<<"Ingrese el precio del videojuego: ";
    getline(cin,cadenaEntrada);
    videojuego.setPrecio(atoi(cadenaEntrada.c_str()));

    guardarVideojuego();
    guardarIndice();
}

void AdminCatalogo :: buscaNombreRepetido(string nombreAux){
    contadorIndices = 0;
    ifstream archivo(ARCH_DATOS);
    if(archivo.is_open()){
        archivo.read((char*)&videojuego,sizeof(Videojuego));
        while(!archivo.eof()){
            stringstream flujo;
            string cadenaAux;
            flujo << nombreAux;
            flujo << contadorIndices;
            flujo >> cadenaAux;
            if(videojuego.getNombre() == cadenaAux){
                contadorIndices++;
            }
            archivo.read((char*)&videojuego,sizeof(Videojuego));
        }
    }
    archivo.close();
}

void AdminCatalogo :: guardarVideojuego(){
    ofstream archivo(ARCH_DATOS, ios::app);
    if(archivo.is_open()){
        indices.setPosicion(archivo.tellp());
        archivo.write((char*)&videojuego,sizeof(Videojuego));
    }
    else{
        cout<<"Error al guardar el videojuego"<<endl;
    }
    archivo.close();
}


void AdminCatalogo :: guardarIndice(){
    /*
    stringstream flujo;
    cadenaEntrada = videojuego.getNombre();
    flujo << cadenaEntrada;
    flujo << contadorIndices;
    flujo >> cadenaEntrada;
    indices.setIndice(cadenaEntrada);
    */
    ofstream archivo(ARCH_INDICES,ios::app);
    if(archivo.is_open()){
        archivo.write((char*)&indices,sizeof(Indices));
    }
    else{
        cout<<"Error al guardar el archivo de indices."<<endl;
    }
    archivo.close();
}

void AdminCatalogo :: mostrarIndices(){
    ifstream archivo(ARCH_INDICES);
    if(archivo.is_open()){
        archivo.read((char*)&indices,sizeof(Indices));
        while(!archivo.eof()){
            cout<<"Clave: "<<indices.getIndice()<<endl;
            cout<<"Posicion de registro: "<<indices.getPosicion()<<endl<<endl;

            archivo.read((char*)&indices,sizeof(Indices));
        }
    }
    else{
        cout<<"Error al mostrar indices."<<endl;
    }
    archivo.close();
}

void AdminCatalogo :: cargaVideojuegos(){
    ifstream archivo(ARCH_INDICES);
    if(archivo.is_open()){
        archivo.read((char*)&indices,sizeof(Indices));
        while(!archivo.eof()){
            buscaVideojuego(indices.getPosicion());
            archivo.read((char*)&indices,sizeof(Indices));
        }
    }
    else{
        cout<<"Error al abrir archivo de indices."<<endl;
    }
    archivo.close();

}

void AdminCatalogo :: buscaVideojuego(long int posVideojuego){
    ifstream archivo(ARCH_DATOS);
    if(archivo.is_open()){
        archivo.seekg(posVideojuego, ios_base::beg);
        archivo.read((char*)&videojuego,sizeof(Videojuego));
        cout<<"Nombre: "<<videojuego.getNombre()<<endl;
        cout<<"Consola: "<<videojuego.getConsola()<<endl;
        cout<<"Precio: "<<videojuego.getPrecio()<<endl<<endl;
    }
    else{
        cout<<"Error al abrir archivo de datos."<<endl;
    }
    archivo.close();

}

#endif
