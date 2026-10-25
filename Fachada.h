#ifndef CENTRODEPORTIVO_FACHADA_H
#define CENTRODEPORTIVO_FACHADA_H

#include "ListaTemplate.h"
#include "Cliente.h"
#include "Espacio.h"
#include "Reserva.h"
#include "Reporte.h"
#include <string>

// PATRÓN FACADE (obligatorio).
// Es el único punto de entrada del Menu al sistema: oculta las listas, el Iterador, la validación
// y la creación de objetos detrás de operaciones simples (registrarCliente, crearReserva, ...).
// Ninguna operación imprime ni pide datos: devuelven texto o lanzan CustomException,
// y el Menu decide cómo mostrarlo.
//
// La Fachada no es dueña de las listas: las recibe por referencia (las crea y destruye el GestorSistema).
class Fachada {
    ListaTemplate<Cliente>* clientes;
    ListaTemplate<Espacio>* espacios;
    ListaTemplate<Reserva>* reservas;
    Reporte reporte;

    Cliente* localizarCliente(const std::string& identificacion);
    Espacio* localizarEspacio(const std::string& codigo);
    Reserva* localizarReserva(const std::string& codigo);
    bool estaOcupado(const std::string& codigoEspacio, const std::string& fecha, int hora);
    std::string generarCodigoReserva();

public:
    Fachada(ListaTemplate<Cliente>& clientes, ListaTemplate<Espacio>& espacios,
            ListaTemplate<Reserva>& reservas);
    ~Fachada();

    Fachada(const Fachada&) = delete;
    Fachada& operator=(const Fachada&) = delete;

    // --- Clientes ---
    void registrarCliente(const std::string& identificacion, const std::string& nombre,
                          const std::string& telefono, const std::string& correo);
    void modificarCliente(const std::string& identificacion, const std::string& nombre,
                          const std::string& telefono, const std::string& correo);
    std::string buscarCliente(const std::string& identificacion);
    std::string listarClientes();

    // --- Espacios ---
    std::string listarEspacios();
    std::string buscarEspacio(const std::string& codigo);
    bool consultarDisponibilidad(const std::string& codigoEspacio, const std::string& fecha, int hora);
    std::string mostrarEspaciosDisponibles(const std::string& fecha, int hora);
    std::string mostrarEspaciosOcupados(const std::string& fecha, int hora);

    // --- Reservas ---
    // Devuelve el código de la reserva creada (ej. "R013").
    std::string crearReserva(const std::string& identificacionCliente, const std::string& codigoEspacio,
                             const std::string& fecha, int hora);
    std::string consultarReserva(const std::string& codigo);
    void cancelarReserva(const std::string& codigo);
    std::string listarReservasActivas();

    // --- Reportes ---
    std::string reporteTotalReservas();
    std::string reporteClienteConMasReservas();
    std::string reporteEspacioMasReservado();
    std::string reporteReservasActivas();
};

#endif
