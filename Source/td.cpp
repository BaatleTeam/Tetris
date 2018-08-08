#include <iostream>
#include <SFML/Graphics.hpp>
#include "screens.hpp"

int main()
{
	//Applications variables
	std::vector<cScreen*> Screens;
	Screens.reserve(2);
	int screen = 0;

	//Window creation
	// TODO
	// Нужно как-то управляться с разным расширением, а не только с жалкими 640 на 480
	// The style parameter can be a combination of the sf::Style flags, which are None, Titlebar,
	// Resize, Close and Fullscreen.
	// The default style is Resize | Close.
	sf::RenderWindow App(sf::VideoMode(640, 480, 32), "Super Mega SIRTET", sf::Style::Titlebar | sf::Style::Close);

	//Mouse cursor no more visible
	App.setMouseCursorVisible(false);

	//Screens preparations
	// TODO
	// Нужно как-то красиво обернуть try-catch'ем, так как в конструкторе меню может вылететь исключение
	screenMenu s_menu;
	screenGame s_game;
	
	try {
		Screens.push_back(&s_menu);
		Screens.push_back(&s_game);
	}
	catch(...){
		std::cout << "Programm has beem terminated.";
		exit(-1);
	}

	//Main loop
	while (screen >= 0)
	{
		screen = Screens[screen]->Run(App);
	}

	return EXIT_SUCCESS;
}