#include "ScreenGame.hpp"

ScreenGame::ScreenGame(Settings &settings, ResourceManager &rM)
 : resourceManager(rM)
 , gameController(settings)
 , settings(settings)

{	
	auto arraySize = settings.getFieldSize().x * settings.getFieldSize().y;
	gameFieldSpites.reserve(arraySize);

	const sf::Texture& cellTexture = resourceManager.getCellTexture();
	auto defaultX = settings.getScreenSize().x / 2 - settings.getFieldSize().x/2 * 50;
	float currX = defaultX;
	float currY = 50;
	for (unsigned i = 0; i < arraySize; i++){
		gameFieldSpites.emplace_back(sf::Sprite{});
		gameFieldSpites.back().setTexture(cellTexture);
		gameFieldSpites.back().setColor(sf::Color::Red);
		gameFieldSpites.back().setPosition({ currX, currY });
		gameFieldSpites.back().setScale({0.25, 0.25});
		currX += 55;
		if (currX >= defaultX + 55 * settings.getFieldSize().x){
			currY += 55;
			currX = defaultX;
		}
	}
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
    
		drawGameField(window);

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


void ScreenGame::drawGameField(sf::RenderWindow &App){
	updateGameField();
	for (auto blockSprite : gameFieldSpites)
		App.draw(blockSprite);		
}

void ScreenGame::updateGameField(){
	for (int i = settings.getFieldSize().y-1; i >= 0; i--)
		for (int j = 0; j < (int)settings.getFieldSize().x; j++){
			if (gameController.getCellColor({j,i}) != gameFieldSpites[convertIndexes(i,j)].getColor())
				gameFieldSpites[convertIndexes(i,j)].setColor(gameController.getCellColor({j,i}));
			// std::cout << "i = " << i << " j = " << j << " --> [" << convertIndexes(i,j) << "]" << std::endl;
		}
}

int ScreenGame::convertIndexes(int i, int j) const {
	return (settings.getFieldSize().y -1 - i)*settings.getFieldSize().x + j;
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
		
					break;
				case sf::Keyboard::Down:
					
					break;
				case sf::Keyboard::Left:
					
					break;
				case sf::Keyboard::Right:
					
					break;
				default:
					break;
				}
			}
	return SCREEN_BASE_NOT_CHANGING_SCREEN;
}