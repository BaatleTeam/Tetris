#include "Screens.hpp" // из-за Resourses_path
#include "../Buttons/Buttons.hpp" // сомнительный путь, хз как поменять
#include "../Buttons/ButtonsList.hpp"

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
	//Mouse cursor no more visible
	App.setMouseCursorVisible(true);

	ButtonList buttonList;
	buttonList.add_button(sf::Vector2f(App.getSize().x/2, App.getSize().y/12*5), "New game", font);
	buttonList.add_button(sf::Vector2f(App.getSize().x/2, App.getSize().y/12*6), "Settings", font);
	buttonList.add_button(sf::Vector2f(App.getSize().x/2, App.getSize().y/12*7), "Score", font);


	sf::Event Event;
	bool isRunning = true;

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
						return 1;
						break;
					case sf::Keyboard::Escape:
						return -1;
						break;
					case sf::Keyboard::Down:
						buttonList.next_button();
						break;
					case sf::Keyboard::Up:
						buttonList.prev_button();
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