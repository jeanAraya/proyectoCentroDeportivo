#ifndef CENTRODEPORTIVO_CANCHATENIS_H
#define CENTRODEPORTIVO_CANCHATENIS_H

#include "Espacio.h"
#include <string>

class CanchaTenis : public Espacio {
    std::string superficie;

public:
    CanchaTenis(const std::string& codigo, const std::string& nombre, int capacidad,
                double precioHora, const std::string& superficie);
    ~CanchaTenis() override;

    std::string getSuperficie() const;
    void setSuperficie(const std::string& superficie);

    std::string getTipo() const override;
    double calcularCosto(int horas) const override;
    std::string toString() const override;
    std::string toCSV() const override;
};

#endif
