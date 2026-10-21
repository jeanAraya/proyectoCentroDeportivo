#ifndef CENTRODEPORTIVO_CLIENTE_H
#define CENTRODEPORTIVO_CLIENTE_H

#include <string>

// Representa a un cliente del centro deportivo.
// Formato CSV (clientes.csv): identificacion,nombre,telefono,correo
class Cliente {
    std::string identificacion;
    std::string nombre;
    std::string telefono;
    std::string correo;

public:
    Cliente(const std::string& identificacion, const std::string& nombre,
            const std::string& telefono, const std::string& correo);
    ~Cliente();

    std::string getIdentificacion() const;
    std::string getNombre() const;
    std::string getTelefono() const;
    std::string getCorreo() const;

    // La identificación no se modifica, porque es la llave de búsqueda.
    void setNombre(const std::string& nombre);
    void setTelefono(const std::string& telefono);
    void setCorreo(const std::string& correo);

    std::string toString() const;
    std::string toCSV() const;

    // Crea un Cliente (con new) a partir de una línea CSV. Lanza CustomException si es inválida.
    static Cliente* fromCSV(const std::string& linea);
};

#endif