#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "../../Settings/Settings.hpp"
#include "../../ResourceManager.hpp"
#include "../../GameController/GameController.hpp"

class NextFigureGraphics {
private:
    std::vector <sf::Sprite> fieldSprites;
    float beginField_X = 600;
	float beginField_Y = 200;
    sf::Color BackgroundSpriteColor = sf::Color::Red;

    sf::RectangleShape border;

    Settings &settings;

public:
    NextFigureGraphics(Settings&, ResourceManager&);

    void resize(float SpriteKF, float indentBetweenCells);
    void draw(const GameController &gc);

private:
    void update(const GameController &gc);

};