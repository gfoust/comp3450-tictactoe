#include "io.hpp"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

namespace tic {

  char charFor(OptPlayer player) {
    if (player) {
      if (*player == Player::Player1) {
        return 'X';
      }
      else {
        return 'O';
      }
    }
    else {
      return ' ';
    }
  }

  void reportError(Location loc) {
    cout << "Invalid location: " << loc.row + 1 << ", " << loc.col + 1 << "\n\n";
  }

  Location getNextMove() {
    int row, col;
    cin >> row >> col;
    cout << '\n';
    // Convert from 1-based to 0-based indexes
    return { row - 1, col - 1 };
  }

  void printBoard(Board board) {
    for (int r = 0; r < 3; ++r) {
      if (r != 0) {
        cout << "---+---+---\n";
      }
      for (int c = 0; c < 3; ++c) {
        if (c == 0) {
          cout << ' ';
        }
        else {
          cout << " | ";
        }
        cout << charFor(board.getCell({ r, c }));
      }
      cout << '\n';
    }
    cout << '\n';
  }

  void printResults(OptPlayer winner) {
    if (winner) {
      if (winner == Player::Player1) {
        cout << "Player 1 wins!\n";
      }
      else {
        cout << "Player 2 wins!\n";
      }
    }
    else {
      cout << "Tie game.\n";
    }
  }

}
