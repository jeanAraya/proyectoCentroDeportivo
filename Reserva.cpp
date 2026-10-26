#include "Reserva.h"
#include "CustomException.h"
#include <cctype>
#include <iomanip>
#include <iostream>
#include <sstream>

namespace {
    bool fechaValida(const std::string& f) {
        if (f.size() != 10 || f[4] != '-' || f[7] != '-') {
            return false;
        }
        for (int i = 0; i < 10; i++) {
            if (i != 4 && i != 7 && !std::isdigit(static_cast<unsigned char>(f[i]))) {
                return false;
            }
        }
        int mes = std::stoi(f.substr(5, 2));
        int dia = std::stoi(f.substr(8, 2));
        return mes >= 1 && mes <= 12 && dia >= 1 && dia <= 31;
    }
}

Reserva::Reserva(const std::string& codigo, const std::string& identificacionCliente,
                 const std::string& codigoEspacio, const std::string& fecha, int hora, bool activa) {
    if (codigo.empty() || identificacionCliente.empty() || codigoEspacio.empty()) {
        throw CustomException("El codigo, el cliente y el espacio de la reserva no pueden estar vacios.");
    }
    validarFechaHora(fecha, hora);

    this->codigo = codigo;
    this->identificacionCliente = identificacionCliente;
    this->codigoEspacio = codigoEspacio;
    this->fecha = fecha;
    this->hora = hora;
    this->activa = activa;
}

Reserva::~Reserva() {
}

void Reserva::validarFechaHora(const std::string& fecha, int hora) {
    if (!fechaValida(fecha)) {
        std::cout << "Fecha invalida (use AAAA-MM-DD): " + fecha << std::endl;
        return;
    }
    if (hora < 0 || hora > 23) {
        std::cout << "Hora invalida (use un valor entre 0 y 23)." << std::endl;
    }
}

std::string Reserva::getCodigo() const {
    return codigo;
}

std::string Reserva::getIdentificacionCliente() const {
    return identificacionCliente;
}

std::string Reserva::getCodigoEspacio() const {
    return codigoEspacio;
}

std::string Reserva::getFecha() const {
    return fecha;
}

int Reserva::getHora() const {
    return hora;
}

bool Reserva::estaActiva() const {
    return activa;
}

void Reserva::cancelar() {
    if (!activa) {
        throw CustomException("La reserva " + codigo + " ya estaba cancelada.");
    }
    activa = false;
}

bool Reserva::ocupa(const std::string& codigoEspacio, const std::string& fecha, int hora) const {
    return activa && this->codigoEspacio == codigoEspacio && this->fecha == fecha && this->hora == hora;
}

std::string Reserva::toString() const {
    std::ostringstream oss;
    oss << "Reserva: " << codigo
        << " | Cliente: " << identificacionCliente
        << " | Espacio: " << codigoEspacio
        << " | Fecha: " << fecha
        << " | Hora: " << std::setw(2) << std::setfill('0') << hora << ":00"
        << " | Estado: " << (activa ? "Activa" : "Cancelada");
    return oss.str();
}

std::string Reserva::toCSV() const {
    return codigo + "," + identificacionCliente + "," + codigoEspacio + "," + fecha + "," +
           std::to_string(hora) + "," + (activa ? "1" : "0");
}

