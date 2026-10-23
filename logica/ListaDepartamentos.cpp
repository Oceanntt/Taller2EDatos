#include "ListaDepartamentos.h"
#include <iostream>
#include <cctype>
using namespace std;

// Deja el texto en minusculas y sin tildes, para poder comparar
// "Cardiologia" con "Cardiología" o "cardiologia".
static string normalizar(string texto) {
    string resultado = "";
    for (size_t i = 0; i < texto.size(); i++) {
        unsigned char c = texto[i];
        if (c == 0xC3 && i + 1 < texto.size()) {
            unsigned char d = texto[i + 1];
            i++;
            if (d == 0xA1 || d == 0x81) resultado += 'a';
            else if (d == 0xA9 || d == 0x89) resultado += 'e';
            else if (d == 0xAD || d == 0x8D) resultado += 'i';
            else if (d == 0xB3 || d == 0x93) resultado += 'o';
            else if (d == 0xBA || d == 0x9A) resultado += 'u';
            else if (d == 0xB1 || d == 0x91) resultado += 'n';
        } else {
            resultado += tolower(c);
        }
    }
    return resultado;
}

ListaServicios::ListaServicios() {
    primero = nullptr;
    cantidad = 0;
}

ListaServicios::~ListaServicios() {
    NodoServicio* actual = primero;
    while (actual != nullptr) {
        NodoServicio* siguiente = actual->siguiente;
        delete actual->servicio;
        delete actual;
        actual = siguiente;
    }
}

void ListaServicios::insertar(Servicio* s) {
    NodoServicio* nuevo = new NodoServicio(s);
    if (primero == nullptr) {
        primero = nuevo;
    } else {
        NodoServicio* actual = primero;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }
    cantidad++;
}

void ListaServicios::cargarServiciosFijos() {
    string nombres[8] = {
        "Urgencias", "Medicina General", "Cardiologia", "Neurologia",
        "Traumatologia", "Cirugia", "Pediatria", "Hospitalizacion"
    };

    string* puntero = nombres;          // apunta al primer nombre
    for (int i = 0; i < 8; i++) {
        insertar(new Servicio(*(puntero + i)));   // *(puntero + i) = el nombre numero i
    }
}

Servicio* ListaServicios::buscarPorNombre(string nombre) const {
    string buscado = normalizar(nombre);
    NodoServicio* actual = primero;
    while (actual != nullptr) {
        if (normalizar(actual->servicio->getNombre()) == buscado) {
            return actual->servicio;
        }
        actual = actual->siguiente;
    }
    return nullptr;
}

Servicio* ListaServicios::buscarPorPosicion(int posicion) const {
    if (posicion < 1 || posicion > cantidad) {
        return nullptr;
    }
    NodoServicio* actual = primero;
    for (int i = 1; i < posicion; i++) {
        actual = actual->siguiente;
    }
    return actual->servicio;
}

Paciente* ListaServicios::buscarPacienteEnServicios(string id) const {
    NodoServicio* actual = primero;
    while (actual != nullptr) {
        Paciente* p = actual->servicio->buscarPaciente(id);
        if (p != nullptr) {
            return p;
        }
        actual = actual->siguiente;
    }
    return nullptr;
}

int ListaServicios::getCantidad() const {
    return cantidad;
}

void ListaServicios::mostrarNombres() const {
    cout << "=== DEPARTAMENTOS/SERVICIOS ===" << endl;
    NodoServicio* actual = primero;
    int numero = 1;
    while (actual != nullptr) {
        cout << numero << ". " << actual->servicio->getNombre() << endl;
        actual = actual->siguiente;
        numero++;
    }
}