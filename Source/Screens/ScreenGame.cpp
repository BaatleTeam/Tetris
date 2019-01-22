#include "ScreenGame.hpp"

ScreenGame::ScreenGame(Settings &settings, ResourceManager &rM)
 : ScreenBase(rM)
 , gameController(settings)
 , settings(settings)

{	
	gameBackground.setTexture(resourceManager.getBackground());

	auto arraySize = settings.getFieldSize().x * settings.getFieldSize().y;
	gameFieldSpites.reserve(arraySize);

	const sf::Texture& cellTexture = resourceManager.getCellTexture();

	for (unsigned i = 0; i < arraySize; i++){
		gameFieldSpites.emplace_back(sf::Sprite{});
		gameFieldSpites.back().setTexture(cellTexture);
		gameFieldSpites.back().setColor(sf::Color::Red); // why red?
	}
}

ScreenType ScreenGame::run(sf::RenderWindow &window)
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
			ScreenType result = processEvent(event);
			if (result != ScreenType::NotChange) {
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
		drawBackground(window);
    
		drawGameField(window);

		window.display();
	}

	//Never reaching this point normally, but just in case, exit the windowlication
	return ScreenType::Error;
}

void ScreenGame::resizeSprites() {
	std::cout << "resizeGame" << std::endl;
	resizeBackground();
	resizeGameField();
}







void ScreenGame::drawGameField(sf::RenderWindow &window){
	updateGameField();
	for (auto blockSprite : gameFieldSpites)
		window.draw(blockSprite);		
}

void ScreenGame::resizeGameField() {
	float currSpriteKF = SpriteKF;
	float windowKF = (float)settings.getScreenSize().x / Settings::RenderWindowMaxWidth;
	currSpriteKF *= windowKF;
	
	float currX = beginGameField_X * windowKF;
	float currY = beginGameField_Y * windowKF;
	float spriteSize = Settings::SpriteBlockOriginalWidth * currSpriteKF;
	float indent = indentBetweenCells * windowKF;

	unsigned numberInRow = 1;
	for (auto &sprite : gameFieldSpites){
		sprite.setScale({currSpriteKF, currSpriteKF});
		currX += spriteSize + indent;
		sprite.setPosition({ currX, currY });
		if (numberInRow >= settings.getFieldSize().x){
			currY += spriteSize + indent;
			currX = beginGameField_X * windowKF;
			numberInRow = 0;
		}
		numberInRow++;
	}
}

// change color of changed sprites
void ScreenGame::updateGameField(){
	for (int i = settings.getFieldSize().y-1; i >= 0; i--)
		for (int j = 0; j < (int)settings.getFieldSize().x; j++){
			if (gameController.getCellColor({(unsigned)j, (unsigned)i}) != gameFieldSpites[convertIndexes(i,j)].getColor())
				gameFieldSpites[convertIndexes(i,j)].setColor(gameController.getCellColor({(unsigned)j, (unsigned)i}));
			// std::cout << "i = " << i << " j = " << j << " --> [" << convertIndexes(i,j) << "]" << std::endl;
		}
}

int ScreenGame::convertIndexes(int i, int j) const {
	return (settings.getFieldSize().y -1 - i)*settings.getFieldSize().x + j;
}




void ScreenGame::drawBackground(sf::RenderWindow &window){
	window.draw(gameBackground);
}

void ScreenGame::resizeBackground() {
	auto scaleKF = (float)settings.getScreenSize().x / Settings::RenderWindowMaxWidth;
	gameBackground.setScale({scaleKF, scaleKF});
}

ScreenType ScreenGame::processEvent(const sf::Event &event) {
	// Window closed
	if (event.type == sf::Event::Closed)
	{
		return (ScreenType::Exit);
	}

	//Key pressed
	if (event.type == sf::Event::KeyPressed)
	{
		switch (event.key.code){
			case sf::Keyboard::Escape:
				return ScreenType::Menu;
				break;
			
			case sf::Keyboard::Up:
				gameController.rotateFigure();
				break;

			case sf::Keyboard::Down:
				gameController.moveFigureDown();
				if (!gameController.checkFurtherMoving())
					gameController.doStep();
				break;

			case sf::Keyboard::Left:
				gameController.moveFigureLeft();
				break;
			
			case sf::Keyboard::Right:
				gameController.moveFigureRight();	
				break;

			case sf::Keyboard::Space:
				gameController.dropFigure();
				gameController.doStep();
				break;
			
			default:
				break;
		}
	}
	
	return ScreenType::NotChange;
}