#pragma once
#include <string>

struct NodoHistorial {
    std::string id;
    std::string nombre;
    int edad;
    std::string departamento;
    NodoHistorial* siguiente;

    NodoHistorial(std::string id, std::string nombre, int edad, std::string departamento) {
        this->id = id;
        this->nombre = nombre;
        this->edad = edad;
        this->departamento = departamento;
        siguiente = nullptr;
    }
};

class Pila {
private:
    NodoHistorial* tope;
    int cantidad;

public:
    Pila();
    ~Pila();

    void agregar(std::string id, std::string nombre, int edad, std::string departamento);
    bool estaVacia() const;
    int getCantidad() const;
    void mostrar() const;
};