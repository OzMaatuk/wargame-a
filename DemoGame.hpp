#pragma once
/**
 * This is a game that demonstrates how to use the Board class.
 * You can modify it and build your own games.
 * 
 * @author Oz Levi 
 * @author Erel Segal-Halevi
 * @since  2020-05
 */

class Board;

namespace WarGame {
	class DemoGame {
	 private:
		Board board;
		const int numRows = 8;
		const int numCols = 8;
		enum class MoveDIR { Up, Down, Right, Left };
	 public:

 		/**
		 * The constructor initilizes the board and places the soldiers.
		 */
		DemoGame();
		
		/**
		 * This function runs a sample play of the game and returns the winner (1 or 2, or 0 in case of tie).
		 */
		int play(); 

 		/**
		 * The destructor deletes the soldiers from the board.
		 */
		~DemoGame();
	};
}
