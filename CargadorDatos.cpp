#include "CargadorDatos.h"
#include <fstream>
#include <sstream>
#include "GestorSistema.h"
#include "Factory.h"
void CargadorDatos::leer(string entrada) {
    char delim = ',';
    if (entrada == "clientes.csv") {
        leerClientes(entrada,delim);
        return;
    }

    if (entrada == "reservas.csv") {
        leerReservas(entrada,delim);
        return;
    }

    if (entrada == "espacios.csv") {
        leerEspacios(entrada,delim);
        return;
    }
}

void CargadorDatos::leerClientes(string entrada, char delim) {
    ifstream archivo(entrada);
    if (!archivo.is_open()) {
        cout << "El archivo " << entrada << " no se pudo abrir" << endl;
        return;
    }
    string linea;

    getline(archivo, linea);

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string identificacion, nombre, telefono, correo;

        getline(ss, identificacion, delim);
        getline(ss, nombre, delim);
        getline(ss, telefono, delim);
        getline(ss, correo, delim);

        GestorSistema::getInstancia().registrarCliente(Factory::crearCliente(identificacion, nombre, telefono, correo));
        cout<<"Cliente cargado"<<endl;
    }
    archivo.close();
}

void CargadorDatos::leerEspacios(string entrada, char delim) {
    ifstream archivo(entrada);
    if (!archivo.is_open()) {
        cout << "El archivo " << entrada << " no se pudo abrir" << endl;
        return;
    }
    string linea;

    getline(archivo, linea);

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string tipo, codigo, nombre, capacidadStr, precioHoraStr, extra;

        getline(ss, tipo, delim);
        getline(ss, codigo, delim);
        getline(ss, nombre, delim);
        getline(ss, capacidadStr, delim);
        getline(ss, precioHoraStr, delim);
        getline(ss, extra, delim);

        int capacidad = stoi(capacidadStr);
        double precioHora = stod(precioHoraStr);

        GestorSistema::getInstancia().registrarEspacio(Factory::crearEspacio(tipo, codigo, nombre, capacidad, precioHora, extra));
        cout<<"Espacio cargado"<<endl;
    }
    archivo.close();
}

void CargadorDatos::leerReservas(string entrada, char delim) {
    ifstream archivo(entrada);
    if (!archivo.is_open()) {
        cout << "El archivo " << entrada << " no se pudo abrir" << endl;
        return;
    }
    string linea;

    getline(archivo, linea);

    while (getline(archivo,linea)) {
        stringstream ss(linea);
        string codigo, idCliente, codigoEspacio, fecha, horaStr, activaStr;

        getline(ss, codigo, delim);
        getline(ss, idCliente, delim);
        getline(ss, codigoEspacio, delim);
        getline(ss, fecha, delim);
        getline(ss, horaStr, delim);
        getline(ss, activaStr, delim);

        int hora = stoi(horaStr);
        bool activa = (activaStr == "1");

        GestorSistema::getInstancia().registrarReserva(Factory::crearReserva(codigo, idCliente, codigoEspacio, fecha, hora, activa));
        cout<<"Reserva cargada"<<endl;
    }
    archivo.close();
}