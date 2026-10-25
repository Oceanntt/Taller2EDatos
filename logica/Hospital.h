
#pragma once
#include <string>
#include "Cola.h"
#include "ListaDepartamentos.h"
#include "ArbolDecision.h"
using namespace std;

class Hospital {
private:
    Cola colaEspera;
    ListaDepartamentos departamentos;
    ArbolDecision arbolDecision;

public:
    Hospital();

    bool cargarPacientes(string nombreArchivo);

    void mostrarEnEspera() const;
    int getPacientesEnEspera() const;

    void atenderPacientes(int cantidad);
    void mostrarDepartamentos() const;

    void buscarPaciente(string dato) const;
    void mostrarEstadoServicio(string nombre) const;
};
