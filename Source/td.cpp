#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Screens/Screens.hpp"

int main()
{
	//Applications variables
	std::vector<std::unique_ptr<ScreenBase>> Screens;

	// Сомнительное резервирование памяти (зочем?)
	Screens.reserve(2);
	int screen = 0;

	//Window creation
	// TODO
	// Нужно как-то управляться с разным расширением, а не только с жалкими 640 на 480
	// The style parameter can be a combination of the sf::Style flags, which are None, Titlebar,
	// Resize, Close and Fullscreen.
	// The default style is Resize | Close.
	sf::RenderWindow App(sf::VideoMode(640, 480, 32), "Super Mega SIRTET", sf::Style::Titlebar | sf::Style::Close);
	
	std::cout << std::endl;

	try {
		Screens.push_back(std::unique_ptr<ScreenMenu>(new ScreenMenu));
		Screens.push_back(std::unique_ptr<ScreenGame>(new ScreenGame));
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