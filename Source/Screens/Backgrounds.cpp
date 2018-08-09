#include "Backgrounds.hpp"
#include <iostream>

Background::Background(const Settings *settings, const std::string &path){
	std::cout << " In construcor bckg" << std::endl;
	std::cout << texture.loadFromFile(path) << std::endl;
	double kf = (double)settings->getScreenSize().x / Settings::StandartWidth;
	backgroundSprite.setTexture(texture);
	backgroundSprite.setScale(kf, kf);
	std::cout << "Out from constructor" << std::endl;
}

void Background::Draw(sf::RenderWindow &WIN){
	WIN.draw(backgroundSprite);
}