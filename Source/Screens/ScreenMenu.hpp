#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include "Screens.hpp"
#include "../Settings.hpp"


class ScreenMenu : public ScreenBase {
private:
	
public:
	ScreenMenu(Settings &settings);
	int run(sf::RenderWindow &App);
protected:
    Settings &settings;
};