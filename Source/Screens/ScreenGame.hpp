#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "ScreenBase.hpp"
#include "../Settings/Settings.hpp"
#include "../GameController/GameController.hpp"

class ScreenGame : public ScreenBase {
private:
	float movement_step;
	float posx;
	float posy;
	sf::RectangleShape Rectangle;
	GameController gameController;
	virtual int processEvent(const sf::Event &event) override;
public:
	ScreenGame(Settings&);
	// TODO:
	// Why do we need to pass sf::RenderWindow here if we have it in settings?
	// Can't we use settings.getRenderWindow() instead?(@Denmey)
	int run(sf::RenderWindow &window) override;
	void drawBackground(sf::RenderWindow &WIN);

  protected:
    Settings &settings; // Deleted const qualifier to be able to use .getRenderWindow() function in processEvent(...).(@Denmey)
};
