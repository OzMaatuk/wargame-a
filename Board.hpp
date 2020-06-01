#include "Soldier.hpp"
#include <vector>
#include <iostream>
namespace WarGame
{
	class Board
	{
		public:
			std::vector<std::vector<Soldier*>> board;
		    	enum class MoveDIR { Up, Down, Right, Left };
			
			Board(int numRows, int numCols): board(numRows, std::vector<Soldier*>(numCols,nullptr)){};
		    	Soldier*& operator[](std::pair<int,int> location);
			void move(int player_number, std::pair<int,int> source, MoveDIR direction);
		    	bool has_soldiers(int player_number) const;
			std::pair<int,int> calc_move(std::pair<int,int> source, MoveDIR direction);
		    	friend std::ostream& operator << (std::ostream &out, Board& b);
	};
}
