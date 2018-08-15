#include "Screens.hpp"
#include "../Settings.hpp"
#include "../Buttons/ButtonList.hpp"

ScreenSettings::ScreenSettings(Settings &settings)
: settings(settings)
{}

int ScreenSettings::run(sf::RenderWindow &App)
{
	settings.printVars();
	sf::Event Event;
	bool isRunning = true;
	ButtonList buttonList(App.getSize());
	static int NumOfcurrentHighlightedButton = 0;

	auto callChangeResolution = [&App, &buttonList,this]() -> int {
		settings.nextScreenSize(); 
		float screenWidth = settings.getScreenSize().x;
		float screenHeigth = settings.getScreenSize().y;

		App.create(sf::VideoMode(screenWidth, screenHeigth, 32)
				, settings.strings.find("windowName")->second
				, settings.vars.find("windowStyle")->second);
		buttonList.updateResolution(App.getSize());
		return 0;
	};

	auto callChangeFieldSize  = [&App, this]() -> int { 
		settings.nextFieldSize();
		//float width = settings.getFieldSize().x;
		//float heigth = settings.getFieldSize().y;
		// ???
		return 0;
	};

	auto callToggleFullScreen = [&App, this]() -> int {
		settings.vars.find("windowStyle")->second ^= sf::Style::Fullscreen;

		App.create(sf::VideoMode(App.getSize().x, App.getSize().y, 32),
			"Super Mega SIRTET",
			settings.vars.find("windowStyle")->second);
		return 0;
	};

	sf::Font font = settings.getFont();

	buttonList.addButton(sf::Vector2f(1.0f/2, 1.0f/12*4), "Resolution",	font, 	callChangeResolution);
	buttonList.addButton(sf::Vector2f(1.0f/2, 1.0f/12*6), "Field size", font, 	callChangeFieldSize);
	buttonList.addButton(sf::Vector2f(1.0f/2, 1.0f/12*8), "Fullscreen", font, 	callToggleFullScreen);

	buttonList.updateHighlightedButton(NumOfcurrentHighlightedButton);

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
					buttonList.updateResolution(App.getSize());
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
							NumOfcurrentHighlightedButton = buttonList.getCurrentButtonNumber();
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