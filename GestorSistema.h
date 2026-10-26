#include <iostream>
#include "Cliente.h"
#include "Espacio.h"
#include "ListaTemplate.h"
#include "Reserva.h"

using namespace std;
class GestorSistema {
    ListaTemplate<Cliente>* listaClientes;
    ListaTemplate<Espacio>* listaEspacios;
    ListaTemplate<Reserva>* listaReservas;

    GestorSistema();

    GestorSistema(const GestorSistema&) = delete;
    GestorSistema& operator=(const GestorSistema&) = delete;

public:
    ~GestorSistema();

    ListaTemplate<Cliente>* getListaClientes();
    ListaTemplate<Espacio>* getListaEspacios();
    ListaTemplate<Reserva>* getListaReservas();

    static GestorSistema& getInstancia();

    void inicializar();
    void leer(string entrada);
    void guardar(string archivo);

    bool registrarCliente(Cliente* cliente);

    bool registrarEspacio(Espacio* espacio);

    bool registrarReserva(Reserva* reserva);
    bool cancelarReserva(string idReserva);

    void mostrarEspacios();
    void espaciosOcupados();
    void espaciosDisponibles();
    void mostrarClientes();
    void mostrarReservas();
    void reservasActivas();

    Cliente* buscarCliente(string id);
    Espacio* buscarEspacio(string codigo);
    Reserva* buscarReserva(string id);
};