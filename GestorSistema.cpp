#include "GestorSistema.h"
#include "CargadorDatos.h"
#include "GuardadorDatos.h"
#include "Iterador.h"

GestorSistema::GestorSistema() {
    listaClientes = nullptr;
    listaEspacios = nullptr;
    listaReservas = nullptr;
}

GestorSistema& GestorSistema::getInstancia() {
    static GestorSistema instancia;
    return instancia;
}

GestorSistema::~GestorSistema() {
    delete listaClientes;
    delete listaEspacios;
    delete listaReservas;
}

ListaTemplate<Cliente>* GestorSistema::getListaClientes() {
    return listaClientes;
}

ListaTemplate<Espacio>* GestorSistema::getListaEspacios() {
    return listaEspacios;
}

ListaTemplate<Reserva>* GestorSistema::getListaReservas() {
    return listaReservas;
}

void GestorSistema::inicializar() {
    listaClientes = new ListaTemplate<Cliente>();
    listaEspacios = new ListaTemplate<Espacio>();
    listaReservas = new ListaTemplate<Reserva>();
    leer("clientes.csv");
    leer("espacios.csv");
    leer("reservas.csv");
}

void GestorSistema::leer(string entrada) {
    CargadorDatos::leer(entrada);
}

void GestorSistema::guardar(string archivo) {
    GuardadorDatos::guardar(archivo);
}

bool GestorSistema::registrarCliente(Cliente *cliente) {
    if (cliente == nullptr || buscarCliente(cliente->getIdentificacion()) != nullptr) {
        return false;
    }

    NodoTemplate<Cliente>* nodo = new NodoTemplate<Cliente>(cliente);

    listaClientes->insertarNuevoNodo(nodo);
    return true;
}

bool GestorSistema::registrarEspacio(Espacio *espacio) {
    if (espacio == nullptr || buscarEspacio(espacio->getCodigo()) != nullptr) {
        return false;
    }
    NodoTemplate<Espacio>* nodo = new NodoTemplate<Espacio>(espacio);

    listaEspacios->insertarNuevoNodo(nodo);
    return true;
}

bool GestorSistema::registrarReserva(Reserva *reserva) {
    if (reserva == nullptr || buscarReserva(reserva->getCodigo()) != nullptr) {
        return false;
    }
    NodoTemplate<Reserva>* nodo = new NodoTemplate<Reserva>(reserva);
    listaReservas->insertarNuevoNodo(nodo);
    return true;
}

bool GestorSistema::cancelarReserva(string idReserva) {
    if (buscarReserva(idReserva)) {
        buscarReserva(idReserva)->cancelar();
        return true;
    }
    return false;
}

Cliente* GestorSistema::buscarCliente(string id) {
    Iterador<Cliente> it(*listaClientes);
    while (it.hayMas()) {
        Cliente* c = it.siguiente();
        if (c->getIdentificacion() == id) {
            return c;
        }
    }
    return nullptr;
}

Espacio* GestorSistema::buscarEspacio(string codigo) {
    Iterador<Espacio> it(*listaEspacios);
    while (it.hayMas()) {
        Espacio* espacio = it.siguiente();
        if (espacio->getCodigo() == codigo) {
            return espacio;
        }
    }
    return nullptr;
}

Reserva* GestorSistema::buscarReserva(string codigo) {
    Iterador<Reserva> it(*listaReservas);
    while (it.hayMas()) {
        Reserva* reserva = it.siguiente();
        if (reserva->getCodigo() == codigo) {
            return reserva;
        }
    }
    return nullptr;
}

void GestorSistema::mostrarEspacios() {
    Iterador<Espacio> it(*listaEspacios);
    while (it.hayMas()) {
        Espacio* espacio = it.siguiente();
        cout << espacio->toString() << endl;
    }
}

void GestorSistema::mostrarClientes() {
    Iterador<Cliente> it(*listaClientes);
    while (it.hayMas()) {
        Cliente* cliente = it.siguiente();
        cout << cliente->toString() << endl;
    }
}

void GestorSistema::mostrarReservas() {
    Iterador<Reserva> it(*listaReservas);
    while (it.hayMas()) {
        Reserva* reserva = it.siguiente();
        cout << reserva->toString() << endl;
    }
}
