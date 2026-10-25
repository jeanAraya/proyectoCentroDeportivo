#ifndef CENTRODEPORTIVO_REPORTE_H
#define CENTRODEPORTIVO_REPORTE_H

#include "ListaTemplate.h"
#include "Cliente.h"
#include "Espacio.h"
#include "Reserva.h"
#include <string>

// Genera los reportes del sistema. No imprime nada: devuelve texto para que el Menu lo muestre.
// Recorre las listas únicamente mediante el Iterador.
// "Reservas realizadas" cuenta todas las reservas registradas (activas y canceladas).
class Reporte {
    ListaTemplate<Cliente>* clientes;
    ListaTemplate<Espacio>* espacios;
    ListaTemplate<Reserva>* reservas;

    int contarReservasDeCliente(const std::string& identificacion);
    int contarReservasDeEspacio(const std::string& codigoEspacio);

public:
    Reporte(ListaTemplate<Cliente>& clientes, ListaTemplate<Espacio>& espacios,
            ListaTemplate<Reserva>& reservas);
    ~Reporte();

    std::string totalReservas();
    std::string clienteConMasReservas();
    std::string espacioMasReservado();
    std::string reservasActivas();
};

#endif
