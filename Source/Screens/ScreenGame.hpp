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
	sf::RectangleShape Rectangle;
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
	void drawGameField(sf::RenderWindow &App, const std::vector <std::vector <ArrayCell>>& gameField);
	void drawBackground(sf::RenderWindow &WIN);
  
  protected:
    const Settings &settings;
};