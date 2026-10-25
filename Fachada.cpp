#include "Fachada.h"
#include "Iterador.h"
#include "CustomException.h"
#include <iomanip>
#include <sstream>

namespace {
    std::string formatearHora(int hora) {
        std::ostringstream oss;
        oss << std::setw(2) << std::setfill('0') << hora << ":00";
        return oss.str();
    }
}

Fachada::Fachada(ListaTemplate<Cliente>& clientes, ListaTemplate<Espacio>& espacios,
                 ListaTemplate<Reserva>& reservas)
    : reporte(clientes, espacios, reservas) {
    this->clientes = &clientes;
    this->espacios = &espacios;
    this->reservas = &reservas;
}

Fachada::~Fachada() {
}

// ---------------------- Búsquedas internas (usan el Iterador) ----------------------

Cliente* Fachada::localizarCliente(const std::string& identificacion) {
    Iterador<Cliente> it(*clientes);
    while (it.hayMas()) {
        Cliente* cliente = it.siguiente();
        if (cliente->getIdentificacion() == identificacion) {
            return cliente;
        }
    }
    return nullptr;
}

Espacio* Fachada::localizarEspacio(const std::string& codigo) {
    Iterador<Espacio> it(*espacios);
    while (it.hayMas()) {
        Espacio* espacio = it.siguiente();
        if (espacio->getCodigo() == codigo) {
            return espacio;
        }
    }
    return nullptr;
}

Reserva* Fachada::localizarReserva(const std::string& codigo) {
    Iterador<Reserva> it(*reservas);
    while (it.hayMas()) {
        Reserva* reserva = it.siguiente();
        if (reserva->getCodigo() == codigo) {
            return reserva;
        }
    }
    return nullptr;
}

bool Fachada::estaOcupado(const std::string& codigoEspacio, const std::string& fecha, int hora) {
    Iterador<Reserva> it(*reservas);
    while (it.hayMas()) {
        if (it.siguiente()->ocupa(codigoEspacio, fecha, hora)) {
            return true;
        }
    }
    return false;
}

std::string Fachada::generarCodigoReserva() {
    int maximo = 0;

    Iterador<Reserva> it(*reservas);
    while (it.hayMas()) {
        std::string codigo = it.siguiente()->getCodigo();
        if (codigo.size() > 1 && codigo[0] == 'R') {
            try {
                int numero = std::stoi(codigo.substr(1));
                if (numero > maximo) {
                    maximo = numero;
                }
            } catch (const std::exception&) {
                // Código con otro formato: se ignora para el consecutivo.
            }
        }
    }

    std::ostringstream oss;
    oss << "R" << std::setw(3) << std::setfill('0') << (maximo + 1);
    return oss.str();
}

// ---------------------- Clientes ----------------------

void Fachada::registrarCliente(const std::string& identificacion, const std::string& nombre,
                               const std::string& telefono, const std::string& correo) {
    if (localizarCliente(identificacion) != nullptr) {
        throw CustomException("Ya existe un cliente con la identificacion " + identificacion + ".");
    }

    Cliente* nuevo = new Cliente(identificacion, nombre, telefono, correo);
    clientes->insertarNuevoNodo(new NodoTemplate<Cliente>(nuevo));
}

void Fachada::modificarCliente(const std::string& identificacion, const std::string& nombre,
                               const std::string& telefono, const std::string& correo) {
    Cliente* cliente = localizarCliente(identificacion);
    if (cliente == nullptr) {
        throw CustomException("No existe un cliente con la identificacion " + identificacion + ".");
    }

    cliente->setNombre(nombre);
    cliente->setTelefono(telefono);
    cliente->setCorreo(correo);
}

std::string Fachada::buscarCliente(const std::string& identificacion) {
    Cliente* cliente = localizarCliente(identificacion);
    if (cliente == nullptr) {
        throw CustomException("No existe un cliente con la identificacion " + identificacion + ".");
    }
    return cliente->toString() + "\n";
}

std::string Fachada::listarClientes() {
    std::string resultado;

    Iterador<Cliente> it(*clientes);
    while (it.hayMas()) {
        resultado += it.siguiente()->toString() + "\n";
    }

    if (resultado.empty()) {
        return "No hay clientes registrados.\n";
    }
    return resultado;
}

// ---------------------- Espacios ----------------------

std::string Fachada::listarEspacios() {
    std::string resultado;

    Iterador<Espacio> it(*espacios);
    while (it.hayMas()) {
        resultado += it.siguiente()->toString() + "\n";
    }

    if (resultado.empty()) {
        return "No hay espacios registrados.\n";
    }
    return resultado;
}

std::string Fachada::buscarEspacio(const std::string& codigo) {
    Espacio* espacio = localizarEspacio(codigo);
    if (espacio == nullptr) {
        throw CustomException("No existe un espacio con el codigo " + codigo + ".");
    }
    return espacio->toString() + "\n";
}

bool Fachada::consultarDisponibilidad(const std::string& codigoEspacio, const std::string& fecha, int hora) {
    Reserva::validarFechaHora(fecha, hora);

    if (localizarEspacio(codigoEspacio) == nullptr) {
        throw CustomException("No existe un espacio con el codigo " + codigoEspacio + ".");
    }
    return !estaOcupado(codigoEspacio, fecha, hora);
}

std::string Fachada::mostrarEspaciosDisponibles(const std::string& fecha, int hora) {
    Reserva::validarFechaHora(fecha, hora);

    std::string resultado;
    Iterador<Espacio> it(*espacios);
    while (it.hayMas()) {
        Espacio* espacio = it.siguiente();
        if (!estaOcupado(espacio->getCodigo(), fecha, hora)) {
            resultado += espacio->toString() + "\n";
        }
    }

    if (resultado.empty()) {
        return "No hay espacios disponibles el " + fecha + " a las " + formatearHora(hora) + ".\n";
    }
    return resultado;
}

std::string Fachada::mostrarEspaciosOcupados(const std::string& fecha, int hora) {
    Reserva::validarFechaHora(fecha, hora);

    std::string resultado;
    Iterador<Espacio> it(*espacios);
    while (it.hayMas()) {
        Espacio* espacio = it.siguiente();
        if (estaOcupado(espacio->getCodigo(), fecha, hora)) {
            resultado += espacio->toString() + "\n";
        }
    }

    if (resultado.empty()) {
        return "No hay espacios ocupados el " + fecha + " a las " + formatearHora(hora) + ".\n";
    }
    return resultado;
}

// ---------------------- Reservas ----------------------

std::string Fachada::crearReserva(const std::string& identificacionCliente, const std::string& codigoEspacio,
                                  const std::string& fecha, int hora) {
    Reserva::validarFechaHora(fecha, hora);

    if (localizarCliente(identificacionCliente) == nullptr) {
        throw CustomException("No existe un cliente con la identificacion " + identificacionCliente + ".");
    }
    if (localizarEspacio(codigoEspacio) == nullptr) {
        throw CustomException("No existe un espacio con el codigo " + codigoEspacio + ".");
    }
    if (estaOcupado(codigoEspacio, fecha, hora)) {
        throw CustomException("El espacio " + codigoEspacio + " ya esta reservado el " + fecha +
                              " a las " + formatearHora(hora) + ".");
    }

    std::string codigo = generarCodigoReserva();
    Reserva* nueva = new Reserva(codigo, identificacionCliente, codigoEspacio, fecha, hora, true);
    reservas->insertarNuevoNodo(new NodoTemplate<Reserva>(nueva));
    return codigo;
}

std::string Fachada::consultarReserva(const std::string& codigo) {
    Reserva* reserva = localizarReserva(codigo);
    if (reserva == nullptr) {
        throw CustomException("No existe una reserva con el codigo " + codigo + ".");
    }
    return reserva->toString() + "\n";
}

void Fachada::cancelarReserva(const std::string& codigo) {
    Reserva* reserva = localizarReserva(codigo);
    if (reserva == nullptr) {
        throw CustomException("No existe una reserva con el codigo " + codigo + ".");
    }
    reserva->cancelar();
}

std::string Fachada::listarReservasActivas() {
    return reporte.reservasActivas();
}

// ---------------------- Reportes ----------------------

std::string Fachada::reporteTotalReservas() {
    return reporte.totalReservas();
}

std::string Fachada::reporteClienteConMasReservas() {
    return reporte.clienteConMasReservas();
}

std::string Fachada::reporteEspacioMasReservado() {
    return reporte.espacioMasReservado();
}

std::string Fachada::reporteReservasActivas() {
    return reporte.reservasActivas();
}
