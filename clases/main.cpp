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
    int GetClaveEmpleado() {return ClaveEmpleado; }
    std::string GetDomicilio() {return Domicilio; }
    std::string GetReportaA() {return ReportaA; }


};

      int main()
     {
       #include <iostream>
       using namespace std;
       Empleado JefePlanta(2212, "Javier", "Martires #12", 2000, "Javier");   //OBJETOS
       Empleado JefePersonal(1452, "Manuel", "Soledad #500", 3000, "Manuel");

       int opcion;
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

           if(codigo ==2212) {
            JefePlanta.Imprime();
           } else  {
             JefePersonal.Imprime();
           }

          }
            break;
            case 2: {
             int codigo;
             cout<<"Ingresa codigo del empleado: \n";
             cin>> codigo;

             if(codigo==2212){
                JefePlanta.CambiaDomic();
                cout<<("Domiclio actualizado \n");
             } else {
                JefePersonal.CambiaDomic();
                cout<<("Domicilio Actualizado \n");
             }
             break;
            }
            case 3: {
             int codigo;
             cout<<"Ingresa codigo del empleado: \n";
             cin>> codigo;

             if(codigo== 2212){
                JefePlanta.CambiaReportaA();
                cout<<("Actualizado \n");
              } else {
                JefePersonal.CambiaReportaA();
                cout<<("Actualizado \n");
              }
             break;
            }
            case 4: {
             int codigo;
             cout<<"Ingresa codigo del empleado: \n";
             cin>> codigo;

             if(codigo==2212){
                JefePlanta.ActualSueldo();
                cout<<("Actualizado \n");
             } else {
                JefePersonal.ActualSueldo();
                cout<<("Actualizado \n");
             }
}

}
} while(opcion != 5);
    return 0;
}
