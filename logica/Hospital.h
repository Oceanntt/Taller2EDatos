#pragma once
#include <string>
#include "Cola.h"
#include "ListaDepartamentos.h"
#include "Pila.h"

class Hospital {
private:
    Cola colaEspera;
    ListaServicios servicios;
    Pila historial;

public:
    Hospital();

    bool cargarPacientes(std::string nombreArchivo);
    void mostrarEnEspera() const;
    int getPacientesEnEspera() const;
    int getCantidadServicios() const;
    void atenderPacientes(int cantidad);
    void mostrarDepartamentos() const;
    void mostrarEstadoServicio(int posicion) const;
    void mostrarHistorial() const;
};