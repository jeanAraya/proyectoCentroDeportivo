#ifndef CENTRODEPORTIVO_REPORTE_H
#define CENTRODEPORTIVO_REPORTE_H

#include <string>

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
