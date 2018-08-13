#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>

class GameArray;

class ActiveShape {
protected:
    std::vector <sf::Vector2u> coordinates;
    bool isActive_m;

public:
    ActiveShape(std::vector<sf::Vector2u> &&coord);
    ActiveShape();
    virtual ~ActiveShape() = default;
    void moveDown();
    bool isActive() const;
    unsigned int getCellsNum() const;
    std::vector <sf::Vector2u> getCurCoordinates() const;
    void setInactive();
    void setActive();

    // virtual void rotate(const GameArray&) = 0;
};

// квадрат
class Type1 : public ActiveShape {
public:
    Type1();
    Type1(std::vector<sf::Vector2u> &&coord);


};
//          **
// квдрат   **
class Type2 : public ActiveShape {
    private:
        int position; // todo
public:
    Type2();
    Type2(std::vector<sf::Vector2u> &&coord);

    // void rotate(const GameArray&) override;


};