#ifndef CENTRODEPORTIVO_PISCINA_H
#define CENTRODEPORTIVO_PISCINA_H

#include "Espacio.h"
#include <string>

class Piscina : public Espacio {
    bool tieneClimatizacion;

public:
    Piscina(const std::string& codigo, const std::string& nombre, int capacidad,
            double precioHora, bool tieneClimatizacion);
    ~Piscina() override;

    bool getTieneClimatizacion() const;
    void setTieneClimatizacion(bool tieneClimatizacion);

    std::string getTipo() const override;
    double calcularCosto(int horas) const override;
    std::string toString() const override;
    std::string toCSV() const override;
};

#endif
