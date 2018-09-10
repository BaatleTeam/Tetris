#include "ResourceManager.hpp"

ResourceManager::ResourceManager(){
    try {
        if (!cellTexture.loadFromFile("Resources/Pictures/testSprite.png"))
            throw "Texture load failed";
    }
    catch (const char* message){
        std::cout << message << std::endl;
        exit(-1);
    }
}

sf::Texture& ResourceManager::getCellTexture() {
    return cellTexture;
}