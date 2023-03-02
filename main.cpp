#include <iostream>
#include <string>
#include <string.h>
//#include "estructura.h"
using namespace std;

void DatosGenerales();
void ShowData();

struct AcademicInformation{
    string Sede;
    string career;
    string curso;
    char section[2];
};
struct BasicInformation {
    string nombre;
    int age;
    string estado;
    string address;
    string email;
    AcademicInformation info;
}estudiante;

int main(){

    DatosGenerales();
    ShowData();


    return 0;
}

void DatosGenerales(){
    
    cout<<"Bienvenido usuario"<<endl;
    bool registre = true;

    while(registre){

    cout<<"Ingrese su nombre y apellido: "; 
    getline(cin,estudiante.nombre,'\n');
    fflush(stdin);
    cout<<"Ingrese su edad: "; cin>>estudiante.age;
    fflush(stdin);
    cout<<"Ingrese su estado civil: "; getline(cin,estudiante.estado,'\n');
    fflush(stdin);
    cout<<"Ingrese su direccion "; getline(cin,estudiante.address,'\n');
    cout<<"Ingrese su e-mail: "; getline(cin,estudiante.email,'\n');
    registre = false;
    }
    /*
    cout<<"Ingrese su nombre y apellido: "; 
    getline(cin,estudiante.nombreapellido,'\n');
    //fflush(stdin);
    cout<<"Ingrese su edad: "; cin>>estudiante.age;
    fflush(stdin);
    cout<<"Ingrese su estado civil: "; getline(cin,estudiante.estado,'\n');
    fflush(stdin);
    cout<<"Ingrese su direccion "; getline(cin,estudiante.address,'\n');
    cout<<"Ingrese su e-mail: "; getline(cin,estudiante.email,'\n');
    */

    


}
void ShowData(){
    cout<<"\n\n\n\n\n\n\n\n";
    cout<<"Nombre y apellido: "<<estudiante.nombre<<endl;
    cout<<"Edad: "<<estudiante.age <<endl;
    cout<<"Estado civil: "<<estudiante.estado <<endl;
    cout<<"Direccion: "<<estudiante.address<<endl;
    cout<<"Email:  "<<estudiante.email <<endl;

}