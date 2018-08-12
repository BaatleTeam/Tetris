#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>

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

public:
    Settings();
    ~Settings() = default;
    static const int StandartWidth = 1280; // затем умножается на коэфициенты

    sf::Vector2u getScreenSize() const;
    sf::Vector2u getFieldSize() const;

    void setScreenSize(unsigned int index);
    void setFieldSize(unsigned int index);
};