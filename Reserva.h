#ifndef CENTRODEPORTIVO_RESERVA_H
#define CENTRODEPORTIVO_RESERVA_H

#include <string>
// Guarda solo los IDs, no punteros: así las listas dueñas de Cliente y Espacio
// siguen siendo las únicas responsables de liberar esa memoria.
// Formato CSV (reservas.csv): codigo, identificacionCliente,  codigoEspacio, fecha, hora,activa
//   fecha: AAAA-MM-DD | hora: 0-23 | activa: 1 o 0
class Reserva {
    std::string codigo;
    std::string identificacionCliente;
    std::string codigoEspacio;
    std::string fecha;
    int hora;
    bool activa;

public:
    Reserva(const std::string& codigo, const std::string& identificacionCliente,
            const std::string& codigoEspacio, const std::string& fecha, int hora, bool activa = true);
    ~Reserva();

    std::string getCodigo() const;
    std::string getIdentificacionCliente() const;
    std::string getCodigoEspacio() const;
    std::string getFecha() const;
    int getHora() const;
    bool estaActiva() const;

    void cancelar();

    bool ocupa(const std::string& codigoEspacio, const std::string& fecha, int hora) const;

    std::string toString() const;
    std::string toCSV() const;

    static Reserva* fromCSV(const std::string& linea);
};

#endif