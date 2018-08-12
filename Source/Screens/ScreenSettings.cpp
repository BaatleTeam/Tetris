#include "Screens.hpp" // из-за Resourses_path

#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED
#include "../Buttons/Button.hpp"
#endif

#ifndef BUTTON_LIST_HPP_INCLUDED
#define BUTTON_LIST_HPP_INCLUDED
#include "../Buttons/ButtonList.hpp"
#endif

ScreenSettings::ScreenSettings() // Нужно брать шрифт из настроек, а не грузить его постоянно
{
	if (!font.loadFromFile(RESOURCES_PATH_PREFIX + "Fonts/SIMPLIFICA Typeface.ttf"))
	{
		std::cout << "Font didn't load!" << std::endl;
		throw;
	}
}

int ScreenSettings::run(sf::RenderWindow &App)
{
	sf::Event Event;
	bool isRunning = true;
	ButtonList buttonList(App.getSize());
	int screenNumberToReturn = 0;
	static int NumOfcurrentHighlightedButton = 0;

	auto callChangeResolution = []() -> int { return 0; };
	auto callChangeFieldSize  = []() -> int { return 0; };
	
	auto callToggleFullScreen = [&App]() -> int {
		static int windowStyle = sf::Style::Titlebar | sf::Style::Close;
		windowStyle ^= sf::Style::Fullscreen;

		App.create(sf::VideoMode(App.getSize().x, App.getSize().y, 32),
			"Super Mega SIRTET",
			windowStyle);
		return 0;
	};
	
	buttonList.addButton(sf::Vector2f(1.0f/2, 1.0f/12*4), "Resolution",	 		font, 	callChangeResolution);
	buttonList.addButton(sf::Vector2f(1.0f/2, 1.0f/12*6), "Field size", 		font, 	callChangeFieldSize);
	buttonList.addButton(sf::Vector2f(1.0f/2, 1.0f/12*8), "Toggle fullscreen", 	font, 	callToggleFullScreen);

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
                    
                    //sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
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