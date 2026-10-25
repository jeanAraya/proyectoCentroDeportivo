//
// Created by juand on 25/10/2026.
//

#ifndef CENTRODEPORTIVO_MENUREPORTES_H
#define CENTRODEPORTIVO_MENUREPORTES_H
#include "IMenu.h"
#include "Reporte.h"
#include <string>


class MenuReportes : public IMenu{
    void gestionReportes();
    void totalReservas();
    void clienteConMasReservas();
    void espacioMasReservado();
    void reservasActivas();
    Reporte reporte;
public:
    ~MenuReportes() = default;
    void mostrarMenu() override;

    std::string reporteTotalReservas();
    std::string reporteClienteConMasReservas();
    std::string reporteEspacioMasReservado();
    std::string reporteReservasActivas();
};


#endif //CENTRODEPORTIVO_MENUREPORTES_H
