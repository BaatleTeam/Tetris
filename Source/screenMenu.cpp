#include "screens.hpp" // из-за Resourses_path

screenMenu::screenMenu() : playing(false) 
{
	if (!font.loadFromFile(RESOURCES_PATH_PREFIX + "coopbl.ttf"))
	{
		std::cout << "Font didn't load!" << std::endl;
		throw;
	}
	
}

int screenMenu::Run(sf::RenderWindow &App)
{
	sf::Text text;

	// select the font
	text.setFont(font); // font is a sf::Font

	// set the string to display
	text.setString("Hello world");

	// set the character size
	text.setCharacterSize(24); // in pixels, not points! 
	
	std::cout << App.getSize().x << " " << App.getSize().y << std::endl;

	// TODO
	// Сделать нормальное выравнивание по центру экрана не через константы
	text.setPosition(App.getSize().x / 2 - 60, App.getSize().y / 2 - 12); 

	sf::Event Event;
	bool Running = true;

	while (Running)
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
		App.draw(text);
		
		App.display();
	}

	//Never reaching this point normally, but just in case, exit the application
	return (-1);
}