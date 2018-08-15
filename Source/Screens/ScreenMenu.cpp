#include "Screens.hpp"
#include "../Buttons/ButtonList.hpp"

ScreenMenu::ScreenMenu(Settings &settings)
: settings(settings)
{}

int ScreenMenu::run(sf::RenderWindow &App)
{
	settings.printVars();
	sf::Event Event;
	bool isRunning = true;
	ButtonList buttonList(App.getSize());
	static int NumOfcurrentHighlightedButton = 0;

	//Mouse cursor no more visible
	App.setMouseCursorVisible(true);

	auto callNewGame = 	[]() -> int { return 1; };
	auto callSettings = []() -> int { return 2; };
	auto callScore = 	[]() -> int { return 3; };
	sf::Font font = settings.getFont();
	
	buttonList.addButton(sf::Vector2f(1.0f/2, 1.0f/12*4), "New game", font, callNewGame);
	buttonList.addButton(sf::Vector2f(1.0f/2, 1.0f/12*6), "Settings", font, callSettings);
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
							NumOfcurrentHighlightedButton = buttonList.getCurrentButtonNumber();
							return buttonList.callCBFunction();;
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