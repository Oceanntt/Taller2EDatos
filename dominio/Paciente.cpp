#include "Paciente.h"
#include <iostream>
using namespace std;

Paciente::Paciente(string id, string nombre, int edad, string servicio) {
    this->id = id;
    this->nombre = nombre;
    this->edad = edad;
    this->servicio = servicio;
}

string Paciente::getId() const { return id; }
string Paciente::getNombre() const { return nombre; }
int Paciente::getEdad() const { return edad; }
string Paciente::getServicio() const { return servicio; }

void Paciente::mostrar() const {
    cout << "ID: " << id << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Servicio: " << servicio << endl;
}