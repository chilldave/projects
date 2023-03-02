#include <iostream>
#include <string>

using namespace std;

void DatosGenerales();
void ShowData();

struct AcademicInformation{
    string sede;
    string career;
    string course;
    char section[2];
};
struct BasicInformation : AcademicInformation {
    string nombre;
    int age;
    string state;
    string address;
    string email;
}student;

int main(){

    DatosGenerales();
    
    return 0;
}

void DatosGenerales(){
    bool loop = true;

    while (loop) {

        system("clear");
        system("figlet -c 'Grupo:'");
        system("figlet -c 'Los hackers'");

        cout << "Ingrese su nombre completo: "; getline(cin, student.nombre,'\n');

        cout << "Ingrese su edad: "; cin >> student.age;
        cin.ignore();

        cout << "Ingrese su estado civil: "; getline(cin, student.state,'\n');
        cout << "Ingrese su direccion "; getline(cin, student.address,'\n');
        cout << "Ingrese su e-mail: "; getline(cin, student.email,'\n');

        ShowData();

        string conf;

        while (conf != "n") {
            cout << endl << "¿Deseas volver a intentarlo? [s/n]: "; cin >> conf;
            cin.ignore();

            if (conf == "n") {
                loop = false;
                break;
            };

            if (conf != "s") {
                cout << "Comando no reconocido!!" << endl << endl;
            }

            if (conf == "s") {
                break;
            }
        }        
    }

}
void ShowData(){
    system("clear");
    system("figlet -c 'Datos generales'");

    cout << "Nombre completo: " << student.nombre << endl;
    cout << "Edad: " << student.age << endl;
    cout << "Estado civil: " << student.state << endl;
    cout << "Direccion: "<< student.address << endl;
    cout << "E-mail:  " << student.email << endl;

    
}