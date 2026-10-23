#include "ColeccionPacientes.h"
using namespace std;

ColeccionPacientes::ColeccionPacientes() {
    primero = nullptr;
    cantidad = 0;
}

ColeccionPacientes::~ColeccionPacientes() {
    NodoPaciente* actual = primero;
    while (actual != nullptr) {
        NodoPaciente* siguiente = actual->siguiente;
        delete actual->paciente;
        delete actual;
        actual = siguiente;
    }
}

bool ColeccionPacientes::estaVacia() const {
    return primero == nullptr;
}

int ColeccionPacientes::getCantidad() const {
    return cantidad;
}

Paciente* ColeccionPacientes::buscarPorId(string id) const {
    NodoPaciente* actual = primero;
    while (actual != nullptr) {
        if (actual->paciente->getId() == id) {
            return actual->paciente;
        }
        actual = actual->siguiente;
    }
    return nullptr;
}