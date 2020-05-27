/**
 * This is a game that demonstrates how to use the Board class.
 * You can modify it and build your own games.
 * 
 * @author Oz Levi 
 * @author Erel Segal-Halevi
 * @since  2020-05
 */

#include "DemoGame.hpp"

//#include <cassert>

namespace WarGame {

		DemoGame::DemoGame(): board (numRows, numCols) {
		// Add soldiers for player 1:
			//assert(!board.has_soldiers(1));
			board[{0,1}]; // =
			*(new Soldier(1));
			/*board[{0,3}] = *(new Soldier(1));
			*board[{0,5}] = *(new Soldier(1));
			//assert(board.has_soldiers(1));

			// Add soldiers for player 2:
			//assert(!board.has_soldiers(2));
			*board[{7,1}] = *(new Soldier(2));
			*board[{7,3}] = *(new Soldier(2));
			*board[{7,5}] = *(new Soldier(2));
			//assert(board.has_soldiers(2));
*/
			// In your game, you can put more soldier types, such as the sniper and the paramedic types.
		}

		int DemoGame::play() {
			board.move(1, {0,1}, (int)MoveDIR::Up);      // FootSoldier of player 1 moves forward and attacks from {0,1} to {1,1}.
			if (!board.has_soldiers(2)) return 1;

			board.move(2, {7,1}, (int)MoveDIR::Down);    // FootSoldier of player 2 moves forward and attacks from {7,1} to {6,1}.
			if (!board.has_soldiers(1)) return 2;

			board.move(1, {0,3}, (int)MoveDIR::Up);      // FootCommander of player 1 moves forward from {0,3} to {1,3}, and all soldiers of player 1 attack.
			if (!board.has_soldiers(2)) return 1;

			board.move(2, {7,3}, (int)MoveDIR::Left);    // FootCommander of player 2 moves left from {7,3} to {7,2}, and all soldiers of player 2 attack.
			if (!board.has_soldiers(1)) return 2;

			/// Write more moves here..

			// If no player won, return "tie":
			return 0;
		}

		DemoGame::~DemoGame() {
			for (int iRow=0; iRow<numRows; ++iRow) {
				for (int iCol=0; iCol<numCols; ++iCol) {
					Soldier* soldier = board[{iRow,iCol}];
					if (soldier)
						delete soldier;
				}
			}
		}

}

int main() {
	WarGame::DemoGame *demoGame = new WarGame::DemoGame();
	//cout << "The winner is:\n " << demoGame.play() << endl;
    return 0;
}
