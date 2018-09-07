#include "ResourceManager.hpp"

ResourceManager::ResourceManager(){
    try {
        if (!blockTexture.loadFromFile("Resources/Pictures/testSprite.png"))
            throw "Texture load failed";
        
        blockSprite.setTexture(blockTexture);
    }
    catch (const char* message){
        std::cout << message << std::endl;
        exit(-1);
    }
}

const sf::Sprite& ResourceManager::getSpriteBlock() const {
    return blockSprite;
}