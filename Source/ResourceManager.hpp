#pragma once
#include <iostream>
#include <map>
#include <array>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

static constexpr size_t TexturesNumber = 2;
static constexpr size_t SoundsNumber = 2;

static constexpr auto resourceDirectory = "Resources";
static constexpr auto textureDirectory = "Pictures";
static constexpr auto soundDirectory = "Sounds";

static constexpr std::array<const char*, TexturesNumber> textureNames {
    "testSprite.png",
    "background.png",
};
static constexpr std::array<const char*, SoundsNumber> soundNames {
    "clear.wav",
    "fall.wav",
};

class ResourceManager {
private:
    sf::Font font;

    std::map <std::string, sf::Texture> textureContainer;
    std::map <std::string, sf::SoundBuffer> soundContainer;
public:
    ResourceManager();
    sf::Font& getFont();

    sf::Texture& getCellTexture();
    sf::Texture& getBackground();

private:
    std::string removeExtension(const std::string& str) const;

    template <typename... T>
    auto concatStrings(const std::string &divider, const T&... args) const {
        std::string result = {};
        for (const auto& elem : std::initializer_list<std::string>{args...})
            result = result + elem + divider;
        return result;
    };

    template <typename T, std::size_t SIZE>
    void loadResources(std::map<std::string, T> &container, const std::string &LoadPath, const std::array<const char*, SIZE> &names){
        for (const auto &fileName : names){
            try {
                T currentRes{};
                if (!currentRes.loadFromFile(concatStrings("", LoadPath, fileName)))
                    throw concatStrings(" ", "Resource file load failed: ", fileName);
                
                container.emplace(
                    std::move(removeExtension(fileName)),
                    std::move(currentRes)
                );
            }
            catch (const char* message){
                std::cout << message << std::endl;
                exit(-1);
            }
        }
        
    }
};