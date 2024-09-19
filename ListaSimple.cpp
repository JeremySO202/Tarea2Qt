#include "ListaSimple.h"

void ListaSimple::insertarAlInicio(int data) {
    if(inicio == NULL){
        inicio = new Nodo(data);
    }
    else{
        Nodo * nuevo = new Nodo(data);
        nuevo->siguiente = inicio;
        inicio = nuevo;
    }
}

Nodo * ListaSimple::buscar(int data){
    Nodo * tmp = inicio;
    while (tmp != NULL){
        if (tmp->data == data)
            return tmp;
        tmp = tmp->siguiente;
    }
    return NULL;
}

bool ListaSimple::estaVacia(){
    return inicio == NULL;
}

int ListaSimple::get(int posicion) {
    Nodo *tmp = inicio;
    int contador = 0;

    while (tmp != NULL) {
        if (contador == posicion) {
            return tmp->data;
        }
        contador++;
        tmp = tmp->siguiente;
    }

    throw std::out_of_range("Posición fuera del rango de la lista");
}

void ListaSimple::set(int posicion, int nuevoValor) {
    Nodo *tmp = inicio;
    int contador = 0;

    while (tmp != NULL) {
        if (contador == posicion) {
            tmp->data = nuevoValor;
            return;
        }
        contador++;
        tmp = tmp->siguiente;
    }

    throw std::out_of_range("Posición fuera del rango de la lista");
}



