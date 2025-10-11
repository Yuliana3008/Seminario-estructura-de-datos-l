#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

template<class T>
class LSLSE;

template<class T>
class node{
private:
    T data;
    node<T>* sig;
public:
    node():sig(nullptr){};
    friend class LSLSE<T>;
};

template<class T>
class LSLSE{
private:
    node<T>* lista;
public:
    LSLSE():lista(nullptr){};
    bool vacia()const;
    node<T>* ultimo()const;
    node<T>* primero()const;
    node<T>* anterior(node<T>* pos)const;
    node<T>* siguiente(node<T>* pos)const;
    void insertar(node<T>* pos, T elem);
    bool eliminar(node<T>* pos);
    void imprimir()const;
    node<T>* buscar(const T& elem)const;
    int contar()const;
    T obtenerDato(node<T>* pos)const;
};

template<class T>
int LSLSE<T>::contar()const{
    int contador = 0;
    node<T>* aux = lista;
    while(aux != nullptr){
        contador++;
        aux = aux->sig;
    }
    return contador;
}

template<class T>
node<T>* LSLSE<T>::buscar(const T& elem)const{
    node<T>* aux = lista;
    while(aux != nullptr){
        if(aux->data == elem){
            return aux;
        }
        aux = aux->sig;
    }
    return nullptr;
}

template<class T>
void LSLSE<T>::imprimir()const{
    node<T>* aux=lista;
    while(aux!=nullptr){
        cout<<aux->data<<endl;
        aux=aux->sig;
    }
}

template<class T>
bool LSLSE<T>::eliminar(node<T>* pos){
    if(vacia() || pos==nullptr){
        return false;
    }
    if(pos==lista){
        lista=lista->sig;
    }
    else{
        anterior(pos)->sig=pos->sig;
    }
    delete pos;
    return true;
}

template<class T>
void LSLSE<T>::insertar(node<T>* pos, T elem){
    node<T>* aux= new node<T>;
    aux->data=elem;
    if(pos==nullptr){
        aux->sig=lista;
        lista=aux;
    }
    else{
        aux->sig=pos->sig;
        pos->sig=aux;
    }
}

template<class T>
node<T>* LSLSE<T>::anterior(node<T>* pos)const{
    if(vacia() || pos==nullptr){
        return nullptr;
    }
    node<T>* aux=lista;
    while(aux!=nullptr && aux->sig!=pos){
        aux=aux->sig;
    }
    return aux;
}

template<class T>
node<T>* LSLSE<T>::primero()const{
    if(vacia()){
        return nullptr;
    }
    return lista;
}

template<class T>
node<T>* LSLSE<T>::ultimo()const{
    if(vacia()){
        return nullptr;
    }
    node<T>* aux=lista;
    while(aux->sig!=nullptr){
        aux=aux->sig;
    }
    return aux;
}

template<class T>
bool LSLSE<T>::vacia()const{
    if(lista==nullptr)
        return true;
    return false;
}

template<class T>
node<T>* LSLSE<T>::siguiente(node<T>* pos)const{
    if(vacia() || pos==nullptr){
        return nullptr;
    }
    return pos->sig;
}

template<class T>
T LSLSE<T>::obtenerDato(node<T>* pos)const{
    return pos->data;
}

// Clase SocioClub
class SocioClub{
private:
    int NumeroSocio;
    string NombreSocio;
    string Domicilio;
    int AnoIngreso;

public:
    // Constructores
    SocioClub(): NumeroSocio(0), NombreSocio(""), Domicilio(""), AnoIngreso(0) {}

    SocioClub(int num, string nombre, string dom, int ano):
        NumeroSocio(num), NombreSocio(nombre), Domicilio(dom), AnoIngreso(ano) {}

    // Métodos de acceso
    int getNumeroSocio() const { return NumeroSocio; }
    string getNombreSocio() const { return NombreSocio; }
    string getDomicilio() const { return Domicilio; }
    int getAnoIngreso() const { return AnoIngreso; }

    void setNumeroSocio(int num) { NumeroSocio = num; }
    void setNombreSocio(string nombre) { NombreSocio = nombre; }
    void setDomicilio(string dom) { Domicilio = dom; }
    void setAnoIngreso(int ano) { AnoIngreso = ano; }

    // Sobrecarga de operadores
    bool operator==(const SocioClub& otro) const {
        return this->NumeroSocio == otro.NumeroSocio;
    }

    bool operator<(const SocioClub& otro) const {
        return this->NumeroSocio < otro.NumeroSocio;
    }

    bool operator>(const SocioClub& otro) const {
        return this->NumeroSocio > otro.NumeroSocio;
    }

    friend ostream& operator<<(ostream& os, const SocioClub& socio){
        os << "Numero de Socio: " << socio.NumeroSocio << endl;
        os << "Nombre: " << socio.NombreSocio << endl;
        os << "Domicilio: " << socio.Domicilio << endl;
        os << "Ano de Ingreso: " << socio.AnoIngreso << endl;
        return os;
    }
};

// Funciones del sistema
void registrarSocio(LSLSE<SocioClub>& lista){
    int num, ano;
    string nombre, domicilio;

    cout << "\n=== REGISTRAR NUEVO SOCIO ===" << endl;
    cout << "Numero de Socio: ";
    cin >> num;
    cin.ignore();

    // Verificar que no exista el número de socio
    SocioClub temp(num, "", "", 0);
    if(lista.buscar(temp) != nullptr){
        cout << "\nError: Ya existe un socio con ese numero!" << endl;
        return;
    }

    cout << "Nombre del Socio: ";
    getline(cin, nombre);
    cout << "Domicilio: ";
    getline(cin, domicilio);
    cout << "Ano de Ingreso: ";
    cin >> ano;

    SocioClub nuevoSocio(num, nombre, domicilio, ano);

    // Insertar ordenado por número de socio
    if(lista.vacia()){
        lista.insertar(nullptr, nuevoSocio);
    }
    else{
        node<SocioClub>* actual = lista.primero();
        node<SocioClub>* anterior = nullptr;
        bool insertado = false;

        while(actual != nullptr){
            SocioClub datoActual = lista.obtenerDato(actual);
            if(nuevoSocio < datoActual){
                lista.insertar(anterior, nuevoSocio);
                insertado = true;
                break;
            }
            anterior = actual;
            actual = lista.siguiente(actual);
        }

        if(!insertado){
            lista.insertar(lista.ultimo(), nuevoSocio);
        }
    }

    cout << "\nSocio registrado exitosamente!" << endl;
}

void darDeBaja(LSLSE<SocioClub>& lista){
    if(lista.vacia()){
        cout << "\nNo hay socios registrados." << endl;
        return;
    }

    int num;
    cout << "\n=== DAR DE BAJA SOCIO ===" << endl;
    cout << "Ingrese el numero de socio a eliminar: ";
    cin >> num;

    SocioClub temp(num, "", "", 0);
    node<SocioClub>* pos = lista.buscar(temp);

    if(pos == nullptr){
        cout << "\nSocio no encontrado." << endl;
    }
    else{
        if(lista.eliminar(pos)){
            cout << "\nSocio dado de baja exitosamente." << endl;
        }
        else{
            cout << "\nError al dar de baja al socio." << endl;
        }
    }
}

void generarReporte(const LSLSE<SocioClub>& lista){
    if(lista.vacia()){
        cout << "\nNo hay socios registrados." << endl;
        return;
    }
    lista.imprimir();
}

void buscarSocio(const LSLSE<SocioClub>& lista){
    if(lista.vacia()){
        cout << "\nNo hay socios registrados." << endl;
        return;
    }

    string busqueda;
    cout << "Ingrese nombre o domicilio a buscar: ";
    cin.ignore();
    getline(cin, busqueda);

    node<SocioClub>* actual = lista.primero();
    bool encontrado = false;

    cout << "\nResultados de la busqueda:" << endl;
    while(actual != nullptr){
        SocioClub datoActual = lista.obtenerDato(actual);
        if(datoActual.getNombreSocio().find(busqueda) != string::npos ||
           datoActual.getDomicilio().find(busqueda) != string::npos){
            cout << datoActual << endl;
            encontrado = true;
        }
        actual = lista.siguiente(actual);
    }

    if(!encontrado){
        cout << "No se encontraron coincidencias." << endl;
    }
}

void calcularTotal(const LSLSE<SocioClub>& lista){
    int total = lista.contar();
    cout << "Total de socios registrados: " << total << endl;
}

void mostrarMenu(){
    cout << "1. Registrar nuevo socio" << endl;
    cout << "2. Dar de baja un socio" << endl;
    cout << "3. Generar reporte de socios" << endl;
    cout << "4. Buscar socio" << endl;
    cout << "5. Calcular total de socios" << endl;
    cout << "6. Salir" << endl;
}

int main(){
    LSLSE<SocioClub> clubSocios;
    int opcion;

    do{
        mostrarMenu();
        cin >> opcion;

        switch(opcion){
            case 1:
                registrarSocio(clubSocios);
                break;
            case 2:
                darDeBaja(clubSocios);
                break;
            case 3:
                generarReporte(clubSocios);
                break;
            case 4:
                buscarSocio(clubSocios);
                break;
            case 5:
                calcularTotal(clubSocios);
                break;
            case 6:
                cout << "\nGracias por usar el sistema. Adios!" << endl;
                break;
            default:
                cout << "\nOpcion invalida. Intente nuevamente." << endl;
        }

    } while(opcion != 6);

    return 0;
}
