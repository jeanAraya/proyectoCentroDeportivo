#ifndef CENTRODEPORTIVO_REPORTE_H
#define CENTRODEPORTIVO_REPORTE_H

#include <string>

// Genera los reportes del sistema. No imprime nada: devuelve texto para que el Menu lo muestre.
// Recorre las listas únicamente mediante el Iterador.
// "Reservas realizadas" cuenta todas las reservas registradas (activas y canceladas).
class Reporte {
    int contarReservasDeCliente(const std::string& identificacion);
    int contarReservasDeEspacio(const std::string& codigoEspacio);

public:
    Reporte() = default;
    ~Reporte() = default;

    std::string totalReservas();
    std::string clienteConMasReservas();
    std::string espacioMasReservado();
    std::string reservasActivas();
};

#endif
