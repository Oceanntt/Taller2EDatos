#include <iostream>
#include "Hospital.h"
using namespace std;

int pedirOpcionValida(string mensaje, int minimo, int maximo) {
    int respuesta;

    cout << mensaje;
    cin >> respuesta;

    while (cin.fail() || respuesta < minimo || respuesta > maximo) {
        cin.clear();
        cin.ignore(1000, '\n');

        cout << "Opcion invalida. Intenta nuevamente: ";
        cin >> respuesta;
    }

    cin.ignore(1000, '\n');
    return respuesta;
}

int main() {
    Hospital hospital;
    hospital.cargarPacientes("pacientes.txt");

    int respuesta;
    int cantidad;
    int posicion;

    do {
        cout << "\n=== HOSPITAL MARMAJA ===\n"
             << "1. Atender pacientes\n"
             << "2. Ver departamento\n"
             << "3. Revisar historial de atencion\n"
             << "4. Salir\n";

        respuesta = pedirOpcionValida("Seleccionar opcion: ", 1, 4);

        switch (respuesta) {
        case 1:
            if (hospital.getPacientesEnEspera() == 0) {
                cout << "No hay pacientes en espera." << endl;
            } else {
                hospital.mostrarEnEspera();
                cantidad = pedirOpcionValida("Indique la cantidad de pacientes a atender: ",
                                             1, hospital.getPacientesEnEspera());
                hospital.atenderPacientes(cantidad);
            }
            break;

        case 2:
            hospital.mostrarDepartamentos();
            posicion = pedirOpcionValida("Seleccionar opcion: ", 1, hospital.getCantidadServicios());
            hospital.mostrarEstadoServicio(posicion);
            break;

        case 3:
            hospital.mostrarHistorial();
            break;

        case 4:
            cout << "Gracias por usar nuestros servicios" << endl;
            break;
        }
    } while (respuesta != 4);

    return 0;
}