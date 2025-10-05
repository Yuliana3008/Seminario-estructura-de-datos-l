#include <iostream>
#include <string>
#include <iomanip>
#define TAM 50

class Solicitud {
private:
    std::string nombre;
    std::string carrera;
    std::string preparatoria;
    float promedio;

public:
    std::string getNombre() const { return nombre; }
    std::string getCarrera() const { return carrera; }
    std::string getPreparatoria() const { return preparatoria; }
    float getPromedio() const { return promedio; }

    Solicitud() {
        nombre = "";
        carrera = "";
        preparatoria = "";
        promedio = 0;
    }

    Solicitud(std::string n, std::string c, std::string p, float pr) {
        nombre = n;
        carrera = c;
        preparatoria = p;
        promedio = pr;
    }

    bool operator==(Solicitud& other) const {
        return (nombre == other.getNombre());
    }

    friend std::istream& operator>>(std::istream& is, Solicitud& s) {
        std::cout << "Ingresa nombre alumno: ";
        is >> s.nombre;
        is.ignore();
        std::cout << "Ingrese carrera a cursar: ";
        std::getline(is, s.carrera);
        std::cout << "Ingrese preparatoria de procedencia: ";
        std::getline(is, s.preparatoria);
        std::cout << "Ingrese promedio general: ";
        is >> s.promedio;
        is.ignore();
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Solicitud& s) {
    os << "Nombre: " << s.nombre << "\n"
       << "Carrera: " << s.carrera << "\n"
       << "Preparatoria: " << s.preparatoria << "\n"
       << "Promedio: " << s.promedio << "\n";
    return os;
}

};

class Lista {
private:
    Solicitud datos[TAM];
    int ult;

public:
    Lista() : ult(-1) {}
    bool vacia() const;
    bool llena() const;
    bool inserta(Solicitud, int);
    bool elimina(int);
    Solicitud recupera(int) const;
    int primero() const;
    int ultimo() const;
    void imprime() const;
    int buscar(std::string);
    int busquedaBinaria(std::string);
    void ordenamientoInsercionPromedio();
    void ordenamientoInsercionNombre();
    void insertarAlFinal(Solicitud);
    void mostrarSolicitud(int) const;
    Solicitud obtenerElemento(int) const;
};

bool Lista::vacia() const {
    return ult == -1;
}

bool Lista::llena() const {
    return ult == TAM - 1;
}

bool Lista::inserta(Solicitud elem, int pos) {
    if (llena() || pos < 0 || pos > ult + 1) {
        std::cout << "\nNo se pudo insertar";
        return false;
    }
    int i = ult + 1;
    while (i > pos) {
        datos[i] = datos[i - 1];
        i--;
    }
    datos[pos] = elem;
    ult++;
    return true;
}

bool Lista::elimina(int pos) {
    if (vacia() || pos < 0 || pos > ult) {
        std::cout << "\nNo se pudo eliminar";
        return false;
    }
    int i = pos;
    while (i < ult) {
        datos[i] = datos[i + 1];
        i++;
    }
    ult--;
    return true;
}

Solicitud Lista::recupera(int pos) const {
    if (vacia() || pos < 0 || pos > ult) {
        std::cout << "\nInsuficiencia de datos";
        return Solicitud();
    }
    return datos[pos];
}

int Lista::primero() const {
    if (vacia()) {
        return -1;
    }
    return 0;
}

int Lista::ultimo() const {
    if (vacia()) {
        return -1;
    }
    return ult;
}

void Lista::imprime() const {
    if (!vacia()) {
        std::cout << "\n=== RANKING DE SOLICITUDES (ORDENADO POR PROMEDIO) ===" << std::endl;
        std::cout << std::string(80, '=') << std::endl;
        for (int i = 0; i <= ult; i++) {
            std::cout << "Posicion: " << (i + 1) << std::endl;
            std::cout << "Nombre: " << datos[i].getNombre() << std::endl;
            std::cout << "Carrera: " << datos[i].getCarrera() << std::endl;
            std::cout << "Preparatoria: " << datos[i].getPreparatoria() << std::endl;
            std::cout << "Promedio: " << std::fixed << std::setprecision(2)
                      << datos[i].getPromedio() << std::endl;
            std::cout << std::string(80, '-') << std::endl;
        }
    } else {
        std::cout << "\nLa lista está vacía." << std::endl;
    }
}

int Lista::buscar(std::string nombre) {
    int i = 0;
    while (i <= ult) {
        if (nombre == datos[i].getNombre()) {
            return i;
        }
        i++;
    }
    return -1;
}

void Lista::insertarAlFinal(Solicitud elem) {
    if (!llena()) {
        ult++;
        datos[ult] = elem;
    }
}



void Lista::mostrarSolicitud(int pos) const {
    if (pos >= 0 && pos <= ult) {
        std::cout << "\n=== SOLICITUD ENCONTRADA ===" << std::endl;
        std::cout << "Nombre: " << datos[pos].getNombre() << std::endl;
        std::cout << "Carrera: " << datos[pos].getCarrera() << std::endl;
        std::cout << "Preparatoria: " << datos[pos].getPreparatoria() << std::endl;
        std::cout << "Promedio: " << std::fixed << std::setprecision(2)
                  << datos[pos].getPromedio() << std::endl;
        std::cout << "Lugar obtenido: " << (pos + 1) << " de " << (ult + 1) << std::endl;
    }
}

Solicitud Lista::obtenerElemento(int pos) const {
    if (pos >= 0 && pos <= ult) {
        return datos[pos];
    }
    return Solicitud();
}

// Ordenamiento por PROMEDIO
void Lista::ordenamientoInsercionPromedio() {
    if (ult <= 0) return;

    int i = 1;
    while (i <= ult) {
        Solicitud aux = datos[i];
        int j = i;

        while (j > 0 && aux.getPromedio() > datos[j - 1].getPromedio()) {
            datos[j] = datos[j - 1];
            j = j - 1;
        }

        if (i != j) {
            datos[j] = aux;
        }

        i = i + 1;
    }
}

// Ordenamiento por NOMBRE
void Lista::ordenamientoInsercionNombre() {
    if (ult <= 0) return;

    int i = 1;
    while (i <= ult) {
        Solicitud aux = datos[i];
        int j = i;

        while (j > 0 && aux.getNombre() < datos[j - 1].getNombre()) {
            datos[j] = datos[j - 1];
            j = j - 1;
        }

        if (i != j) {
            datos[j] = aux;
        }

        i = i + 1;
    }
}

// Búsqueda binaria por NOMBRE
int Lista::busquedaBinaria(std::string nombre) {
    int i = 0, j = ult;
    while (i <= j) {
        int medio = (i + j) / 2;
        if (datos[medio].getNombre() == nombre) {
            return medio;
        }

        if (nombre < datos[medio].getNombre()) {
            j = medio - 1;
        } else {
            i = medio + 1;
        }
    }
    return -1;
}

void darDeAltaSolicitud(Lista& listaPromedio, Lista& listaNombre) {
    if (listaPromedio.llena()) {
        std::cout << "\nLa lista está llena. No se pueden agregar más solicitudes." << std::endl;
        return;
    }

    Solicitud s;
    std::cin >> s;

    listaPromedio.insertarAlFinal(s);
    listaNombre.insertarAlFinal(s);

    listaPromedio.ordenamientoInsercionPromedio();

    listaNombre.ordenamientoInsercionNombre();

    std::cout << "\nSolicitud registrada exitosamente." << std::endl;
}

void buscarSolicitud(Lista& listaPromedio, Lista& listaNombre) {
    if (listaNombre.vacia()) {
        std::cout << "\nNo hay solicitudes registradas. Debe dar de alta una solicitud primero." << std::endl;
        return;
    }

    std::string nombre;
    std::cout << "Ingrese el nombre del alumno a buscar: ";
    std::cin.ignore();
    std::getline(std::cin, nombre);


    int posNombre = listaNombre.busquedaBinaria(nombre);

    if (posNombre != -1) {

        Solicitud encontrada = listaNombre.obtenerElemento(posNombre);

        int posPromedio = listaPromedio.buscar(encontrada.getNombre());

        if (posPromedio != -1) {
            std::cout << "\n*** BUSQUEDA BINARIA EXITOSA ***" << std::endl;
            listaPromedio.mostrarSolicitud(posPromedio);
        }
    } else {
        std::cout << "\nSolicitud no encontrada." << std::endl;
    }
}



int main() {
    // Ordenada por PROMEDIO
    Lista listaPromedio;

    // Ordenada por NOMBRE
    Lista listaNombre;

    int opcion;

    do {
         std::cout << "   SISTEMA DE SOLICITUDES - MENU" << std::endl;
    std::cout << "1. Dar de alta solicitud" << std::endl;
    std::cout << "2. Buscar solicitud (Busqueda Binaria)" << std::endl;
    std::cout << "3. Mostrar todas las solicitudes (Ranking)" << std::endl;
    std::cout << "4. Salir" << std::endl;
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                darDeAltaSolicitud(listaPromedio, listaNombre);
                break;

            case 2:
                buscarSolicitud(listaPromedio, listaNombre);
                break;

            case 3:
                listaPromedio.imprime();
                break;

            case 4:
                std::cout << "\nSaldrás del programa. ¡Hasta luego!" << std::endl;
                break;

            default:
                std::cout << "\nOpción inválida. Intente nuevamente." << std::endl;
                break;
        }

    } while (opcion != 4);

    return 0;
}
