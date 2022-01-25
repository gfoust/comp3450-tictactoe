#include "board.hpp"

namespace tic {

  bool inBounds(Location loc) {
    return loc.row >= 0 && loc.row < 3 && loc.col >= 0 && loc.col < 3;
  }

  Board::Board() {
    cells.resize(3);
  }

  OptPlayer Board::getCell(Location loc) {
    if (inBounds(loc)) {
      return cells[loc.row][loc.col];
    }
    else {
      throw loc;
    }
  }

  void Board::setCell(Location loc, Player player) {
    if (inBounds(loc) && !cells[loc.row][loc.col]) {
      cells[loc.row][loc.col] = player;
    }
    else {
      throw loc;
    }
  }

  bool Board::isFull() {
    for (int r = 0; r < 3; ++r) {
      for (int c = 0; c < 3; ++c) {
        if (!cells[r][c]) {
          return false;
        }
      }
    }
    return true;
  }

  OptPlayer Board::winner() {
    for (int r = 0; r < 3; ++r) {
      auto p = same({ r, 0 }, { r, 1 }, { r, 2 });
      if (p) return p;
    }

    for (int c = 0; c < 3; ++c) {
      auto p = same({ 0, c }, { 1, c }, { 2, c });
      if (p) return p;
    }

    auto p = same({ 0, 0 }, { 1, 1 }, { 2, 2 });
    if (p) return p;

    return same({ 0, 2 }, { 1, 1 }, { 2, 0 });
  }

  OptPlayer Board::same(Location a, Location b, Location c) {
    if (
      cells[a.row][a.col] &&
      cells[a.row][a.col] == cells[b.row][b.col] &&
      cells[b.row][b.col] == cells[c.row][c.col]
      ) {
      return cells[a.row][a.col];
    }
    else {
      return {};
    }
  }

}