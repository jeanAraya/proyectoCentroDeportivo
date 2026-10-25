#ifndef CENTRODEPORTIVO_PISCINA_H
#define CENTRODEPORTIVO_PISCINA_H

#include "Espacio.h"
#include <string>

// Espacio concreto: piscina. Atributo propio: cantidad de carriles.
class Piscina : public Espacio {
    int cantidadCarriles;

public:
    Piscina(const std::string& codigo, const std::string& nombre, int capacidad,
            double precioHora, int cantidadCarriles);
    ~Piscina() override;

    int getCantidadCarriles() const;
    void setCantidadCarriles(int cantidadCarriles);

    std::string getTipo() const override;
    double calcularCosto(int horas) const override;
    std::string toString() const override;
    std::string toCSV() const override;
};

#endif
