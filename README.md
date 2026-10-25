# Taller 2: Clasificación de Pacientes y Árboles AVL - Hospital Marmaja

Sistema de gestión y clasificación de pacientes de un hospital desarrollado en C++ para el curso de Estructura de Datos. El programa lee los pacientes desde un archivo de texto, los almacena en una cola según su orden de llegada, los clasifica mediante un árbol binario de decisión y los deriva a uno de los ocho departamentos del hospital. Cada departamento almacena sus pacientes utilizando un árbol AVL ordenado por ID.

Las estructuras de datos principales (cola, árbol binario de decisión y árboles AVL) están implementadas manualmente utilizando nodos, punteros y memoria dinámica.

Nombre: Sebastian Parada  
RUT: 22312246-9  
Nombre en GitHub: Oceanntt  
Carrera: ICCI

## Estructura del proyecto

**dominio/**: contiene las entidades y nodos principales del hospital, como Paciente, Departamento, NodoPaciente, NodoDecision y NodoAVL.

**logica/**: contiene las estructuras de datos y el control del sistema, incluyendo Cola, ArbolDecision, AVL, ListaDepartamentos y Hospital.

**main/**: contiene el menú de consola y el punto de entrada del programa (`main.cpp`).

## Diseño

**Cola:** se utiliza una cola FIFO implementada manualmente para almacenar a los pacientes que esperan ser atendidos. Esto permite respetar el orden de llegada de los pacientes cargados desde el archivo.

**Árbol de decisión:** se utiliza un árbol binario implementado manualmente para clasificar a cada paciente. Cada nodo interno representa una condición médica y cada hoja representa uno de los ocho departamentos disponibles.

Los departamentos posibles son:

- Urgencias
- Medicina General
- Cardiologia
- Neurologia
- Traumatologia
- Cirugia
- Pediatria
- Hospitalizacion

La clasificación considera atributos como la edad, presencia de trauma, necesidad de cirugía, síntomas neurológicos, tipo de dolor, temperatura, intensidad del dolor y días de hospitalización.

La prioridad utilizada en el árbol permite, por ejemplo, enviar pacientes menores de 14 años a Pediatria, pacientes con trauma a Cirugia o Traumatologia según corresponda, pacientes con síntomas neurológicos a Neurologia y pacientes con dolor de pecho a Cardiologia.

Durante la clasificación se puede visualizar la ruta seguida dentro del árbol hasta llegar al departamento correspondiente.

**Árboles AVL:** cada uno de los ocho departamentos posee su propio árbol AVL. Los pacientes son almacenados utilizando su ID como clave de ordenamiento.

El AVL implementa inserción, búsqueda, cálculo de altura y factor de balance, además de las rotaciones necesarias para mantener el árbol balanceado:

- Rotación LL
- Rotación RR
- Rotación LR
- Rotación RL

También se implementan los recorridos inorden, preorden y postorden.

**Búsqueda:** los pacientes pueden buscarse por ID o por nombre. La búsqueda por ID aprovecha el orden del árbol AVL y permite visualizar la ruta seguida durante el proceso de búsqueda.

**Punteros y memoria:** las estructuras utilizan memoria dinámica mediante nodos y punteros. Los destructores correspondientes se encargan de liberar los nodos y pacientes almacenados para evitar pérdidas de memoria.

**Responsabilidades:** Hospital coordina el flujo principal:

Archivo → Cola → Árbol de decisión → Departamento → AVL

`main.cpp` se encarga principalmente de mostrar el menú y recibir las opciones ingresadas por el usuario.

## Archivo de pacientes

Los pacientes se cargan desde `pacientes.txt`.

Cada línea utiliza el siguiente formato:

`ID;Nombre;Edad;Temperatura;PresionArterial;Dolor;TipoDolor;Trauma;SintomasNeurologicos;RequiereCirugia;DiasHospitalizacion`

El programa valida la cantidad de campos, los datos numéricos, los rangos permitidos y los ID duplicados antes de agregar un paciente a la cola.

## Instrucciones de compilación y ejecución

Requisito: compilador g++ (MinGW-w64 en Windows).

Los comandos se ejecutan desde la carpeta raíz del proyecto, donde se encuentran este README y `pacientes.txt`.

### Compilación

Si el Makefile está configurado correctamente:

`mingw32-make`

Si make no funciona, compilar con este comando en una sola línea:

`g++ -std=c++17 -Wall -Wextra -I dominio -I logica dominio/*.cpp logica/*.cpp main/*.cpp -o hospital.exe`

### Ejecución

`.\hospital.exe`

## Funcionamiento

Al iniciar el programa se cargan los pacientes desde `pacientes.txt` y se muestra el menú principal:

1. Atender pacientes
2. Ver departamento
3. Buscar paciente
4. Salir

Al atender pacientes, estos son retirados de la cola respetando el orden FIFO, clasificados mediante el árbol de decisión e insertados en el AVL del departamento asignado.

La opción de departamentos permite consultar los pacientes almacenados y observar información relacionada con la estructura AVL.

La búsqueda permite localizar pacientes previamente atendidos utilizando su ID o nombre.
