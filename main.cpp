#include <iostream>
#include <string>
#include "colors.h"
using namespace std;

// struct about of academic information
struct AcademicInformation{
    string sede;
    string career;
    string course;
    char section[2];
};

// struct about basic information, has the same struct that academic information
struct BasicInformation : AcademicInformation {
    string nombre;
    int age;
    string state;
    string address;
    string email;
};

//Function Prototype
void DatosGenerales(); // function that ask the basic datas of the user
void ShowData(BasicInformation student); // fuction that show the information of the user

// function main that start our program
int main(){
    
    // invoque the function for the basic information
    DatosGenerales();
    
    return 0;
}

void DatosGenerales(){
    bool loop = true;

    // we create a new instance of the struct
    BasicInformation student;

    while (loop) {

        system("clear"); // clear the terminal

        // show the name group
        system("figlet -c 'Grupo:'"); 
        system("figlet -c 'Byte Band'");

        // ask the information
        cout << FGYellow << "\n\tIngrese su nombre completo: "<< blank; getline(cin, student.nombre,'\n');
        cout << FGYellow <<"\n\tIngrese su edad: "<< blank  ; cin >> student.age;
        cin.ignore();
        cout << FGYellow <<"\n\tIngrese su estado civil: "<< blank; getline(cin, student.state,'\n');
        cout << FGYellow <<"\n\tIngrese su direccion "<< blank; getline(cin, student.address,'\n');
        cout << FGYellow <<"\n\tIngrese su e-mail: "<< blank; getline(cin, student.email,'\n');
        cout << FGYellow <<"\n\tIngrese su sede: "<< blank; getline(cin, student.sede,'\n');
        cout << FGYellow <<"\n\tIngrese su carrera: "<< blank; getline(cin, student.career,'\n');
        cout << FGYellow <<"\n\tIngrese su curso: "<< blank; getline(cin, student.course,'\n');
        cout << FGYellow <<"\n\tIngrese su seccion: "<< blank; cin >> student.section;

        // show the infomation
        ShowData(student);

        // ask to control the loop main
        char conf;
        while (conf != 'n') {
            cout << endl << "¿Deseas volver a intentarlo? [s/n]: "; cin >> conf; // we ask
            cin.ignore();

            if (conf == 'n') { // if the 'conf' is 'n' break the program
                loop = false;
                break;
            };

            if (conf != 's') { // if the 'conf' not is 's' show a message
                cout << "Comando no reconocido!!" << endl << endl;
            }

            if (conf == 's') { // if the 'conf' is 's' continue with the program
                break;
            }
        }        
    }

}

void ShowData(BasicInformation student){
    system("clear"); // clear the terminal

    system("figlet -c 'Registrado'"); // show a message above of the information
    cout<<" -----------------------------------------------------------------------------"<<endl;
    cout << FGYellow <<"\tNombre completo: "<< blank <<student.nombre << endl;
    cout << FGYellow <<"\n\tEdad: " << blank << student.age << endl;
    cout << FGYellow <<"\n\tEstado civil: " << blank << student.state << endl;
    cout << FGYellow <<"\n\tDireccion: "<< blank << student.address << endl;
    cout << FGYellow <<"\n\tSede: " << blank << student.sede << endl;
    cout << FGYellow <<"\n\tCarrera: " << blank << student.career << endl;
    cout << FGYellow <<"\n\tCurso: " << blank << student.course << endl;
    cout << FGYellow <<"\n\tSección: " << blank << student.section << endl;
   
}