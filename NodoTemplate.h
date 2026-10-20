#ifndef PROYECTOBIBLIOTECA_NODOTEMPLATE_H
#define PROYECTOBIBLIOTECA_NODOTEMPLATE_H

template<class T>
class NodoTemplate {
    T* dato;
    NodoTemplate* siguiente;

public:
    NodoTemplate() {
        dato = nullptr;
        siguiente = nullptr;
    }

    NodoTemplate(T* dato) {
        this->dato = dato;
        siguiente = nullptr;
    }

    ~NodoTemplate() {
        delete dato;
        delete siguiente;
    }

    T* getDato() {
        return dato;
    }

    void setDato(T* dato) {
        if (this->dato != dato) {
            delete this->dato;
            this->dato = dato;
        }
    }

    NodoTemplate<T>* getSiguiente() {
        return siguiente;
    }

    void setSiguiente(NodoTemplate<T>* siguiente) {
        this->siguiente = siguiente;
    }
};

#endif