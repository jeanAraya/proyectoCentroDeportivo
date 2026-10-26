#ifndef CENTRODEPORTIVO_SALASENTRENAMIENTO_H
#define CENTRODEPORTIVO_SALASENTRENAMIENTO_H

#include "Espacio.h"
#include <string>

// Espacio concreto: sala de entrenamiento funcional. Atributo propio: tipo de entrenamiento
// (ej. "Funcional", "Crossfit"). Su tipo en el CSV es "SALA".
class SalasEntrenamiento : public Espacio {
    bool tieneProyector;

public:
    SalasEntrenamiento(const std::string& codigo, const std::string& nombre, int capacidad,
                       double precioHora, bool tieneProyector);
    ~SalasEntrenamiento() override;

    bool getTieneProyector() const;
    void setTieneProyector(bool tieneProyector);

    std::string getTipo() const override;
    double calcularCosto(int horas) const override;
    std::string toString() const override;
    std::string toCSV() const override;
};

#endif
