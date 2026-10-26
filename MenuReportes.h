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
    void reservasActivas();
    std::string reporteTotalReservas();
    std::string reporteClienteConMasReservas();
    std::string reporteEspacioMasReservado();
    std::string reporteReservasActivas();
    // Reporte reporte;
public:
    void mostrarMenu() override;
    MenuReportes() = default;
};


#endif //CENTRODEPORTIVO_MENUREPORTES_H
