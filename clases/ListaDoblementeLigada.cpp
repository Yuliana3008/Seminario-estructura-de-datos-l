#include <iostream>
#include <string>
#include <stdexcept>

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
    bool vacia()const;
    nodo<T>* primero()const;
    nodo<T>* ultimo()const;
    nodo<T>* anterior(nodo<T>*)const;
    nodo<T>* siguiente(nodo<T>* )const;
    nodo<T>* localiza(T)const;
    T recupera(nodo<T>* )const;
    void imprime()const;
    void anula();
    void inserta(T elem, nodo<T>* pos);
    void elimina(nodo<T>* pos);
};

template<class T>
void LDLLSE<T>::inserta(T elem, nodo<T>* pos){
    nodo<T>* aux = new nodo<T>();
    aux->data = elem;

    if(pos == nullptr){
        aux->ant = nullptr;
        aux->sig = ancla;
        if(ancla != nullptr){
            ancla->ant = aux;
        }
        ancla = aux;
    }
    else{
        aux->ant = pos;
        aux->sig = pos->sig;
        if(pos->sig != nullptr){
            pos->sig->ant = aux;
        }
        pos->sig = aux;
    }
}

template<class T>
void LDLLSE<T>::elimina(nodo<T>* pos){
    if(vacia() || pos == nullptr){
        return;
    }

    if(pos->ant != nullptr){
        pos->ant->sig = pos->sig;
    }

    if(pos->sig != nullptr){
        pos->sig->ant = pos->ant;
    }

    if(pos == ancla){
        ancla = ancla->sig;
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
        nodo<T>* aux=ancla;
        while(aux->sig!=nullptr){
            aux=aux->sig;
        }
        return aux;
    }
}

template<class T>
nodo<T>* LDLLSE<T>::anterior(nodo<T>* pos)const{
    if(vacia()|| pos==nullptr){
        return nullptr;
    }
    else{
        return pos->ant;
    }
}

template<class T>
nodo<T>* LDLLSE<T>::siguiente(nodo<T>* pos)const{
    if(vacia()|| pos==nullptr){
        return nullptr;
    }
    else{
        return pos->sig;
    }
}

template<class T>
nodo<T>* LDLLSE<T>::localiza(T elem)const{
    nodo<T>* aux=ancla;
    while(aux!=nullptr && !(aux->data == elem)){
        aux=aux->sig;
    }
    return aux;
}

template<class T>
T LDLLSE<T>::recupera(nodo<T>* pos)const{
    if(vacia()|| pos==nullptr){
        throw runtime_error("Error: Insuficiencia de datos");
    }
    else{
        return pos->data;
    }
}

template<class T>
bool LDLLSE<T>::vacia()const{
    if(ancla==nullptr){
        return true;
    }
    return false;
}

template<class T>
void LDLLSE<T>::imprime()const{
    if(!vacia()){
        nodo<T>* aux=ancla;
        while(aux!=nullptr){
            cout<<aux->data<<endl;
            aux=aux->sig;
        }
    }
}

template<class T>
void LDLLSE<T>::anula(){
    nodo<T>* aux;
    while(ancla!=nullptr){
        aux=ancla;
        ancla=aux->sig;
        delete aux;
    }
}

// Clase SocioClub
class SocioClub{
private:
    int NumeroSocio;
    string NombreSocio;
    string Domicilio;
    int AnoIngreso;

public:
    SocioClub(): NumeroSocio(0), NombreSocio(""), Domicilio(""), AnoIngreso(0) {}

    SocioClub(int num, string nombre, string dom, int anio):
        NumeroSocio(num), NombreSocio(nombre), Domicilio(dom), AnoIngreso(anio) {}

    // Getters
    int getNumeroSocio() const { return NumeroSocio; }
    string getNombreSocio() const { return NombreSocio; }
    string getDomicilio() const { return Domicilio; }
    int getAnoIngreso() const { return AnoIngreso; }

    // Setters
    void setNumeroSocio(int num) { NumeroSocio = num; }
    void setNombreSocio(string nombre) { NombreSocio = nombre; }
    void setDomicilio(string dom) { Domicilio = dom; }
    void setAnoIngreso(int anio) { AnoIngreso = anio; }

    // Sobrecarga del operador ==
    bool operator==(const SocioClub& otro) const {
        return this->NumeroSocio == otro.NumeroSocio;
    }

    // Sobrecarga del operador << para impresión
    friend ostream& operator<<(ostream& os, const SocioClub& socio){
        os << "----------------------------------------\n";
        os << "Numero de Socio: " << socio.NumeroSocio << "\n";
        os << "Nombre: " << socio.NombreSocio << "\n";
        os << "Domicilio: " << socio.Domicilio << "\n";
        os << "Año de Ingreso: " << socio.AnoIngreso << "\n";
        os << "----------------------------------------";
        return os;
    }
};

// Funciones del menú
void registrarSocio(LDLLSE<SocioClub>& lista){
    int num, anio;
    string nombre, domicilio;

    cout << "\n=== REGISTRAR NUEVO SOCIO ===\n";
    cout << "Numero de Socio: ";
    cin >> num;
    cin.ignore();

    // Verificar que no exista el número de socio
    SocioClub temp(num, "", "", 0);
    if(lista.localiza(temp) != nullptr){
        cout << "Error: Ya existe un socio con ese numero.\n";
        return;
    }

    cout << "Nombre: ";
    getline(cin, nombre);
    cout << "Domicilio: ";
    getline(cin, domicilio);
    cout << "Año de Ingreso: ";
    cin >> anio;

    SocioClub nuevoSocio(num, nombre, domicilio, anio);
    lista.inserta(nuevoSocio, lista.ultimo());

    cout << "Socio registrado exitosamente!\n";
}

void darDeBaja(LDLLSE<SocioClub>& lista){
    int num;
    cout << "Numero de Socio a eliminar: ";
    cin >> num;

    SocioClub temp(num, "", "", 0);
    nodo<SocioClub>* pos = lista.localiza(temp);

    if(pos == nullptr){
        cout << "Error: Socio no encontrado.\n";
    }
    else{
        lista.elimina(pos);
        cout << "Socio dado de baja exitosamente.\n";
    }
}

void generarReporte(LDLLSE<SocioClub>& lista){
    if(lista.vacia()){
        cout << "No hay socios registrados.\n";
    }
    else{
        lista.imprime();
    }
}

void buscarSocio(LDLLSE<SocioClub>& lista){
    string nombre, domicilio;
    cin.ignore();

    cout << "Nombre a buscar: ";
    getline(cin, nombre);
    cout << "Domicilio a buscar: ";
    getline(cin, domicilio);

    nodo<SocioClub>* actual = lista.primero();
    bool encontrado = false;

    while(actual != nullptr){
        SocioClub socio = lista.recupera(actual);
        if(socio.getNombreSocio() == nombre && socio.getDomicilio() == domicilio){
            cout << "\nSocio encontrado:\n";
            cout << socio << endl;
            encontrado = true;
        }
        actual = lista.siguiente(actual);
    }

    if(!encontrado){
        cout << "No se encontro ningun socio con esos datos.\n";
    }
}

void imprimirSocios(LDLLSE<SocioClub>& lista){
    if(lista.vacia()){
        cout << "No hay socios registrados.\n";
    }
    else{
        lista.imprime();
    }
}

int main()
{
    LDLLSE<SocioClub> listaSocios;
    int opcion;

    do{
        cout << "1. Registrar nuevo socio\n";
        cout << "2. Dar de baja un socio\n";
        cout << "3. Generar reporte de todos los socios\n";
        cout << "4. Buscar socio por nombre y domicilio\n";
        cout << "5. Imprimir socios registrados\n";
        cout << "6. Salir\n";
        cin >> opcion;

        switch(opcion){
            case 1:
                registrarSocio(listaSocios);
                break;
            case 2:
                darDeBaja(listaSocios);
                break;
            case 3:
                generarReporte(listaSocios);
                break;
            case 4:
                buscarSocio(listaSocios);
                break;
            case 5:
                imprimirSocios(listaSocios);
                break;
            case 6:
                cout << "Saliendo del programa...\n";
                listaSocios.anula();
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
        }
    }while(opcion != 6);

    return 0;
}
