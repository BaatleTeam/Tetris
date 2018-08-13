#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include "Screens.hpp"


class ScreenSettings : public ScreenBase {
private:
	
public:
	ScreenSettings(Settings &settings);
	int run(sf::RenderWindow &App);
protected:
    Settings &settings;
};