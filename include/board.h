#ifndef BOARD_H
#define BOARD_H

#include "additional.h"
#include "panel.h"
#include "piece.h"
#include "raylib.h"

class Board : public Panel {
private:
  Color grid[GRID_HEIGHT][GRID_WIDTH];
  Vector2 piece_position;
  Piece *piece;

  bool has_available_space(int x, int y);
  bool check_for_horizontal_collision(int x, int y);
  bool piece_is_grounded();

public:
  // Constructors and destructors
  Board();
  Board(Vector2 _offset, int _width, int _height, std::string _text);

  // Getters and setters
  void set_piece_position(Vector2 _piece_position);
  Vector2 get_piece_position();
  void set_piece(Piece *_piece);
  Piece get_piece();

  void move_down();
  void move_right();
  void move_left();

  void merge();
};

#endif
