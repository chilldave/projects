#include "classmanager.hpp"

ClassManager::ClassManager() {
  x = y = 0;
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
    sidebar();
    print();
    int c = getch();
    input(c);
  }
}
// show the headers to insert datas
void ClassManager::sidebar() {
  for (auto i : headers) {
    if (i.length() >= LIMIT) LIMIT = i.length() + 2;
  }

  for (size_t i {}; i < (size_t)LINES - 1; i++) {
    if (i >= headers.size()) {
      move(i, 0);
      clrtoeol();
    } else {
      mvprintw(i, 0, "%s: ", headers[i].c_str());
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
// this manage the key press with the switch event
void ClassManager::input(int c) {
  switch (c) {
    case KEY_LEFT:
      return;
    case KEY_RIGHT:
      return;
    case KEY_UP:
      return;
    case KEY_DOWN:
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
      } else if (x > 0) {
        lines[y].erase(--x, 1);
      }
    break;
    // these are for the enter key
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
