#include "GameFieldGraphics.hpp"

GameFieldGraphics::GameFieldGraphics(Settings &settings, ResourceManager &resourceManager)
	: settings(settings) {
	auto arraySize = settings.getGameFieldSize().x * settings.getGameFieldSize().y;
	gameFieldSpites.reserve(arraySize);

	const sf::Texture& cellTexture = resourceManager.getCellTexture();
	for (unsigned i = 0; i < arraySize; i++){
		gameFieldSpites.emplace_back(sf::Sprite{});
		gameFieldSpites.back().setTexture(cellTexture);
		gameFieldSpites.back().setColor(sf::Color::Red); // why red?
	}
}

void GameFieldGraphics::draw(const GameController &gc){
	update(gc);
	for (auto blockSprite : gameFieldSpites)
		settings.getRenderWindow().draw(blockSprite);	
}

void GameFieldGraphics::resize(float SpriteKF, float indentBetweenCells) {
	float currSpriteKF = SpriteKF;
	float windowKF = (float)settings.getScreenSize().x / Settings::RenderWindowMaxWidth;
	currSpriteKF *= windowKF;
	
	float currX = beginField_X * windowKF;
	float currY = beginField_Y * windowKF;
	float spriteSize = Settings::SpriteBlockOriginalWidth * currSpriteKF;
	float indent = indentBetweenCells * windowKF;

	unsigned numberInRow = 1;
	for (auto &sprite : gameFieldSpites){
		sprite.setScale({currSpriteKF, currSpriteKF});
		currX += spriteSize + indent;
		sprite.setPosition({ currX, currY });
		if (numberInRow >= settings.getGameFieldSize().x){
			currY += spriteSize + indent;
			currX = beginField_X * windowKF;
			numberInRow = 0;
		}
		numberInRow++;
	}
}

// change color of changed sprites
void GameFieldGraphics::update(const GameController &gameController){
	int fieldWidth = (int)settings.getGameFieldSize().x;
	int fieldHeight = (int)settings.getGameFieldSize().y;

	for (int i = fieldHeight-1; i >= 0; i--)
		for (int j = 0; j < fieldWidth; j++){
			if (gameController.getCellColor({(unsigned)j, (unsigned)i}) != gameFieldSpites[convertIndexes(i,j)].getColor())
				gameFieldSpites[convertIndexes(i,j)].setColor(gameController.getCellColor({(unsigned)j, (unsigned)i}));
			// std::cout << "i = " << i << " j = " << j << " --> [" << convertIndexes(i,j) << "]" << std::endl;
		}
}




int GameFieldGraphics::convertIndexes(int i, int j) const {
	return (settings.getGameFieldSize().y -1 - i)*settings.getGameFieldSize().x + j;
}
