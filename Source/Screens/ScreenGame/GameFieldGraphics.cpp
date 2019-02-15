#include "GameFieldGraphics.hpp"

GameFieldGraphics::GameFieldGraphics(Settings &settings, ResourceManager &resourceManager)
	: settings(settings) {
	auto arraySize = settings.getFieldSize().x * settings.getFieldSize().y;
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

void GameFieldGraphics::resize() {
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
void GameFieldGraphics::update(const GameController &gameController){
	int fieldWidth = (int)settings.getFieldSize().x;
	int fieldHeight = (int)settings.getFieldSize().y;

	for (int i = fieldHeight-1; i >= 0; i--)
		for (int j = 0; j < fieldWidth; j++){
			if (gameController.getCellColor({(unsigned)j, (unsigned)i}) != gameFieldSpites[convertIndexes(i,j)].getColor())
				gameFieldSpites[convertIndexes(i,j)].setColor(gameController.getCellColor({(unsigned)j, (unsigned)i}));
			// std::cout << "i = " << i << " j = " << j << " --> [" << convertIndexes(i,j) << "]" << std::endl;
		}
}




int GameFieldGraphics::convertIndexes(int i, int j) const {
	return (settings.getFieldSize().y -1 - i)*settings.getFieldSize().x + j;
}
