#include "game.hpp"

namespace tic {

  void Game::makeMove(Location loc) {
    board.setCell(loc, turn);
    turn = (turn == Player::Player1 ? Player::Player2 : Player::Player1);
  }

  bool Game::over() {
    return board.isFull() || board.winner();
  }

  OptPlayer Game::winner() {
    return board.winner();
  }

  Board Game::getBoard() {
    return board;
 
  }
}