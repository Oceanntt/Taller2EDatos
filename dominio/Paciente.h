#pragma once
#include <string>
using namespace std;

class Paciente {
private:
    string id;
    string nombre;
    int edad;
    double temperatura;
    int presionArterial;
    int dolor;
    string tipoDolor;
    bool trauma;
    bool sintomasNeurologicos;
    bool requiereCirugia;
    int diasHospitalizacion;
    string servicio;

public:
    Paciente(string id, string nombre, int edad,
             double temperatura, int presionArterial,
             int dolor, string tipoDolor, bool trauma,
             bool sintomasNeurologicos, bool requiereCirugia,
             int diasHospitalizacion);

    string getId() const;
    string getNombre() const;
    int getEdad() const;
    double getTemperatura() const;
    int getPresionArterial() const;
    int getDolor() const;
    string getTipoDolor() const;
    bool getTrauma() const;
    bool getSintomasNeurologicos() const;
    bool getRequiereCirugia() const;
    int getDiasHospitalizacion() const;
    string getServicio() const;

    void setServicio(string servicio);
    void mostrar() const;
};
