#include "CanchaBaloncesto.h"
#include "CustomException.h"

CanchaBaloncesto::CanchaBaloncesto(const std::string& codigo, const std::string& nombre, int capacidad,
                                   double precioHora, bool techada)
    : Espacio(codigo, nombre, capacidad, precioHora) {
    this->techada = techada;
}

CanchaBaloncesto::~CanchaBaloncesto() {
}

bool CanchaBaloncesto::esTechada() const {
    return techada;
}

void CanchaBaloncesto::setTechada(bool techada) {
    this->techada = techada;
}

std::string CanchaBaloncesto::getTipo() const {
    return "BALONCESTO";
}

// Regla de ejemplo: la cancha techada tiene un recargo del 10%.
double CanchaBaloncesto::calcularCosto(int horas) const {
    if (horas <= 0) {
        throw CustomException("La cantidad de horas debe ser mayor que cero.");
    }
    double costo = getPrecioHora() * horas;
    if (techada) {
        costo = costo * 1.10;
    }
    return costo;
}

std::string CanchaBaloncesto::toString() const {
    return Espacio::toString() + " | Techada: " + (techada ? "Si" : "No");
}

std::string CanchaBaloncesto::toCSV() const {
    return Espacio::toCSV() + "," + (techada ? "1" : "0");
}
