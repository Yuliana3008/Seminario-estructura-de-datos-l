#include <iostream>
#include <string>
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

    friend ostream& operator<<(ostream& o, Solicitud& s);
    friend istream& operator>>(istream& i, Solicitud& s);
};

Solicitud::Solicitud() : nombre(""), carrera(""), materias_aprobadas(0), promedio(0.0) {}

Solicitud::Solicitud(string n, string c, int m, float p) {  //constructor
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

ostream& operator<<(ostream& o, Solicitud& s) {
    o << "\nConstancia de estudios\n";
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

class Cola {
private:
    Solicitud datos[TAM];
    int ult;
    bool elimina(int pos);
    int inserta(Solicitud& elem, int pos);

public:
    Cola(): ult(-1) {}
    bool vacia() const;
    bool llena() const;
    int ultimo() const;
    void enqueue(Solicitud& elem);
    Solicitud& dequeue();

    friend ostream& operator<<(ostream& o, Cola& L);
};

bool Cola::vacia() const { return ult == -1; }
bool Cola::llena() const { return ult == TAM - 1; }
int Cola::ultimo() const { return ult; }

int Cola::inserta(Solicitud& elem, int pos) {
    if (llena() || pos < 0 || pos > ult + 1) return 0;
    for (int i = ult + 1; i > pos; i--)
        datos[i] = datos[i-1];       //funcion de agregar
    datos[pos] = elem;
    ult++;
    return 1;
}

bool Cola::elimina(int pos) {
    if (vacia() || pos < 0 || pos > ult) return false;
    for (int i = pos; i < ult; i++)   //funcion de eliminar
        datos[i] = datos[i+1];
    ult--;
    return true;
}

void Cola::enqueue(Solicitud& elem) {  //agregar a la cola
    inserta(elem, ult + 1);
}

Solicitud& Cola::dequeue() {
    static Solicitud aux;
    if (!vacia()) {    //sacar de la cola
        aux = datos[0];
        elimina(0);
    }
    return aux;
}

ostream& operator<<(ostream& o, Cola& L) {
    for (int i = 0; i <= L.ult; i++) {
        o << L.datos[i] << endl;
    }
    return o;
}

int main() {
    Cola solicitudes;
    Solicitud s;

    int opcion;
    do {
        cout << "1. Dar de alta solicitud\n";
        cout << "2. Elaborar constancia\n";
        cout << "3. Salir\n";
        cin >> opcion;

        switch(opcion) {
            case 1:
                cin >> s;
                solicitudes.enqueue(s);
                break;

            case 2:
                if (!solicitudes.vacia()) {
                    Solicitud atendida = solicitudes.dequeue();
                    cout << atendida;
                } else {
                    cout << "No hay solicitudes pendientes.\n";
                }
                break;

            case 3:
                cout << "Saliendo...\n";
                break;

            default:
                cout << "Opcion invalida.\n";
        }
    } while(opcion != 3);

    return 0;
}
