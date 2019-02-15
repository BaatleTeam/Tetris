#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../../Settings/Settings.hpp"
#include "../../GameController/GameController.hpp"
#include "../../ResourceManager.hpp"

class GameFieldGraphics {
private:
	std::vector <sf::Sprite> gameFieldSpites;
	float SpriteKF = 0.15; // due to size of spite -> can used in settings instead
	float beginGameField_X = 300;
	float beginGameField_Y = 70;
	float indentBetweenCells = 3; // in pixels in gameField

	Settings &settings;

public:
    GameFieldGraphics(Settings &settings, ResourceManager &rM);

	void draw(const GameController &gc);
    void resize();


private:
	void update(const GameController &gc);
	int convertIndexes(int i, int j) const;
};