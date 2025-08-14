#include <iostream>

using namespace std;

class Materia{

private:
    int Clave;
    std::string Nombre;
    std::string ProfesorTit;
    std::string LibroTexto;
public:

  Materia(int C, std::string N, std::string P, std::string L)
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
  std::string GetNombre() {return Nombre;}
  void SetProfesorTit(std::string P) {ProfesorTit=P;}
  std::string GetProfesorTit() {return ProfesorTit;}
  void SetLibroTexto(std::string L) {LibroTexto=L;}
  std::string GetLibroTexto() {return LibroTexto;}
};

int main()
{
    Materia Programacion(30, "Programacion", "Andres", "Programacion II");
    Materia BasesDatos(10, "Bases de datos", "Samuel", "Bases de datos VI");

     int opcion;
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
