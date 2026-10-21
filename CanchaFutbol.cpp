#include "CanchaFutbol.h"
#include "CustomException.h"

CanchaFutbol::CanchaFutbol(const std::string& codigo, const std::string& nombre, int capacidad,
                           double precioHora, const std::string& superficie)
    : Espacio(codigo, nombre, capacidad, precioHora) {
    if (superficie.empty()) {
        throw CustomException("La superficie de la cancha de futbol no puede estar vacia.");
    }
    this->superficie = superficie;
}

CanchaFutbol::~CanchaFutbol() {
}

std::string CanchaFutbol::getSuperficie() const {
    return superficie;
}

void CanchaFutbol::setSuperficie(const std::string& superficie) {
    if (superficie.empty()) {
        throw CustomException("La superficie de la cancha de futbol no puede estar vacia.");
    }
    this->superficie = superficie;
}

std::string CanchaFutbol::getTipo() const {
    return "FUTBOL";
}

double CanchaFutbol::calcularCosto(int horas) const {
    if (horas <= 0) {
        throw CustomException("La cantidad de horas debe ser mayor que cero.");
    }
    return getPrecioHora() * horas;
}

std::string CanchaFutbol::toString() const {
    return Espacio::toString() + " | Superficie: " + superficie;
}

std::string CanchaFutbol::toCSV() const {
    return Espacio::toCSV() + "," + superficie;
}