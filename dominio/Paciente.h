#pragma once
#include <string>
using namespace std;

class Paciente {
private:
    string id;
    string nombre;
    int edad;
    string servicio;

public:
    Paciente(string id, string nombre, int edad, string servicio);

    string getId() const;
    string getNombre() const;
    int getEdad() const;
    string getServicio() const;

    void mostrar() const;
};
