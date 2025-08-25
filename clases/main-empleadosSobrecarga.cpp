#include <iostream>
using namespace std;

class Empleado{
private:
    int ClaveEmpleado;
    std::string Nombre;
    std::string Domicilio;
    float Sueldo;
    std::string ReportaA;
public:

    Empleado(int C, std::string N, std::string D, float S, std::string R)
    {
        ClaveEmpleado=C;
        Nombre= N;
        Domicilio= D;
        Sueldo= S;
        ReportaA= R;
    }

    void Imprime(){
     std::cout<< " Clave: " <<ClaveEmpleado<< std::endl;
     std::cout<< " Nombre: " <<Nombre<<std::endl;
     std::cout<< " Domicilio: "<<Domicilio<<std::endl;
     std::cout<< " Sueldo: " <<Sueldo<<std::endl;
     std::cout<< " Reporta a: " <<ReportaA<<std::endl;

    }

    void CambiaDomic(){

            string nuevoDomicilio;
            cin.ignore();
            cout<<"Ingresa el nuevo domicilio: \n ";   //METODOS
            getline(cin, nuevoDomicilio);
            SetDomicilio(nuevoDomicilio);

    }
    void CambiaReportaA(){
     string nuevoNombre;
     cin.ignore();
     cout<<"Ingresa el nuevo nombre a quien reporta: \n";
     getline(cin, nuevoNombre);                           //METODOS
     SetReportaA (nuevoNombre);
    }

    void ActualSueldo(){
        float porcentaje;
        cout<<"Ingresa el porcentaje de incremento:";
        cin >> porcentaje;

        float nuevoSueldo= GetSueldo() * (1 + porcentaje / 100);
        SetSueldo(nuevoSueldo);
    }
    void SetClaveEmpleado(int C) {ClaveEmpleado=C;}
    void SetNombre(std::string N) {Nombre=N;}
    void SetDomicilio(std::string D) {Domicilio=D;}
    void SetSueldo(float S) {Sueldo=S;}
    void SetReportaA(std::string R) {ReportaA=R;}
    float GetSueldo() {return Sueldo;}
    std::string GetNombre() {return Nombre;}
    int GetClaveEmpleado() {return ClaveEmpleado; }
    std::string GetDomicilio() {return Domicilio; }
    std::string GetReportaA() {return ReportaA; }

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
       std::string nuevoNombre= Nombre + JefePlanta.GetNombre();
       std::string nuevoDomicilio = Domicilio + JefePlanta.GetDomicilio();
       float nuevoSueldo = Sueldo + JefePlanta.GetSueldo();
       std::string nuevoReportaA = ReportaA + JefePlanta.GetReportaA();
      return Empleado(nuevaClave, nuevoNombre, nuevoDomicilio, nuevoSueldo, nuevoReportaA);

    }

     friend std::istream & operator>>(std::istream &i, Empleado& e){
     std::cout<<"Ingresa clave: ";
     i>>e.ClaveEmpleado;
     i.ignore();
     std::cout<<"Ingrese Nombre: ";
     i>>e.Nombre;
     std::cout<<"Ingresa Domicilio: ";
     i>>e.Domicilio;
     std::cout<<"Ingresa Sueldo: ";
     i>>e.Sueldo;
     i.ignore();
     std::cout<<"Ingresa a quien reporta: ";
     i>>e.ReportaA;
     return i;
  }
     friend std::ostream &operator<<(std::ostream &o, Empleado& e){
     o<<"Clave: "<<e.ClaveEmpleado<<std::endl;
     o<<"Nombre: "<<e.Nombre<<std::endl;
     o<<"Domicilio: "<<e.Domicilio<<std::endl;
     o<<"Sueldo: "<<e.Sueldo<<std::endl;
     o<<"Reporta a : "<<e.ReportaA<<std::endl;
     return o; }

};

      int main()
     {
       #include <iostream>
       using namespace std;
       Empleado JefePlanta(2212, "Javier", "Martires #12", 2000, "Javier");   //OBJETOS
       Empleado JefePersonal(1452, "Manuel", "Soledad #500", 3000, "Manuel");

       std::cin>>JefePlanta;
       //std::cin>>JefePersonal;
       std::cout<<JefePlanta;
       //std::cout<<JefePersonal;

       int opcion;

      /* Empleado j1 = JefePersonal + JefePlanta;
       j1.Imprime();

       if (JefePlanta < JefePersonal) {

        cout<<"Es correcto";
       } else {
          cout<<"Gana mas";
       }

       if (JefePersonal == JefePlanta){

          cout<<"Son la misma persona";
       }  else{
         cout<<"No son la misma persona";
       } */


   do {
       cout <<"1.Imprimir datos" <<endl;
       cout <<"2. Cambiar domicilio" <<endl;
       cout <<"3. Cambiar reportar A" <<endl ;
       cout <<"4. Actualizar sueldo \n " <<endl;
       cin >> opcion;

       switch(opcion){
           case 1: {
           int codigo;
           cout<<"Ingresa codigo del empleado: \n";
           cin >> codigo;

          /* if(codigo ==2212) {
            JefePlanta.Imprime();
           } else  {
             JefePersonal.Imprime();
           } */
           if(codigo == JefePlanta.GetClaveEmpleado()){
              JefePlanta.Imprime();
           } else if(codigo == JefePersonal.GetClaveEmpleado()){
           JefePersonal.Imprime();
           }

          }
            break;
            case 2: {
             int codigo;
             cout<<"Ingresa codigo del empleado: \n";
             cin>> codigo;

             if(codigo == JefePlanta.GetClaveEmpleado()){
                JefePlanta.CambiaDomic();
                cout<<("Domiclio actualizado \n");
             } else if (codigo == JefePersonal.GetClaveEmpleado()){
                JefePersonal.CambiaDomic();
                cout<<("Domicilio Actualizado \n");
             }
             break;
            }
            case 3: {
             int codigo;
             cout<<"Ingresa codigo del empleado: \n";
             cin>> codigo;

             if(codigo== JefePlanta.GetClaveEmpleado()){
                JefePlanta.CambiaReportaA();
                cout<<("Actualizado \n");
              } else if (codigo== JefePersonal.GetClaveEmpleado()){
                JefePersonal.CambiaReportaA();
                cout<<("Actualizado \n");
              }
             break;
            }
            case 4: {
             int codigo;
             cout<<"Ingresa codigo del empleado: \n";
             cin>> codigo;

             if(codigo== JefePlanta.GetClaveEmpleado()){
                JefePlanta.ActualSueldo();
                cout<<("Actualizado \n");
             } else  if(codigo == JefePersonal.GetClaveEmpleado()){
                JefePersonal.ActualSueldo();
                cout<<("Actualizado \n");
             }
}

}
} while(opcion != 5);
    return 0;
}
