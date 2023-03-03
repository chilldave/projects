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
        cout << "\n\tIngrese su nombre completo: "; getline(cin, student.nombre,'\n');
        cout << "\n\tIngrese su edad: "; cin >> student.age;
        cin.ignore();
        cout << "\n\tIngrese su estado civil: "; getline(cin, student.state,'\n');
        cout << "\n\tIngrese su direccion "; getline(cin, student.address,'\n');
        cout << "\n\tIngrese su e-mail: "; getline(cin, student.email,'\n');
        cout << "\n\tIngrese su sede: "; getline(cin, student.sede,'\n');
        cout << "\n\tIngrese su carrera: "; getline(cin, student.career,'\n');
        cout << "\n\tIngrese su curso: "; getline(cin, student.course,'\n');
        cout << "\n\tIngrese su seccion: "; cin >> student.section;

        // show the infomation
        ShowData(student);

        // ask to control the loop main
        string conf;
        while (conf != "n") {
            cout << endl << "¿Deseas volver a intentarlo? [s/n]: "; cin >> conf; // we ask
            cin.ignore();

            if (conf == "n") { // if the 'conf' is 'n' break the program
                loop = false;
                break;
            };

            if (conf != "s") { // if the 'conf' not is 's' show a message
                cout << "Comando no reconocido!!" << endl << endl;
            }

            if (conf == "s") { // if the 'conf' is 's' continue with the program
                break;
            }
        }        
    }

}

void ShowData(BasicInformation student){
    system("clear"); // clear the terminal

    system("figlet -c 'Registrado'"); // show a message above of the information
    cout<<" ---------------------------------------------------------------------------------"<<endl;
    cout << FGYellow <<"\tNombre completo: " << blank <<student.nombre << endl;
    cout << FGYellow <<"\n\tEdad: " << blank << student.age << endl;
    cout << FGYellow <<"\n\tEstado civil: " << blank << student.state << endl;
    cout << FGYellow <<"\n\tDireccion: "<< blank << student.address << endl;
    cout << FGYellow <<"\n\tSede: " << blank << student.sede << endl;
    cout << FGYellow <<"\n\tCarrera: " << blank << student.career << endl;
    cout << FGYellow <<"\n\tCurso: " << blank << student.course << endl;
    cout << FGYellow <<"\n\tSección: " << blank << student.section << endl;
   
}