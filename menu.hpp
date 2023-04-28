#include <vector>
#include <string>
#include <cstring>

class menu {
  public:
    std::vector<std::vector<std::string>>item_list;
    menu();
    ~menu();
    std::vector<std::string>get_item_list(int index);
};
