#include "Screens.hpp"
#include "../Settings/Settings.hpp"
#include "../Buttons/ButtonList.hpp"

ScreenSettings::ScreenSettings(Settings &newSettings)
: settings(newSettings)
{
	auto callChangeResolution = [this]() -> int {
		settings.nextScreenSize(); 
		float screenWidth = settings.getScreenSize().x;
		float screenHeigth = settings.getScreenSize().y;

		settings.getRenderWindow().create(sf::VideoMode(screenWidth, screenHeigth, 32)
			, settings.strings.find("windowName")->second
			, settings.vars.find("windowStyle")->second);

		buttonList.update(sf::Vector2u(screenWidth, screenHeigth));

		return 0;
	};

	auto callChangeFieldSize  = [this]() -> int { 
		settings.nextFieldSize();
		//float width = settings.getFieldSize().x;
		//float heigth = settings.getFieldSize().y;
		// ???
		return 0;
	};

	auto callToggleFullScreen = [this]() -> int {
		settings.vars.find("windowStyle")->second ^= sf::Style::Fullscreen;
		sf::Vector2u windowSize = settings.getRenderWindow().getSize();

		settings.getRenderWindow().create(sf::VideoMode(windowSize.x, windowSize.y, 32)
			, settings.strings.find("windowName")->second
			, settings.vars.find("windowStyle")->second);
		return 0;
	};

	sf::Font &font = settings.getFont();
	buttonList.addButton(sf::Vector2f(1.0f/2, 1.0f/12*4), "Resolution",	font, 	callChangeResolution);
	buttonList.addButton(sf::Vector2f(1.0f/2, 1.0f/12*6), "Field size", font, 	callChangeFieldSize);
	buttonList.addButton(sf::Vector2f(1.0f/2, 1.0f/12*8), "Fullscreen", font, 	callToggleFullScreen);
	buttonList.update(settings.getRenderWindow().getSize());
}

int ScreenSettings::run(sf::RenderWindow &App)
{
	sf::Event Event;
	bool isRunning = true;

	while (isRunning)
	{
		//Verifying events
		while (App.pollEvent(Event))
		{
			switch(Event.type)
			{
				// Window closed
				case sf::Event::Closed:
					return -1;
					break;

				case sf::Event::Resized:
                    std::cout << "Resize catched! New size [ " << Event.size.width << ", " << Event.size.height << "]" << std::endl;
                    
                    App.setView(sf::View(sf::FloatRect(0, 0, Event.size.width, Event.size.height)));
					buttonList.update(App.getSize());
                    break;

				//Key pressed
				case sf::Event::KeyPressed:
				{
					switch (Event.key.code)
					{
						case sf::Keyboard::Enter:
							buttonList.callCBFunction();
							break;
						case sf::Keyboard::Escape:
							return 0;
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
					break;
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