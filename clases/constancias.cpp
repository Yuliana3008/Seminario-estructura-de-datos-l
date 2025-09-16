#include <iostream>
using namespace std;
const int Tam = 2;

class Solicitud{
private:
    std::string Nombre;
    std::string Carrera;
    int MateriasAprobadas;
    float Promedio;
public:
    Solicitud(){
    Nombre = "";
    Carrera = "";
    MateriasAprobadas = 0;
    Promedio = 0;
    }

    Solicitud(std::string N, std::string C, int M, float P){
    Nombre = N;
    Carrera = C;
    MateriasAprobadas = M;
    Promedio = P;
    }

    void SetNombre(std::string N) {Nombre=N;}
    void SetCarrera(std::string C) {Carrera=C;}
    void SetMateriasAprobadas(int M) {MateriasAprobadas=M;}
    void SetPromedio(float P) {Promedio=P;}
    std::string GetNombre() {return Nombre;}
    std::string GetCarrera() {return Carrera;}
    int GetMateriasAprobadas() {return MateriasAprobadas;}
    float GetPromedio() {return Promedio;}

    bool operator ==(Solicitud &otra){
    return(Nombre == otra.GetNombre() && Carrera == otra.GetCarrera());
    }
    bool operator !=(Solicitud &otra){
    return !(*this == otra);
    }
    bool operator > (Solicitud &otra){
    return Promedio > otra.GetPromedio();
    }
    bool operator < (Solicitud &otra){
    return Promedio < otra.GetPromedio();
    }

    friend std::istream & operator>>(std::istream &i, Solicitud& e){
    std::cout<<"Nombre alumno: ";
    i>>e.Nombre;
    i.ignore();
    std::cout<<"Ingrese carrera: ";
    i>>e.Carrera;
    std::cout<<"Ingrese materias aprobadas: ";
    i>>e.MateriasAprobadas;
    std::cout<<"Ingrese promedio: ";
    i>>e.Promedio;
    return i;
    }

    friend std::ostream &operator<<(std::ostream &o, Solicitud& e){
    o<<"Nombre: "<<e.Nombre<<std::endl;
    o<<"Carrera: "<<e.Carrera<<std::endl;
    o<<"Materias Aprobadas: "<<e.MateriasAprobadas<<std::endl;
    o<<"Promedio: "<<e.Promedio<<std::endl;
    return o;
    }
};
    class ListaEstatica{
private:
    Solicitud datos[Tam];
    int tam;
    int ult;
public:
    ListaEstatica(){ult=-1;}
    bool Vacia()const{
    if(ult==-1)
    return true;
    return false;
    }
     int getUlt() const {
     return ult;
     }

     bool Llena()const{
    if(ult==Tam-1)
        return true;
        return false;
     }

     bool Encolar(Solicitud s){
       if(Llena()) return false;
       ult ++;
       datos[ult] = s;
       return true;
     }

     bool Desencolar(Solicitud &s){
       if(Vacia()) return false;
       s = datos[0];
       for(int i=0; i<ult; i++)
          datos[i] = datos[i+1];
       ult--;
       return true;
     }

};

  int main(){
  ListaEstatica cola;
  int opcion;
  do{

    cout<<"1. Dar de alta solicitud " <<endl;
    cout<<"2. Elaborar constancia " <<endl;
    cout<<"3. Salir " <<endl;
    cin>>opcion;

    switch(opcion){

    case 1: {
       if(cola.Llena()){
        cout<<"La cola esta llena \n";
        break;
       }
       Solicitud s;
       cin >>s;
       cola.Encolar(s);
       cout<<"Solicitud agregada a la cola \n";
    break;
    }

    case 2: {
       if(cola.Vacia()){
        cout<<"No existen solicitudes \n";
        break;
       }
       Solicitud s;
       cola.Desencolar(s);
       cout<<"Constancia elaborada: \n";
       cout<<s;
    break;
    }

    case 3: {
     cout<<"Usted saldra del programa \n";
    break;
    }
    }
  }while(opcion != 3);
  return 0;

  }
