//
// Created by juand on 24/10/2026.
//

#include "MenuClientes.h"
#include <iostream>
#include "GestorSistema.h"
#include "Factory.h"

using namespace std;
void MenuClientes::gestionClientes() {
    int opc;
    cout << "--------------------------------------------" << endl;
    cout << "             Gestionar Clientes             " << endl;
    cout << "--------------------------------------------" << endl;
    cout << "1. Registrar Cliente" << endl;
    cout << "2. Modificar Cliente" << endl;
    cout << "3. Buscar Cliente" << endl;
    cout << "4. Listar Clientes" << endl;
    cout << "0. Volver al Menú Principal" << endl;
    cout << "Seleccione una opcion: ";
    cin >> opc;
    switch (opc) {
        case 1:
            registrarCliente();
            break;
        case 2:
            modificarCliente();
            break;
        case 3:
            buscarCliente();
            break;
        case 4:
            GestorSistema::getInstancia().mostrarClientes();
            break;
        case 0:
            break;
        default:
            cout << "Opción inválida. Intente de nuevo." << endl;
            break;
    }
}

void MenuClientes::registrarCliente() {
    string id;
    string nombre;
    string telefono;
    string correo;
    cout<<"------ Registrar cliente ------"<<endl;
    cout<<"Ingrese la identificacion del cliente: ";
    cin >> id;
    cout<<"Ingrese el nombre del cliente: ";
    cin >> nombre;
    cout<<"Ingrese el telefono del cliente: ";
    cin >> telefono;
    cout<<"Ingrese el correo del cliente: ";
    cin >> correo;
    if (!GestorSistema::getInstancia().registrarCliente(Factory::crearCliente(id, nombre, telefono, correo))) {
        cout << "El cliente con identificacion " << id << " ya existe." << endl;
    }
}

void MenuClientes::modificarCliente() {
}

void MenuClientes::buscarCliente() {
    string id;
    cout << "Ingrese la identificacion del cliente a buscar: ";
    cin >> id;
    const Cliente* aux = GestorSistema::getInstancia().buscarCliente(id);
    if (aux == nullptr) {
        cout << "El cliente con identificacion " << id << " no existe." << endl;
        return;
    }
    cout << aux->toString();
}


void MenuClientes::mostrarMenu() {
    gestionClientes();
}
