#include "ScreenGame.hpp"

ScreenGame::ScreenGame(Settings &settings)
	: gameController(settings),
		settings(settings)
{
	movement_step = 5;
	posx = 320;
	posy = 240;
	//Setting sprite
	Rectangle.setFillColor(sf::Color(255, 255, 255, 150));
	Rectangle.setSize({ 10.f, 10.f });
}

int ScreenGame::run(sf::RenderWindow &window)
{
	//Mouse cursor no more visible
	window.setMouseCursorVisible(true);

	sf::Event event;
	bool isRunning = true;

	sf::Clock clockStep;
	clockStep.restart();

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
		window.clear(sf::Color(0, 0, 0, 0));
		//Drawing
		window.draw(Rectangle);
		drawBackground(window);
		window.display();
	}

	//Never reaching this point normally, but just in case, exit the windowlication
	return -1;
}

void ScreenGame::drawBackground(sf::RenderWindow &WIN){
	// screenBackground.Draw(WIN);
	// gameBackground.Draw(WIN);
}

int ScreenGame::processEvent(const sf::Event &event) {
	// Window closed
	if (event.type == sf::Event::Closed)
	{
		return (-1);
	}
	//Key pressed
	if (event.type == sf::Event::KeyPressed)
	{
		switch (event.key.code)
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
	return SCREEN_BASE_NOT_CHANGING_SCREEN;
}
