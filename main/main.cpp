
#include <iostream>
#include <string>
#include <limits>
#include "../logica/Hospital.h"

using namespace std;

int pedirOpcionValida(string mensaje, int minimo, int maximo) {
    int respuesta;

    while (true) {
        cout << mensaje;

        if (cin >> respuesta && respuesta >= minimo && respuesta <= maximo) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return respuesta;
        }

        if (cin.eof()) {
            return minimo - 1;
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Opcion invalida. Intenta nuevamente: " << endl;
    }
}

int main() {
    Hospital hospital;

    if (!hospital.cargarPacientes("pacientes.txt")) {
        cout << "No se pudieron cargar los pacientes." << endl;
        return 1;
    }

    int respuesta;
    int cantidad;
    int posicion;
    string dato;

    const string nombresDepartamentos[8] = {
        "Urgencias",
        "Medicina General",
        "Cardiologia",
        "Neurologia",
        "Traumatologia",
        "Cirugia",
        "Pediatria",
        "Hospitalizacion"
    };

    do {
        cout << "\n=== HOSPITAL MARMAJA ===\n"
             << "1. Atender pacientes\n"
             << "2. Ver departamento\n"
             << "3. Buscar paciente\n"
             << "4. Salir\n";

        respuesta = pedirOpcionValida("Seleccionar opcion: ", 1, 4);

        if (respuesta == 0) {
            break;
        }

        switch (respuesta) {
        case 1:
            if (hospital.getPacientesEnEspera() == 0) {
                cout << "No hay pacientes en espera." << endl;
            } else {
                hospital.mostrarEnEspera();

                cantidad = pedirOpcionValida(
                    "Indique la cantidad de pacientes a atender: ",
                    1,
                    hospital.getPacientesEnEspera()
                );

                if (cantidad > 0) {
                    hospital.atenderPacientes(cantidad);
                }
            }
            break;

       case 2:
            hospital.mostrarDepartamentos();
            break;

        case 3:
            cout << "\nIngrese ID o nombre del paciente: ";
            getline(cin, dato);

            if (dato.empty()) {
                cout << "Debe ingresar un ID o nombre." << endl;
            } else {
                hospital.buscarPaciente(dato);
            }
            break;

        case 4:
            cout << "Gracias por usar nuestros servicios" << endl;
            break;
        }

    } while (respuesta != 4);

    return 0;
}
