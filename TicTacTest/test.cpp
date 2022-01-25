#include <gtest/gtest.h>
#include "board.hpp"

using tic::Board;

TEST(Board, NewBoardIsEmpty) {
  Board b;
  for (int r = 0; r < 3; ++r) {
    for (int c = 0; c < 3; ++c) {
      EXPECT_FALSE((bool)b.getCell({ r, c }));
    }
  }
}

TEST(Board, CorrectlyReportsWhenFull) {
  Board b;
  for (int r = 0; r < 3; ++r) {
    for (int c = 0; c < 3; ++c) {
      EXPECT_FALSE(b.isFull());
      b.setCell({ r, c }, tic::Player::Player1);
    }
  }
  EXPECT_TRUE(b.isFull());
}