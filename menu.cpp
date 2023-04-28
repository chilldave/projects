#include "menu.hpp"

menu::menu() {
  item_list.push_back({ // menu principal
    "Ingreso de datos", "Consulta de registros", "Modificacion de los registros",
    "Eliminacion de registros", "Salir"
  });
  item_list.push_back({ // menu de datos generales y datos academicos
    "Nombre", "Edad", "Estado Civil", "Direccion", "Correo",
    "Sede", "Carrera", "Curso", "Seccion"
  });
}
menu::~menu() {

}
std::vector<std::string>menu::get_item_list (int index) {
  if ( index > item_list.size() or index < 0 ) {
    return {};
  }
  return item_list[index];
}
