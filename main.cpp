#include <iostream>
#include "menu.hpp"
#include "classmanager.hpp"

int main () {
  int opc;
  menu menu_controller;
  std::vector<std::string>menu = menu_controller.get_item_list(0);

  int c = 1;

  for (std::string item : menu) {
    std::printf("[%d] -> %s\n", c++, item.c_str());
  }
  std::printf("Seleccione (1-%d): ", menu.size()); std::cin >> opc;

  std::vector<std::string>menu_selected = menu_controller.get_item_list(opc);

  auto classmanager = std::make_shared<ClassManager>();
  classmanager->start(menu_selected);

  return 0;
}
