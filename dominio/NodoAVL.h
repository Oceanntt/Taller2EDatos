
#pragma once
#include "Paciente.h"

struct NodoAVL {
    Paciente* paciente;
    NodoAVL* izquierdo;
    NodoAVL* derecho;
    int altura;

    NodoAVL(Paciente* p) {
        paciente = p;
        izquierdo = nullptr;
        derecho = nullptr;
        altura = 1;
    }
};
