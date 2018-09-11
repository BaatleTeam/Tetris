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

	
public:
	// TODO:
	// Why do we need to pass sf::RenderWindow here if we have it in settings?
	// Can't we use settings.getRenderWindow() instead?(@Denmey)
	ScreenGame(Settings&, ResourceManager&);
	int run(sf::RenderWindow &window) override;

private:
	void drawGameField(sf::RenderWindow &App);
	void drawBackground(sf::RenderWindow &WIN);
	void updateGameField();
	int convertIndexes(int i, int j) const;
	virtual int processEvent(const sf::Event &event) override;

  protected:
    Settings &settings; // Deleted const qualifier to be able to use .getRenderWindow() function in processEvent(...).(@Denmey)
};
