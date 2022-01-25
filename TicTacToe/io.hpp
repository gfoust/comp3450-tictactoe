#pragma once
#include "board.hpp"

namespace tic {

  Location getNextMove();

  void reportError(Location loc);

  void printBoard(Board board);

  void printResults(OptPlayer winner);

}