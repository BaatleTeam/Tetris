#include "Screens.hpp" // из-за Resourses_path

ScreenMenu::ScreenMenu()
{
	if (!font.loadFromFile(RESOURCES_PATH_PREFIX + "Fonts/coopbl.ttf"))
	{
		std::cout << "Font didn't load!" << std::endl;
		throw;
	}
}

int ScreenMenu::run(sf::RenderWindow &App)
{
	//Mouse cursor no more visible
	App.setMouseCursorVisible(false);

	sf::Text text;

	// select the font
	text.setFont(font); // font is a sf::Font

	// set the string to display
	text.setString("Hello world 1111111111");

	// set the character size
	text.setCharacterSize(24); // in pixels, not points! 
	
	std::cout << App.getSize().x << " " << App.getSize().y << std::endl;

	// TODO
	// Сделать нормальное выравнивание по центру экрана не через константы
	// DONE но не совсем нормальное
	sf::FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width/2.0f,
				textRect.top  + textRect.height/2.0f);
	text.setPosition(sf::Vector2f(App.getSize().x/2.0f,App.getSize().y/2.0f));

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
		App.draw(text);
		
		App.display();
	}

	//Never reaching this point normally, but just in case, exit the application
	return (-1);
}