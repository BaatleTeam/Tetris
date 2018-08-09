#include "Screens.hpp" // из-за Resourses_path
#include "../Buttons/Buttons.hpp" // сомнительный путь, хз как поменять

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

	Button buttonNewGame((sf::Vector2f(App.getSize().x/2, App.getSize().y/12*5)), "New game", font);
	Button buttonSettings((sf::Vector2f(App.getSize().x/2, App.getSize().y/12*6)), "Settings", font);
	Button buttonRecords((sf::Vector2f(App.getSize().x/2, App.getSize().y/12*7)), "Score", font);

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
					default:
						break;
				}
			}
		}

		//Clearing screen
		App.clear();

		//Drawing
		App.draw(buttonNewGame);
		App.draw(buttonSettings);
		App.draw(buttonRecords);
		
		App.display();
	}

	//Never reaching this point normally, but just in case, exit the application
	return (-1);
}