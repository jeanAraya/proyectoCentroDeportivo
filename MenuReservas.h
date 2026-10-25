//
// Created by juand on 24/10/2026.
//

#ifndef CENTRODEPORTIVO_MENURESERVAS_H
#define CENTRODEPORTIVO_MENURESERVAS_H
#include "IMenu.h"


class MenuReservas : public IMenu{
    void gestionReservas();
    void registrarReserva();
    void cancelarReserva();
    void buscarReserva();
public:
    void mostrarMenu() override;
};


#endif //CENTRODEPORTIVO_MENURESERVAS_H
