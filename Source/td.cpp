#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Screens/Screens.hpp"
#include "Settings/Settings.hpp"

int main()
{
	//Applications variables
	std::vector<std::unique_ptr<ScreenBase>> Screens;
	Settings settings;

	// Сомнительное резервирование памяти (зочем?)`
	Screens.reserve(4);
	int screen = 0;

	//Window creation
	sf::RenderWindow App(sf::VideoMode(1366, 768, 32)
		, settings.strings.find("windowName")->second
		, settings.vars.find("windowStyle")->second);

	try {
		Screens.push_back(std::unique_ptr<ScreenMenu>(new ScreenMenu(settings)));
		Screens.push_back(std::unique_ptr<ScreenGame>(new ScreenGame(settings)));
		Screens.push_back(std::unique_ptr<ScreenSettings>(new ScreenSettings(settings)));
		Screens.push_back(std::unique_ptr<ScreenGame>(new ScreenGame(settings)));
	}
	catch(...){
		std::cout << "Program has been terminated.";
		exit(-1);
	}

	App.requestFocus();

	//Main loop
	while (screen >= 0)
	{
		screen = Screens[screen]->run(App);
	}

	return EXIT_SUCCESS;
}