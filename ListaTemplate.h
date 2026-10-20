#ifndef PROYECTOBIBLIOTECA_LISTATEMPLATE_H
#define PROYECTOBIBLIOTECA_LISTATEMPLATE_H

#include "NodoTemplate.h"

template <class T>
class ListaTemplate {
    NodoTemplate<T>* primero;
    NodoTemplate<T>* ultimo;

public:
    ListaTemplate() {
        primero = nullptr;
        ultimo = nullptr;
    }

    ListaTemplate(NodoTemplate<T>* primero, NodoTemplate<T>* ultimo) {
        this->primero = primero;
        this->ultimo = ultimo;
    }

    ~ListaTemplate() {
        delete primero;
        primero = nullptr;
        ultimo = nullptr;
    }

    NodoTemplate<T>* getPrimero() {
        return primero;
    }

    NodoTemplate<T>* getUltimo() {
        return ultimo;
    }

    void setPrimero(NodoTemplate<T>* prim) {
        primero = prim;
    }

    void setUltimo(NodoTemplate<T>* ult) {
        ultimo = ult;
    }

    void insertarNuevoNodo(NodoTemplate<T>* nodo) {
        if (nodo == nullptr) {
            return;
        }

        nodo->setSiguiente(nullptr);

        if (primero == nullptr) {
            primero = nodo;
            ultimo = nodo;
        } else {
            ultimo->setSiguiente(nodo);
            ultimo = nodo;
        }
    }

    void eliminarNodo(NodoTemplate<T>* nodo) {
        if (primero == nullptr || nodo == nullptr) {
            return;
        }

        if (primero == nodo) {
            primero = primero->getSiguiente();

            nodo->setSiguiente(nullptr);
            delete nodo;

            if (primero == nullptr) {
                ultimo = nullptr;
            }

            return;
        }

        NodoTemplate<T>* actual = primero;

        while (actual->getSiguiente() != nullptr) {
            if (actual->getSiguiente() == nodo) {
                actual->setSiguiente(nodo->getSiguiente());

                if (nodo == ultimo) {
                    ultimo = actual;
                }

                nodo->setSiguiente(nullptr);
                delete nodo;
                return;
            }

            actual = actual->getSiguiente();
        }
    }

    bool buscarNodo(NodoTemplate<T>* nodo) {
        NodoTemplate<T>* actual = primero;

        while (actual != nullptr) {
            if (actual == nodo) {
                return true;
            }

            actual = actual->getSiguiente();
        }

        return false;
    }
};

#endif