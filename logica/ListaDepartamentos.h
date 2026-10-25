
#pragma once
#include "../dominio/Departamento.h"
#include <string>
using namespace std;

class ListaDepartamentos {
private:
    Departamento* departamentos[8];
    int cantidad;

public:
    ListaDepartamentos();
    ~ListaDepartamentos();

    Departamento* buscarDepartamento(string nombre) const;

    bool agregarPaciente(string servicio, Paciente* p);

    Paciente* buscarPorId(string id) const;
    Paciente* buscarPorNombre(string nombre) const;

    void mostrarDepartamentos() const;

    ListaDepartamentos(const ListaDepartamentos&) = delete;
    ListaDepartamentos& operator=(const ListaDepartamentos&) = delete;
    Paciente* buscarPorIdConRuta(string id) const;
};
