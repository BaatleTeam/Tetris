#include "NextFigureGraphics.hpp"

NextFigureGraphics::NextFigureGraphics(Settings& settings, ResourceManager& resourceManager)
    : settings(settings) 
{
    auto arraySize = settings.getNextFigureFieldSize().x * settings.getNextFigureFieldSize().y;
	fieldSprites.reserve(arraySize);
	const sf::Texture& cellTexture = resourceManager.getCellTexture();

	for (size_t i = 0; i < arraySize; i++){
		fieldSprites.emplace_back(sf::Sprite{});
		fieldSprites.back().setTexture(cellTexture);
		fieldSprites.back().setColor(BackgroundSpriteColor); // why red?
	}    

	border.setFillColor(BackgroundSpriteColor);
	border.setOutlineThickness(10);
	border.setOutlineColor(sf::Color::Black);
	border.setSize({250, 400});
	border.setPosition(650, 50);
}

void NextFigureGraphics::draw(const GameController &gc){
	settings.getRenderWindow().draw(border);

	update(gc);
	for (auto blockSprite : fieldSprites)
		settings.getRenderWindow().draw(blockSprite);
}

void NextFigureGraphics::resize(float SpriteKF, float indentBetweenCells){
	float currSpriteKF = SpriteKF;
	float windowKF = (float)settings.getScreenSize().x / Settings::RenderWindowMaxWidth;
	currSpriteKF *= windowKF;
	
	float currX = beginField_X * windowKF;
	float currY = beginField_Y * windowKF;
	float spriteSize = Settings::SpriteBlockOriginalWidth * currSpriteKF;
	float indent = indentBetweenCells * windowKF;

	unsigned numberInRow = 1;
	for (auto &sprite : fieldSprites){
		sprite.setScale({currSpriteKF, currSpriteKF});
		currX += spriteSize + indent;
		sprite.setPosition({ currX, currY });
		if (numberInRow >= settings.getNextFigureFieldSize().x){
			currY += spriteSize + indent;
			currX = beginField_X * windowKF;
			numberInRow = 0;
		}
		numberInRow++;
	}
}


void NextFigureGraphics::update(const GameController &gc){
	//  to do update from gc
}