#include <ncurses.h>
#include <memory>
#include <string>
#include <vector>
#include <ctime>
#include <cstring>

class ClassManager { 
  public:
    size_t x, y;
    int LIMIT = 0;
    bool loop = true;

    std::vector<std::string>lines;
    std::string section;

    ClassManager();
    ~ClassManager();
    void start(std::vector<std::string>);
  protected:
    void statusbar();
    void print();
    void sidebar(std::vector<std::string>);
    void text_insert(std::string, int);
    void input(int, int);

    void text_erase(int);
    void m_tabs(std::string&);

    void save();
    void upload();
    void remove();

    void right();
    void down();
};
