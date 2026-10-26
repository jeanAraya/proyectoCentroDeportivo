#include "Piscina.h"
#include "CustomException.h"

Piscina::Piscina(const std::string& codigo, const std::string& nombre, int capacidad,
                 double precioHora, bool tieneClimatizacion)
    : Espacio(codigo, nombre, capacidad, precioHora) {
    this->tieneClimatizacion = tieneClimatizacion;
}

Piscina::~Piscina() {
}

bool Piscina::getTieneClimatizacion() const {
    return tieneClimatizacion;
}

void Piscina::setTieneClimatizacion(bool tieneClimatizacion) {
    this->tieneClimatizacion = tieneClimatizacion;
}

std::string Piscina::toString() const {
    return Espacio::toString() + " | Tiene climatización: " + (tieneClimatizacion ? "Sí" : "No");
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


std::string Piscina::toCSV() const {
    return Espacio::toCSV() + "," + std::to_string(tieneClimatizacion);
}
