#include "GuardadorDatos.h"
#include "fstream"
#include "GestorSistema.h"
#include "Iterador.h"

void GuardadorDatos::guardar(string salida) {
    if (GestorSistema::getInstancia().getListaClientes()->getPrimero() == nullptr
        && GestorSistema::getInstancia().getListaEspacios()->getPrimero() == nullptr
        && GestorSistema::getInstancia().getListaReservas()->getPrimero() == nullptr)
    {
        std::cout << "Todos los registros estan vacios, no existen datos para guardar" << endl;
        return;
    }

    if (salida == "clientes.csv") {
        guardarClientes( salida);
    }
    if (salida == "espacios.csv") {
        guardarEspacios(salida);
    }
    if (salida == "reservas.csv") {
        guardarReservas(salida);
    }
}

void GuardadorDatos::guardarClientes(string salida) {
    ofstream archivo(salida, ios::out);
    archivo << "identificacion,nombre,telefono,correo" << '\n';
    Iterador<Cliente> iterador(*GestorSistema::getInstancia().getListaClientes());
    while (iterador.hayMas()) {
        Cliente* cliente = iterador.siguiente();
        archivo << cliente->toCSV() << '\n';
    }

    archivo.close();
}

void GuardadorDatos::guardarEspacios(string salida) {
    ofstream archivo(salida, ios::out);
    archivo << "tipo,codigo,nombre,capacidad,precioHora,extra" << '\n';
    Iterador<Espacio> iterador(*GestorSistema::getInstancia().getListaEspacios());
    while (iterador.hayMas()) {
        Espacio* espacio = iterador.siguiente();
        archivo << espacio->toCSV() << '\n';
    }
    archivo.close();
}

void GuardadorDatos::guardarReservas(string salida) {
    ofstream archivo(salida, ios::out);
    archivo << "codigo,identificacionCliente,codigoEspacio,fecha,hora,activa" << '\n';
    Iterador<Reserva> iterador(*GestorSistema::getInstancia().getListaReservas());
    while (iterador.hayMas()) {
        Reserva* reserva = iterador.siguiente();
        archivo << reserva->toCSV() << '\n';
    }

    archivo.close();
}
