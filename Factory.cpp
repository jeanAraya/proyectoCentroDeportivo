#include "Factory.h"

#include "CanchaFutbol.h"

Cliente* Factory::crearCliente(string identificacion, string nombre, string telefono, string correo) {
    return new Cliente(identificacion, nombre, telefono, correo);
}

Reserva* Factory::crearReserva(string codigo, string idCliente, string codigoEspacio, string fecha, int hora, bool activa) {
    return new Reserva(codigo, idCliente, codigoEspacio, fecha, hora, activa);
}

Espacio* Factory::crearEspacio(string tipo, string codigo, string nombre, int capacidad, double precioHora, string extra) {
    Espacio* espacio = nullptr;
    if (tipo == "FUTBOL") {
        espacio = crearCanchaFutbol(codigo,nombre,capacidad,precioHora,extra);
    }
    if (tipo == "BALONCESTO") {
        espacio = crearCanchaBaloncesto(codigo,nombre,capacidad,precioHora,extra == "1");
    }
    if (tipo == "TENIS") {
        espacio = crearCanchaTenis(codigo,nombre,capacidad,precioHora,extra);
    }
    if (tipo == "PISCINA") {
        espacio = crearPiscina(codigo,nombre,capacidad,precioHora,extra == "1");
    }
    if (tipo == "SALA") {
        espacio = crearSalaMultiuso(codigo,nombre,capacidad,precioHora,extra == "1");
    }
    return espacio;
}

CanchaFutbol* Factory::crearCanchaFutbol(string codigo, string nombre, int capacidad, double precioHora, string superficie) {
    return new CanchaFutbol(codigo, nombre, capacidad, precioHora, superficie);
}
CanchaBaloncesto* Factory::crearCanchaBaloncesto(string codigo, string nombre, int capacidad, double precioHora, bool esCubierta){
    return new CanchaBaloncesto(codigo, nombre, capacidad, precioHora, esCubierta);
}
CanchaTenis* Factory::crearCanchaTenis(string codigo, string nombre, int capacidad, double precioHora, string tipoPiso){
    return new CanchaTenis(codigo, nombre, capacidad, precioHora, tipoPiso);
}
Piscina* Factory::crearPiscina(string codigo, string nombre, int capacidad, double precioHora, bool tieneClimatizacion){
    return new Piscina(codigo, nombre, capacidad, precioHora, tieneClimatizacion);
}
SalasEntrenamiento* Factory::crearSalaMultiuso(string codigo, string nombre, int capacidad, double precioHora, bool tieneProyector){
    return new SalasEntrenamiento(codigo, nombre, capacidad, precioHora, tieneProyector);
}
