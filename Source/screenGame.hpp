#include <iostream>
#include <SFML/Graphics.hpp>
#include "cScreen.hpp"

class screenGame : public cScreen {
private:
	float movement_step;
	float posx;
	float posy;
	sf::RectangleShape Rectangle;
public:
	screenGame();
	int Run(sf::RenderWindow &App) override;
};