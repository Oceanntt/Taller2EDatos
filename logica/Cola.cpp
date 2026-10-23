#include "Cola.h"
#include <iostream>
using namespace std;

Cola::Cola() {
    ultimo = nullptr;
}

void Cola::encolar(Paciente* p) {
    NodoPaciente* nuevo = new NodoPaciente(p);
    if (estaVacia()) {
        primero = nuevo;
        ultimo = nuevo;
    } else {
        ultimo->siguiente = nuevo;
        ultimo = nuevo;
    }
    cantidad++;
}

Paciente* Cola::desencolar() {
    if (estaVacia()) {
        return nullptr;
    }
    NodoPaciente* nodo = primero;
    Paciente* p = nodo->paciente;
    primero = primero->siguiente;
    if (primero == nullptr) {
        ultimo = nullptr;
    }
    delete nodo;
    cantidad--;
    return p;
}

void Cola::mostrar() const {
    cout << "=== PACIENTES EN ESPERA ===" << endl;
    if (estaVacia()) {
        cout << "No hay pacientes en espera." << endl;
        return;
    }
    NodoPaciente* actual = primero;
    int numero = 1;
    while (actual != nullptr) {
        cout << numero << ". " << actual->paciente->getId()
             << " - " << actual->paciente->getNombre() << endl;
        actual = actual->siguiente;
        numero++;
    }
}