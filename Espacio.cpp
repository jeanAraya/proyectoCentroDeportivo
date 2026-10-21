#include "Espacio.h"
#include "CustomException.h"
#include <iomanip>
#include <sstream>

namespace {
    std::string formatearPrecio(double valor) {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(2) << valor;
        return oss.str();
    }
}

Espacio::Espacio(const std::string& codigo, const std::string& nombre, int capacidad, double precioHora) {
    if (codigo.empty()) {
        throw CustomException("El codigo del espacio no puede estar vacio.");
    }
    if (nombre.empty()) {
        throw CustomException("El nombre del espacio no puede estar vacio.");
    }
    if (capacidad <= 0) {
        throw CustomException("La capacidad del espacio debe ser mayor que cero.");
    }
    if (precioHora < 0) {
        throw CustomException("El precio por hora no puede ser negativo.");
    }

    this->codigo = codigo;
    this->nombre = nombre;
    this->capacidad = capacidad;
    this->precioHora = precioHora;
}

Espacio::~Espacio() {
}

std::string Espacio::getCodigo() const {
    return codigo;
}

std::string Espacio::getNombre() const {
    return nombre;
}

int Espacio::getCapacidad() const {
    return capacidad;
}

double Espacio::getPrecioHora() const {
    return precioHora;
}

void Espacio::setNombre(const std::string& nombre) {
    if (nombre.empty()) {
        throw CustomException("El nombre del espacio no puede estar vacio.");
    }
    this->nombre = nombre;
}

void Espacio::setCapacidad(int capacidad) {
    if (capacidad <= 0) {
        throw CustomException("La capacidad del espacio debe ser mayor que cero.");
    }
    this->capacidad = capacidad;
}

void Espacio::setPrecioHora(double precioHora) {
    if (precioHora < 0) {
        throw CustomException("El precio por hora no puede ser negativo.");
    }
    this->precioHora = precioHora;
}

std::string Espacio::toString() const {
    return "Codigo: " + codigo + " | Tipo: " + getTipo() + " | Nombre: " + nombre +
           " | Capacidad: " + std::to_string(capacidad) +
           " | Precio/hora: " + formatearPrecio(precioHora);
}

std::string Espacio::toCSV() const {
    return getTipo() + "," + codigo + "," + nombre + "," + std::to_string(capacidad) +
           "," + formatearPrecio(precioHora);
}