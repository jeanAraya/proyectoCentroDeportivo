#include "GestorSistema.h"

class Menu {

    void registrarCliente();
    void registrarEspacio();
    void registrarReserva();
    void cancelarReserva();
    bool validarGuardado();
    string extraFutbol();
    string extraBaloncesto();
    string extraTenis();
    string extraPiscina();
    string extraSalaEntreno();

public:
    Menu();
    void mostrarMenu();
};