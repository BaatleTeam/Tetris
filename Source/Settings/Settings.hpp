#ifndef SETTINGS_HPP_INCLUDED
#define SETTINGS_HPP_INCLUDED

#include <map>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics.hpp>

class vector;
class string;

typedef unsigned int uint; 

// В Settings хрянятся все настраиваемые парметры, их возможные значения и их текущее значение
// можно инициализироватьь с файла.dat, пока что в консстукторе
// на основе настроек конфигурируются размеры спрайтов, сложность игры, поля и т.д.

class Settings {
private:
    std::vector<sf::Vector2u> screenSizes;
    std::vector<sf::Vector2u> fieldSizes;
    // сложность
    // цвет - ?
    
    mutable int indexScreenSize;
    mutable int indexFieldSize;

    int windowStyle;
    std::string windowName;
    sf::RenderWindow window; 

public:
    static const int RenderWindowMaxWidth = 1000; // затем умножается на коэфициенты
    static const int RenderWindowMaxHeight = 800;
    static const int SpriteBlockOriginalWidth = 204;
    Settings();
    ~Settings() = default;

    void nextScreenSize();
    void nextFieldSize();

    int getConfigurationVar(const std::string&) const;
    const std::string& getConfigurationString(const std::string&) const; 

    sf::Vector2u getScreenSize() const;
    sf::Vector2u getFieldSize() const;
    sf::RenderWindow &getRenderWindow();
    void printVars() const;

private:
    std::map<std::string, int&> vars;
    std::map<std::string, std::string&> strings;


    void setScreenSize(unsigned int index);
    void setFieldSize(unsigned int index);
    
};

#endif