#include "Screens.hpp"
#include "../Buttons/ButtonList.hpp"

ScreenMenu::ScreenMenu(Settings &newSettings, ResourceManager& r_m)
 : ScreenBase(r_m)
 , settings(newSettings)
{
	auto callNewGame = 	[]() -> ScreenType { return ScreenType::Game; };
	auto callSettings = []() -> ScreenType { return ScreenType::Settings; };
	auto callScore = 	[]() -> ScreenType { return ScreenType::Menu; };

	sf::Font &font = resourceManager.getFont();

	buttonList.addButton(sf::Vector2f(1.0f/2, 1.0f/12*4), "New game", font, callNewGame);
	buttonList.addButton(sf::Vector2f(1.0f/2, 1.0f/12*6), "Settings", font, callSettings);
	buttonList.addButton(sf::Vector2f(1.0f/2, 1.0f/12*8), "Score", 	 font, 	callScore);
}

ScreenType ScreenMenu::run(sf::RenderWindow &window)
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
			auto result = processEvent(event);
			if (result != ScreenType::NotChange) {
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
	return ScreenType::Error;
}

void ScreenMenu::resizeSprites() {
	
}

ScreenType ScreenMenu::processEvent(const sf::Event &event) {
	sf::RenderWindow &window = settings.getRenderWindow();
	switch(event.type)
	{
		// Window closed
		case sf::Event::Closed:
			return ScreenType::Exit;
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
					return ScreenType::Exit;
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
	return ScreenType::NotChange;
}
