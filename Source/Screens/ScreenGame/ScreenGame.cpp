#include "ScreenGame.hpp"

ScreenGame::ScreenGame(Settings &settings, ResourceManager &rM)
	: ScreenBase(rM)
	, gameController(settings)
	, gameFieldGraphics(settings, rM)
	, nextFigureGraphics(settings, rM)
	, settings(settings) // ?
{	
	gameBackground.setTexture(resourceManager.getBackground());

	// temp
	soundFigureLanded.setBuffer(resourceManager.getFigureLandedSound());
	soundRowCleared.setBuffer(resourceManager.getRowClearedSound());

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
    
		drawGameField();
		drawNextFigure();

		window.display();
	}

	//Never reaching this point normally, but just in case, exit the windowlication
	return ScreenType::Error;
}

void ScreenGame::resizeSprites() {
	std::cout << "resizeGame" << std::endl;
	resizeBackground();
	gameFieldGraphics.resize(SpriteKF, indentBetweenCells);
	nextFigureGraphics.resize(SpriteKF, indentBetweenCells);
}

void ScreenGame::drawGameField(){
	gameFieldGraphics.draw(gameController);	
}

void ScreenGame::drawNextFigure(){
	nextFigureGraphics.draw(gameController);
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
				// if (!gameController.checkFurtherMoving())
				// 	gameController.doStep();
				break;

			case sf::Keyboard::Left:
				gameController.moveFigureLeft();
				break;
			
			case sf::Keyboard::Right:
				gameController.moveFigureRight();	
				break;

			case sf::Keyboard::Space:
				gameController.dropFigure();
				break;
			
			default:
				break;
		}
	}
	
	return ScreenType::NotChange;
}