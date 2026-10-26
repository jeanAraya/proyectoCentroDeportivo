#ifndef CENTRODEPORTIVO_RESERVA_H
#define CENTRODEPORTIVO_RESERVA_H

#include <string>

// Una reserva une un cliente con un espacio en una fecha y hora.
// Guarda solo los IDs (strings), no punteros: así las listas dueñas de Cliente y Espacio
// siguen siendo las únicas responsables de liberar esa memoria.
// Formato CSV (reservas.csv): codigo,identificacionCliente,codigoEspacio,fecha,hora,activa
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

    // Lanza CustomException si la fecha (AAAA-MM-DD) o la hora (0-23) no son válidas.
    static void validarFechaHora(const std::string& fecha, int hora);

    // true si esta reserva está activa y ocupa ese espacio en esa fecha y hora (detecta conflictos).
    bool ocupa(const std::string& codigoEspacio, const std::string& fecha, int hora) const;

    std::string toString() const;
    std::string toCSV() const;
};

#endif
