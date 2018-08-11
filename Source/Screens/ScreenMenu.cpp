#include "Screens.hpp" // из-за Resourses_path
#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED
#include "../Buttons/Button.hpp"
#endif
#include "../Buttons/ButtonList.hpp"

ScreenMenu::ScreenMenu()
{
	if (!font.loadFromFile(RESOURCES_PATH_PREFIX + "Fonts/SIMPLIFICA Typeface.ttf"))
	{
		std::cout << "Font didn't load!" << std::endl;
		throw;
	}
}

int ScreenMenu::run(sf::RenderWindow &App)
{
	sf::Event Event;
	bool isRunning = true;
	ButtonList buttonList;
	int screenNumberToReturn = 0;
	static int NumOfcurrentHighlightedButton = 0;

	//Mouse cursor no more visible
	App.setMouseCursorVisible(true);

	auto callNewGame = 	[&screenNumberToReturn]() -> int { return screenNumberToReturn = 1; };
	auto callSettings = [&screenNumberToReturn]() -> int { return screenNumberToReturn = 2; };
	auto callScore = 	[&screenNumberToReturn]() -> int { return screenNumberToReturn = 3; };
	
	buttonList.addButton(sf::Vector2f(App.getSize().x/2, App.getSize().y/12*4), "New game", font, 	callNewGame);
	buttonList.addButton(sf::Vector2f(App.getSize().x/2, App.getSize().y/12*6), "Settings", font, 	callSettings);
	buttonList.addButton(sf::Vector2f(App.getSize().x/2, App.getSize().y/12*8), "Score", 	 font, 	callScore);

	buttonList.updateHighlightedButton(NumOfcurrentHighlightedButton);

	while (isRunning)
	{
		//Verifying events
		while (App.pollEvent(Event))
		{
			// Window closed
			if (Event.type == sf::Event::Closed)
			{
				return -1;
			}

			//Key pressed
			if (Event.type == sf::Event::KeyPressed)
			{
				switch (Event.key.code)
				{
					case sf::Keyboard::Enter:
						buttonList.callCBFunction();
						NumOfcurrentHighlightedButton = buttonList.getCurrentButtonNumber();
						return screenNumberToReturn;
						break;
					case sf::Keyboard::Escape:
						return -1;
						break;
					case sf::Keyboard::Down:
						buttonList.nextButton();
						break;
					case sf::Keyboard::Up:
						buttonList.prevButton();
						break;
					default:
						break;
				}
			}
		}

		//Clearing screen
		App.clear();

		//Drawing
		App.draw(buttonList);
		
		App.display();
	}

	//Never reaching this point normally, but just in case, exit the application
	return (-1);
}