//
// Created by juand on 24/10/2026.
//

#ifndef CENTRODEPORTIVO_MENUESPACIOS_H
#define CENTRODEPORTIVO_MENUESPACIOS_H
#include <iostream>
#include "IMenu.h"
using namespace std;
class MenuEspacios : public IMenu {
    void gestionEspacios();
    void registrarEspacio();
    void mostrarEspaciosOcupados();
    void mostrarEspaciosDisponibles();
    void buscarEspacio();

    std::string extraFutbol();
    string extraBaloncesto();
    string extraTenis();
    string extraPiscina();
    string extraSalaEntreno();
public:
    void mostrarMenu() override;
};


#endif //CENTRODEPORTIVO_MENUESPACIOS_H
