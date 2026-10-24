
#include "ArbolDecision.h"
#include <iostream>
using namespace std;

ArbolDecision::ArbolDecision() {
    raiz = nullptr;
    construir();
}

ArbolDecision::~ArbolDecision() {
    liberar(raiz);
}

void ArbolDecision::liberar(NodoDecision* nodo) {
    if (nodo == nullptr) {
        return;
    }

    liberar(nodo->si);
    liberar(nodo->no);
    delete nodo;
}

void ArbolDecision::construir() {
    liberar(raiz);

    raiz = new NodoDecision(1);

    raiz->si = new NodoDecision("Pediatria");
    raiz->no = new NodoDecision(2);

    NodoDecision* trauma = raiz->no;

    trauma->si = new NodoDecision(3);
    trauma->si->si = new NodoDecision("Cirugia");
    trauma->si->no = new NodoDecision("Traumatologia");

    trauma->no = new NodoDecision(4);

    NodoDecision* neurologia = trauma->no;
    neurologia->si = new NodoDecision("Neurologia");
    neurologia->no = new NodoDecision(5);

    NodoDecision* pecho = neurologia->no;
    pecho->si = new NodoDecision("Cardiologia");
    pecho->no = new NodoDecision(6);

    NodoDecision* urgencias = pecho->no;
    urgencias->si = new NodoDecision("Urgencias");
    urgencias->no = new NodoDecision(7);

    NodoDecision* hospitalizacion = urgencias->no;
    hospitalizacion->si = new NodoDecision("Hospitalizacion");
    hospitalizacion->no = new NodoDecision("Medicina General");
}

bool ArbolDecision::evaluarCondicion(int tipo, const Paciente* p) const {
    switch (tipo) {
        case 1:
            return p->getEdad() < 14;
        case 2:
            return p->getTrauma();
        case 3:
            return p->getRequiereCirugia();
        case 4:
            return p->getSintomasNeurologicos();
        case 5:
            return p->getTipoDolor() == "pecho";
        case 6:
            return p->getTemperatura() >= 38.5 ||
                   p->getDolor() >= 8;
        case 7:
            return p->getDiasHospitalizacion() >= 2;
        default:
            return false;
    }
}

string ArbolDecision::clasificar(const Paciente* p) const {
    if (p == nullptr) {
        return "Error";
    }

    NodoDecision* actual = raiz;

    while (actual != nullptr) {
        if (actual->tipo == 0) {
            return actual->servicio;
        }

        if (evaluarCondicion(actual->tipo, p)) {
            actual = actual->si;
        } else {
            actual = actual->no;
        }
    }

    return "Error";
}

void ArbolDecision::mostrarPreorden(NodoDecision* nodo) const {
    if (nodo == nullptr) return;

    if (nodo->tipo == 0)
        cout << nodo->servicio << endl;
    else
        cout << "Decision " << nodo->tipo << endl;

    mostrarPreorden(nodo->si);
    mostrarPreorden(nodo->no);
}

void ArbolDecision::mostrarInorden(NodoDecision* nodo) const {
    if (nodo == nullptr) return;

    mostrarInorden(nodo->si);

    if (nodo->tipo == 0)
        cout << nodo->servicio << endl;
    else
        cout << "Decision " << nodo->tipo << endl;

    mostrarInorden(nodo->no);
}

void ArbolDecision::mostrarPostorden(NodoDecision* nodo) const {
    if (nodo == nullptr) return;

    mostrarPostorden(nodo->si);
    mostrarPostorden(nodo->no);

    if (nodo->tipo == 0)
        cout << nodo->servicio << endl;
    else
        cout << "Decision " << nodo->tipo << endl;
}

void ArbolDecision::preorden() const {
    mostrarPreorden(raiz);
}

void ArbolDecision::inorden() const {
    mostrarInorden(raiz);
}

void ArbolDecision::postorden() const {
    mostrarPostorden(raiz);
}
