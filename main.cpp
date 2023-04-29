#include <iostream>
#include "menu.hpp"
#include "classmanager.hpp"

int main () {
  int opc;
  menu menu_controller;
  std::vector<std::string>menu = menu_controller.get_item_list(0);

  while (true) {
    // system("clear");

    system("figlet -c Grupo :");
    system("figlet -c Byte Band");

    int c = 1;
    for (std::string item : menu) {
      std::printf("[%d] -> %s\n", c++, item.c_str());
    }
    std::printf("Seleccione (1-%d): ", menu.size()); std::cin >> opc;

    if (opc == 5) break;

    if (opc <= 0 or opc > 4) {
      std::printf("\n\tIngresa un numero valido en el rango (1-5)!\n");
      continue;
    }

    std::vector<std::string>menu_selected = menu_controller.get_item_list(opc);

    auto classmanager = std::make_shared<ClassManager>(menu_controller.item_list);
    classmanager->start(menu_selected, opc);
  }

  return 0;
}
