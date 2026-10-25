
#include "ListaDepartamentos.h"
#include <iostream>
using namespace std;

ListaDepartamentos::ListaDepartamentos() {
    cantidad = 8;

    departamentos[0] = new Departamento("Urgencias");
    departamentos[1] = new Departamento("Medicina General");
    departamentos[2] = new Departamento("Cardiologia");
    departamentos[3] = new Departamento("Neurologia");
    departamentos[4] = new Departamento("Traumatologia");
    departamentos[5] = new Departamento("Cirugia");
    departamentos[6] = new Departamento("Pediatria");
    departamentos[7] = new Departamento("Hospitalizacion");
}

ListaDepartamentos::~ListaDepartamentos() {
    for (int i = 0; i < cantidad; i++) {
        delete departamentos[i];
    }
}

Departamento* ListaDepartamentos::buscarDepartamento(string nombre) const {
    for (int i = 0; i < cantidad; i++) {
        if (departamentos[i]->getNombre() == nombre) {
            return departamentos[i];
        }
    }

    return nullptr;
}

bool ListaDepartamentos::agregarPaciente(string servicio, Paciente* p) {
    if (p == nullptr) {
        return false;
    }

    Departamento* departamento = buscarDepartamento(servicio);

    if (departamento == nullptr) {
        return false;
    }

    if (buscarPorId(p->getId()) != nullptr) {
        return false;
    }

    departamento->agregarPaciente(p);
    return true;
}

Paciente* ListaDepartamentos::buscarPorId(string id) const {
    for (int i = 0; i < cantidad; i++) {
        Paciente* encontrado = departamentos[i]->buscarPorId(id);

        if (encontrado != nullptr) {
            return encontrado;
        }
    }

    return nullptr;
}

Paciente* ListaDepartamentos::buscarPorNombre(string nombre) const {
    for (int i = 0; i < cantidad; i++) {
        Paciente* encontrado = departamentos[i]->buscarPorNombre(nombre);

        if (encontrado != nullptr) {
            return encontrado;
        }
    }

    return nullptr;
}

void ListaDepartamentos::mostrarDepartamentos() const {
    cout << "=== ESTADO DE LOS DEPARTAMENTOS ===" << endl;

    for (int i = 0; i < cantidad; i++) {
        departamentos[i]->mostrarPacientes();
        cout << endl;
    }
}
