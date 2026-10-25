//
// Created by juand on 25/10/2026.
//

#include "MenuReportes.h"
#include <iostream>

using namespace std;
void MenuReportes::gestionReportes() {
    int opc;
    cout << "--------------------------------------------" << endl;
    cout << "             Gestionar Reportes             " << endl;
    cout << "--------------------------------------------" << endl;
    cout << "1. Total de reservas" << endl;
    cout << "2. Cliente con más reservas" << endl;
    cout << "3. Espacio más reservado" << endl;
    cout << "4. Reservas activas" << endl;
    cout << "0. Salir" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opc;
    switch (opc) {
        case 1:
            totalReservas();
            break;
        case 2:
            clienteConMasReservas();
            break;
        case 3:
            espacioMasReservado();
            break;
        case 4:
            reservasActivas();
            break;
        case 0:
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo" << endl;
    }
}

void MenuReportes::totalReservas() {
}

void MenuReportes::clienteConMasReservas() {
}

void MenuReportes::espacioMasReservado() {
}

void MenuReportes::reservasActivas() {
}

void MenuReportes::mostrarMenu() {
    gestionReportes();
}
