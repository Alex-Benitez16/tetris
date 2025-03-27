#include <iostream>
#include <string>

int main() {
  constexpr int board_height = 20;
  constexpr int board_width = 10;
  int board[board_width * board_height];

  for (int i = 0; i < board_width * board_height; i++) {
    board[i] = 0;
  }

  for (int i = 0; i < board_height; i++) {
    for (int j = 0; j < board_width; j++) {
      std::cout << board[board_width * i + j] << ' ';
    }
    std::cout << std::endl;
  }

  std::string input;
  getline(std::cin, input);

  // Make a shape
  int shape[4][2] = {{2, 0}, {3, 0}, {4, 0}, {4, 1}};

  // Draw shape on matrix
  for (int i = 0; i < 4; i++) {
    board[board_width * shape[i][1] + shape[i][0]] = 1;
  }

  for (int i = 0; i < board_height; i++) {
    for (int j = 0; j < board_width; j++) {
      std::cout << board[board_width * i + j] << ' ';
    }
    std::cout << std::endl;
  }

  std::cout << std::endl;
  getline(std::cin, input);

  // NOTE: each block has only one coordinate, the matrix/board coordinate.
  // The position coordinate gets calculated with a factor of conversion

  // Draw shape on matrix
  for (int i = 0; i < 4; i++) {
    board[board_width * shape[i][1] + shape[i][0]] = 0;
  }

  for (int i = 0; i < 4; i++) {
    shape[i][1] += 1;
  }

  // Draw shape on matrix
  for (int i = 0; i < 4; i++) {
    board[board_width * shape[i][1] + shape[i][0]] = 1;
  }

  for (int i = 0; i < board_height; i++) {
    for (int j = 0; j < board_width; j++) {
      std::cout << board[board_width * i + j] << ' ';
    }
    std::cout << std::endl;
  }

  return 0;
}
