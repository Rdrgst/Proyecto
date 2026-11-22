#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <limits>
#include <algorithm>

using namespace std;

const int MAX = 100;

struct Alumno {
    string clave_a;
    string nombre;
    string matricula;
    double calif[3];
    string grupo;
};

struct Grupo {
    string clave_g;
    string nombre;
    string carrera;
};

struct Maestro {
    string clave_m;
    string nombre;
    string materia;
};

double calcularPromedio(const double calif[3]) {
    double suma = 0;

    for (int i = 0; i < 3; i++) {
        suma += calif[i];
    }

    return suma / 3;
}

int contarAlumnos() {
    ifstream archivo("alumnos_proyecto.txt");
    string linea;
    int contador = 0;

    while (getline(archivo, linea)) {
        if (!linea.empty()) {
            contador++;
        }
    }

    archivo.close();
    return contador;
    
}

string generarClaveAlumnos(int numero) {
        string texto = to_string(numero);

    while (texto.size() <3) {
        texto = "0" + texto;
    }

    return ("A" + texto);
}

void registrarAlumnos(Alumno alumnos[], int &n) {
    int cantidad;

    cout << "\n¿Cuantos alumnos deseas registrar? ";
    cin >> cantidad;
    cin.ignore(1000, '\n');

    if (cantidad <= 0 || n + cantidad > MAX) {
        cout << "\nCantidad no valida o supera el limite.\n";
        return;
    }

    for (int i = n; i < n + cantidad; i++) {
        cout << "\nIngrese el nombre del alumno " << (i + 1) << ": ";
        getline(cin, alumnos[i].nombre);

        cout << "Ingrese la matricula del alumno " << (i + 1) << ": ";
        cin >> alumnos[i].matricula;
        cin.ignore(1000, '\n');

        cout << "Ingrese el grupo del alumno " << (i + 1) << ": ";
        cin >> alumnos[i].grupo;
        cin.ignore(1000, '\n');

        cout << "Ingrese las calificaciones del alumno " << (i + 1) << ":\n";

        for (int j = 0; j < 3; j++) {
            cout << "Calificacion " << (j + 1) << ": ";
            cin >> alumnos[i].calif[j];
        }

        cin.ignore(1000, '\n');
    }

    n += cantidad;
             
    int siguiente = contarAlumnos() + 1;
   
    ofstream archivo("alumnos_proyecto.txt", ios::app);

    if(!archivo) {
        cout << "Error al abrir el archivo.";
        return ;
    }

    archivo <<setprecision(numeric_limits<double>::max_digits10);
    for (int i = n - cantidad; i < n; i++) {
        alumnos[i].clave_a = (generarClaveAlumnos(siguiente));
        siguiente++;

        archivo << alumnos[i].clave_a << '|'
                << alumnos[i].nombre << '|'
                << alumnos[i].matricula << '|'
                << alumnos[i].grupo << '|';
        for (int j = 0; j < 3; j++) {
            archivo << alumnos[i].calif[j];

            if (j < 2) {
                archivo << '|';
            }

        }

        archivo << '\n';
    }
    
    archivo.close();

    if(!archivo) {
        cout << "Ocurrio un error al guardar al alumno.\n";
        return ;

    }

    cout << "\nAlumnos registrados correctamente.\n";
    return;

}

int contarGrupos() {
    ifstream archivo("grupos_proyecto.txt");
    string linea;
    int contador = 0;

    while (getline(archivo, linea)) {
        if (!linea.empty()) {
            contador++;
        }
    }

    archivo.close();
    return contador;
    
}

string generarClaveGrupos(int numero) {
        string texto = to_string(numero);

    while (texto.size() <3) {
        texto = "0" + texto;
    }

    return ("G" + texto);
}

void registrarGrupos(Grupo grupos[], int &totalGrupos) {
    int cantidad;

    cout << "\n¿Cuantos grupos deseas registrar? ";
    cin >> cantidad;
    cin.ignore(1000, '\n');

    if (cantidad <= 0 || totalGrupos + cantidad > MAX) {
        cout << "\nCantidad no valida o supera el limite.\n";
        return;
    }

    for (int i = totalGrupos; i < totalGrupos + cantidad; i++) {
        cout << "\nIngrese el nombre del grupo " << (i + 1) << ": ";
        getline(cin, grupos[i].nombre);

        cout << "Ingrese la carrera del grupo " << (i + 1) << ": ";
        getline(cin, grupos[i].carrera);
    }

    totalGrupos += cantidad;

        int siguiente = contarGrupos() + 1;
   
    ofstream archivo("grupos_proyecto.txt", ios::app);

    if(!archivo) {
        cout << "Error al abrir el archivo.";
        return ;
    }

    archivo <<setprecision(numeric_limits<double>::max_digits10);
    for (int i = totalGrupos - cantidad; i < totalGrupos; i++) {
        grupos[i].clave_g = (generarClaveGrupos(siguiente));
        siguiente++;

        archivo << grupos[i].clave_g << '|'
                << grupos[i].nombre << '|'
                << grupos[i].carrera << '\n';

    }
    
    archivo.close();

    if(!archivo) {
        cout << "Ocurrio un error al guardar el grupo.\n";
        return ;

    }

    cout << "\nGrupos registrados correctamente.\n";
    return;

}

int contarMaestros() {
    ifstream archivo("maestros_proyecto.txt");
    string linea;
    int contador = 0;

    while (getline(archivo, linea)) {
        if (!linea.empty()) {
            contador++;
        }
    }

    archivo.close();
    return contador;
    
}

string generarClaveMaestros(int numero) {
        string texto = to_string(numero);

    while (texto.size() <3) {
        texto = "0" + texto;
    }

    return ("M" + texto);
}

void registrarMaestros(Maestro maestros[], int &totalMaestros) {
    int cantidad;

    cout << "\n¿Cuantos maestros deseas registrar? ";
    cin >> cantidad;
    cin.ignore(1000, '\n');

    if (cantidad <= 0 || totalMaestros + cantidad > MAX) {
        cout << "\nCantidad no valida o supera el limite.\n";
        return;
    }

    for (int i = totalMaestros; i < totalMaestros + cantidad; i++) {
        cout << "\nIngrese el nombre del maestro " << (i + 1) << ": ";
        getline(cin, maestros[i].nombre);

        cout << "Ingrese la materia del maestro " << (i + 1) << ": ";
        getline(cin, maestros[i].materia);
    }

    totalMaestros += cantidad;

        int siguiente = contarMaestros() + 1;
   
    ofstream archivo("maestros_proyecto.txt", ios::app);

    if(!archivo) {
        cout << "Error al abrir el archivo.";
        return ;
    }

    archivo <<setprecision(numeric_limits<double>::max_digits10);
    for (int i = totalMaestros - cantidad; i < totalMaestros; i++) {
        maestros[i].clave_m = (generarClaveMaestros(siguiente));
        siguiente++;

        archivo << maestros[i].clave_m << '|'
                << maestros[i].nombre << '|'
                << maestros[i].materia << '\n';

    }
    
    archivo.close();

    if(!archivo) {
        cout << "Ocurrio un error al guardar al maestro.\n";
        return ;

    }

    cout << "\nMaestros registrados correctamente.\n";
    return;

}

void mostrarAlumnos(Alumno alumnos[], int n) {
    if (n == 0) {
        cout << "\nNo hay alumnos registrados.\n";
        return;
    }

    cout << left;
    cout    << setw(8) << "Clave"
            << setw(25) << "Nombre"
            << setw(15) << "Matricula"
            << setw(10) << "Grupo"
            << setw(12) << "Calif. 1"
            << setw(12) << "Calif. 2"
            << setw(12) << "Calif. 3"
            << setw(12) << "Promedio"
            << '\n';

    cout << fixed << setprecision(2);

    for (int i = 0; i < n; i++) {
        cout    << setw(8) << alumnos[i].clave_a 
                << setw(25) << alumnos[i].nombre
                << setw(15) << alumnos[i].matricula
                << setw(10) << alumnos[i].grupo
                << setw(12) << alumnos[i].calif[0]
                << setw(12) << alumnos[i].calif[1]
                << setw(12) << alumnos[i].calif[2]
                << setw(12) << calcularPromedio(alumnos[i].calif) 
                << '\n';
    }
}

void mostrarGrupos(Grupo grupos[], int totalGrupos) {
    if (totalGrupos == 0) {
        cout << "\nNo hay grupos registrados.\n";
        return;
    }

    cout << left;
    cout << setw(8) << "Clave"
         << setw(30) << "Nombre"
         << setw(35) << "Carrera" 
         << '\n';

    for (int i = 0; i < totalGrupos; i++) {
        cout << setw(8) << grupos[i].clave_g
             << setw(30) << grupos[i].nombre
             << setw(35) << grupos[i].carrera 
             << '\n';
    }
}

void mostrarMaestros(Maestro maestros[], int totalMaestros) {
    if (totalMaestros == 0) {
        cout << "\nNo hay maestros registrados.\n";
        return;
    }

    cout << left;
    cout << setw(8) << "Clave"
         << setw(25) << "Nombre"
         << setw(30) << "Materia"
         << '\n';

    for (int i = 0; i < totalMaestros; i++) {
        cout << setw(8) << maestros[i].clave_m
             << setw(25) << maestros[i].nombre
             << setw(30) << maestros[i].materia 
             << '\n';

    }
}

void promedioAlumnos(Alumno alumnos[], int n) {
    if (n == 0) {
        cout << "\nNo hay alumnos registrados.\n";
        return;
    }

    cout << "\n===== PROMEDIO DE CADA ALUMNO =====\n";
    cout << fixed << setprecision(2);

    for (int i = 0; i < n; i++) {
        cout << alumnos[i].nombre
             << " - Promedio: "
             << calcularPromedio(alumnos[i].calif) << endl;
    }
}

void mejorPromedioPorGrupo(Alumno alumnos[], int n) {
    if (n == 0) {
        cout << "\nNo hay alumnos registrados.\n";
        return;
    }

    cout << "\n===== MEJOR PROMEDIO POR GRUPO =====\n";
    cout << fixed << setprecision(2);

    for (int i = 0; i < n; i++) {
        bool grupoYaRevisado = false;

        for (int j = 0; j < i; j++) {
            if (alumnos[i].grupo == alumnos[j].grupo) {
                grupoYaRevisado = true;
                break;
            }
        }

        if (grupoYaRevisado) {
            continue;
        }

        string grupoActual = alumnos[i].grupo;
        double mejorPromedio = calcularPromedio(alumnos[i].calif);
        string mejorAlumno = alumnos[i].nombre;

        for (int j = i + 1; j < n; j++) {
            if (alumnos[j].grupo == grupoActual) {
                double promedioActual = calcularPromedio(alumnos[j].calif);

                if (promedioActual > mejorPromedio) {
                    mejorPromedio = promedioActual;
                    mejorAlumno = alumnos[j].nombre;
                }
            }
        }

        cout << "Grupo " << grupoActual
             << ": " << mejorAlumno
             << " con promedio " << mejorPromedio << endl;
    }
}

void alumnosPorCarrera(Alumno alumnos[], int n, Grupo grupos[], int totalGrupos) {
    if (totalGrupos == 0) {
        cout << "\nNo hay grupos registrados.\n";
        return;
    }

    cout << "\n===== ALUMNOS POR CARRERA =====\n";

    for (int i = 0; i < totalGrupos; i++) {
        int contador = 0;

        for (int j = 0; j < n; j++) {
            if (alumnos[j].grupo == grupos[i].nombre) {
                contador++;
            }
        }

        cout << grupos[i].carrera
             << ": " << contador << " alumno(s)\n";
    }
}

void mostrarReportes(Alumno alumnos[], int &n, Grupo grupos[], int &totalGrupos) {
    int opcionReporte;

    do {
        cout << "\n===== REPORTES =====\n";
        cout << "1. Promedio de cada alumno\n";
        cout << "2. Alumno con mejor promedio por grupo\n";
        cout << "3. Cantidad de alumnos por carrera\n";
        cout << "4. Volver al menu principal\n";
        cout << "Selecciona una opcion: ";
        cin >> opcionReporte;
        cin.ignore(1000, '\n');

        switch (opcionReporte) {
            case 1:
                promedioAlumnos(alumnos, n);
                break;

            case 2:
                mejorPromedioPorGrupo(alumnos, n);
                break;

            case 3:
                alumnosPorCarrera(alumnos, n, grupos, totalGrupos);
                break;

            case 4:
                cout << "\nVolviendo al menu principal...\n";
                break;

            default:
                cout << "\nOpcion no valida.\n";
        }

    } while (opcionReporte != 4);
}

int cargarAlumnos(Alumno alumnos[], int maximo) {
    ifstream archivo("alumnos_proyecto.txt");
    string linea;
    int totalAlumnos = 0;

    if(!archivo) {
        return 0;
    }

    while (getline(archivo, linea) && totalAlumnos < maximo) {
        if (linea.empty()) {
            continue;
        }

        stringstream ss(linea);

        string clave, nombre, matricula, grupo, calif1, calif2, calif3;

        getline(ss, clave, '|');
        getline(ss, nombre, '|');
        getline(ss, matricula, '|');
        getline(ss, grupo, '|');
        getline(ss, calif1, '|');
        getline(ss, calif2, '|');
        getline(ss, calif3, '|');

        if (clave.empty() || nombre.empty() || matricula.empty() || grupo.empty() || calif1.empty() || calif2.empty() || calif3.empty()) {
            cout << "Registro invalido: " << linea << '\n';
            continue;
        }

        alumnos[totalAlumnos].clave_a = clave;
        alumnos[totalAlumnos].nombre = nombre;
        alumnos[totalAlumnos].matricula = matricula;
        alumnos[totalAlumnos].grupo = grupo;

        alumnos[totalAlumnos].calif[0] = stod(calif1);
        alumnos[totalAlumnos].calif[1] = stod(calif2);
        alumnos[totalAlumnos].calif[2] = stod(calif3);

        totalAlumnos++;
    }

    archivo.close();
    return totalAlumnos;
}

int cargarGrupos(Grupo grupos[], int maximo) {
    ifstream archivo("grupos_proyecto.txt");
    string linea;
    int totalGrupos = 0;

    if(!archivo) {
        return 0;
    }

    while (getline(archivo, linea) && totalGrupos < maximo) {
        if (linea.empty()) {
            continue;
        }

        stringstream ss(linea);

        string clave, nombre, carrera;

        getline(ss, clave, '|');
        getline(ss, nombre, '|');
        getline(ss, carrera, '|');
        

        if (clave.empty() || nombre.empty() || carrera.empty()) {
            cout << "Registro invalido: " << linea << '\n';
            continue;
        }

        grupos[totalGrupos].clave_g = clave;
        grupos[totalGrupos].nombre = nombre;
        grupos[totalGrupos].carrera = carrera;

        totalGrupos++;
    }

    archivo.close();
    return totalGrupos;
}

int cargarMaestros(Maestro maestros[], int maximo) {
    ifstream archivo("maestros_proyecto.txt");
    string linea;
    int totalMaestros = 0;

    if(!archivo) {
        return 0;
    }

    while (getline(archivo, linea) && totalMaestros < maximo) {
        if (linea.empty()) {
            continue;
        }

        stringstream ss(linea);

        string clave, nombre, materia;

        getline(ss, clave, '|');
        getline(ss, nombre, '|');
        getline(ss, materia, '|');
        

        if (clave.empty() || nombre.empty() || materia.empty()) {
            cout << "Registro invalido: " << linea << '\n';
            continue;
        }

        maestros[totalMaestros].clave_m = clave;
        maestros[totalMaestros].nombre = nombre;
        maestros[totalMaestros].materia = materia;

        totalMaestros++;
    }

    archivo.close();
    return totalMaestros;
}

void guardarAlumnos(Alumno alumnos[], int totalAlumnos) {
    ofstream archivo("alumnos_proyecto.txt");

    if (!archivo) {
        cout << "\nError al guardar los alumnos.\n";
        return;
    }

    archivo << fixed << setprecision(2);

    for (int i = 0; i < totalAlumnos; i++) {
        archivo << alumnos[i].clave_a << '|'
                << alumnos[i].nombre << '|'
                << alumnos[i].matricula << '|'
                << alumnos[i].grupo << '|'
                << alumnos[i].calif[0] << '|'
                << alumnos[i].calif[1] << '|'
                << alumnos[i].calif[2] << '\n';
    }

    archivo.close();
    cout << "\nAlumnos guardados correctamente.\n";
}

void guardarGrupos(Grupo grupos[], int totalGrupos) {
    ofstream archivo("grupos_proyecto.txt");

    if (!archivo) {
        cout << "\nError al guardar los grupos.\n";
        return;
    }

    for (int i = 0; i < totalGrupos; i++) {
        archivo << grupos[i].clave_g << '|'
                << grupos[i].nombre << '|'
                << grupos[i].carrera << '\n';
    }

    archivo.close();
    cout << "\nGrupos guardados correctamente.\n";
}

void guardarMaestros(Maestro maestros[], int totalMaestros) {
    ofstream archivo("maestros_proyecto.txt");

    if (!archivo) {
        cout << "\nError al guardar los maestros.\n";
        return;
    }

    for (int i = 0; i < totalMaestros; i++) {
        archivo << maestros[i].clave_m << '|'
                << maestros[i].nombre << '|'
                << maestros[i].materia << '\n';
    }

    archivo.close();
    cout << "\nMaestros guardados correctamente.\n";
}

void guardarTodo(Alumno alumnos[], int totalAlumnos, Grupo grupos[], int totalGrupos, Maestro maestros[], int totalMaestros) {
    guardarAlumnos(alumnos, totalAlumnos);
    guardarGrupos(grupos, totalGrupos);
    guardarMaestros(maestros, totalMaestros);
}

void reportePromedios(Alumno alumnos[], int totalAlumnos) {
    if (totalAlumnos == 0) {
        cout << "\nNo hay alumnos registrados.\n";
        return;
    }

    Alumno copia[MAX];

    for (int i = 0; i < totalAlumnos; i++) {
        copia[i] = alumnos[i];
    }

    sort(copia, copia + totalAlumnos, [](const Alumno &a, const Alumno &b) {
        return calcularPromedio(a.calif) > calcularPromedio(b.calif);
    });

    ofstream archivo("reporte_promedios_proyecto.txt");

    if (!archivo) {
        cout << "\nError al crear el reporte.\n";
        return;
    }

    archivo << "REPORTE DE ALUMNOS\n";
    archivo << "========================\n";
    archivo << left;
    archivo << setw(8) << "Clave"
            << setw(25) << "Nombre"
            << setw(15) << "Matricula"
            << setw(10) << "Grupo"
            << setw(12) << "Promedio" << '\n';

    archivo << fixed << setprecision(2);

    for (int i = 0; i < totalAlumnos; i++) {
        archivo << setw(8) << copia[i].clave_a
                << setw(25) << copia[i].nombre
                << setw(15) << copia[i].matricula
                << setw(10) << copia[i].grupo
                << setw(12) << calcularPromedio(copia[i].calif) << '\n';
    }

    archivo.close();

    cout << "\nReporte generado correctamente\n";
}

int main() {
    Alumno alumnos[MAX];
    Maestro maestros[MAX];
    Grupo grupos[MAX];

    int totalAlumnos = 0;
    int totalMaestros = 0;
    int totalGrupos = 0;
    totalAlumnos = cargarAlumnos(alumnos, MAX);
    totalMaestros = cargarMaestros(maestros, MAX);
    totalGrupos = cargarGrupos(grupos, MAX);

    int opcion;

    cout << "===== PROYECTO V2 =====\n";

    do {
        cout << "\nSeleccione una opcion:\n";
        cout << "1. Registrar alumnos\n";
        cout << "2. Registrar grupos y carreras\n";
        cout << "3. Registrar maestros\n";
        cout << "4. Mostrar alumnos\n";
        cout << "5. Mostrar grupos\n";
        cout << "6. Mostrar maestros\n";
        cout << "7. Mostrar reportes\n";
        cout << "8. Guardar todos los datos\n";
        cout << "9. Generar reporte por promedio\n";
        cout << "10. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;
        
    if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            opcion = 0;
        } else {
            cin.ignore(1000, '\n');
        }

        switch (opcion) {
            case 1:
                registrarAlumnos(alumnos, totalAlumnos);
                totalAlumnos = cargarAlumnos(alumnos, MAX);
                break;

            case 2:
                registrarGrupos(grupos, totalGrupos);
                totalGrupos = cargarGrupos(grupos, MAX);
                break;

            case 3:
                registrarMaestros(maestros, totalMaestros);
                totalMaestros = cargarMaestros(maestros, MAX);
                break;

            case 4:
                mostrarAlumnos(alumnos, totalAlumnos);
                break;

            case 5:
                mostrarGrupos(grupos, totalGrupos);
                break;

            case 6:
                mostrarMaestros(maestros, totalMaestros);
                break;

            case 7:
                mostrarReportes(alumnos, totalAlumnos, grupos, totalGrupos);
                break;

            case 8:
                guardarTodo(alumnos, totalAlumnos, grupos, totalGrupos, maestros, totalMaestros);
                break;

            case 9:
                reportePromedios(alumnos, totalAlumnos);
                break;

            case 10:
                guardarTodo(alumnos, totalAlumnos, grupos, totalGrupos, maestros, totalMaestros);
                cout << "\nSaliendo del programa...\n";
                break;

            default:
                cout << "\nOpcion no valida. Intenta de nuevo.\n";
        }

    } while (opcion != 10);

    return 0;
}