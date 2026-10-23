#include "Hospital.h"
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

Hospital::Hospital() {
    servicios.cargarServiciosFijos();
}

bool Hospital::cargarPacientes(string nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "Error: no se pudo abrir el archivo " << nombreArchivo << endl;
        return false;
    }

    string linea;
    int numeroLinea = 0;
    int cargados = 0;

    while (getline(archivo, linea)) {
        numeroLinea++;

        if (!linea.empty() && linea.back() == '\r') {
            linea.pop_back();
        }
        if (linea.empty()) {
            continue;
        }

        stringstream ss(linea);
        string id, nombre, edadTexto, servicio, sobrante;

        if (!getline(ss, id, ';') || !getline(ss, nombre, ';') ||
            !getline(ss, edadTexto, ';') || !getline(ss, servicio, ';') ||
            getline(ss, sobrante, ';')) {
            cout << "Linea " << numeroLinea << " invalida (cantidad de campos)." << endl;
            continue;
        }

        if (id.empty() || nombre.empty() || edadTexto.empty() || servicio.empty()) {
            cout << "Linea " << numeroLinea << " invalida (campo vacio)." << endl;
            continue;
        }

        int edad;
        try {
            edad = stoi(edadTexto);
        } catch (...) {
            cout << "Linea " << numeroLinea << " invalida (edad no numerica)." << endl;
            continue;
        }
        if (edad < 0 || edad > 120) {
            cout << "Linea " << numeroLinea << " invalida (edad fuera de rango)." << endl;
            continue;
        }

        Servicio* destino = servicios.buscarPorNombre(servicio);
        if (destino == nullptr) {
            cout << "Linea " << numeroLinea << " invalida (servicio no existe: " << servicio << ")." << endl;
            continue;
        }

        if (colaEspera.buscarPorId(id) != nullptr ||
            servicios.buscarPacienteEnServicios(id) != nullptr) {
            cout << "Linea " << numeroLinea << " invalida (ID duplicado: " << id << ")." << endl;
            continue;
        }

        // Se guarda el nombre oficial del servicio (con la escritura correcta)
        colaEspera.encolar(new Paciente(id, nombre, edad, destino->getNombre()));
        cargados++;
    }

    archivo.close();
    cout << "Pacientes cargados: " << cargados << endl;
    return true;
}

void Hospital::mostrarEnEspera() const {
    colaEspera.mostrar();
}

int Hospital::getPacientesEnEspera() const {
    return colaEspera.getCantidad();
}

int Hospital::getCantidadServicios() const {
    return servicios.getCantidad();
}

void Hospital::atenderPacientes(int cantidad) {
    cout << "\n=== ATENDIENDO PACIENTES ===" << endl;
    for (int i = 0; i < cantidad; i++) {
        Paciente* p = colaEspera.desencolar();
        if (p == nullptr) {
            cout << "No quedan mas pacientes en espera." << endl;
            break;
        }

        Servicio* destino = servicios.buscarPorNombre(p->getServicio());
        if (destino == nullptr) {
            cout << "Servicio no valido para " << p->getNombre() << "." << endl;
            delete p;
            continue;
        }

        p->mostrar();
        destino->agregarPaciente(p);
        historial.agregar(p->getId(), p->getNombre(), p->getEdad(), destino->getNombre());
        cout << "Paciente enviado a " << destino->getNombre() << ".\n" << endl;
    }
}

void Hospital::mostrarDepartamentos() const {
    servicios.mostrarNombres();
}

void Hospital::mostrarEstadoServicio(int posicion) const {
    Servicio* s = servicios.buscarPorPosicion(posicion);
    if (s == nullptr) {
        cout << "Departamento no valido." << endl;
        return;
    }
    s->mostrarEstado();
}

void Hospital::mostrarHistorial() const {
    cout << "=== HISTORIAL DE ULTIMAS ATENCIONES DEL HOSPITAL ===" << endl;
    historial.mostrar();
}