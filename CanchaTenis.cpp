#include "CanchaTenis.h"
#include "CustomException.h"

CanchaTenis::CanchaTenis(const std::string& codigo, const std::string& nombre, int capacidad,
                         double precioHora, const std::string& superficie)
    : Espacio(codigo, nombre, capacidad, precioHora) {
    if (superficie.empty()) {
        throw CustomException("La superficie de la cancha de tenis no puede estar vacia.");
    }
    this->superficie = superficie;
}

CanchaTenis::~CanchaTenis() {
}

std::string CanchaTenis::getSuperficie() const {
    return superficie;
}

void CanchaTenis::setSuperficie(const std::string& superficie) {
    if (superficie.empty()) {
        throw CustomException("La superficie de la cancha de tenis no puede estar vacia.");
    }
    this->superficie = superficie;
}

std::string CanchaTenis::getTipo() const {
    return "TENIS";
}

double CanchaTenis::calcularCosto(int horas) const {
    if (horas <= 0) {
        throw CustomException("La cantidad de horas debe ser mayor que cero.");
    }
    return getPrecioHora() * horas;
}

std::string CanchaTenis::toString() const {
    return Espacio::toString() + " | Superficie: " + superficie;
}

std::string CanchaTenis::toCSV() const {
    return Espacio::toCSV() + "," + superficie;
}
