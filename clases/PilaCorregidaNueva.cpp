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

     bool operator ==(Empleado & JefePlanta){
    return (ClaveEmpleado == JefePlanta.GetClaveEmpleado());
}

    bool operator !=(Empleado & JefePlanta){
    return (ClaveEmpleado != JefePlanta.GetClaveEmpleado());
}

    bool operator >(Empleado & JefePlanta){
    return (Sueldo > JefePlanta.GetSueldo());
}

    bool operator <(Empleado & JefePlanta){
    return(Sueldo < JefePlanta.GetSueldo());
}

   Empleado operator +(Empleado & JefePlanta) {
   int nuevaClave = ClaveEmpleado + JefePlanta.GetClaveEmpleado();
   std::string nuevoNombre= Nombre + " & " + JefePlanta.GetNombre();
   std::string nuevoDomicilio = Domicilio + " & " + JefePlanta.GetDomicilio();
   float nuevoSueldo = Sueldo + JefePlanta.GetSueldo();
   std::string nuevoReportaA = ReportaA + " & " + JefePlanta.GetReportaA();
   return Empleado(nuevaClave, nuevoNombre, nuevoDomicilio, nuevoSueldo, nuevoReportaA);

}

    void SetClaveEmpleado(int C) {ClaveEmpleado=C;}
    void SetNombre(std::string N) {Nombre=N;}
    void SetDomicilio(std::string D) {Domicilio=D;}
    void SetSueldo(float S) {Sueldo=S;}
    void SetReportaA(std::string R) {ReportaA=R;}
    float GetSueldo() {return Sueldo;}
    std::string GetNombre() {return Nombre;}
    int GetClaveEmpleado() const{return ClaveEmpleado; }
    std::string GetDomicilio() {return Domicilio; }
    std::string GetReportaA() {return ReportaA; }
};

class ListaEstatica {
private:
    Empleado datos[Tam];
    int ult;
     void inserta(const Empleado &e, int pos) {
        if (llena()) {
            cout << "La lista esta llena.\n";
            return;
        }
        if (pos < 0 || pos > ult + 1) {
            cout << "No se puede insertar en la posicion " << pos << ".\n";
            return;
        }
        int i = ult + 1;
        while (i > pos) {
            datos[i] = datos[i - 1];
            i--;
        }
        datos[pos] = e;
        ult++;
        cout << "Empleado insertado correctamente en la posicion " << pos << ".\n";
    }
    void eliminar(int pos){
        if(vacia() || pos<0 || pos>ult){
            std::cout<<"No existe el empleado \n";
        }
        else{
            int i=pos;
            while(i<ult){
               datos[i]=datos[i+1];
               i++;
            }
            ult--;
        }
    }
      void Mostrar() const {
      if(vacia()){
      cout << "No hay empleados en la lista.\\n";
     } else {
     for(int i = 0; i <= ult; i++){
        datos[i].Imprime();
        cout << endl;
    }
}

}
     int buscar(int codigo) {
     if (ult == -1) {
     std::cout << "La lista no tiene elementos guardados aun.\n";
     return -1;
} }

public:
    ListaEstatica() { ult = -1; }

     bool vacia()const{
        if(ult==-1)
            return true;
        return false;
    }

     bool llena()const{
        if(ult==Tam-1)
            return true;
        return false;
    }
    int ultimo()const{
        return ult;
    }

      void push(const Empleado& e, int pos) {
        if (llena() || pos < 0 || pos > ult + 1) {
            cout << "\nError de insercion\n"; return;   //push
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
        int i = pos;   //pop
        while (i < ult) {
            datos[i] = datos[i + 1];
            i++;
        }
        ult--;
    }


       Empleado top(int pos) const {
        if (vacia() || pos < 0 || pos > ult) {
            cout << "Pila vacia\n";
            return Empleado(); //tope
        }
        return datos[pos];
    }
};

int main() {
    ListaEstatica pilaEmpleados;
    int opcion;

    do {
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        cout << "4. Salir\n";
        cin>>opcion;
        cin.ignore();

        switch(opcion) {
        case 1: {
            Empleado e;
            cin >> e;
            pilaEmpleados.push(e, pilaEmpleados.ultimo() +1);
            break;
        }
        case 2:
             if (!pilaEmpleados.vacia()) {
            cout << "Empleado eliminado:\n";
            cout << pilaEmpleados.top(pilaEmpleados.ultimo()) << endl;
            pilaEmpleados.pop(pilaEmpleados.ultimo());
        } else {
            cout << "La pila esta vacia\n";
        } break;
        case 3:
            if (!pilaEmpleados.vacia()) {
            cout << "Empleado en el tope:\n";
            cout << pilaEmpleados.top(pilaEmpleados.ultimo()) << endl;
        } else {
            cout << "La pila esta vacia\n";
        }
        break;
        case 4:
            cout << "Saldras del programa...\n";
            break;
        default:
            cout << "Opción inválida\n";
        }
    } while(opcion != 4);

    return 0;
}


