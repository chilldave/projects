#include <iostream>
#include <string>

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
        system("figlet -c 'Los hackers'");

        // ask the information
        cout << "Ingrese su nombre completo: "; getline(cin, student.nombre,'\n');

        cout << "Ingrese su edad: "; cin >> student.age;
        cin.ignore();

        cout << "Ingrese su estado civil: "; getline(cin, student.state,'\n');
        cout << "Ingrese su direccion "; getline(cin, student.address,'\n');
        cout << "Ingrese su e-mail: "; getline(cin, student.email,'\n');

        cout << "Ingrese su sede: "; getline(cin, student.sede,'\n');
        cout << "Ingrese su carrera: "; getline(cin, student.career,'\n');
        cout << "Ingrese su curso: "; getline(cin, student.course,'\n');
        cout << "Ingrese su seccion: "; cin >> student.section;

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
    system("figlet -c 'Datos generales'"); // show a message above of the information

    cout << "Nombre completo: " << student.nombre << endl;
    cout << "Edad: " << student.age << endl;
    cout << "Estado civil: " << student.state << endl;
    cout << "Direccion: "<< student.address << endl;
    cout << "Sede: " << student.sede << endl;
    cout << "Carrera: " << student.career << endl;
    cout << "Curso: " << student.course << endl;
    cout << "Sección: " << student.section << endl;
   
}