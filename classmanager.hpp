#include <ncurses.h>
#include <memory>
#include <vector>
#include <ctime>
#include <cstring>
#include <string>
#include <stdio.h>
#include <bits/stdc++.h>
#include <iostream>

class ClassManager { 
  public:
    char buffer[255];
    size_t x, y;
    int LIMIT = 0;
    bool loop = true;
    FILE *file;

    std::string alert_message = "";
    const char *path_database = "./database.csv";
    std::vector<std::vector<std::string>>menu_list;
    std::vector<std::vector<std::string>>data_list;
    std::vector<std::string>lines;
    std::string section;

    ClassManager(std::vector<std::vector<std::string>>);
    ~ClassManager();
    void start(std::vector<std::string>, int);
  protected:
    void print();
    void write_file();

    void statusbar();
    void sidebar(std::vector<std::string>);

    void text_insert(std::string, int);
    void input(int, int, int);
    void text_erase(int);
    void m_tabs(std::string&);

    void save_item();
    void update_item();
    void remove_item();
    void get_item();

    void right();
    void down();
    void up();
    void left();
};
