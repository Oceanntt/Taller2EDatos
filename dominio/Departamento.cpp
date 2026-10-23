#include "Departamento.h"
#include <iostream>
using namespace std;

Servicio::Servicio(string nombre) {
    this->nombre = nombre;
}

string Servicio::getNombre() const {
    return nombre;
}

int Servicio::getCantidad() const {
    return pacientes.getCantidad();
}

void Servicio::agregarPaciente(Paciente* p) {
    pacientes.insertar(p);
}

Paciente* Servicio::buscarPaciente(string id) const {
    return pacientes.buscarPorId(id);
}

void Servicio::mostrarEstado() const {
    cout << "=== ESTADO " << nombre << " ===" << endl;
    cout << "Pacientes en el departamento de " << nombre << ": "
         << pacientes.getCantidad() << endl;
    pacientes.mostrar();
}