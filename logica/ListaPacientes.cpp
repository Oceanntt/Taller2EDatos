#include "ListaPacientes.h"
#include <iostream>
using namespace std;

void ListaPacientes::insertar(Paciente* p) {
    NodoPaciente* nuevo = new NodoPaciente(p);
    if (estaVacia()) {
        primero = nuevo;
    } else {
        NodoPaciente* actual = primero;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }
    cantidad++;
}

void ListaPacientes::mostrar() const {
    if (estaVacia()) {
        cout << "No hay pacientes en este departamento." << endl;
        return;
    }
    NodoPaciente* actual = primero;
    while (actual != nullptr) {
        cout << actual->paciente->getNombre()
             << " (" << actual->paciente->getEdad() << ")" << endl;
        actual = actual->siguiente;
    }
}