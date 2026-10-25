//
// Created by juand on 25/10/2026.
//

#ifndef CENTRODEPORTIVO_MENUREPORTES_H
#define CENTRODEPORTIVO_MENUREPORTES_H
#include "IMenu.h"


class MenuReportes : public IMenu{
    void gestionReportes();
    void totalReservas();
    void clienteConMasReservas();
    void espacioMasReservado();
    void reservasActivas();
public:
    ~MenuReportes() = default;
    void mostrarMenu() override;
};


#endif //CENTRODEPORTIVO_MENUREPORTES_H
