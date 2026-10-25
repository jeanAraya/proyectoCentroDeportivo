#include <string>
using namespace std;
class GuardadorDatos {
    static void guardarClientes(string salida);
    static void guardarEspacios(string salida);
    static void guardarReservas(string salida);
public:
    static void guardar(std::string salida);
};
