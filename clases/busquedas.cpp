#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int TAM = 100;

class Solicitud {
private:
    string nombre;
    string carrera;
    int materias_aprobadas;
    float promedio;

public:
    Solicitud();
    Solicitud(string n, string c, int m, float p);
    void operator=(Solicitud& x);


    bool operator==(const Solicitud& other) const;
    bool operator<(const Solicitud& other) const;
    bool operator>(const Solicitud& other) const;


    string getNombre() const { return nombre; }
    string getCarrera() const { return carrera; }
    int getMateriasAprobadas() const { return materias_aprobadas; }
    float getPromedio() const { return promedio; }

    friend ostream& operator<<(ostream& o, Solicitud& s);
    friend istream& operator>>(istream& i, Solicitud& s);
};

Solicitud::Solicitud() : nombre(""), carrera(""), materias_aprobadas(0), promedio(0.0) {}

Solicitud::Solicitud(string n, string c, int m, float p) {
    nombre = n;
    carrera = c;
    materias_aprobadas = m;
    promedio = p;
}

void Solicitud::operator=(Solicitud& x) {
    nombre = x.nombre;
    carrera = x.carrera;
    materias_aprobadas = x.materias_aprobadas;
    promedio = x.promedio;
}


bool Solicitud::operator==(const Solicitud& other) const {
    return nombre == other.nombre;
}

//  ordenamiento por nombre
bool Solicitud::operator<(const Solicitud& other) const {
    return nombre < other.nombre;
}


bool Solicitud::operator>(const Solicitud& other) const {
    return nombre > other.nombre;
}

ostream& operator<<(ostream& o, Solicitud& s) {
    o << "Alumno: " << s.nombre << endl;
    o << "Carrera: " << s.carrera << endl;
    o << "Materias aprobadas: " << s.materias_aprobadas << endl;
    o << "Promedio: " << s.promedio << endl;
    return o;
}

istream& operator>>(istream& i, Solicitud& s) {
    cout << "Nombre del alumno: ";
    getline(i >> ws, s.nombre);
    cout << "Carrera: ";
    getline(i >> ws, s.carrera);
    cout << "Materias aprobadas: ";
    i >> s.materias_aprobadas;
    cout << "Promedio: ";
    i >> s.promedio;
    return i;
}

template <typename T>
class Cola {
private:
    T datos[TAM];
    int ult;
    bool elimina(int pos);
    int inserta(T& elem, int pos);

public:
    Cola(): ult(-1) {}
    bool vacia() const;
    bool llena() const;
    int ultimo() const;
    void enqueue(T& elem);
    T& dequeue();

    int busquedaLineal(const T& elem);
    int busquedaBinaria(const T& elem);
    void ordenar();

    template <typename U>
    friend ostream& operator<<(ostream& o, Cola<U>& L);
};

template <typename T>
bool Cola<T>::vacia() const { return ult == -1; }

template <typename T>
bool Cola<T>::llena() const { return ult == TAM - 1; }

template <typename T>
int Cola<T>::ultimo() const { return ult; }

template <typename T>
int Cola<T>::inserta(T& elem, int pos) {
    if (llena() || pos < 0 || pos > ult + 1)
        return 0;

    int i = ult + 1;
    while (i > pos) {
        datos[i] = datos[i - 1];
        i--;
    }

    datos[pos] = elem;
    ult++;
    return 1;
}

template <typename T>
bool Cola<T>::elimina(int pos) {
    if (vacia() || pos < 0 || pos > ult) {
        std::cout << "\nError de eliminacion";
        return true;
    }

    int i = pos;
    while (i < ult) {
        datos[i] = datos[i + 1];
        i++;
    }

    ult--;
    return false;
}


template <typename T>
void Cola<T>::enqueue(T& elem) {
    inserta(elem, ult + 1);
}

template <typename T>
T& Cola<T>::dequeue() {
    static T aux;
    if (!vacia()) {
        aux = datos[0];
        elimina(0);
    }
    return aux;
}

//  bsqueda lineal
template <typename T>
int Cola<T>::busquedaLineal(const T& elem) {
    int i = 0;
    while (i <= ult) {
        if (elem == datos[i]) {
            return i;
        }
        i = i + 1;
    }
    return -1;
}

//busqueda binaria
template <typename T>
int Cola<T>::busquedaBinaria(const T& elem) {
    int i = 0, j = ult;
    while (i <= j) {
        int medio = (i + j) / 2;
        if (datos[medio] == elem) {
            return medio;
        }
        if (elem < datos[medio]) {
            j = medio - 1;
        } else {
            i = medio + 1;
        }
    }
    return -1;
}

template <typename T>
void Cola<T>::ordenar() {
    for (int i = 0; i < ult; i++) {
        for (int j = i + 1; j <= ult; j++) {
            if (datos[i] > datos[j]) {
                T temp = datos[i];
                datos[i] = datos[j];
                datos[j] = temp;
            }
            }
    }
}

template <typename U>
ostream& operator<<(ostream& o, Cola<U>& L) {
    for (int i = 0; i <= L.ult; i++) {
        o << L.datos[i] << endl;
    }
    return o;
}

int main() {
    Cola<Solicitud> solicitudes;
    Solicitud s;
    int opcion;

    do {

        cout << "1. Dar de alta solicitud\n";
        cout << "2. Elaborar constancia\n";
        cout << "3. Buscar solicitud (busqueda lineal)\n";
        cout << "4. Buscar solicitud (busqueda binaria)\n";
        cout << "5. Salir\n";
        cin >> opcion;

        switch(opcion) {
            case 1:
                cin >> s;
                solicitudes.enqueue(s);
                cout << "Solicitud registrada exitosamente.\n";
                break;

            case 2:
                if (!solicitudes.vacia()) {
                    Solicitud atendida = solicitudes.dequeue();
                    cout << atendida;
                } else {
                    cout << "No hay solicitudes pendientes.\n";
                }
                break;

            case 3: {
                if (solicitudes.vacia()) {
                    cout << "No hay solicitudes registradas.\n";
                    break;
                }

                string nombreBuscar;
                cout << "Ingrese el nombre del alumno a buscar: ";
                getline(cin >> ws, nombreBuscar);

                Solicitud solicitudBuscar(nombreBuscar, "", 0, 0.0);
                int posicion = solicitudes.busquedaLineal(solicitudBuscar);

                if (posicion != -1) {
                    cout << "Solicitud encontrada!\n";
                    cout << "Constancias por elaborar antes del turno: " << posicion << endl;
                } else {
                    cout << "Solicitud no encontrada.\n";
                    cout << "Debe dar de alta una solicitud primero.\n";
                }
                break;
            }

            case 4: {
                if (solicitudes.vacia()) {
                    cout << "No hay solicitudes registradas.\n";
                    break;
                }

                cout << "Ordenando solicitudes para búsqueda binaria...\n";
                solicitudes.ordenar();

                string nombreBuscar;
                cout << "Ingrese el nombre del alumno a buscar: ";
                getline(cin >> ws, nombreBuscar);

                Solicitud solicitudBuscar(nombreBuscar, "", 0, 0.0);
                int posicion = solicitudes.busquedaBinaria(solicitudBuscar);

                if (posicion != -1) {
                    cout << "Solicitud encontrada!\n";
                    cout << "Constancias por elaborar antes del turno: " << posicion << endl;
                } else {
                    cout << "Solicitud no encontrada.\n";
                    cout << "Debe dar de alta una solicitud primero.\n";
                }
                break;
            }
            case 5:
                cout << "Saliendo del programa...\n";
                break;

            default:
                cout << "Opcion invalida. Por favor seleccione una opcion valida.\n";
        }
    } while(opcion != 5);

    return 0;
}

