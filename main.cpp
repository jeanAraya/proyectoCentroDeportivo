#include "Menu.h"
int main() {
    GestorSistema::getInstancia().inicializar();
    Menu menu;
    menu.mostrarMenu();
    return 0;
}