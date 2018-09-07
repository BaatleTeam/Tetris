#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "ScreenBase.hpp"
#include "../Settings/Settings.hpp"
#include "../GameController/GameController.hpp"
#include "../ResourceManager.hpp"

class ScreenGame : public ScreenBase {
private:
	float movement_step;
	float posx;
	float posy;
	sf::RectangleShape Rectangle;
	const ResourceManager& resourceManager;
	GameController gameController;
	
public:
	ScreenGame(const Settings&, const ResourceManager&);
	int run(sf::RenderWindow &App) override;

private:
	void drawGameField(sf::RenderWindow &App, const std::vector <std::vector <ArrayCell>>& gameField);
	void drawBackground(sf::RenderWindow &WIN);
  
  protected:
    const Settings &settings;
};