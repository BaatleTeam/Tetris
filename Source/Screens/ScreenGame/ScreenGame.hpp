#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../ScreenBase.hpp"
#include "../../Settings/Settings.hpp"
#include "../../GameController/GameController.hpp"
// #include "../../ResourceManager.hpp"
class GameFieldGraphics;
#include "GameFieldGraphics.hpp"
#include "NextFigureGraphics.hpp"
class ScreenGame : public ScreenBase {
private:
	GameController gameController;

	GameFieldGraphics gameFieldGraphics;
	sf::Vector2u gameFieldBegin {250, 70};

	NextFigureGraphics nextFigureGraphics;
	sf::Sprite gameBackground;

	// so it is a temprerory decision, it is needed to create own class for audio managmnet (where?)
	// reference to this class will be given in Screen-type classes, which will be call required methods to play 
	// different sounds
	sf::Sound soundFigureLanded;
	sf::Sound soundRowCleared;

	float SpriteKF = 0.15; // due to size of spite -> can used in settings instead
	float indentBetweenCells = 3; // in pixels in gameField

public:
	// TODO:
	// Why do we need to pass sf::RenderWindow here if we have it in settings?
	// Can't we use settings.getRenderWindow() instead?(@Denmey)
	ScreenGame(Settings&, ResourceManager&);
	ScreenType run(sf::RenderWindow &window) override;
	void resizeSprites() override;

private:
	void drawGameField();
	void drawNextFigure();

	void drawBackground(sf::RenderWindow&);
	void resizeBackground();
	
	virtual ScreenType processEvent(const sf::Event &event) override;

protected:
    Settings &settings; // Deleted const qualifier to be able to use .getRenderWindow() function in processEvent(...).(@Denmey)


friend class GameFieldGraphics;
};
