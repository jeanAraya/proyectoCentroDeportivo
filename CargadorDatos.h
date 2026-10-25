#include <iostream>
using namespace std;
class CargadorDatos {
    void static leerClientes(string archivo, char delim);
    void static leerEspacios(string archivo, char delim);
    void static leerReservas(string archivo, char delim);
public:
    void static leer(string entrada);

};