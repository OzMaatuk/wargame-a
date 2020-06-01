#include "Board.hpp"
namespace WarGame
{
	Soldier*& Board::operator[](std::pair<int,int> location)
	{
		return this->board[location.first][location.second];
	}

	void Board::move(int player_number, std::pair<int,int> source, MoveDIR direction)
	{
		std::pair<int,int> new_location;
		new_location = calc_move(source, direction);
	       	if (new_location.first >= 0 && new_location.first < this->board.size() && new_location.second >= 0 && new_location.second < this->board.size()){	
		if (this->board[source.first][source.second]!=nullptr && this->board[source.first][source.second]->owner==player_number )
		{
	                new_location = calc_move(source, direction);
			board[new_location.first][new_location.second] = board[source.first][source.second];
			board[source.first][source.second] = nullptr;
			board[new_location.first][new_location.second]->activate(board, new_location.first, new_location.second);
		}}
	}

	bool Board::has_soldiers(int player_number) const
	{
		for (int iRow=0; iRow<board.size(); ++iRow) {
				for (int iCol=0; iCol<board[0].size(); ++iCol) {
					if(board[iRow][iCol]) return false;
				}
			}
		return true;
	}

	std::pair<int,int> Board::calc_move(std::pair<int,int> source, MoveDIR direction)
        {
                switch (direction){
		case MoveDIR::Up: source.first++;  break;
		case MoveDIR::Down: source.first--; break;
		case MoveDIR::Right: source.second++; break;
		case MoveDIR::Left: source.second--; break;
                }return source;
        }


	std::ostream& operator << (std::ostream &out, Board& b)
	{
		std::cout << "ostream oerator called"<<std::endl;
	    	// Displaying the 2D vector 
    		for (int i = 0; i < b.board.size(); i++)
		{ 
        		for (int j = 0; j < b.board[0].size(); j++) 
            			if (b[{i,j}]!=nullptr) {out << *b[{i,j}] << " ";} else {out << "0" << " ";} 
			out << std::endl; 
    		}
	    	return out;
	}
}
