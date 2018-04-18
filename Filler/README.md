# Filler

Player-bot to fight on the world famous Filler board.

The concept is simple: two players gain points by placing on a board, one after the other,
the game piece obtained by the game master (in the form of an executable Ruby program).
The game ends when the game piece cannot be placed anymore.

The goal is to win:
  - Player read the board and the game pieces placed on the standard output.
  
  - Each turn the filler rewrites the board map and includes a new game piece.

  - In order to place the game piece on the board, the player write
it’s coordinates on the standard ouput.

  - The following format is “X Y\n”
  
  - Collect points each time place a piece.
