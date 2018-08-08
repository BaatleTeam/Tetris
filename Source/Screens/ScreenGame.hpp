#include <iostream>
#include <SFML/Graphics.hpp>
#include "ScreenBase.hpp"

class ScreenGame : public ScreenBase {
private:
	float movement_step;
	float posx;
	float posy;
	sf::RectangleShape Rectangle;
public:
	ScreenGame();
	int run(sf::RenderWindow &App) override;
};