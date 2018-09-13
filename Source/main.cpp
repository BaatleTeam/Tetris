#include <iostream>
#include <memory>
#include "Screens/Screens.hpp"
#include "Settings/Settings.hpp"
#include "ResourceManager.hpp"

int main()
{
	//Applications variables
	Settings settings;
	ResourceManager resourceManager{};
	std::vector<std::unique_ptr<ScreenBase>> Screens;
	Screens.reserve(4);
	int screen = 0;

	try {
		Screens.push_back(std::unique_ptr<ScreenMenu>(new ScreenMenu(settings, resourceManager)));
		Screens.push_back(std::unique_ptr<ScreenGame>(new ScreenGame(settings, resourceManager)));
		Screens.push_back(std::unique_ptr<ScreenSettings>(new ScreenSettings(settings, resourceManager)));
		Screens.push_back(std::unique_ptr<ScreenGame>(new ScreenGame(settings, resourceManager)));
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
