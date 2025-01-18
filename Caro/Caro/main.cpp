// Game System
#include "GameSystem.h"

#define D_CLEARDISPLAY "cls"
#define D_SYSTEMPAUSE "pause"

int main()
{
	GameSystem objGameSystem;
	uint16_t nChoice = 0;
	while (true)
	{
		system(D_CLEARDISPLAY);
		std::cout << "*-----------MENU------------*" << std::endl;
		std::cout << "Press number to choice:" << std::endl;
		std::cout << "1. Play with other Player" << std::endl;
		std::cout << "2. Play with BOT" << std::endl;
		std::cout << "3. Replay" << std::endl;
		std::cout << "4. Player information" << std::endl;
		std::cout << "5. Guild" << std::endl;
		std::cout << "6. Exit" << std::endl;
		do {
			std::cout << "Your choice: ";
			std::cin >> nChoice;

			// [VN] 
			if (std::cin.fail() || nChoice <= 0 || nChoice > 6)
			{
				// [VN]
				std::cin.clear();
				// [VN]
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid input. Please enter a number between 1 and 6." << std::endl;
			}
			else 
			{
				// [VN] Xóa bỏ ký tự thừa nếu có
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				break;
			}
		} while (true);
		switch (nChoice) {
		case 1:
			system(D_CLEARDISPLAY);
			objGameSystem.PlayWithHuman();
			break;
		case 2:
			objGameSystem.playWithBot();
			break;
		case 3:
			objGameSystem.replay();
			break;
		case 4:
			objGameSystem.searchPlayer();
			system(D_SYSTEMPAUSE);
			break;
		case 5:
			objGameSystem.guildline();
			break;
		default:
			return 0;
		}
	}
}
