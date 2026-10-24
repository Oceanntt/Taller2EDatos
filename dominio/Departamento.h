
#pragma once
#include <string>
#include "../logica/AVL.h"
using namespace std;

class Departamento {
private:
    string nombre;
    AVL pacientes;

public:
    Departamento(string nombre);

    string getNombre() const;

    void agregarPaciente(Paciente* p);
    Paciente* buscarPorId(string id) const;
    Paciente* buscarPorNombre(string nombre) const;

    void mostrarPacientes() const;
    void mostrarPreorden() const;
    void mostrarPostorden() const;
    void mostrarBalance() const;
    void mostrarAltura() const;
};
