#include <iostream>
#include <memory>
#include "Screens/Screens.hpp"
#include "Settings/Settings.hpp"

int main()
{
	//Applications variables
	std::vector<std::unique_ptr<ScreenBase>> Screens;
	Settings settings;
	Screens.reserve(4);
	int screen = 0;

	try {
		Screens.push_back(std::unique_ptr<ScreenMenu>(new ScreenMenu(settings)));
		Screens.push_back(std::unique_ptr<ScreenGame>(new ScreenGame(settings)));
		Screens.push_back(std::unique_ptr<ScreenSettings>(new ScreenSettings(settings)));
		Screens.push_back(std::unique_ptr<ScreenGame>(new ScreenGame(settings)));
	}
	catch(...) {
		std::cout << "Program has been terminated.";
		exit(-1);
	}

	//Main loop
	while (screen >= 0)
	{
		screen = Screens[screen]->run(settings.getRenderWindow());
	}

	return EXIT_SUCCESS;
}