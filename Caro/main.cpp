#include <iostream>
#include <vector>
#include <map>

#include "Screen/IScreen.h"

bool init(std::map<ScreenID, std::shared_ptr<ScreenID>>& lstScreen)
{
	lstScreen[ScreenID::SINGLEPLAY] = std::make_shared<ScreenID>();
	lstScreen[ScreenID::SINGLEPLAY] = std::make_shared<ScreenID>();
}

int main()
{
	std::map<ScreenID, std::shared_ptr<ScreenID>> lstScreen;
	init(lstScreen);
	ScreenID enmScreenID;
	while(true)
	{
		uint16_t unChose;
		std::cout << "Input Your Chose:";
		std::cin >> unChose;
		enmScreenID = static_cast<ScreenID>(unChose);

		if (lstScreen.count(enmScreenID) == 0)
		{
			break;
		}
		lstScreen[enmScreenID]->show();
	}
}