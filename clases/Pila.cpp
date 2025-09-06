#include <iostream>
  using namespace std;
  const int Tam=2;

    class Empleado{
private:
int ClaveEmpleado;
std::string Nombre;
std::string Domicilio;
float Sueldo;
std::string ReportaA;
public:
   Empleado()
{
    ClaveEmpleado=0;
    Nombre= "";
    Domicilio= "";
    Sueldo= 0;
    ReportaA= "";
}

    Empleado(int C, std::string N, std::string D, float S, std::string R) {
    ClaveEmpleado = C;
    Nombre = N;
    Domicilio = D;
    Sueldo = S;
    ReportaA = R;
}

    void Imprime()const {
     std::cout<< " Clave: " <<ClaveEmpleado<< std::endl;
     std::cout<< " Nombre: " <<Nombre<<std::endl;
     std::cout<< " Domicilio: "<<Domicilio<<std::endl;
     std::cout<< " Sueldo: " <<Sueldo<<std::endl;
     std::cout<< " Reporta a: " <<ReportaA<<std::endl;
}

    void CambiaDomic(){

        string nuevoDomicilio;
        cin.ignore();
        cout<<"Ingresa el nuevo domicilio: \\n ";   //METODOS
        getline(cin, nuevoDomicilio);
        SetDomicilio(nuevoDomicilio);

}
    void CambiaReportaA(){
       string nuevoNombre;
       cin.ignore();
       cout<<"Ingresa el nuevo nombre a quien reporta: \\n";
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
    int GetClaveEmpleado() const{return ClaveEmpleado; }
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
   std::string nuevoNombre= Nombre + " & " + JefePlanta.GetNombre();
   std::string nuevoDomicilio = Domicilio + " & " + JefePlanta.GetDomicilio();
   float nuevoSueldo = Sueldo + JefePlanta.GetSueldo();
   std::string nuevoReportaA = ReportaA + " & " + JefePlanta.GetReportaA();
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

   class ListaEstatica{
private:
Empleado datos[Tam];
int tam;
int ult;
void inserta(const Empleado &e, int pos) {
    if (Llena()) {
    cout << "No se pudo insertar: la lista está llena.\n"; //lista llena
    return;
 }
     if (pos < 0 || pos > ult + 1) {
     cout << "No se puede insertar en la posición " << pos << ".\n"; //no existe posicion
     return;
   }
    int i = ult + 1;
    while (i > pos) {
    datos[i] = datos[i - 1];
    i--;
}
    datos[pos] = e;
    ult++;
    cout << "Empleado insertado correctamente en la posición " << pos << ".\n";
}
 void eliminar(int pos){
      if(Vacia() || pos<0 || pos>ult){
        std::cout<<"No existe el empleado \\n";
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
public:
//ListaEstatica(){tam=0;}
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
    /** void Agrega(const Empleado& e, int pos) {
    if (Llena() || pos < 0 || pos > ult + 1) {
        cout << "La lista esta llena ";
        return;
    } else{
        int i=ult+1;
        while(i>pos){
            datos[i]=datos[i-1];
            i--;
        }
        datos[pos]=e;
        ult++;
    }
}**/

      void Mostrar() const {
    if(Vacia()){
        cout << "No hay empleados en la pila.\n";
        return;
    }
    cout << "Mostrando pila (de tope a base):\n";
    for(int i = ult; i >= 0; i--){
        datos[i].Imprime();
        cout << endl;
    }
}


     int buscar(int codigo) {
     if (ult == -1) {
     std::cout << "La lista no tiene elementos guardados aún.\n";
     return -1;
}
     for (int i = 0; i <= ult; i++) {
    if (datos[i].GetClaveEmpleado() == codigo) {
        std::cout << "Empleado encontrado en la posición: " << i << "\\n";
        return i;
    }
}

    std::cout << "No hubo resultados en la búsqueda.\\n";
    return -1;
}
    void Imprimir(int pos) {
    if (Vacia()) {
    std::cout << "La lista está vacía.\n";
    return;
  }
    if (pos < 0 || pos > ult) {
    std::cout << "Posición inválida.\n";
    return;
}
    datos[pos].Imprime();
}

    void push(const Empleado &e) {
        if (Llena()) {
            cout << "La pila está llena, no se puede hacer push.\n";
            return;
        }
        ult++;
        datos[ult] = e;
        cout << "Empleado agregado al tope de la pila.\n";
    }

    void pop() {
        if (Vacia()) {
            cout << "La pila está vacía, no se puede hacer pop.\n";
            return;
        }
        cout << "Empleado eliminado del tope de la pila:\n";
        datos[ult].Imprime();

        ult--;
    }
    void MostrarTope() const {
    if (Vacia()) {
        cout << "La pila está vacía, no hay tope.\n";
        return;
    }
    cout << "Elemento en el tope de la pila:\n";
    datos[ult].Imprime();
}


};


     int main()
    {
   #include <iostream>
   using namespace std;
   Empleado JefePlanta(2212, "Javier", "Martires #12", 2000, "Javier");   //OBJETOS
   Empleado JefePersonal(1452, "Manuel", "Soledad #500", 3000, "Manuel");
   ListaEstatica lista;
   //std::cin>>JefePlanta;
   //std::cout<<JefePlanta;
   //std::cout<<JefePersonal;

   int opcion;
    do {
     // cout <<"1. Agrega" <<endl;
      cout <<"2. Buscar" <<endl;
      cout <<"3. Pop" <<endl ;
      cout <<"4. Push" <<endl;
      cout <<"5. Muestra"<<endl;
      cout <<"6. Imprimir"<<endl;
      cout <<"7. Vacia"<<endl;
      cout <<"8. Llena"<<endl;
      cout <<"9. Tope"<<endl;
      cout <<"10. Salir"<<endl;
      cin >> opcion;

   switch(opcion){
      /** case 1: {
      Empleado nuevo;
      cin >> nuevo;
      lista.Agrega(nuevo, lista.getUlt() + 1);
      break;

      } **/
        break;
        case 2: {
           int codigoBuscar;
       std::cout << "Ingrese el código del empleado a buscar: ";
       std::cin >> codigoBuscar;

       lista.buscar(codigoBuscar);

         break;
        }
        case 3: { // pop
    lista.pop();
    break;
      }
        case 4: { // push
    Empleado e;
    cin >> e;
    lista.push(e);
    break;
}
        case 5: {
        lista.Mostrar();
        break; }

        case 6: {
     int pos;
      std::cout << "Ingrese la posición del empleado a imprimir (0 a " << lista.getUlt() << "): ";
      std::cin >> pos;

      lista.Imprimir(pos);  // imprime solo ese empleado
       break;
       }
     case 7: {
     if(lista.Vacia()){
       cout<<"Esta vacia la lista \n"; }
    else{cout<<"Existen elementos \n";}

       break;
        }
     case 8: {
     if(lista.Llena()){
        cout<<"La lista esta llena \\n"; }
     else{
        cout<<"Aún no esta llena \\n";
          }
          break;
        }
    case 9: {
    lista.MostrarTope();
    break;
   }
     case 10: {
        cout<<"Usted saldra del programa";
          break;
        }

}
} while(opcion != 10);
return 0;
}
