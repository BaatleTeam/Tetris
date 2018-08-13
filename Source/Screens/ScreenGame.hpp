#include <iostream>
#include <SFML/Graphics.hpp>
#include "ScreenBase.hpp"
#include "../Settings.hpp"

class ScreenGame : public ScreenBase {
private:
	float movement_step;
	float posx;
	float posy;
	sf::RectangleShape Rectangle;
public:
	ScreenGame(Settings &settings);
	int run(sf::RenderWindow &App) override;
protected:
    Settings &settings;
};