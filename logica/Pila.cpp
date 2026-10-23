#include "Pila.h"
#include <iostream>
using namespace std;

Pila::Pila() {
    tope = nullptr;
    cantidad = 0;
}

Pila::~Pila() {
    NodoHistorial* actual = tope;
    while (actual != nullptr) {
        NodoHistorial* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}

void Pila::agregar(string id, string nombre, int edad, string departamento) {
    NodoHistorial* nuevo = new NodoHistorial(id, nombre, edad, departamento);
    nuevo->siguiente = tope;   // el nuevo apunta al que era el tope
    tope = nuevo;              // y pasa a ser el nuevo tope
    cantidad++;
}

bool Pila::estaVacia() const {
    return tope == nullptr;
}

int Pila::getCantidad() const {
    return cantidad;
}

void Pila::mostrar() const {
    if (estaVacia()) {
        cout << "No hay atenciones registradas." << endl;
        return;
    }
    NodoHistorial* actual = tope;
    while (actual != nullptr) {
        cout << "Nombre: " << actual->nombre
             << " | Edad: " << actual->edad
             << " | Departamento: " << actual->departamento << endl;
        actual = actual->siguiente;
    }
}