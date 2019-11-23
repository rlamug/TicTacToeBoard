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

/*** getPiece ***/
// Gets piece of first move
TEST(TicTacToeBoardTest, getPieceX) {
  TicTacToeBoard ticTacToeBoard;
  ticTacToeBoard.placePiece(0, 0);
  ASSERT_EQ(ticTacToeBoard.getPiece(0, 0), 'X');
}
// Gets piece of second move
TEST(TicTacToeBoardTest, getPieceO) {
  TicTacToeBoard ticTacToeBoard;
  ticTacToeBoard.placePiece(0, 0);
  ticTacToeBoard.placePiece(0, 1);
  ASSERT_EQ(ticTacToeBoard.getPiece(0, 1), 'O');
}
// Gets piece of invalid coordinate
TEST(TicTacToeBoardTest, getPieceInvalid) {
  TicTacToeBoard ticTacToeBoard;
  ASSERT_EQ(ticTacToeBoard.getPiece(3, 3), '?');
}

/*** getWinner ***/
// No winner game is still going
TEST(TicTacToeBoardTest, getWinnerInvalid) {
  TicTacToeBoard ticTacToeBoard;
  ASSERT_EQ(ticTacToeBoard.getWinner(), '?');
}
// No winner game is over
TEST(TicTacToeBoardTest, getWinnerBlank) {
  TicTacToeBoard ticTacToeBoard;
  ticTacToeBoard.placePiece(0, 0);
  ticTacToeBoard.placePiece(0, 1);
  ticTacToeBoard.placePiece(0, 2);
  ticTacToeBoard.placePiece(1, 1);
  ticTacToeBoard.placePiece(2, 1);
  ticTacToeBoard.placePiece(2, 0);
  ticTacToeBoard.placePiece(1, 0);
  ticTacToeBoard.placePiece(1, 2);
  ticTacToeBoard.placePiece(2, 2);
  ASSERT_EQ(ticTacToeBoard.getWinner(), ' ');
}
// Winner
TEST(TicTacToeBoardTest, getWinnerX) {
  TicTacToeBoard ticTacToeBoard;
  ticTacToeBoard.placePiece(0, 0);
  ticTacToeBoard.placePiece(1, 0);
  ticTacToeBoard.placePiece(0, 1);
  ticTacToeBoard.placePiece(1, 1);
  ticTacToeBoard.placePiece(0, 2);
  ASSERT_EQ(ticTacToeBoard.getWinner(), 'X');
}