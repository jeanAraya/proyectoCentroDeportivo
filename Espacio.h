#ifndef CENTRODEPORTIVO_ESPACIO_H
#define CENTRODEPORTIVO_ESPACIO_H

#include <string>

// Clase base de todos los espacios(canchas de futbol, tenis)
// Formato CSV (espacios.csv): tipo, codigo, nombre, capacidad, precioHora, extra
//   tipo: FUTBOL | BALONCESTO | TENIS | PISCINA | SALA
class Espacio {
    std::string codigo;
    std::string nombre;
    int capacidad;
    double precioHora;

public:
    Espacio(const std::string& codigo, const std::string& nombre, int capacidad, double precioHora);
    virtual ~Espacio();

    std::string getCodigo() const;
    std::string getNombre() const;
    int getCapacidad() const;
    double getPrecioHora() const;

    void setNombre(const std::string& nombre);
    void setCapacidad(int capacidad);
    void setPrecioHora(double precioHora);

    virtual std::string getTipo() const = 0;
    virtual double calcularCosto(int horas) const = 0;

    virtual std::string toString() const;
    virtual std::string toCSV() const;
};

#endif