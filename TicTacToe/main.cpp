#include "game.hpp"
#include "io.hpp"

int main() {
  tic::Game game;
  tic::printBoard(game.getBoard());
  while (!game.over()) {
    auto loc = tic::getNextMove();
    try {
      game.makeMove(loc);
    }
    catch (tic::Location loc) {
      tic::reportError(loc);
    }
    tic::printBoard(game.getBoard());
  }

  tic::printResults(game.winner());
}