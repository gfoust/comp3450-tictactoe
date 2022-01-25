#pragma once
#include "board.hpp"

namespace tic {

  class Game {
  public:
    void makeMove(Location loc);
    bool over();
    OptPlayer winner();
    Board getBoard();

  private:
    Board board;
    Player turn = Player::Player1;
  };

}