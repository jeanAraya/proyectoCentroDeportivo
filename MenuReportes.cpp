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
    cout << "2. Cliente con mas reservas" << endl;
    cout << "3. Espacio mas reservado" << endl;
    cout << "4. Reservas activas" << endl;
    cout << "0. Salir" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opc;
    switch (opc) {
        case 1:
            cout << reporteTotalReservas();
            break;
        case 2:
            cout << reporteClienteConMasReservas();
            break;
        case 3:
            cout << reporteEspacioMasReservado();
            break;
        case 4:
            cout << reporteReservasActivas();
            break;
        case 0:
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo" << endl;
    }
}

void MenuReportes::mostrarMenu() {
    gestionReportes();
}
std::string MenuReportes::reporteTotalReservas() {
    Reporte reporte;
    return reporte.totalReservas();
}

std::string MenuReportes::reporteClienteConMasReservas() {
    Reporte reporte;
    return reporte.clienteConMasReservas();
}

std::string MenuReportes::reporteEspacioMasReservado() {
    Reporte reporte;
    return reporte.espacioMasReservado();
}

std::string MenuReportes::reporteReservasActivas() {
    Reporte reporte;
    return reporte.reservasActivas();
}
