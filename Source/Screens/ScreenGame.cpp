#include "ScreenGame.hpp"

ScreenGame::ScreenGame(const Settings &settings, const ResourceManager &rM)
 : 	resourceManager(rM)
 , gameController(settings)
 , settings(settings)

{
	movement_step = 5;
	posx = 320;
	posy = 240;
	//Setting sprite
	Rectangle.setFillColor(sf::Color(255, 255, 255, 150));
	Rectangle.setSize({ 10.f, 10.f });
}

int ScreenGame::run(sf::RenderWindow &App)
{
	//Mouse cursor no more visible
	App.setMouseCursorVisible(true);

	sf::Event Event;
	bool isRunning = true;

	sf::Clock clockStep;
	clockStep.restart();

	while (isRunning)
	{
		//Verifying events
		while (App.pollEvent(Event))
		{
			// Window closed
			if (Event.type == sf::Event::Closed)
			{
				return (-1);
			}
			//Key pressed
			if (Event.type == sf::Event::KeyPressed)
			{
				switch (Event.key.code)
				{
				case sf::Keyboard::Escape:
					return (0);
					break;
				case sf::Keyboard::Up:
					posy -= movement_step;
					break;
				case sf::Keyboard::Down:
					posy += movement_step;
					break;
				case sf::Keyboard::Left:
					posx -= movement_step;
					break;
				case sf::Keyboard::Right:
					posx += movement_step;
					break;
				default:
					break;
				}
			}
		}

		//Updating
		if (posx>630)
			posx = 630;
		if (posx<0)
			posx = 0;
		if (posy>470)
			posy = 470;
		if (posy<0)
			posy = 0;
		Rectangle.setPosition({ posx, posy });

		sf::Time elapsedTime = clockStep.getElapsedTime();
		if (elapsedTime >= sf::seconds(1)){
			std::cout << elapsedTime.asSeconds() << std::endl;
			gameController.doStep();
			std::cout << "Step done" << std::endl;
			std::cout << gameController;
			clockStep.restart();
		}
		

		//Clearing screen
		App.clear(sf::Color(0, 0, 0, 0));
		//Drawing
		App.draw(Rectangle);

		App.draw(resourceManager.getSpriteBlock());

		drawBackground(App);
		App.display();
	}

	//Never reaching this point normally, but just in case, exit the application
	return -1;
}

void ScreenGame::drawBackground(sf::RenderWindow &WIN){
	// screenBackground.Draw(WIN);
	// gameBackground.Draw(WIN);
}