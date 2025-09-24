#include <iostream>
#include <string>
using namespace std;

const int Tam = 500;

class Empleado {
private:
    int ClaveEmpleado;
    string Nombre;
    string Domicilio;
    float Sueldo;
    string ReportaA;

public:
    Empleado() { ClaveEmpleado = 0; Nombre = ""; Domicilio = ""; Sueldo = 0; ReportaA = ""; }

    Empleado(int C, string N, string D, float S, string R) {
        ClaveEmpleado = C; Nombre = N; Domicilio = D; Sueldo = S; ReportaA = R;
    }

    void Imprime() const {
        cout << "Clave: " << ClaveEmpleado << endl;
        cout << "Nombre: " << Nombre << endl;
        cout << "Domicilio: " << Domicilio << endl;
        cout << "Sueldo: " << Sueldo << endl;
        cout << "Reporta a: " << ReportaA << endl;
    }

    friend istream& operator>>(istream& i, Empleado& e) {
        cout << "Ingresa clave: "; i >> e.ClaveEmpleado; i.ignore();
        cout << "Ingrese nombre: "; getline(i, e.Nombre);
        cout << "Ingresa domicilio: "; getline(i, e.Domicilio);
        cout << "Ingresa sueldo: "; i >> e.Sueldo; i.ignore();
        cout << "Ingresa a quien reporta: "; getline(i, e.ReportaA);
        return i;
    }

    friend ostream& operator<<(ostream& o, const Empleado& e) {
        o << "Clave: " << e.ClaveEmpleado << endl;
        o << "Nombre: " << e.Nombre << endl;
        o << "Domicilio: " << e.Domicilio << endl;
        o << "Sueldo: " << e.Sueldo << endl;
        o << "Reporta a: " << e.ReportaA << endl;
        return o;
    }

    int GetClaveEmpleado() const{return ClaveEmpleado;}
    string GetNombre() {return Nombre;}
    string GetDomicilio() {return Domicilio;}
    string GetReportaA() {return ReportaA;}
    float GetSueldo() {return Sueldo;}
};

class ListaEstatica {
private:
    Empleado datos[Tam];
    int ult;

public:
    ListaEstatica() { ult = -1; }

    bool vacia()const { return ult==-1; }
    bool llena()const { return ult==Tam-1; }
    int ultimo()const { return ult; }

    void push(const Empleado& e, int pos) {
        if (llena() || pos < 0 || pos > ult + 1) {
            cout << "\nError de insercion\n"; return;
        }
        int i = ult + 1;
        while (i > pos) {
            datos[i] = datos[i - 1];
            i--;
        }
        datos[pos] = e;
        ult++;
    }

    void pop(int pos) {
        if (vacia() || pos < 0 || pos > ult) {
            cout << "Error de eliminacion\n"; return;
        }
        int i = pos;
        while (i < ult) {
            datos[i] = datos[i + 1];
            i++;
        }
        ult--;
    }

    Empleado top(int pos) const {
        if (vacia() || pos < 0 || pos > ult) {
            cout << "Pila vacia\n";
            return Empleado();
        }
        return datos[pos];
    }
};


void opcionPush(ListaEstatica &pila) {
    Empleado e;
    cin >> e;
    pila.push(e, pila.ultimo() + 1);
}

void opcionPop(ListaEstatica &pila) {
    if (!pila.vacia()) {
        cout << "Empleado eliminado:\n";
        cout << pila.top(pila.ultimo()) << endl;
        pila.pop(pila.ultimo());
    } else {
        cout << "La pila esta vacia\n";
    }
}

void opcionTop(ListaEstatica &pila) {
    if (!pila.vacia()) {
        cout << "Empleado en el tope:\n";
        cout << pila.top(pila.ultimo()) << endl;
    } else {
        cout << "La pila esta vacia\n";
    }
}

int main() {
    ListaEstatica pilaEmpleados;
    int opcion;

    do {
        cout << "\n1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        cout << "4. Salir\n";
        cin >> opcion;
        cin.ignore();

        switch(opcion) {
            case 1: opcionPush(pilaEmpleados); break;
            case 2: opcionPop(pilaEmpleados); break;
            case 3: opcionTop(pilaEmpleados); break;
            case 4: cout << "Saldras del programa...\n"; break;
            default: cout << "Opcion invalida\n";
        }
    } while(opcion != 4);

    return 0;
}

