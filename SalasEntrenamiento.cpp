#include "SalasEntrenamiento.h"
#include "CustomException.h"

SalasEntrenamiento::SalasEntrenamiento(const std::string& codigo, const std::string& nombre, int capacidad,
                                       double precioHora, bool tieneProyector)
    : Espacio(codigo, nombre, capacidad, precioHora) {
    this->tieneProyector = tieneProyector;
}

SalasEntrenamiento::~SalasEntrenamiento() {
}


bool SalasEntrenamiento::getTieneProyector() const {
    return tieneProyector;
}

void SalasEntrenamiento::setTieneProyector(bool tieneProyector) {
    this->tieneProyector = tieneProyector;
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
    return Espacio::toString() + " | Tiene proyector: " + (tieneProyector ? "Sí" : "No");
}

std::string SalasEntrenamiento::toCSV() const {
    return Espacio::toCSV() + "," + std::to_string(tieneProyector);
}
