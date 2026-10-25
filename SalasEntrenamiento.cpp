#include "SalasEntrenamiento.h"
#include "CustomException.h"

SalasEntrenamiento::SalasEntrenamiento(const std::string& codigo, const std::string& nombre, int capacidad,
                                       double precioHora, const std::string& tipoEntrenamiento)
    : Espacio(codigo, nombre, capacidad, precioHora) {
    if (tipoEntrenamiento.empty()) {
        throw CustomException("El tipo de entrenamiento no puede estar vacio.");
    }
    this->tipoEntrenamiento = tipoEntrenamiento;
}

SalasEntrenamiento::~SalasEntrenamiento() {
}

std::string SalasEntrenamiento::getTipoEntrenamiento() const {
    return tipoEntrenamiento;
}

void SalasEntrenamiento::setTipoEntrenamiento(const std::string& tipoEntrenamiento) {
    if (tipoEntrenamiento.empty()) {
        throw CustomException("El tipo de entrenamiento no puede estar vacio.");
    }
    this->tipoEntrenamiento = tipoEntrenamiento;
}

std::string SalasEntrenamiento::getTipo() const {
    return "SALA";
}

double SalasEntrenamiento::calcularCosto(int horas) const {
    if (horas <= 0) {
        throw CustomException("La cantidad de horas debe ser mayor que cero.");
    }
    return getPrecioHora() * horas;
}

std::string SalasEntrenamiento::toString() const {
    return Espacio::toString() + " | Entrenamiento: " + tipoEntrenamiento;
}

std::string SalasEntrenamiento::toCSV() const {
    return Espacio::toCSV() + "," + tipoEntrenamiento;
}
