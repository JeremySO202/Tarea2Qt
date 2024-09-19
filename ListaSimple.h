#ifndef PRUEBAS_LISTASIMPLE_H
#define PRUEBAS_LISTASIMPLE_H

#include <iostream>
struct Nodo{
    int data;
    Nodo* siguiente = nullptr;
    Nodo(int valor) : data(valor), siguiente(nullptr) {}
};

class ListaSimple {
private:
    Nodo * inicio = nullptr;
public:

    ListaSimple(){
        inicio = NULL;
    }

    void insertarAlInicio(int data);
    Nodo* buscar(int data);
    bool estaVacia();

    int get(int posicion);

    void set(int posicion, int nuevoValor);
};


#endif //PRUEBAS_LISTASIMPLE_H
