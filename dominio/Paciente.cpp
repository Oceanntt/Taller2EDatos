#include "Paciente.h"
#include <iostream>
using namespace std;

Paciente::Paciente(string id, string nombre, int edad,
                   double temperatura, int presionArterial,
                   int dolor, string tipoDolor, bool trauma,
                   bool sintomasNeurologicos, bool requiereCirugia,
                   int diasHospitalizacion) {

    this->id = id;
    this->nombre = nombre;
    this->edad = edad;
    this->temperatura = temperatura;
    this->presionArterial = presionArterial;
    this->dolor = dolor;
    this->tipoDolor = tipoDolor;
    this->trauma = trauma;
    this->sintomasNeurologicos = sintomasNeurologicos;
    this->requiereCirugia = requiereCirugia;
    this->diasHospitalizacion = diasHospitalizacion;
    this->servicio = "Sin asignar";
}

string Paciente::getId() const { return id; }
string Paciente::getNombre() const { return nombre; }
int Paciente::getEdad() const { return edad; }
double Paciente::getTemperatura() const { return temperatura; }
int Paciente::getPresionArterial() const { return presionArterial; }
int Paciente::getDolor() const { return dolor; }
string Paciente::getTipoDolor() const { return tipoDolor; }
bool Paciente::getTrauma() const { return trauma; }
bool Paciente::getSintomasNeurologicos() const { return sintomasNeurologicos; }
bool Paciente::getRequiereCirugia() const { return requiereCirugia; }
int Paciente::getDiasHospitalizacion() const { return diasHospitalizacion; }
string Paciente::getServicio() const { return servicio; }

void Paciente::setServicio(string servicio) {
    this->servicio = servicio;
}

void Paciente::mostrar() const {
    cout << "ID: " << id << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Temperatura: " << temperatura << endl;
    cout << "Presion arterial: " << presionArterial << endl;
    cout << "Dolor: " << dolor << endl;
    cout << "Tipo de dolor: " << tipoDolor << endl;
    cout << "Trauma: " << (trauma ? "Si" : "No") << endl;
    cout << "Sintomas neurologicos: "
         << (sintomasNeurologicos ? "Si" : "No") << endl;
    cout << "Requiere cirugia: "
         << (requiereCirugia ? "Si" : "No") << endl;
    cout << "Dias hospitalizacion: "
         << diasHospitalizacion << endl;
    cout << "Servicio: " << servicio << endl;
}
