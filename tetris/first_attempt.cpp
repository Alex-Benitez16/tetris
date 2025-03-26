#include <cmath>
#include <ctime>
#include <ncurses.h>

class Block {
private:
  char shape[4];
  int x;
  int y;
  int last_x;
  int last_y;
  WINDOW *win;

public:
  Block(int set_x, int set_y, WINDOW *set_win) {
    shape[0] = '[';
    shape[1] = ' ';
    shape[2] = ']';
    shape[3] = '\0';
    x = set_x;
    y = set_y;
    last_x = set_x;
    last_y = set_y;
    win = set_win;
  }
  Block() {
    shape[0] = '[';
    shape[1] = ' ';
    shape[2] = ']';
    shape[3] = '\0';
    x = 0;
    y = 0;
    last_x = 0;
    last_y = 0;
    win = stdscr;
  }

private:
  bool bounds_arent_valid() {
    int height, width;
    getmaxyx(win, height, width);

    return y <= 0 || y >= height - 1 || x <= 0 || x >= width - 1;
  }

public:
  void show(int mv_x, int mv_y) { mvwprintw(win, mv_y, mv_x, shape); }
  void erase(int er_x, int er_y) { mvwprintw(win, er_y, er_x, "   "); }
  void move() {
    erase(last_x, last_y);
    show(x, y);
  }
  void update_coordinates() {
    last_x = x;
    last_y = y;
  }
  void fall() {
    if (bounds_arent_valid())
      return;
    update_coordinates();
    y += 1;
    move();
  }
  void move_right() {
    update_coordinates();
    if (bounds_arent_valid())
      return;
    x += 1;
    move();
  }
  void move_left() {
    if (bounds_arent_valid())
      return;
    update_coordinates();
    x -= 1;
    move();
  }
};

int main() {
  initscr();

  Block block(1, 1, stdscr);
  block.move();
  refresh();

  getch();

  clock_t start = clock();
  double interval = 0.4;

  while (true) {
    clock_t check = clock();
    double elapsed_time = (double)(check - start) / CLOCKS_PER_SEC;
    if (elapsed_time >= interval) {
      block.fall();
      refresh();
      start = clock();
    }
  }

  endwin();

  return 0;
}
