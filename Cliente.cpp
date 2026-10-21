#include "Cliente.h"
#include "CustomException.h"
#include <sstream>

namespace {
    void validarNoVacio(const std::string& valor, const std::string& campo) {
        if (valor.empty()) {
            throw CustomException("El campo '" + campo + "' del cliente no puede estar vacio.");
        }
    }
}

Cliente::Cliente(const std::string& identificacion, const std::string& nombre,
                 const std::string& telefono, const std::string& correo) {
    validarNoVacio(identificacion, "identificacion");
    validarNoVacio(nombre, "nombre");
    validarNoVacio(telefono, "telefono");
    validarNoVacio(correo, "correo");

    this->identificacion = identificacion;
    this->nombre = nombre;
    this->telefono = telefono;
    this->correo = correo;
}

Cliente::~Cliente() {
}

std::string Cliente::getIdentificacion() const {
    return identificacion;
}

std::string Cliente::getNombre() const {
    return nombre;
}

std::string Cliente::getTelefono() const {
    return telefono;
}

std::string Cliente::getCorreo() const {
    return correo;
}

void Cliente::setNombre(const std::string& nombre) {
    validarNoVacio(nombre, "nombre");
    this->nombre = nombre;
}

void Cliente::setTelefono(const std::string& telefono) {
    validarNoVacio(telefono, "telefono");
    this->telefono = telefono;
}

void Cliente::setCorreo(const std::string& correo) {
    validarNoVacio(correo, "correo");
    this->correo = correo;
}

std::string Cliente::toString() const {
    return "Identificacion: " + identificacion + " | Nombre: " + nombre +
           " | Telefono: " + telefono + " | Correo: " + correo;
}

std::string Cliente::toCSV() const {
    return identificacion + "," + nombre + "," + telefono + "," + correo;
}

Cliente* Cliente::fromCSV(const std::string& linea) {
    std::string limpia = linea;
    if (!limpia.empty() && limpia.back() == '\r') {
        limpia.pop_back();
    }

    std::stringstream ss(limpia);
    std::string campos[4];
    std::string campo;
    int cantidad = 0;

    while (std::getline(ss, campo, ',')) {
        if (cantidad < 4) {
            campos[cantidad] = campo;
        }
        cantidad++;
    }

    if (cantidad != 4) {
        throw CustomException("Linea de cliente invalida: " + linea);
    }

    return new Cliente(campos[0], campos[1], campos[2], campos[3]);
}