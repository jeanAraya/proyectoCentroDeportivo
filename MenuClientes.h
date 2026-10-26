//
// Created by juand on 24/10/2026.
//

#ifndef CENTRODEPORTIVO_MENUCLIENTES_H
#define CENTRODEPORTIVO_MENUCLIENTES_H
#include "Cliente.h"
#include "IMenu.h"

class MenuClientes : public IMenu{
    void gestionClientes();
    void registrarCliente();
    void modificarCliente();
    Cliente* buscarClienteAux();
    void buscarCliente();
    void listarClientes();
public:
    void mostrarMenu() override;
};


#endif //CENTRODEPORTIVO_MENUCLIENTES_H
