#ifndef CENTRODEPORTIVO_CANCHABALONCESTO_H
#define CENTRODEPORTIVO_CANCHABALONCESTO_H

#include "Espacio.h"
#include <string>

class CanchaBaloncesto : public Espacio {
    bool techada;

public:
    CanchaBaloncesto(const std::string& codigo, const std::string& nombre, int capacidad,
                     double precioHora, bool techada);
    ~CanchaBaloncesto() override;

    bool esTechada() const;
    void setTechada(bool techada);

    std::string getTipo() const override;
    double calcularCosto(int horas) const override;
    std::string toString() const override;
    std::string toCSV() const override;
};

#endif
