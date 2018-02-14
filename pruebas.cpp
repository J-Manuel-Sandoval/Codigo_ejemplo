#include <iostream>

using namespace std;

int main(){
    string nombre = "juan";
    char cadena[10];

    cout<<"Ingrese un nombre: ";
    cin>>cadena;
    cin.ignore();
    if(cadena == nombre){
        cout<<"Es el mismo nombre"<<endl;
    }
    else{
        cout<<"Es nombre diferente"<<endl;
    }
    return 0;
}
