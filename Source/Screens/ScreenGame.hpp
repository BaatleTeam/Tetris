#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "ScreenBase.hpp"
#include "../Settings/Settings.hpp"
#include "../GameController.hpp"

class ScreenGame : public ScreenBase {
private:
	float movement_step;
	float posx;
	float posy;
	sf::RectangleShape Rectangle;
	GameController gameController;
	
public:
	ScreenGame(const Settings&);
	int run(sf::RenderWindow &App) override;
	void drawBackground(sf::RenderWindow &WIN);
  
  protected:
    Settings &settings;
};