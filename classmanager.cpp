#include "classmanager.hpp"

ClassManager::ClassManager() {
  x = LIMIT;
  y = LIMIT-15;
  section = "Class Manager | Grupo: Byte Band";

  initscr();
  noecho();
  cbreak();
  keypad(stdscr, true);
  use_default_colors();
  start_color();
}
ClassManager::~ClassManager() {
  refresh();
  endwin();
}
void ClassManager::start() {
  lines.push_back({});
  while(true) {
    statusbar();
    print_headers();
    int c = getch();
    input(c);
  }
}
void ClassManager::print_headers() {
  for (size_t i {}; i < (size_t)LINES - 1; i++) {
    if (i >= basic_information.size()) {
      move(i, 0);
      clrtoeol();
    } else {
      mvprintw(i, 0, "%s: ", basic_information[i].c_str());
    }
    clrtoeol();
  }
  move(y, x);
}
void ClassManager::statusbar() {
  init_pair(1, COLOR_GREEN, COLOR_BLACK);

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

  mvprintw(LINES-1, COLS-strlen(clock), "%s", clock);
  attron(COLOR_PAIR(1));
  attron(A_REVERSE);
}
void ClassManager::input(int c) {
  switch (c) {
    case KEY_DOWN:
      down();
      return;
  }
  switch (c) {
    case KEY_BACKSPACE:
      if (x == 0 && y > 0) {
        x = lines[y - 1].length();
        lines[y - 1] += lines[y];
        text_erase(y);
      } else if (x > 0) {
        lines[y].erase(--x, 1);
      }
    break;
    case KEY_ENTER:
    case 10:
    if( x < lines[y].size() ) {
      text_insert(lines[y].substr(x, lines[y].length() - x), y + 1);
      lines[y].erase(x, lines[y].length() - x);
    } else {
      text_insert("", y + 1);
    }
    x = 0;
    down();
    break;
    case KEY_BTAB:
    case KEY_CTAB:
    case KEY_STAB:
    case KEY_CATAB:
    case 9:
      lines[y].insert(x, 2, ' ');
      x+=2;
    break;
    default:
      lines[y].insert(x, 1, c);
      x++;
  }
}
void ClassManager::text_insert(std::string line, int number) {
  lines.insert(lines.begin() + number, line);
}
void ClassManager::text_erase(int number) {
  lines.erase(lines.begin() + number);
}
void ClassManager::down() {
  if ((int)y < LINES && lines.size() - 1) {
    y++;
  }
  if (x >= lines[y].length()) {
    x = lines[y].length();
  }
  move(y, x);
}
