#include "ResourceManager.hpp"

ResourceManager::ResourceManager(){
    try {
        if (!cellTexture.loadFromFile("Resources/Pictures/testSprite.png"))
            throw "Texture load failed";
        if (!font.loadFromFile("Resources/Fonts/SIMPLIFICA Typeface.ttf"))
		    throw "Font load failed";
        if (!backgroundGame.loadFromFile("Resources/Pictures/background.png"))
            throw "Gamebackground load failed";
    }
    catch (const char* message){
        std::cout << message << std::endl;
        exit(-1);
    }
}

sf::Texture& ResourceManager::getCellTexture() {
    return cellTexture;
}

sf::Font& ResourceManager::getFont(){
    return font;
}

sf::Texture& ResourceManager::getBackground(std::string bcg_name) {
    // todo set and searching by name
    return backgroundGame;
}