/**
 * This is a game that demonstrates how to use the Board class.
 * You can modify it and build your own games.
 * 
 * @author Oz Levi 
 * @author Erel Segal-Halevi
 * @since  2020-05
 */

#include "DemoGame.hpp"
#include <iostream>
//#include <cassert>

namespace WarGame {

		DemoGame::DemoGame(int numRows, int numCols): board (numRows, numCols)
		{
			// Add soldiers for player 1:
			std::cout << "Game Starting............." << std::endl;
			
			board[{0,1}] = new Soldier(1);
			//board[{0,3}] = (new Soldier(1));
			//board[{0,5}] = (new Soldier(1));

			// Add soldiers for player 2:
			board[{7,1}] = new Soldier(2);
			//board[{7,3}] = (new Soldier(2));
			//board[{7,5}] = (new Soldier(2));

			// In your game, you can put more soldier types, such as the sniper and the paramedic types.
			std::cout << board << std::endl;
                        std::cout << "Game Initilized............." << std::endl;

		}

		int DemoGame::play()
		{
                        std::cout << "Starits Moving............." << std::endl;
			
			board.move(1, {0,1}, Board::MoveDIR::Up);      // FootSoldier of player 1 moves forward and attacks from {0,1} to {1,1}.
			std::cout << board << std::endl;
			
			


			
			//board.move(2, {7,1}, Board::MoveDIR::Down);    // FootSoldier of player 2 moves forward and attacks from {7,1} to {6,1}.
			//if (!board.has_soldiers(1)) return 2;
                        std::cout << board << std::endl;

			board.move(1, {1,1}, Board::MoveDIR::Down);      // FootCommander of player 1 moves forward from {0,3} to {1,3}, and all soldiers of player 1 attack.
			//if (!board.has_soldiers(2)) return 1;
                        std::cout << board << std::endl;
			//board.move(2, {6,1}, Board::MoveDIR::Left);    // FootCommander of player 2 moves left from {7,3} to {7,2}, and all soldiers of player 2 attack.
			//if (!board.has_soldiers(1)) return 2;
                        std::cout << board << std::endl;
			/// Write more moves here..

                        board.move(1, {0,1}, Board::MoveDIR::Up);      // FootSoldier of player 1 moves forward and attacks from {0,1} to {1,1}.
                        board.move(1, {1,1}, Board::MoveDIR::Down);      // FootCommander of player 1 moves forward from {0,3} to {1,3}, and all soldiers of player 1 attack
                        board.move(1, {0,1}, Board::MoveDIR::Up);      // FootSoldier of player 1 moves forward and attacks from {0,1} to {1,1}.
                        board.move(1, {1,1}, Board::MoveDIR::Down);      // FootCommander of player 1 moves forward from {0,3} to {1,3}, and all soldiers of player 1 attack
                        board.move(1, {0,1}, Board::MoveDIR::Up);      // FootSoldier of player 1 moves forward and attacks from {0,1} to {1,1}.
                        board.move(1, {1,1}, Board::MoveDIR::Down);      // FootCommander of player 1 moves forward from {0,3} to {1,3}, and all soldiers of player 1 attack
                        board.move(1, {0,1}, Board::MoveDIR::Up);      // FootSoldier of player 1 moves forward and attacks from {0,1} to {1,1}.
                        board.move(1, {1,1}, Board::MoveDIR::Down);      // FootCommander of player 1 moves forward from {0,3} to {1,3}, and all soldiers of player 1 attack


                        std::cout << board << std::endl;

			std::cout << "Game Ends............." << std::endl;

			// If no player won, return "-1":
			return 0;
		}

		DemoGame::~DemoGame() {
			for (int iRow=0; iRow<board.board.size(); ++iRow) {
				for (int iCol=0; iCol<board.board[0].size(); ++iCol) {
					if(board[{iRow,iCol}])
						delete board[{iRow,iCol}];
				}
			}
		}

}

int main() {
	WarGame::DemoGame *demoGame = new WarGame::DemoGame(8,8);
	std::cout << "The winner is:\n " << demoGame->play() << std::endl;
    return 0;
}
