#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include "ScreenBase.hpp"


class ScreenSettings : public ScreenBase {
private:
	// bool playing;
	sf::Font font;
	
public:
	ScreenSettings();
	int run(sf::RenderWindow &App);
};