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
// Test Initial toggleTurn()
TEST(TicTacToeBoardTest, toggleTurnX) {
  TicTacToeBoard ticTacToeBoard;
  ASSERT_EQ(ticTacToeBoard.toggleTurn(), 'O');
}
// Test Second toggleTurn()
TEST(TicTacToeBoardTest, toggleTurnO) {
  TicTacToeBoard ticTacToeBoard;
  ticTacToeBoard.toggleTurn();
  ASSERT_EQ(ticTacToeBoard.toggleTurn(), 'X');
}

