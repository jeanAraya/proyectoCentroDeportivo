#ifndef CENTRODEPORTIVO_ITERADOR_H
#define CENTRODEPORTIVO_ITERADOR_H

#include "ListaTemplate.h"
#include "NodoTemplate.h"
#include "CustomException.h"

template <class T>
class Iterador {
    ListaTemplate<T>* lista;
    NodoTemplate<T>* actual;

public:
    explicit Iterador(ListaTemplate<T>& lista) {
        this->lista = &lista;
        actual = lista.primero;
    }

    bool hayMas() const {
        return actual != nullptr;
    }

    T* siguiente() {
        if (actual == nullptr) {
            throw CustomException("El iterador no tiene mas elementos.");
        }
        T* dato = actual->getDato();
        actual = actual->getSiguiente();
        return dato;
    }

    void reiniciar() {
        actual = lista->getPrimero();
    }
};

#endif