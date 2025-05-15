#include "../include/panel.h"
#include "raylib.h"

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
