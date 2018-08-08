#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include "cScreen.hpp"


class screenMenu : public cScreen {
private:
	bool playing;
	sf::Font font;
	
public:
	screenMenu();
	int Run(sf::RenderWindow &App);
};