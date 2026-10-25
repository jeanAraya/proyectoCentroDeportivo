#include "GestorSistema.h"
#include "IMenu.h"

class Menu : IMenu{
    bool validarGuardado();
public:
    void mostrarMenu() override;
};
