#include "Reporte.h"

#include "GestorSistema.h"
#include "Iterador.h"

int Reporte::contarReservasDeCliente(const std::string& identificacion) {
    int cantidad = 0;
    Iterador<Reserva> it(*GestorSistema::getInstancia().getListaReservas());
    while (it.hayMas()) {
        if (it.siguiente()->getIdentificacionCliente() == identificacion) {
            cantidad++;
        }
    }
    return cantidad;
}

int Reporte::contarReservasDeEspacio(const std::string& codigoEspacio) {
    int cantidad = 0;
    Iterador<Reserva> it(*GestorSistema::getInstancia().getListaReservas());
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

    Iterador<Reserva> it(*GestorSistema::getInstancia().getListaReservas());
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

    Iterador<Cliente> it(*GestorSistema::getInstancia().getListaClientes());
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

    Iterador<Espacio> it(*GestorSistema::getInstancia().getListaEspacios());
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

    Iterador<Reserva> it(*GestorSistema::getInstancia().getListaReservas());
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
