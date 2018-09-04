#include "Screens.hpp"
#include "../Buttons/ButtonList.hpp"

ScreenMenu::ScreenMenu(Settings &newSettings)
: settings(newSettings)
{
	auto callNewGame = 	[]() -> int { return 1; };
	auto callSettings = []() -> int { return 2; };
	auto callScore = 	[]() -> int { return 3; };
	
	sf::Font &font = settings.getFont();

	buttonList.addButton(sf::Vector2f(1.0f/2, 1.0f/12*4), "New game", font, callNewGame);
	buttonList.addButton(sf::Vector2f(1.0f/2, 1.0f/12*6), "Settings", font, callSettings);
	buttonList.addButton(sf::Vector2f(1.0f/2, 1.0f/12*8), "Score", 	 font, 	callScore);
}
int ScreenMenu::run(sf::RenderWindow &App)
{
	sf::Event Event;
	bool isRunning = true;
	
	buttonList.update(App.getSize());

	//Mouse cursor no more visible
	App.setMouseCursorVisible(true);

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
					buttonList.update(App.getSize());
                    break;

				//Key pressed
				case sf::Event::KeyPressed:
				{
					switch (Event.key.code)
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
				break;
			}
		}

		//Clearing screen
		App.clear(sf::Color(0, 191, 255, 128));

		//Drawing
		App.draw(buttonList);
		
		App.display();
	}

	//Never reaching this point normally, but just in case, exit the application
	return (-1);
}