#include "classmanager.hpp"

ClassManager::ClassManager(std::vector<std::vector<std::string>>item_list) {
  x = y = 0;
  section = "Class Manager | Grupo: Byte Band";
  menu_list = item_list;

  file = fopen(path_database, "r");
  if (file == nullptr) {
    file = fopen(path_database, "w");
  }

  while (std::fgets(buffer, sizeof(buffer), file)) {
    std::string line = buffer;
    std::istringstream ss(line);
    std::string word;
    std::vector<std::string>tmp;
    while (std::getline(ss, word, ',')) {
      tmp.push_back(word);
    }
    data_list.push_back(tmp);
    tmp.erase(tmp.begin(), tmp.end());
  }
  fclose(file);

  initscr();
  noecho();
  cbreak();
  keypad(stdscr, true);
  use_default_colors();
  start_color();
  use_default_colors();
}
ClassManager::~ClassManager() {
  refresh();
  endwin();
}
void ClassManager::start(std::vector<std::string>menu, int opc) {
  lines.push_back({});
  while(loop) {
    statusbar();
    sidebar(menu);
    print();
    int c = getch();
    input(c, menu.size(), opc);
  }
}
// show the headers to insert datas
void ClassManager::sidebar(std::vector<std::string>menu) {
  for (auto i : menu) {
    if (i.length() >= LIMIT) LIMIT = i.length() + 2;
  }

  for (size_t i {}; i < (size_t)LINES - 1; i++) {
    if (i >= menu.size()) {
      move(i, 0);
      clrtoeol();
    } else {
      mvprintw(i, 0, "%s: ", menu[i].c_str());
    }
    clrtoeol();
  }
}
// show the information of the vector 'lines', this is to save the information
void ClassManager::print() {
  for (size_t i {}; i < (size_t)LINES - 1; i++) {
    if (i >= lines.size()) {
      move(i, LIMIT);
      clrtoeol();
    } else {
      mvprintw(i, LIMIT, lines[i].c_str());
    }
    clrtoeol();
  }
  move(y, LIMIT);
}
// this is the estatus bar, show the information about us and the clock
void ClassManager::statusbar() {
  if (alert_message.length() > 0) {
    init_pair(1, COLOR_RED, COLOR_BLACK);
  } else {
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
  }

  time_t now = time(0);
  struct tm* timeinfo = localtime(&now);

  char clock[100];
  strftime(clock, sizeof(clock), "%a %b %d/%y | %H:%M ", timeinfo);

  attron(A_REVERSE);
  attron(COLOR_PAIR(1));

  for (int i{}; i<COLS; i++) {
    mvprintw(LINES-1, i, " ");
  }

  mvprintw(LINES-1, 0, section.c_str());
  mvprintw(LINES-1, section.length(), " | %s", alert_message.c_str());

  mvprintw(LINES-1, COLS-strlen(clock), "%s", clock);
  attroff(COLOR_PAIR(1));
  attroff(A_REVERSE);
}
// this manage the key press with the switch event
void ClassManager::input(int c, int max_size_enter, int number) {
  switch (c) {
    case KEY_LEFT:
      left();
      return;
    case KEY_RIGHT:
      right();
      return;
    case KEY_UP:
      up();
      return;
    case KEY_DOWN:
      if (y > max_size_enter-1) break;
      down();
      return;
  }
  switch (c) {
    // this is to erase char to char
    case KEY_BACKSPACE:
      if (x == 0 && y > 0) {
        x = lines[y - 1].length();
        lines[y - 1] += lines[y];
        text_erase(y);
        up();
      } else if (x > 0) {
        lines[y].erase(--x, 1);
      }
    break;
    // these are for the enter key
    case KEY_ENTER:
    case 10:
    if (y > max_size_enter-1) {
      for (int i = 0; i<lines.size() - 1; i++) {
        if (lines[i].length() < 1) {
          alert_message = "Algunos datos no fueron validos!";
          endwin();
          lines.erase(lines.begin(), lines.end());
          y = 0;
          start(menu_list[number], number);
          return;
        } else {
          alert_message = "";
        }
      }

      if (number == -1) {
        write_file();
      }

      if (number == 1) {
        save_item();
      }
      
      if (number == 2) {
        get_item();
      }

      if (number == 3) {
        update_item();
      }

      if (number == 4) {
        remove_item();
      }

      loop = false;
      endwin();

      break;
    }
    if( x < lines[y].size() ) {
      text_insert(lines[y].substr(x, lines[y].length() - x), y + 1);
      lines[y].erase(x, lines[y].length() - x);
    } else {
      text_insert("", y + 1);
    }
    x = 0;
    down();
    break;
    // these are for the space bar, tab, etc...
    case KEY_BTAB:
    case KEY_CTAB:
    case KEY_STAB:
    case KEY_CATAB:
    case 9:
      lines[y].insert(x, 2, ' ');
      x+=2;
    break;
    default: // this is for every key in the keyboard
      if (y > max_size_enter-1) break;
      lines[y].insert(x, 1, c);
      x++;
  }
}
// this insert the char inserted in the position of the vector line, this works like a matriz
void ClassManager::text_insert(std::string line, int number) {
  lines.insert(lines.begin() + number, line);
}
void ClassManager::text_erase(int number) {
  lines.erase(lines.begin() + number);
}
// functions to manage the datas in the file
void ClassManager::save_item() {
  const std::string charset = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  srand(time(nullptr));
  std::string result;
  int length = 5;
  result.reserve(length);

  for (int i = 0; i < length; i++) {
      result += charset[rand() % charset.length()];
  }

  file = fopen(path_database, "a");
  if (file == nullptr) {
    // crear el archivo si no existe
    file = fopen(path_database, "w");
  }

  // manipular el archivo ya que existe
  std::fprintf(file, "%s,", result.c_str()); // for id

  for (auto item : lines) {
    std::fprintf(file, "%s,", item.c_str());
  }

  std::fprintf(file, "\n");

  std::fclose(file);
}
void ClassManager::write_file() {
  file = fopen(path_database, "w");

  for (auto row : data_list) {
    for (auto item : row) {
      std::fprintf(file, "%s,", item.c_str());
    }
    std::fprintf(file, "\n");
  }

  fclose(file);
}
void ClassManager::update_item() {
  for (auto row : data_list) {
    std::string code = lines[0];
    bool valid = false;
    for (auto item : row) {
      if (code != item) continue;
      std::printf("%s", item.c_str());
      valid = true;
    }

    if (valid) {
      endwin();

      lines.erase(lines.begin(), lines.end());

      for (auto item : row) {
        lines.push_back(item);
      }
      lines.erase(lines.begin());
    }
  }
}
void ClassManager::get_item() {
  for (auto row : data_list) {
    std::string code = lines[0];
    bool valid = false;
    for (auto item : row) {
      if (code != item) continue;
      valid = true;
    }

    if (valid) {
      endwin();

      lines.erase(lines.begin(), lines.end());

      for (auto item : row) {
        lines.push_back(item);
      }
      lines.erase(lines.begin());
      start(menu_list[1], 0);
      break;
    }
  }
}
void ClassManager::remove_item() {
  std::printf("deleting\n");
}
// this manage the key press DOWN, most used for the ENTER
void ClassManager::down() {
  if ((int)y < LINES && lines.size() - 1) {
    y++;
  }
  if (x >= lines[y].length()) {
    x = lines[y].length();
  }
  move(y, x);
}
void ClassManager::up() {
  if (y > 0) {
    y--;
  }
  if (x >= lines[y].length()) {
    x = lines[y].length();
  }

  move(y, x);
}
void ClassManager::left() {
  if (x > 0) {
    x--;
    move(y, x);
  }
}
void ClassManager::right() {
  if ((int)x <= COLS && x <= lines[y].length() - 1) {
    x++;
    move(y, x);
  }
}
