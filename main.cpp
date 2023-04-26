#include "classmanager.hpp"

int main () {

  auto classmanager = std::make_shared<ClassManager>();
  classmanager->start();

  return 0;
}
