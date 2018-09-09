#include "ScreenGame.hpp"

ScreenGame::ScreenGame(const Settings &settings, ResourceManager &rM)
 : resourceManager(rM)
 , gameController(settings)
 , settings(settings)

{	
	auto arraySize = settings.getFieldSize().x * settings.getFieldSize().y;
	gameFieldSpites.reserve(arraySize);

	const sf::Texture& cellTexture = resourceManager.getTextureBlock();
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
		App.clear(sf::Color(0, 0, 0, 0));
		//Drawing

		drawGameField(App, gameController.getGameArray());

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



void ScreenGame::drawGameField(sf::RenderWindow &App, const std::vector <std::vector <ArrayCell>>& gameField){
	updateGameField(gameField);
	for (auto blockSprite : gameFieldSpites)
		App.draw(blockSprite);		
}

void ScreenGame::updateGameField(const std::vector <std::vector <ArrayCell>>& gameField){
	for (int i = settings.getFieldSize().y-1; i >= 0; i--)
		for (int j = 0; j < (int)settings.getFieldSize().x; j++){
			if (gameField[i][j].getColor() != gameFieldSpites[convertIndexes(i,j)].getColor())
				gameFieldSpites[convertIndexes(i,j)].setColor(gameField[i][j].getColor());
			// std::cout << "i = " << i << " j = " << j << " --> [" << convertIndexes(i,j) << "]" << std::endl;
		}
}

int ScreenGame::convertIndexes(int i, int j) const {
	return (settings.getFieldSize().y -1 - i)*settings.getFieldSize().x + j;
}