#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "ScreenBase.hpp"
#include "../Settings/Settings.hpp"
#include "../GameController/GameController.hpp"
#include "../ResourceManager.hpp"
#include <iostream>

class ScreenGame : public ScreenBase {
private:
	ResourceManager& resourceManager;
	GameController gameController;

	std::vector <sf::Sprite> gameFieldSpites;
	int border; // in pixels between cells in gameField

	float movement_step;
	float posx;
	float posy;
	
public:
	ScreenGame(const Settings&, ResourceManager&);
	int run(sf::RenderWindow &App) override;

private:
	void drawGameField(sf::RenderWindow &App);
	void drawBackground(sf::RenderWindow &WIN);
	void updateGameField();
	int convertIndexes(int i, int j) const;
  
  protected:
    const Settings &settings;
};