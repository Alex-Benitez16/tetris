#include "../include/panel.h"
#include "raylib.h"

// Constructors and destructors
Panel::Panel() {
  offset = (Vector2){0.0, 0.0};
  width = 16;
  height = 16;
  text = "";
}

Panel::Panel(Vector2 _offset, int _width, int _height, std::string _text) {
  offset = _offset;
  width = _width;
  height = _height;
  text = _text;
}

Panel::~Panel() {}

// Getters and setters
Vector2 Panel::get_offset() { return offset; }
int Panel::get_width() { return width; }
int Panel::get_height() { return height; }
std::string Panel::get_text() { return text; }
