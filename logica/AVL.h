
#pragma once
#include "../dominio/NodoAVL.h"
#include <string>
using namespace std;

class AVL {
private:
    NodoAVL* raiz;

    int obtenerAltura(NodoAVL* nodo) const;
    int obtenerBalance(NodoAVL* nodo) const;
    int maximo(int a, int b) const;

    NodoAVL* rotacionDerecha(NodoAVL* nodo);
    NodoAVL* rotacionIzquierda(NodoAVL* nodo);
    NodoAVL* insertarNodo(NodoAVL* nodo, Paciente* p);

    Paciente* buscarId(NodoAVL* nodo, string id) const;
    Paciente* buscarNombre(NodoAVL* nodo, string nombre) const;

    void mostrarInorden(NodoAVL* nodo) const;
    void mostrarPreorden(NodoAVL* nodo) const;
    void mostrarPostorden(NodoAVL* nodo) const;
    void mostrarBalance(NodoAVL* nodo) const;
    void liberar(NodoAVL* nodo);

public:
    AVL();
    ~AVL();

    void insertar(Paciente* p);
    Paciente* buscarPorId(string id) const;
    Paciente* buscarPorNombre(string nombre) const;

    void inorden() const;
    void preorden() const;
    void postorden() const;
    void mostrarFactoresBalance() const;

    int altura() const;
    bool estaVacio() const;

    AVL(const AVL&) = delete;
    AVL& operator=(const AVL&) = delete;
    Paciente* buscarPorIdConRuta(string id) const;
};
