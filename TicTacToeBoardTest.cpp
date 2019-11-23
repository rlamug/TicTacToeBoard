/**
 * Unit Tests for TicTacToeBoard
 **/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"

class TicTacToeBoardTest : public ::testing::Test {
 protected:
  TicTacToeBoardTest() {}           // constructor runs before each test
  virtual ~TicTacToeBoardTest() {}  // destructor cleans up after tests
  virtual void SetUp() {}     // sets up before each test (after constructor)
  virtual void TearDown() {}  // clean up after each test, (before destructor)
};

/* EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, unitTestName) {
  ASSERT_TRUE(true);
}
*/

// Sanity Check
TEST(TicTacToeBoardTest, sanityCheck) {
  TicTacToeBoard ticTacToeBoard;
  ASSERT_TRUE(true);
}

/*** toggleTurn ***/
// toggleTurn() when turn = X
TEST(TicTacToeBoardTest, toggleTurnX) {
  TicTacToeBoard ticTacToeBoard;
  ASSERT_EQ(ticTacToeBoard.toggleTurn(), 'O');
}
// toggleTurn() when turn = O
TEST(TicTacToeBoardTest, toggleTurnO) {
  TicTacToeBoard ticTacToeBoard;
  ticTacToeBoard.toggleTurn();
  ASSERT_EQ(ticTacToeBoard.toggleTurn(), 'X');
}

/*** placePiece ***/
// Places piece on blank coordinate
TEST(TicTacToeBoardTest, placePieceBlank) {
  TicTacToeBoard ticTacToeBoard;
  ASSERT_EQ(ticTacToeBoard.placePiece(0, 0), 'X');
}
// Places piece on coordinate already occupied
TEST(TicTacToeBoardTest, placePieceOccupied) {
  TicTacToeBoard ticTacToeBoard;
  ticTacToeBoard.placePiece(0, 0);
  ASSERT_EQ(ticTacToeBoard.placePiece(0, 0), 'X');
}
// Places piece on invalid coordinate
TEST(TicTacToeBoardTest, placePieceInvalid) {
  TicTacToeBoard ticTacToeBoard;
  ASSERT_EQ(ticTacToeBoard.placePiece(3, 3), '?');
}
// Shouldn't place piece when game is over
TEST(TicTacToeBoardTest, placePieceGameOver) {
  TicTacToeBoard ticTacToeBoard;
  ticTacToeBoard.placePiece(0, 0);
  ticTacToeBoard.placePiece(1, 0);
  ticTacToeBoard.placePiece(0, 1);
  ticTacToeBoard.placePiece(1, 1);
  ticTacToeBoard.placePiece(0, 2);
  ticTacToeBoard.placePiece(1, 3);
  ASSERT_EQ(ticTacToeBoard.getPiece(1, 3), ' ');
}
