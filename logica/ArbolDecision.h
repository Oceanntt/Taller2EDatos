
#pragma once
#include "../dominio/NodoDecision.h"
#include "../dominio/Paciente.h"
#include <string>
using namespace std;

class ArbolDecision {
private:
    NodoDecision* raiz;

    bool evaluarCondicion(int tipo, const Paciente* p) const;
    void liberar(NodoDecision* nodo);
    void mostrarPreorden(NodoDecision* nodo) const;
    void mostrarInorden(NodoDecision* nodo) const;
    void mostrarPostorden(NodoDecision* nodo) const;

public:
    ArbolDecision();
    ~ArbolDecision();

    void construir();
    string clasificar(const Paciente* p) const;

    void preorden() const;
    void inorden() const;
    void postorden() const;

    ArbolDecision(const ArbolDecision&) = delete;
    ArbolDecision& operator=(const ArbolDecision&) = delete;
    string clasificarConRuta(const Paciente* paciente) const;
};
