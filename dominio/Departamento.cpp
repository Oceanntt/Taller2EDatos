
#include "Departamento.h"
#include <iostream>
using namespace std;

Departamento::Departamento(string nombre) {
    this->nombre = nombre;
}

string Departamento::getNombre() const {
    return nombre;
}

void Departamento::agregarPaciente(Paciente* p) {
    pacientes.insertar(p);
}

Paciente* Departamento::buscarPorId(string id) const {
    return pacientes.buscarPorId(id);
}

Paciente* Departamento::buscarPorNombre(string nombre) const {
    return pacientes.buscarPorNombre(nombre);
}

void Departamento::mostrarPacientes() const {
    cout << "=== " << nombre << " ===" << endl;

    if (pacientes.estaVacio()) {
        cout << "Sin pacientes." << endl;
        return;
    }

    pacientes.inorden();
}

void Departamento::mostrarPreorden() const {
    pacientes.preorden();
}

void Departamento::mostrarPostorden() const {
    pacientes.postorden();
}

void Departamento::mostrarBalance() const {
    pacientes.mostrarFactoresBalance();
}

void Departamento::mostrarAltura() const {
    cout << "Altura del AVL de " << nombre
         << ": " << pacientes.altura() << endl;
}
Paciente* Departamento::buscarPorIdConRuta(string id) const {
    return pacientes.buscarPorIdConRuta(id);
}