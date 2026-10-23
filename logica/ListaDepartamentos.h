#pragma once
#include <string>
#include "Departamento.h"

struct NodoServicio {
    Servicio* servicio;
    NodoServicio* siguiente;

    NodoServicio(Servicio* s) {
        servicio = s;
        siguiente = nullptr;
    }
};

class ListaServicios {
private:
    NodoServicio* primero;
    int cantidad;

public:
    ListaServicios();
    ~ListaServicios();

    void insertar(Servicio* s);
    void cargarServiciosFijos();
    Servicio* buscarPorNombre(std::string nombre) const;
    Servicio* buscarPorPosicion(int posicion) const;
    Paciente* buscarPacienteEnServicios(std::string id) const;
    int getCantidad() const;
    void mostrarNombres() const;
};