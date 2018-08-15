#pragma once
//#include <vector>
#include <map>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Font.hpp>

class vector;
class string;

typedef unsigned int uint;

// В Settings хрянятся все настраиваемые парметры, их возможные значения и ихтекущее значение
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

    sf::Font font;

public:
    Settings();
    ~Settings() = default;
    static const int StandartWidth = 1280; // затем умножается на коэфициенты
    std::map<std::string, int&> vars;
    std::map<std::string, std::string&> strings;

    sf::Vector2u getScreenSize() const;
    sf::Vector2u getFieldSize() const;
    sf::Font getFont() const;
    void printVars();

    void setScreenSize(unsigned int index);
    void setFieldSize(unsigned int index);
    void nextScreenSize();
    void nextFieldSize();
    
};