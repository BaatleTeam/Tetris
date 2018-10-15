#include "ScreenGame.hpp"

ScreenGame::ScreenGame(Settings &settings, ResourceManager &rM)
 : ScreenBase(rM)
 , gameController(settings)
 , settings(settings)

{	
	gameBackground.setTexture(resourceManager.getBackground("todo"));

	auto arraySize = settings.getFieldSize().x * settings.getFieldSize().y;
	gameFieldSpites.reserve(arraySize);

	const sf::Texture& cellTexture = resourceManager.getCellTexture();

	for (unsigned i = 0; i < arraySize; i++){
		gameFieldSpites.emplace_back(sf::Sprite{});
		gameFieldSpites.back().setTexture(cellTexture);
		gameFieldSpites.back().setColor(sf::Color::Red);
	}
}

ScreenType ScreenGame::run(sf::RenderWindow &window)
{
	// if (isResolutionChanged) {
	// 	resizeSprites();
	// 	isResolutionChanged = false;
	// }
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
	float spriteKF = 0.15;
	float windowKF = (float)settings.getScreenSize().x / Settings::RenderWindowMaxWidth;
	spriteKF *= windowKF;
	
	auto beginX = 350 * windowKF;
	float currX = beginX;
	float currY = 30 * windowKF;
	float spriteSize = Settings::SpriteBlockOriginalWidth * spriteKF;
	float indent = 3;

	unsigned numberInRow = 1;
	for (auto &sprite : gameFieldSpites){
		sprite.setScale({spriteKF, spriteKF});
		currX += spriteSize + indent;
		sprite.setPosition({ currX, currY });
		if (numberInRow >= settings.getFieldSize().x){
			currY += spriteSize + indent;
			currX = beginX;
			numberInRow = 0;
		}
		numberInRow++;
	}
}

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
		switch (event.key.code)
		{
		case sf::Keyboard::Escape:
			return ScreenType::Menu;
			break;
		
		case sf::Keyboard::Up:

			break;
		case sf::Keyboard::Down:
			
			break;
		case sf::Keyboard::Left:
			gameController.moveFigureLeft();
			break;
		
		case sf::Keyboard::Right:
			gameController.moveFigureRight();	
			break;
		default:
			break;
		}
	}
	return ScreenType::NotChange;
}