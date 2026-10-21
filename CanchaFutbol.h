#ifndef CENTRODEPORTIVO_CANCHAFUTBOL_H
#define CENTRODEPORTIVO_CANCHAFUTBOL_H

#include "Espacio.h"
#include <string>

class CanchaFutbol : public Espacio {
    std::string superficie;

public:
    CanchaFutbol(const std::string& codigo, const std::string& nombre, int capacidad,
                 double precioHora, const std::string& superficie);
    ~CanchaFutbol() override;

    std::string getSuperficie() const;
    void setSuperficie(const std::string& superficie);

    std::string getTipo() const override;
    double calcularCosto(int horas) const override;
    std::string toString() const override;
    std::string toCSV() const override;
};

#endif