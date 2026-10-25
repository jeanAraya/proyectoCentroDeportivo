#include "Piscina.h"
#include "CustomException.h"

Piscina::Piscina(const std::string& codigo, const std::string& nombre, int capacidad,
                 double precioHora, int cantidadCarriles)
    : Espacio(codigo, nombre, capacidad, precioHora) {
    if (cantidadCarriles <= 0) {
        throw CustomException("La cantidad de carriles debe ser mayor que cero.");
    }
    this->cantidadCarriles = cantidadCarriles;
}

Piscina::~Piscina() {
}

int Piscina::getCantidadCarriles() const {
    return cantidadCarriles;
}

void Piscina::setCantidadCarriles(int cantidadCarriles) {
    if (cantidadCarriles <= 0) {
        throw CustomException("La cantidad de carriles debe ser mayor que cero.");
    }
    this->cantidadCarriles = cantidadCarriles;
}

std::string Piscina::getTipo() const {
    return "PISCINA";
}

double Piscina::calcularCosto(int horas) const {
    if (horas <= 0) {
        throw CustomException("La cantidad de horas debe ser mayor que cero.");
    }
    return getPrecioHora() * horas;
}

std::string Piscina::toString() const {
    return Espacio::toString() + " | Carriles: " + std::to_string(cantidadCarriles);
}

std::string Piscina::toCSV() const {
    return Espacio::toCSV() + "," + std::to_string(cantidadCarriles);
}
