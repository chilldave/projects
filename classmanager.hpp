#include <ncurses.h>
#include <memory>
#include <string>
#include <vector>
#include <ctime>
#include <cstring>

class ClassManager { 
  public:
    size_t x, y;
    const int LIMIT = 25;

    std::vector<std::string>basic_information = {
      "Nombre", "Edad", "Estado Civil", "Direccion", "Correo"
    };
    std::vector<std::string>academic_information = {
      "Sede", "Carrera", "Curso", "Seccion"
    };
    std::vector<std::string>lines;
    std::string section;

    ClassManager();
    ~ClassManager();
    void start();
  protected:
    void statusbar();
    void print_headers();
    void text_insert(std::string, int);
    void input(int);

    void text_erase(int);
    void m_tabs(std::string&);

    void right();
    void down();
};
