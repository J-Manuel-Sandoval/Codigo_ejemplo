#include <iostream>
#include <cstdlib>
#include <cstring>
#include "AdminCatalogo.h"

using namespace std;

enum {INGRESAR=1, MOSTRAR_VID, MOSTRAR_ARCH, SALIR};
AdminCatalogo admin;

void pausa(){
    cout<<"Presione ENTER para continuar. . ."<<endl;
    cin.get();
}

void imprimeMenu(){
    cout<<"Ingrese una opcion!"<<endl
        <<"1) Ingresar"<<endl
        <<"2) Mostrar videojuegos"<<endl
        <<"3) Mostrar archivo de indices"<<endl
        <<"4) Salir"<<endl
        <<"> ";
}

void opcionIngresar(){
    admin.ingresaVideojuego();
}

void opcionMostrarVideojuegos(){
    admin.cargaVideojuegos();
}

void opcionMostrarArchIndices(){
    admin.mostrarIndices();
}

void imprimeMensajeSalir(){
    cout<<"Presione ENTER para salir. . ."<<endl;
    cin.get();
}

void imprimeMensajeDefault(){
    cout<<"Opcion incorrecta, presione ENTER para continuar. . ."<<endl;
    cin.get();
}

int main(){
    string cadenaEntrada;
    int opcionMenu;
    do{
        system(LIMPIAR);
        imprimeMenu();
        getline(cin,cadenaEntrada);
        opcionMenu = atoi(cadenaEntrada.c_str());
        switch(opcionMenu){
            case INGRESAR:{     opcionIngresar();           pausa();    break;}
            case MOSTRAR_VID:{  opcionMostrarVideojuegos(); pausa();    break;}
            case MOSTRAR_ARCH:{ opcionMostrarArchIndices(); pausa();    break;}
            case SALIR:{        imprimeMensajeSalir();                  break;}
            default:{           imprimeMensajeDefault();                break;}
        }
    }while(opcionMenu!=SALIR);
    return 0;
}
