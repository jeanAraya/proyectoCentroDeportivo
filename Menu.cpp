#include "Menu.h"

#include "Factory.h"
#include "MenuClientes.h"
#include "MenuEspacios.h"
#include "MenuReportes.h"
#include "MenuReservas.h"

using namespace std;

void Menu::mostrarMenu() {
    int opcion;
    MenuClientes menuClientes;
    MenuEspacios menuEspacios;
    MenuReservas menuReservas;
    MenuReportes menuReportes;
    do {
        cout << "\n=========================================\n CENTRO DEPORTIVO MULTIUSO \n=========================================" << endl;
        cout << "1. Gestionar Clientes" << endl;
        cout << "2. Gestionar Espacios" << endl;
        cout << "3. Gestionar Reservas" << endl;
        cout << "4. Reportes" << endl;
        cout << "5. Guardar datos" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                menuClientes.mostrarMenu();
                break;

            case 2:
                menuEspacios.mostrarMenu();
                break;

            case 3:
                menuReservas.mostrarMenu();
                break;

            case 4:
                menuReportes.mostrarMenu();
                break;

            case 5:
                if (validarGuardado()){
                    GestorSistema::getInstancia().guardar("clientes.csv");
                    GestorSistema::getInstancia().guardar("espacios.csv");
                    GestorSistema::getInstancia().guardar("reservas.csv");
                }
                break;

            case 0:
                cout << "Saliendo..." << endl;
                break;

            default:
                cout << "Opcion invalida. Intente de nuevo" << endl;
        }
    } while (opcion != 0);
}

bool Menu::validarGuardado() {
    int opc;
    cout << "Al guardar los datos actuales se sobreescribiran los datos existentes en el archivo.\n Desea continuar?" << endl;
    cout << "1. Continuar" << endl;
    cout << "2. Volver" << endl;
    cin >> opc;
    if (opc == 1) {
        return true;
    }
    if (opc == 2) {
        return false;
    }
    cout << "Opcion invalida." << endl;
    return false;
}
