//
// Created by juand on 24/10/2026.
//

#include "MenuReservas.h"
#include <iostream>

#include "Factory.h"
#include "GestorSistema.h"
using namespace std;

void MenuReservas::gestionReservas() {
    int opc;
    cout << "--------------------------------------------" << endl;
    cout << "             Gestionar Reservas             " << endl;
    cout << "--------------------------------------------" << endl;
    cout << "1. Registrar reserva" << endl;
    cout << "2. Mostrar reservas" << endl;
    cout << "3. Cancelar reserva" << endl;
    cout << "4. Buscar reserva" << endl;
    cout << "0. Salir" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opc;
    switch (opc) {
        case 1:
            registrarReserva();
            break;
        case 2:
            GestorSistema::getInstancia().mostrarReservas();
            break;
        case 3:
            cancelarReserva();
            break;
        case 4:
            buscarReserva();
            break;
        case 0:
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo" << endl;
    }
}

void MenuReservas::registrarReserva() {
    string codReserva;
    string idCliente;
    string codEspacio;
    string fecha;
    int hora;
    cout<<"------ Registrar reserva ------"<<endl;
    cout << "Ingrese el codigo de la reserva: ";
    cin >> codReserva;
    cout << "Ingrese la identificacion del cliente: ";
    cin >> idCliente;
    cout << "Ingrese el codigo del espacio: ";
    cin >> codEspacio;
    cout << "Ingrese la fecha de la reserva: ";
    cin >> fecha;
    cout << "Ingrese la hora de la reserva: ";
    cin >> hora;
    GestorSistema::getInstancia().registrarReserva(Factory::crearReserva(codReserva, idCliente, codEspacio, fecha, hora));
}

void MenuReservas::cancelarReserva() {
    string cod;
    cout<<"------ Cancelar reserva ------"<<endl;
    cout << "Ingrese el codigo de la reserva: ";
    cin >> cod;

    if (!GestorSistema::getInstancia().cancelarReserva(cod)) {
        cout << "No se encontro la reserva." << endl;
        return;
    }
    cout << "Reserva cancelada exitosamente." << endl;
}

void MenuReservas::buscarReserva() {

}

void MenuReservas::mostrarMenu() {
    gestionReservas();
}
