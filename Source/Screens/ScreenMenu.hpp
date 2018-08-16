#include <iostream>
#include <SFML/Graphics.hpp>
#include "Screens.hpp"
#include "../Settings/Settings.hpp"

class ScreenMenu : public ScreenBase {
private:
	
public:
	ScreenMenu(Settings &settings);
	int run(sf::RenderWindow &App);
protected:
    Settings &settings;
};