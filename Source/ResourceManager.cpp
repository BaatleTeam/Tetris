#include "ResourceManager.hpp"

ResourceManager::ResourceManager(){
    const auto pathT = concatStrings("/", resourceDirectory, textureDirectory);
    loadResources<sf::Texture, TexturesNumber> (textureContainer, pathT, textureNames);

    const auto pathS = concatStrings("/", resourceDirectory, soundDirectory);
    loadResources<sf::SoundBuffer, SoundsNumber> (soundContainer, pathS, soundNames);

    // for (auto &elem : textureContainer)
    //     std::cout << elem.first << " ";
    // for (auto &elem : soundContainer)
    //     std::cout << elem.first << " ";

    try {
        if (!font.loadFromFile("Resources/Fonts/SIMPLIFICA Typeface.ttf"))
		    throw "Font load failed";
    }
    catch (const char* message){
        std::cout << message << std::endl;
        exit(-1);
    }
}

sf::Texture& ResourceManager::getCellTexture() {
    return textureContainer["testSprite"];
}

sf::Font& ResourceManager::getFont(){
    return font;
}

sf::Texture& ResourceManager::getBackground() {
    return textureContainer["background"];
}

const sf::SoundBuffer& ResourceManager::getRowClearedSound() {
    return soundContainer["clear"];
}

const sf::SoundBuffer& ResourceManager::getFigureLandedSound() { 
    return soundContainer["fall"];
}

std::string ResourceManager::removeExtension(const std::string& str) const {
    char point = '.';
    const auto begin = str.find_first_not_of(point);
    const auto end = str.find_first_of(point);
    return str.substr(begin, end-begin);
}