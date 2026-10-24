
#pragma once
#include <string>
using namespace std;

struct NodoDecision {
    int tipo;
    string servicio;
    NodoDecision* si;
    NodoDecision* no;

    NodoDecision(int tipo) {
        this->tipo = tipo;
        this->servicio = "";
        this->si = nullptr;
        this->no = nullptr;
    }

    NodoDecision(string servicio) {
        this->tipo = 0;
        this->servicio = servicio;
        this->si = nullptr;
        this->no = nullptr;
    }
};
