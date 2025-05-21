#include "../include/board.h"
#include "raylib.h"

Board::Board() : Panel() {
  for (int i = 0; i < GRID_HEIGHT; i++) {
    for (int j = 0; j < GRID_WIDTH; j++) {
      grid[i][j] = BLANK;
    }
  }
  piece_position = (Vector2){0.0, 0.0};
  piece = nullptr;
  piece_grounded_rotation = 0;
  piece_delay = 0.0;
}

Board::Board(Vector2 _offset, int _width, int _height, std::string _text)
    : Panel(_offset, _width, _height, _text) {

  for (int i = 0; i < GRID_HEIGHT; i++) {
    for (int j = 0; j < GRID_WIDTH; j++) {
      grid[i][j] = BLANK;
    }
  }
  piece_position = (Vector2){0.0, 0.0};
  piece = nullptr;
  piece_grounded_rotation = 0;
  piece_delay = 0.0;
};

void Board::set_piece_position(Vector2 _piece_position) {
  piece_position = _piece_position;
}

Vector2 Board::get_piece_position() { return piece_position; }

void Board::set_piece(Piece *_piece) {
  if (piece) {
    delete piece;
  }
  piece = _piece;
}

Piece *Board::get_piece() { return piece; }

bool Board::has_available_space(int x, int y) {
  for (int i = 0; i < 4; i++) {
    if (grid[(int)(y + piece->get_positions()[i].y)]
            [(int)(x + piece->get_positions()[i].x)] != BLANK) {
      return false;
    }
  }
  return true;
}

bool Board::check_for_horizontal_collision(int x, int y) {
  for (int i = 0; i < 4; i++) {
    if ((x + piece->get_positions()[i].x < 0 ||
         x + piece->get_positions()[i].x >= GRID_WIDTH ||
         y + piece->get_positions()[i].y < 0 ||
         y + piece->get_positions()[i].y >= GRID_HEIGHT) &&
        !has_available_space(x, y)) {
      return false;
    }
  }
  return true;
}

bool Board::piece_is_grounded() {
  int x = piece_position.x;
  int y = piece_position.y;
  y++;
  return !has_available_space(x, y);
}

void Board::move_down() {
  int x = piece_position.x;
  int y = piece_position.y;
  y++;
  piece_position = {(float)x, (float)y};
}

void Board::move_right() {
  int x = piece_position.x;
  int y = piece_position.y;
  x++;
  if (check_for_horizontal_collision(x, y)) {
    piece_position = {(float)x, (float)y};
  }
}

void Board::move_left() {
  int x = piece_position.x;
  int y = piece_position.y;
  x--;
  if (check_for_horizontal_collision(x, y)) {
    piece_position = {(float)x, (float)y};
  }
}

void Board::merge() {
  for (int i = 0; i < 4; i++) {
    grid[(int)(piece_position.y + piece->get_positions()[i].y)]
        [(int)(piece_position.x + piece->get_positions()[i].x)] =
            piece->get_color();
  }
}

void Board::reset_delay() { piece_delay = 0; }

void Board::place_piece() {
  if (piece_is_grounded()) {
    piece_delay += GetFrameTime();
  }
  if (piece_delay >= 0.5) {
    merge();
    // TODO: add piece_reset() or something
  }
}
