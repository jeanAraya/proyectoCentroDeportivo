//
// Created by juand on 24/10/2026.
//

#include "MenuEspacios.h"
#include "Factory.h"
#include "GestorSistema.h"
void MenuEspacios::gestionEspacios() {
    int opc;
    cout << "--------------------------------------------" << endl;
    cout << "             Gestionar Espacios             " << endl;
    cout << "--------------------------------------------" << endl;
    cout << "1. Registrar espacio" << endl;
    cout << "2. Mostrar espacios ocupados" << endl;
    cout << "3. Mostrar espacios disponibles" << endl;
    cout << "4. Buscar espacio" << endl;
    cout << "5. Listar todos los espacios" << endl;
    cout << "0. Volver al menu principal" << endl;
    cout << "Ingrese una opcion: ";
    cin >> opc;
    switch (opc) {
        case 1:
            registrarEspacio();
            break;
        case 2:
            mostrarEspaciosOcupados();
            break;
        case 3:
            mostrarEspaciosDisponibles();
            break;
        case 4:
            buscarEspacio();
            break;
        case 5:
            GestorSistema::getInstancia().mostrarEspacios();
            break;
        case 0:
            break;
        default:
            cout << "Opcion invalida. Intente de nuevo" << endl;
    }
}

void MenuEspacios::registrarEspacio() {
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
    std::cin >> opc;
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

void MenuEspacios::mostrarEspaciosOcupados() {
}

void MenuEspacios::mostrarEspaciosDisponibles() {
}

void MenuEspacios::buscarEspacio() {
}

string MenuEspacios::extraFutbol(){
    string superficie;
    cout << "Ingrese el tipo de superficie del campo de futbol: ";
    cin >> superficie;
    return superficie;
}

string MenuEspacios::extraBaloncesto(){
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

string MenuEspacios::extraTenis(){
    string piso;
    cout << "Ingrese el tipo de piso de la cancha de tenis: ";
    cin >> piso;
    return piso;
}

string MenuEspacios::extraPiscina(){
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

string MenuEspacios::extraSalaEntreno(){
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

void MenuEspacios::mostrarMenu() {
    gestionEspacios();
}
