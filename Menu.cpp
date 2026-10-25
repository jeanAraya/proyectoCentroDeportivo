#include "Menu.h"

#include "Factory.h"

using namespace std;

Menu::Menu() {
}

void Menu::mostrarMenu() {
    int opcion;
    do {
        cout << "\n*****************************\n CENTRO DEPORTIVO MULTIUSO \n*****************************" << endl;
        cout << "1. Registrar cliente" << endl;
        cout << "2. Listar clientes" << endl;
        cout << "3. Registrar espacio" << endl;
        cout << "4. Listar espacios" << endl;
        cout << "5. Registrar reserva" << endl;
        cout << "6. Cancelar reserva" << endl;
        cout << "7. Mostrar reservas" << endl;
        cout << "8. Guardar datos" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarCliente();
                break;

            case 2:
                GestorSistema::getInstancia().mostrarClientes();
                break;

            case 3:
                registrarEspacio();
                break;

            case 4:
                GestorSistema::getInstancia().mostrarEspacios();
                break;

            case 5:
                registrarReserva();
                break;

            case 6:
                cancelarReserva();
                break;

            case 7:
                GestorSistema::getInstancia().mostrarReservas();
                break;


            case 8:
                // if (validarGuardado()){
                GestorSistema::getInstancia().guardar("clientes.csv");
                GestorSistema::getInstancia().guardar("espacios.csv");
                GestorSistema::getInstancia().guardar("reservas.csv");
                // }
                break;
            case 0:
                cout << "Saliendo..." << endl;
                break;

            default:
                cout << "Opcion invalida. Intente de nuevo" << endl;
        }
    } while (opcion != 0);
}

void Menu::registrarCliente() {
    string id;
    string nombre;
    string telefono;
    string correo;
    cout<<"------ Registrar cliente ------"<<endl;
    cout<<"Ingrese la identificacion del cliente: ";
    cin >> id;
    cout<<"Ingrese el nombre del cliente: ";
    cin >> nombre;
    cout<<"Ingrese el telefono del cliente: ";
    cin >> telefono;
    cout<<"Ingrese el correo del cliente: ";
    cin >> correo;
    if (!GestorSistema::getInstancia().registrarCliente(Factory::crearCliente(id, nombre, telefono, correo))) {
        cout << "El cliente con identificacion " << id << " ya existe." << endl;
    }
}

void Menu::registrarReserva() {
    string codReserva;
    string idCliente;
    string codEspacio;
    string fecha;
    int hora;
    cout<<"------ Registrar reserva ------"<<endl;
    cout << "Ingrese el codigo de la reserva: ";
    cin >> codReserva;
    cout << "Ingrese la identificacion del cliente: ";
    cin >> idCliente;
    cout << "Ingrese el codigo del espacio: ";
    cin >> codEspacio;
    cout << "Ingrese la fecha de la reserva: ";
    cin >> fecha;
    cout << "Ingrese la hora de la reserva: ";
    cin >> hora;
    GestorSistema::getInstancia().registrarReserva(Factory::crearReserva(codReserva, idCliente, codEspacio, fecha, hora));
}

void Menu::registrarEspacio() {
    string tipo;
    int opc;
    string codigo;
    string nombre;
    string extra;
    int capacidad;
    double precioHora;
    cout<<"------ Registrar espacio ------"<<endl;
    cout << "Ingrese el codigo del espacio: ";
    cin >> codigo;
    cout << "Seleccione el tipo de espacio: "<<endl;
    cout << "1. Futbol" << endl;
    cout << "2. Baloncesto" << endl;
    cout << "3. Tenis" << endl;
    cout << "4. Piscina" << endl;
    cout << "5. Sala" << endl;
    cin >> opc;
    switch (opc) {
        case 1:
            tipo = "FUTBOL";
            extra = extraFutbol();
            break;
        case 2:
            tipo = "BALONCESTO";
            extra = extraBaloncesto();
            break;
        case 3:
            tipo = "TENIS";
            extra = extraTenis();
            break;
        case 4:
            tipo = "PISCINA";
            extra = extraPiscina();
            break;
        case 5:
            tipo = "SALA";
            extra = extraSalaEntreno();
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo" << endl;
            return;
    }
    cout << "Ingrese el nombre del espacio: ";
    cin >> nombre;
    cout << "Ingrese la capacidad del espacio: ";
    cin >> capacidad;
    cout << "Ingrese el precio por hora del espacio: ";
    cin >> precioHora;
    GestorSistema::getInstancia().registrarEspacio(Factory::crearEspacio(tipo, codigo, nombre, capacidad, precioHora, extra));
}

string Menu::extraFutbol(){
    string superficie;
    cout << "Ingrese el tipo de superficie del campo de futbol: ";
    cin >> superficie;
    return superficie;
}

string Menu::extraBaloncesto(){
    string esCubierta;
    cout << "¿La cancha de baloncesto es cubierta?: " << endl;
    cout << "1. Si" << endl;
    cout << "2. No" << endl;
    int opc = 3;
    while(opc == 3){
        cin >> opc;
        if (opc == 1) {
            esCubierta = "1";
        }
        if (opc == 2) {
            esCubierta = "0";
        }else{
            cout << "Opcion invalida. Intente de nuevo" << endl;
            opc = 3;
        }
    }
    return esCubierta;
}

string Menu::extraTenis(){
    string piso;
    cout << "Ingrese el tipo de piso de la cancha de tenis: ";
    cin >> piso;
    return piso;
}

string Menu::extraPiscina(){
        string climatizada;
        cout << "¿La piscina es climatizada?: ";
        cout << "1. Si" << endl;
        cout << "2. No" << endl;
        int opc = 3;
        while(opc == 3){
            cin >> opc;
            if (opc == 1) {
                climatizada = "1";
            }
            if (opc == 2) {
                climatizada = "0";
            }else{
                cout << "Opcion invalida. Intente de nuevo" << endl;
                opc = 3;
            }
        }
        return climatizada;
    }

string Menu::extraSalaEntreno(){
    string proyector;
    cout << "¿La sala de entrenamiento tiene proyector?: ";
    cout << "1. Si" << endl;
    cout << "2. No" << endl;
    int opc = 3;
    while(opc == 3){
        cin >> opc;
        if (opc == 1) {
            proyector = "1";
        }
        if (opc == 2) {
            proyector = "0";
        }else{
            cout << "Opcion invalida. Intente de nuevo" << endl;
            opc = 3;
        }
    }
    return proyector;
}

void Menu::cancelarReserva() {
    string cod;
    cout<<"------ Cancelar reserva ------"<<endl;
    cout << "Ingrese el codigo de la reserva: ";
    cin >> cod;

    if (!GestorSistema::getInstancia().cancelarReserva(cod)) {
        cout << "No se encontro la reserva." << endl;
        return;
    }
    cout << "Reserva cancelada exitosamente." << endl;
}

bool Menu::validarGuardado() {
    return true;
}
