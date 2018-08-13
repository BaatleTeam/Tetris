#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Screens/Screens.hpp"
#include "Settings.hpp"

int main()
{
	//Applications variables
	std::vector<std::unique_ptr<ScreenBase>> Screens;
	Settings settings;

	// Сомнительное резервирование памяти (зочем?)`
	Screens.reserve(4);
	int screen = 0;

	//Window creation
	// TODO
	// Нужно как-то управляться с разным расширением, а не только с жалкими 640 на 480
	// The style parameter can be a combination of the sf::Style flags, which are None, Titlebar,
	// Resize, Close and Fullscreen.
	// The default style is Resize | Close.
	sf::RenderWindow App(sf::VideoMode(1366, 768, 32), "Super Mega SIRTET", sf::Style::Resize);
	
	std::cout << std::endl;

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

	//Main loop
	while (screen >= 0)
	{
		screen = Screens[screen]->run(App);
	}

	return EXIT_SUCCESS;
}