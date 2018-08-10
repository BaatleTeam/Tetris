#include <iostream>
#include <SFML/Graphics.hpp>
#include "ScreenBase.hpp"
#include "Backgrounds.hpp"


class ScreenGame : public ScreenBase {
private:
	float movement_step;
	float posx;
	float posy;
	sf::RectangleShape Rectangle;
	// Background screenBackground;
	// Background gameBackground;
public:
	ScreenGame(Settings*);
	int run(sf::RenderWindow &App) override;
	void drawBackground(sf::RenderWindow &WIN);
};