#include "Hospital.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

Hospital::Hospital() {
    servicios.cargarServiciosFijos();
}


bool Hospital::cargarPacientes(string nombreArchivo) {
    ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cout << "Error: no se pudo abrir el archivo "
             << nombreArchivo << endl;
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
        string campos[11];
        bool valido = true;

        for (int i = 0; i < 11; i++) {
            if (!getline(ss, campos[i], ';') || campos[i].empty()) {
                valido = false;
                break;
            }
        }

        string sobrante;
        if (getline(ss, sobrante, ';')) {
            valido = false;
        }

        if (!valido) {
            cout << "Linea " << numeroLinea
                 << " invalida (cantidad de campos)." << endl;
            continue;
        }

        try {
            string id = campos[0];
            string nombre = campos[1];

            auto convertirEntero = [](const string& texto) {
                size_t posicion = 0;
                int valor = stoi(texto, &posicion);
                if (posicion != texto.size()) {
                    throw invalid_argument("Entero invalido");
                }
                return valor;
            };

            auto convertirDecimal = [](const string& texto) {
                size_t posicion = 0;
                double valor = stod(texto, &posicion);
                if (posicion != texto.size() || !isfinite(valor)) {
                    throw invalid_argument("Decimal invalido");
                }
                return valor;
            };

            int edad = convertirEntero(campos[2]);
            double temperatura = convertirDecimal(campos[3]);
            int presion = convertirEntero(campos[4]);
            int dolor = convertirEntero(campos[5]);
            string tipoDolor = campos[6];
            int trauma = convertirEntero(campos[7]);
            int sintomas = convertirEntero(campos[8]);
            int cirugia = convertirEntero(campos[9]);
            int dias = convertirEntero(campos[10]);

            if (edad < 0 || edad > 120 ||
                temperatura < 30 || temperatura > 45 ||
                presion <= 0 || presion > 300 ||
                dolor < 0 || dolor > 10 ||
                dias < 0 ||
                (trauma != 0 && trauma != 1) ||
                (sintomas != 0 && sintomas != 1) ||
                (cirugia != 0 && cirugia != 1) ||
                (tipoDolor != "pecho" &&
                 tipoDolor != "cabeza" &&
                 tipoDolor != "abdomen" &&
                 tipoDolor != "extremidad" &&
                 tipoDolor != "otro")) {

                cout << "Linea " << numeroLinea
                     << " invalida (valores fuera de rango)."
                     << endl;
                continue;
            }

            if (colaEspera.buscarPorId(id) != nullptr ||
                servicios.buscarPacienteEnServicios(id) != nullptr) {

                cout << "Linea " << numeroLinea
                     << " invalida (ID duplicado: "
                     << id << ")." << endl;
                continue;
            }

            Paciente* nuevo = new Paciente(
                id, nombre, edad, temperatura, presion,
                dolor, tipoDolor, trauma == 1,
                sintomas == 1, cirugia == 1, dias
            );

            colaEspera.encolar(nuevo);
            cargados++;

        } catch (const exception&) {
            cout << "Linea " << numeroLinea
                 << " invalida (dato numerico incorrecto)."
                 << endl;
        }
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