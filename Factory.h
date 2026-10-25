#include <iostream>

#include "CanchaFutbol.h"
#include "CanchaBaloncesto.h"
#include "CanchaTenis.h"
#include "Piscina.h"
#include "SalasEntrenamiento.h"
#include "Cliente.h"
#include "Espacio.h"
#include "Reserva.h"
using namespace std;
class Factory {
public:
    static Cliente* crearCliente(string identificacion, string nombre, string telefono, string correo);
    static Espacio* crearEspacio(string tipo, string codigo, string nombre, int capacidad, double precioHora, string extra);
    static Reserva* crearReserva(string codigo, string idCliente, string codigoEspacio, string fecha, int hora, bool activa = true);

    static CanchaFutbol* crearCanchaFutbol(string codigo, string nombre, int capacidad, double precioHora, string superficie);
    // static CanchaBaloncesto* crearCanchaBaloncesto(string codigo, string nombre, int capacidad, double precioHora, bool esCubierta);
    // static CanchaTenis* crearCanchaTenis(string codigo, string nombre, int capacidad, double precioHora, string tipoPiso);
    // static Piscina* crearPiscina(string codigo, string nombre, int capacidad, double precioHora, bool tieneClimatizacion);
    // static SalasEntrenamiento* crearSalaMultiuso(string codigo, string nombre, int capacidad, double precioHora, bool tieneProyector);
};