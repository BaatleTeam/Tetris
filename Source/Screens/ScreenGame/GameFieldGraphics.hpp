#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../../Settings/Settings.hpp"
#include "../../GameController/GameController.hpp"
#include "../../ResourceManager.hpp"

class GameFieldGraphics {
private:
	std::vector <sf::Sprite> gameFieldSpites;
	float beginField_X = 250;
	float beginField_Y = 70;

	Settings &settings;

public:
    GameFieldGraphics(Settings &settings, ResourceManager &rM);

	void draw(const GameController &gc);
    void resize(float SpriteKF, float indentBetweenCells);


private:
	void update(const GameController &gc);
	int convertIndexes(int i, int j) const;
};