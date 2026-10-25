#include "Reporte.h"
#include "Iterador.h"

Reporte::Reporte(ListaTemplate<Cliente>& clientes, ListaTemplate<Espacio>& espacios,
                 ListaTemplate<Reserva>& reservas) {
    this->clientes = &clientes;
    this->espacios = &espacios;
    this->reservas = &reservas;
}

Reporte::~Reporte() {
}

int Reporte::contarReservasDeCliente(const std::string& identificacion) {
    int cantidad = 0;
    Iterador<Reserva> it(*reservas);
    while (it.hayMas()) {
        if (it.siguiente()->getIdentificacionCliente() == identificacion) {
            cantidad++;
        }
    }
    return cantidad;
}

int Reporte::contarReservasDeEspacio(const std::string& codigoEspacio) {
    int cantidad = 0;
    Iterador<Reserva> it(*reservas);
    while (it.hayMas()) {
        if (it.siguiente()->getCodigoEspacio() == codigoEspacio) {
            cantidad++;
        }
    }
    return cantidad;
}

std::string Reporte::totalReservas() {
    int total = 0;
    int activas = 0;

    Iterador<Reserva> it(*reservas);
    while (it.hayMas()) {
        Reserva* reserva = it.siguiente();
        total++;
        if (reserva->estaActiva()) {
            activas++;
        }
    }

    return "Total de reservas realizadas: " + std::to_string(total) +
           " (Activas: " + std::to_string(activas) +
           " | Canceladas: " + std::to_string(total - activas) + ")\n";
}

std::string Reporte::clienteConMasReservas() {
    Cliente* mejor = nullptr;
    int maximo = 0;

    Iterador<Cliente> it(*clientes);
    while (it.hayMas()) {
        Cliente* cliente = it.siguiente();
        int cantidad = contarReservasDeCliente(cliente->getIdentificacion());
        if (cantidad > maximo) {
            maximo = cantidad;
            mejor = cliente;
        }
    }

    if (mejor == nullptr) {
        return "No hay reservas registradas.\n";
    }

    return "Cliente con mas reservas (" + std::to_string(maximo) + "):\n" + mejor->toString() + "\n";
}

std::string Reporte::espacioMasReservado() {
    Espacio* mejor = nullptr;
    int maximo = 0;

    Iterador<Espacio> it(*espacios);
    while (it.hayMas()) {
        Espacio* espacio = it.siguiente();
        int cantidad = contarReservasDeEspacio(espacio->getCodigo());
        if (cantidad > maximo) {
            maximo = cantidad;
            mejor = espacio;
        }
    }

    if (mejor == nullptr) {
        return "No hay reservas registradas.\n";
    }

    return "Espacio mas reservado (" + std::to_string(maximo) + " reservas):\n" + mejor->toString() + "\n";
}

std::string Reporte::reservasActivas() {
    std::string resultado;
    int cantidad = 0;

    Iterador<Reserva> it(*reservas);
    while (it.hayMas()) {
        Reserva* reserva = it.siguiente();
        if (reserva->estaActiva()) {
            resultado += reserva->toString() + "\n";
            cantidad++;
        }
    }

    if (cantidad == 0) {
        return "No hay reservas activas.\n";
    }

    return "Reservas activas: " + std::to_string(cantidad) + "\n" + resultado;
}
