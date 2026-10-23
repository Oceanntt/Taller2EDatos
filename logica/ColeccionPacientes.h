#pragma once
#include <string>
#include "Paciente.h"



struct NodoPaciente {
    Paciente* paciente;
    NodoPaciente* siguiente;

    NodoPaciente(Paciente* p) {
        paciente = p;
        siguiente = nullptr;
    }
};

class ColeccionPacientes {
protected:
    NodoPaciente* primero;
    int cantidad;

public:
    ColeccionPacientes();
    virtual ~ColeccionPacientes();

    bool estaVacia() const;
    int getCantidad() const;
    Paciente* buscarPorId(std::string id) const;

    virtual void mostrar() const = 0;
};