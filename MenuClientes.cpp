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
    cout << "0. Volver al Menu Principal" << endl;
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
            cout << "Opcion inválida. Intente de nuevo." << endl;
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
    int opc;
    Cliente* aux = buscarClienteAux();
    if (aux != nullptr) {
        cout<<"------ Modificar cliente ------"<<endl;
        cout<<"1. Modificar nombre"<<endl;
        cout<<"2. Modificar telefono"<<endl;
        cout<<"3. Modificar correo"<<endl;
        cout<<"Seleccione el campo a modificar: "<<endl;
        cin >> opc;
        switch (opc) {
            case 1: {
                string nombre;
                cout << "Ingrese el nuevo nombre: ";
                cin >> nombre;
                aux->setNombre(nombre);
                break;
            }
            case 2: {
                string telefono;
                cout << "Ingrese el nuevo telefono: ";
                cin >> telefono;
                aux->setTelefono(telefono);
                break;
            }
            case 3: {
                string correo;
                cout << "Ingrese el nuevo correo: ";
                cin >> correo;
                aux->setCorreo(correo);
                break;
            }

            default:
                cout << "Opción invalida. Intente de nuevo." << endl;
                break;
        }
    }
}

Cliente* MenuClientes::buscarClienteAux() {
    string id;
    cout << "Ingrese la identificacion del cliente a buscar: ";
    cin >> id;
    Cliente* aux = GestorSistema::getInstancia().buscarCliente(id);
    if (aux != nullptr) {
        return aux;
    }
    return nullptr;
}

void MenuClientes::buscarCliente() {
    Cliente* aux = buscarClienteAux();
    if (aux != nullptr) {
        cout << aux->toString() << endl;
        return;
    }
    cout << "No se encontro el cliente con esa identificacion" << endl;
}


void MenuClientes::mostrarMenu() {
    gestionClientes();
}
