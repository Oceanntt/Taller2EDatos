#pragma once
#include "ColeccionPacientes.h"

class Cola : public ColeccionPacientes {
private:
    NodoPaciente* ultimo;

public:
    Cola();
    void encolar(Paciente* p);
    Paciente* desencolar();
    void mostrar() const override;
};