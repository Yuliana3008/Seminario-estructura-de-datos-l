#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

template<class T>
class LDLLSE;

template<class T>
class nodo{
private:
    T data;
    nodo<T>* sig;
    nodo<T>* ant;
public:
    nodo():sig(nullptr), ant(nullptr){};
    friend class LDLLSE<T>;
};

template<class T>
class LDLLSE{
private:
    nodo<T>* ancla;
public:
    LDLLSE(): ancla(nullptr){};
    ~LDLLSE(){ anula(); }
    bool vacia()const;
    nodo<T>* primero()const;
    nodo<T>* ultimo()const;
    nodo<T>* anterior(nodo<T>*)const;
    nodo<T>* siguiente(nodo<T>* )const;
    nodo<T>* localiza(T)const;
    T recupera(nodo<T>* )const;
    void imprime()const;
    void anula();
    void inserta(nodo<T>* pos, T elem);
    void elimina(nodo<T>* pos);
};

template<class T>
void LDLLSE<T>::inserta(nodo<T>* pos, T elem){
    nodo<T>* nuevo = new nodo<T>();
    nuevo->data = elem;

    if(vacia()){
        ancla = nuevo;
    }
    else if(pos == nullptr){
        nodo<T>* ult = ultimo();
        ult->sig = nuevo;
        nuevo->ant = ult;
    }
    else if(pos == ancla){
        nuevo->sig = ancla;
        ancla->ant = nuevo;
        ancla = nuevo;
    }
    else{
        nuevo->sig = pos;
        nuevo->ant = pos->ant;
        if(pos->ant != nullptr){
            pos->ant->sig = nuevo;
        }
        pos->ant = nuevo;
    }
}

template<class T>
void LDLLSE<T>::elimina(nodo<T>* pos){
    if(vacia() || pos == nullptr){
        return;
    }

    if(pos == ancla){
        ancla = pos->sig;
        if(ancla != nullptr){
            ancla->ant = nullptr;
        }
    }
    else{
        if(pos->ant != nullptr){
            pos->ant->sig = pos->sig;
        }
        if(pos->sig != nullptr){
            pos->sig->ant = pos->ant;
        }
    }
    delete pos;
}

template<class T>
nodo<T>* LDLLSE<T>::primero()const{
    return ancla;
}

template<class T>
nodo<T>* LDLLSE<T>::ultimo()const{
    if(vacia()){
        return nullptr;
    }
    else{
        nodo<T>* aux = ancla;
        while(aux->sig != nullptr){
            aux = aux->sig;
        }
        return aux;
    }
}

template<class T>
nodo<T>* LDLLSE<T>::anterior(nodo<T>* pos)const{
    if(vacia() || pos == nullptr){
        return nullptr;
    }
    else{
        return pos->ant;
    }
}

template<class T>
nodo<T>* LDLLSE<T>::siguiente(nodo<T>* pos)const{
    if(vacia() || pos == nullptr){
        return nullptr;
    }
    else{
        return pos->sig;
    }
}

template<class T>
nodo<T>* LDLLSE<T>::localiza(T elem)const{
    nodo<T>* aux = ancla;
    while(aux != nullptr && aux->data != elem){
        aux = aux->sig;
    }
    return aux;
}

template<class T>
T LDLLSE<T>::recupera(nodo<T>* pos)const{
    if(vacia() || pos == nullptr){
        throw runtime_error("Posición inválida");
    }
    else{
        return pos->data;
    }
}

template<class T>
bool LDLLSE<T>::vacia()const{
    return ancla == nullptr;
}

template<class T>
void LDLLSE<T>::imprime()const{
    if(!vacia()){
        nodo<T>* aux = ancla;
        while(aux != nullptr){
            cout << aux->data << endl;
            aux = aux->sig;
        }
    }
}

template<class T>
void LDLLSE<T>::anula(){
    nodo<T>* aux;
    while(ancla != nullptr){
        aux = ancla;
        ancla = aux->sig;
        delete aux;
    }
}


class Solicitud{
private:
    string nombre;
    string carrera;
    int materiasAprobadas;
    double promedio;
public:
    Solicitud(): nombre(""), carrera(""), materiasAprobadas(0), promedio(0.0){}
    Solicitud(string nom, string carr, int mat, double prom):
        nombre(nom), carrera(carr), materiasAprobadas(mat), promedio(prom){}

    string getNombre()const{ return nombre; }
    string getCarrera()const{ return carrera; }
    int getMateriasAprobadas()const{ return materiasAprobadas; }
    double getPromedio()const{ return promedio; }


    friend istream& operator>>(istream& is, Solicitud& s){
        cout << "Nombre del alumno: ";
        is.ignore();
        getline(is, s.nombre);
        cout << "Carrera: ";
        getline(is, s.carrera);
        cout << "Materias aprobadas: ";
        is >> s.materiasAprobadas;
        cout << "Promedio general: ";
        is >> s.promedio;
        return is;
    }
         friend ostream& operator<<(ostream& os, const Solicitud& s){
        os << "Numero: " << s.nombre << endl;
        os << "Carrera: " << s.carrera << endl;
        os << "Materias aprobadas: " << s.materiasAprobadas << endl;
        os << "Promedio general: " << s.promedio << endl;

        return os;
    }

    bool operator!=(const Solicitud& other)const{
        return nombre != other.nombre;
    }
};

// Clase Cola
template<class T>
class Cola{
private:
    LDLLSE<T> lista;
public:
    Cola(){}
    ~Cola(){}

    void encolar(T elem){
        lista.inserta(nullptr, elem);
    }

    T desencolar(){
        if(vacia()){
            throw runtime_error("Cola vacía, no se puede desencolar");
        }
        nodo<T>* primero = lista.primero();
        T dato = lista.recupera(primero);
        lista.elimina(primero);
        return dato;
    }

    T frente()const{
        if(vacia()){
            throw runtime_error("Cola vacía");
        }
        return lista.recupera(lista.primero());
    }

    bool vacia()const{
        return lista.vacia();
    }

    void imprimir()const{
        lista.imprime();
    }
};

// funciones


void darAltaSolicitud(Cola<Solicitud>& cola){
    Solicitud nueva;
    cin >> nueva;
    cola.encolar(nueva);
    cout << "\n Solicitud registrada exitosamente." << endl;
}

void elaborarConstancia(Cola<Solicitud>& cola){
    if(cola.vacia()){
        cout << "\nNo hay solicitudes pendientes." << endl;
    }
    else{
        try{
            Solicitud actual = cola.desencolar();
            cout << actual;
            cout << "\n✓ Constancia elaborada y solicitud atendida." << endl;
        }
        catch(const exception& e){
            cout << "Error: " << e.what() << endl;
        }
    }
}

int main(){
    Cola<Solicitud> colaSolicitudes;
    int opcion;

    do{
    cout << "1. Dar de alta solicitud" << endl;
    cout << "2. Elaborar constancia" << endl;
    cout << "3. Salir" << endl;
    cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch(opcion){
            case 1:
                darAltaSolicitud(colaSolicitudes);
                break;
            case 2:
                elaborarConstancia(colaSolicitudes);
                break;
            case 3:
                cout << "\nSaldra del programa" << endl;
                break;
            default:
                cout << "\nOpción inválida. Intente nuevamente." << endl;
        }
    }while(opcion != 4);

    return 0;
}
