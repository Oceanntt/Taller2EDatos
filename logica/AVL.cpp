
#include "AVL.h"
#include <iostream>
using namespace std;

AVL::AVL() {
    raiz = nullptr;
}

AVL::~AVL() {
    liberar(raiz);
}

int AVL::maximo(int a, int b) const {
    return (a > b) ? a : b;
}

int AVL::obtenerAltura(NodoAVL* nodo) const {
    if (nodo == nullptr) {
        return 0;
    }
    return nodo->altura;
}

int AVL::obtenerBalance(NodoAVL* nodo) const {
    if (nodo == nullptr) {
        return 0;
    }

    return obtenerAltura(nodo->izquierdo)
         - obtenerAltura(nodo->derecho);
}

NodoAVL* AVL::rotacionDerecha(NodoAVL* y) {
    NodoAVL* x = y->izquierdo;
    NodoAVL* temporal = x->derecho;

    x->derecho = y;
    y->izquierdo = temporal;

    y->altura = 1 + maximo(
        obtenerAltura(y->izquierdo),
        obtenerAltura(y->derecho)
    );

    x->altura = 1 + maximo(
        obtenerAltura(x->izquierdo),
        obtenerAltura(x->derecho)
    );

    return x;
}

NodoAVL* AVL::rotacionIzquierda(NodoAVL* x) {
    NodoAVL* y = x->derecho;
    NodoAVL* temporal = y->izquierdo;

    y->izquierdo = x;
    x->derecho = temporal;

    x->altura = 1 + maximo(
        obtenerAltura(x->izquierdo),
        obtenerAltura(x->derecho)
    );

    y->altura = 1 + maximo(
        obtenerAltura(y->izquierdo),
        obtenerAltura(y->derecho)
    );

    return y;
}

NodoAVL* AVL::insertarNodo(NodoAVL* nodo, Paciente* p) {
    if (nodo == nullptr) {
        return new NodoAVL(p);
    }

    if (p->getId() < nodo->paciente->getId()) {
        nodo->izquierdo = insertarNodo(nodo->izquierdo, p);
    }
    else if (p->getId() > nodo->paciente->getId()) {
        nodo->derecho = insertarNodo(nodo->derecho, p);
    }
    else {
        return nodo;
    }

    nodo->altura = 1 + maximo(
        obtenerAltura(nodo->izquierdo),
        obtenerAltura(nodo->derecho)
    );

    int balance = obtenerBalance(nodo);

    // Caso izquierda-izquierda
    if (balance > 1 &&
        p->getId() < nodo->izquierdo->paciente->getId()) {
        return rotacionDerecha(nodo);
    }

    // Caso derecha-derecha
    if (balance < -1 &&
        p->getId() > nodo->derecho->paciente->getId()) {
        return rotacionIzquierda(nodo);
    }

    // Caso izquierda-derecha
    if (balance > 1 &&
        p->getId() > nodo->izquierdo->paciente->getId()) {
        nodo->izquierdo = rotacionIzquierda(nodo->izquierdo);
        return rotacionDerecha(nodo);
    }

    // Caso derecha-izquierda
    if (balance < -1 &&
        p->getId() < nodo->derecho->paciente->getId()) {
        nodo->derecho = rotacionDerecha(nodo->derecho);
        return rotacionIzquierda(nodo);
    }

    return nodo;
}

void AVL::insertar(Paciente* p) {
    if (p == nullptr) {
        return;
    }

    raiz = insertarNodo(raiz, p);
}

Paciente* AVL::buscarId(NodoAVL* nodo, string id) const {
    if (nodo == nullptr) {
        return nullptr;
    }

    if (id == nodo->paciente->getId()) {
        return nodo->paciente;
    }

    if (id < nodo->paciente->getId()) {
        return buscarId(nodo->izquierdo, id);
    }

    return buscarId(nodo->derecho, id);
}

Paciente* AVL::buscarPorId(string id) const {
    return buscarId(raiz, id);
}

Paciente* AVL::buscarNombre(NodoAVL* nodo, string nombre) const {
    if (nodo == nullptr) {
        return nullptr;
    }

    if (nodo->paciente->getNombre() == nombre) {
        return nodo->paciente;
    }

    Paciente* encontrado = buscarNombre(nodo->izquierdo, nombre);

    if (encontrado != nullptr) {
        return encontrado;
    }

    return buscarNombre(nodo->derecho, nombre);
}

Paciente* AVL::buscarPorNombre(string nombre) const {
    return buscarNombre(raiz, nombre);
}

void AVL::mostrarInorden(NodoAVL* nodo) const {
    if (nodo == nullptr) return;

    mostrarInorden(nodo->izquierdo);
    nodo->paciente->mostrar();
    mostrarInorden(nodo->derecho);
}

void AVL::mostrarPreorden(NodoAVL* nodo) const {
    if (nodo == nullptr) return;

    nodo->paciente->mostrar();
    mostrarPreorden(nodo->izquierdo);
    mostrarPreorden(nodo->derecho);
}

void AVL::mostrarPostorden(NodoAVL* nodo) const {
    if (nodo == nullptr) return;

    mostrarPostorden(nodo->izquierdo);
    mostrarPostorden(nodo->derecho);
    nodo->paciente->mostrar();
}

void AVL::inorden() const {
    mostrarInorden(raiz);
}

void AVL::preorden() const {
    mostrarPreorden(raiz);
}

void AVL::postorden() const {
    mostrarPostorden(raiz);
}

void AVL::mostrarBalance(NodoAVL* nodo) const {
    if (nodo == nullptr) return;

    mostrarBalance(nodo->izquierdo);

    cout << "ID: " << nodo->paciente->getId()
         << " - Factor de balance: "
         << obtenerBalance(nodo) << endl;

    mostrarBalance(nodo->derecho);
}

void AVL::mostrarFactoresBalance() const {
    mostrarBalance(raiz);
}

int AVL::altura() const {
    return obtenerAltura(raiz);
}

bool AVL::estaVacio() const {
    return raiz == nullptr;
}

void AVL::liberar(NodoAVL* nodo) {
    if (nodo == nullptr) return;

    liberar(nodo->izquierdo);
    liberar(nodo->derecho);

    delete nodo->paciente;
    delete nodo;
}
