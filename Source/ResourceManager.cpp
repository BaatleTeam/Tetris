#include "ResourceManager.hpp"

ResourceManager::ResourceManager(){
    try {
        if (!blockTexture.loadFromFile("Resources/Pictures/testSprite.png"))
            throw "Texture load failed";
        
        blockSprite.setTexture(blockTexture);
        blockSprite.setColor(sf::Color::Red);
    }
    catch (const char* message){
        std::cout << message << std::endl;
        exit(-1);
    }
}

sf::Sprite& ResourceManager::getSpriteBlock() {
    return blockSprite;
}

sf::Texture& ResourceManager::getTextureBlock() {
    return blockTexture;
}