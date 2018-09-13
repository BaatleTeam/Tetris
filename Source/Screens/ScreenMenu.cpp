#include "Screens.hpp"
#include "../Buttons/ButtonList.hpp"

ScreenMenu::ScreenMenu(Settings &newSettings, ResourceManager& r_m)
 : ScreenBase(r_m)
 , settings(newSettings)
{
	auto callNewGame = 	[]() -> int { return 1; };
	auto callSettings = []() -> int { return 2; };
	auto callScore = 	[]() -> int { return 3; };

	sf::Font &font = settings.getFont();

	buttonList.addButton(sf::Vector2f(1.0f/2, 1.0f/12*4), "New game", font, callNewGame);
	buttonList.addButton(sf::Vector2f(1.0f/2, 1.0f/12*6), "Settings", font, callSettings);
	buttonList.addButton(sf::Vector2f(1.0f/2, 1.0f/12*8), "Score", 	 font, 	callScore);
}

int ScreenMenu::run(sf::RenderWindow &window)
{
	sf::Event event;
	bool isRunning = true;

	buttonList.update(window.getSize());

	//Mouse cursor no more visible
	window.setMouseCursorVisible(true);

	while (isRunning)
	{
		//Verifying events
		while (window.pollEvent(event))
		{
			int result = processEvent(event);
			if (result != SCREEN_BASE_NOT_CHANGING_SCREEN) {
				return result;
			}
		}

		//Clearing screen
		window.clear(sf::Color(0, 191, 255, 128));

		//Drawing
		window.draw(buttonList);

		window.display();
	}

	//Never reaching this point normally, but just in case, exit the windowlication
	return (-1);
}

int ScreenMenu::processEvent(const sf::Event &event) {
	sf::RenderWindow &window = settings.getRenderWindow();
	switch(event.type)
	{
		// Window closed
		case sf::Event::Closed:
			return -1;
			break;
		case sf::Event::Resized:
			std::cout << "Resize catched! New size [ " << event.size.width << ", " << event.size.height << "]" << std::endl;
			// sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
			window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
			buttonList.update(window.getSize());
			break;

		case sf::Event::KeyPressed:
		{
			switch (event.key.code)
			{
				case sf::Keyboard::Enter:
					return buttonList.callCBFunction();
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
		default:
			// other events do not handle (just now)
			break;
	}
	return SCREEN_BASE_NOT_CHANGING_SCREEN;
}
