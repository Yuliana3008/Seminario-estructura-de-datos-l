#include <iostream>

using namespace std;

class Materia{

private:
    int Clave;
    std::string Nombre;
    std::string ProfesorTit;
    std::string LibroTexto;
public:

  Materia(int C, std::string N ="", std::string P= "", std::string L = "")
  {Clave=C; Nombre=N; ProfesorTit=P; LibroTexto=L;}

  void Imprime(){
     std::cout<<("Clave: ")<<Clave<<endl;
     std::cout<<("Nombre: ")<<Nombre<<endl;
     std::cout<<("Profesor: ")<<ProfesorTit<<endl;
     std::cout<<("Libro: ")<<LibroTexto<<endl;
  }

  void CambiaClave(){
     int nuevaClave;
     cout<<("Ingresa la nueva clave: ");
     cin>>nuevaClave;
     SetClave(nuevaClave);
  }

  void CambiaProfe(){
     string nuevoNombre;
     cin.ignore();
     cout<<("Ingresa el nuevo nombre: ");
     getline(cin, nuevoNombre);
     SetProfesorTit(nuevoNombre);
  }
  void SetClave(int C) {Clave=C;}
  int GetClave() {return Clave;}
  void SetNombre(std::string N) {Nombre=N;}
  std::string GetNombre()  {return Nombre;}
  void SetProfesorTit(std::string P) {ProfesorTit=P;}
  std::string GetProfesorTit() {return ProfesorTit;}
  void SetLibroTexto(std::string L) {LibroTexto=L;}
  std::string GetLibroTexto() {return LibroTexto;}


  bool operator ==(Materia & Programacion){
         return(Nombre == Programacion.GetNombre());
  }

  bool operator !=(Materia & Programacion){
        return(Nombre != Programacion.GetNombre());
  }

  bool operator >(Materia & Programacion){
        return(Clave > Programacion.GetClave());
  }

  bool operator <(Materia & Programacion){
        return (Clave < Programacion.GetClave());
  }

  Materia operator+(Materia & Programacion){
        int nuevaClave = Clave + Programacion.Clave;
        std::string nuevoNombre = Nombre + " & " + Programacion.Nombre;
        std::string nuevoProfesor = ProfesorTit + " & " + Programacion.ProfesorTit;
        std::string nuevoLibro = LibroTexto + " & " + Programacion.LibroTexto;

        return Materia(nuevaClave, nuevoNombre, nuevoProfesor, nuevoLibro);
  }

  friend std::istream & operator>>(std::istream &i, Materia& m){
     std::cout<<"Ingresa codigo: ";
     i>>m.Clave;
     std::cout<<"Ingrese Nombre: ";
     i>>m.Nombre;
     std::cout<<"Ingresa Profesor: ";
     i>>m.ProfesorTit;
     std::cout<<"Ingresa libro texto: ";
     i>>m.LibroTexto;
     return i;
  }

  friend std::ostream &operator<<(std::ostream &o, Materia& m){
     std::cout<<"Clave: "<<m.Clave<<std::endl;
     std::cout<<"Nombre: "<<m.Nombre<<std::endl;
     std::cout<<"Profesor: "<<m.ProfesorTit<<std::endl;
     std::cout<<"Libro texto: "<<m.LibroTexto<<std::endl;
     return o;
  }
};


int main()
{
    Materia Programacion(30, "Programacion", "Andres", "Programacion II");
    Materia BasesDatos(10, "Bases de datos", "Samuel", "Bases de datos VI");

    std::cin>>BasesDatos;
    //std::cout<<"Valores de Bases de datos";
    std::cout<<BasesDatos;
     int opcion;

    /* Materia m3= Programacion + BasesDatos;
     m3.Imprime();
     if (Programacion > BasesDatos) {
    cout << "CORRECTO: es mayor";
}  else {
   cout<<""; } */


  do{
     cout<<("1. Imprimir datos materia Base de datos \n");
     cout<<("2. Cambiar nombre maestro BD \n");
     cout <<("3. Cambiar clave materia de programación \n");
     cin >> opcion;

     switch(opcion) {
     case 1: {
         BasesDatos.Imprime();
         break;
     }
     case 2: {

         BasesDatos.CambiaProfe();
         cout<<"Nombre actualizado \n";
         break;
     }
     case 3: {
         Programacion.CambiaClave();
         cout<<"Clave actualizada \n ";
         break;
     }

     }
}while(opcion !=5);
    return 0;
}
