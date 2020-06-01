#include <ostream>
#include <vector>
namespace WarGame
{
	class Soldier
	{
		public:
			int health = 100;
			int attack = 10;
			int owner = -1;

			Soldier(int _owner) : owner(_owner) {};
	                void activate(std::vector<std::vector<Soldier*>> &board, int source_first, int source_second);
			~Soldier() {};
			std::pair<int,int> get_target_soldier(std::vector<std::vector<Soldier*>> &board,int source_first, int source_second, int player_number);
			friend std::ostream& operator << (std::ostream &out, const Soldier &s);
	};
}
