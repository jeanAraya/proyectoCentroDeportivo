#include "Reserva.h"
#include "CustomException.h"
#include <cctype>
#include <iomanip>
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
    if (!fechaValida(fecha)) {
        throw CustomException("Fecha invalida (use AAAA-MM-DD): " + fecha);
    }
    if (hora < 0 || hora > 23) {
        throw CustomException("Hora invalida (use un valor entre 0 y 23).");
    }

    this->codigo = codigo;
    this->identificacionCliente = identificacionCliente;
    this->codigoEspacio = codigoEspacio;
    this->fecha = fecha;
    this->hora = hora;
    this->activa = activa;
}

Reserva::~Reserva() {
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

Reserva* Reserva::fromCSV(const std::string& linea) {
    std::string limpia = linea;
    if (!limpia.empty() && limpia.back() == '\r') {
        limpia.pop_back();
    }

    std::stringstream ss(limpia);
    std::string campos[6];
    std::string campo;
    int cantidad = 0;

    while (std::getline(ss, campo, ',')) {
        if (cantidad < 6) {
            campos[cantidad] = campo;
        }
        cantidad++;
    }

    if (cantidad != 6) {
        throw CustomException("Linea de reserva invalida: " + linea);
    }

    int hora;
    try {
        hora = std::stoi(campos[4]);
    } catch (const std::exception&) {
        throw CustomException("Hora invalida en la linea de reserva: " + linea);
    }

    return new Reserva(campos[0], campos[1], campos[2], campos[3], hora, campos[5] == "1");
}