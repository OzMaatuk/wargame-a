/**
 * This is a game that demonstrates how to use the Board class.
 * You can modify it and build your own games.
 * 
 * @author Oz Levi 
 * @author Erel Segal-Halevi
 * @since  2020-05
 */

#include "Soldier.hpp"
namespace WarGame {
		/**
		 * This function runs a sample play of the game and returns the winner (1 or 2, or 0 in case of tie).
		 */
		void Soldier::activate(std::vector<std::vector<Soldier*>> &board, int source_first, int source_second)
		{
			
			std::pair<int,int> s = get_target_soldier(board,source_first,source_second,this->owner);
			if (s.first!=-1 && board[s.first][s.second]!=nullptr)
			{
		    		board[s.first][s.second]->health = board[s.first][s.second]->health - this->attack;
				if (board[s.first][s.second]->health <= 0)
				{
					delete board[s.first][s.second];
					board[s.first][s.second] = nullptr;
				}
			}
			
		}

		std::ostream& operator << (std::ostream &out, const Soldier& s)
		{
			out << "S";
			return out;
		}

		std::pair<int,int> Soldier::get_target_soldier(std::vector<std::vector<Soldier*>> &board, int source_first, int source_second, int player_number)
		{
			//finds player to attack
                        int x = source_first;
                        int y = source_second;

                        for (int length = 2; length < board.size(); length++)
			{
                                int current_x = x - length + 1;
                                int current_y = y - length + 1;
                                for (int i = 0; i < length; i++)
                                {
                                        if (current_x >= 0 && current_x < board.size() && current_y+i >= 0 && current_y+i < board.size()){
                                        if (board[current_x][current_y+i]!=nullptr && board[current_x][current_y+i]->owner!=player_number)
                                        {
                                                return {current_x,current_y+i};
                                        }}

                                }

                                current_x = x - length + 1;
                                current_y = y + length - 1;
                                for (int i = 0; i < length; i++)
                                {
                                        if (current_x+i >= 0 && current_x+i < board.size() && current_y >= 0 && current_y < board.size()){
                                        if (board[current_x+i][current_y]!=nullptr && board[current_x+i][current_y]->owner!=player_number)
                                        {
                                                return {current_x+i,current_y};
                                        }}

                                }
				
				current_x = x + length - 1;
                                current_y = y + length - 1;
                                for (int i = 0; i < length; i++)
                                {
                                        if (current_x >= 0 && current_x < board.size() && current_y-i >= 0 && current_y-i < board.size()){
                                        if (board[current_x][current_y-i]!=nullptr && board[current_x][current_y-i]->owner!=player_number)
                                        {
                                                return {current_x,current_y-i};
                                        }}

                                }

                                current_x = x + length - 1;
                                current_y = y - length + 1;
                                for (int i = 0; i < length; i++)
                                {
                                        if (current_x-i >= 0 && current_x-i < board.size() && current_y >= 0 && current_y < board.size()){
                                        if (board[current_x-i][current_y]!=nullptr && board[current_x-i][current_y]->owner!=player_number)
                                        {
                                                return {current_x-i,current_y};
                                        }}
                                }
			}
			return {-1,-1};
		}
	};
