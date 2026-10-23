#pragma once
#include <string>
#include "ListaPacientes.h"

class Servicio {
private:
    std::string nombre;
    ListaPacientes pacientes;

public:
    Servicio(std::string nombre);

    std::string getNombre() const;
    int getCantidad() const;
    void agregarPaciente(Paciente* p);
    Paciente* buscarPaciente(std::string id) const;
    void mostrarEstado() const;
};