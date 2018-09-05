#include "Screens.hpp" // из-за Resourses_path
#include "../Buttons/Button.hpp"
#include "../Buttons/ButtonList.hpp"

ScreenMenu::ScreenMenu(Settings &settings)
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
	ButtonList buttonList {};
	//std::cout << App.getSize().x << App.getSize().y << std::endl;
	int screenNumberToReturn = 0;
	static int NumOfcurrentHighlightedButton = 0;

	//Mouse cursor no more visible
	App.setMouseCursorVisible(true);

	auto callNewGame = 	[&screenNumberToReturn]() -> int { return screenNumberToReturn = 1; };
	auto callSettings = [&screenNumberToReturn]() -> int { return screenNumberToReturn = 2; };
	auto callScore = 	[&screenNumberToReturn]() -> int { return screenNumberToReturn = 3; };
	
	buttonList.addButton(sf::Vector2f(1.0f/2, 1.0f/12*4), "New game", font, 	callNewGame);
	buttonList.addButton(sf::Vector2f(1.0f/2, 1.0f/12*6), "Settings", font, 	callSettings);
	buttonList.addButton(sf::Vector2f(1.0f/2, 1.0f/12*8), "Score", 	 font, 	callScore);

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

				default:
					// other events do not handle (just now)
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