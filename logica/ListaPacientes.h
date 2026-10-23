#pragma once
#include "ColeccionPacientes.h"

class ListaPacientes : public ColeccionPacientes {
public:
    void insertar(Paciente* p);
    void mostrar() const override;
};