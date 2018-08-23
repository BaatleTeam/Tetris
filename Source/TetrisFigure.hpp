#pragma once
#include <vector>
#include <iostream>
#include <SFML/System/Vector2.hpp>
#include "GameController.hpp"

class GameController;

class TetrisFigure {
protected:
    std::vector <sf::Vector2u> coordinates;
    sf::Color shapeColor;
    int rotateVariants;
    int currentRotate;

public:
    TetrisFigure(std::vector<sf::Vector2u> &&coord, int r_Variants);
    TetrisFigure();
    virtual ~TetrisFigure() = default;
    void moveDown();
    unsigned int getCellsNum() const;
    std::vector <sf::Vector2u> getCurCoordinates() const;
    const sf::Color& getColor() const; 

    virtual void rotate(const GameController&) = 0;
    // c такой сигнатурой можно перенести метод checkShapeMoving из GameController
    // тоже чисто виртуальный но с реализацией по умолчанию (как сейчас)

private:
    sf::Color generateColor();
};

//          **
// квадрат  ** 
class Type0 : public TetrisFigure {
public:
    Type0(unsigned int arrayHeight, unsigned int arrayWidth);
    void rotate(const GameController&) override;
};

//
// палка-4   ****  
class Type1 : public TetrisFigure {
public:
    Type1(unsigned int arrayHeight, unsigned int arrayWidth);
    void rotate(const GameController&) override;
};

//                         * 
// палка-3 со шткой слева  ***  
class Type2 : public TetrisFigure {
public:
    Type2(unsigned int arrayHeight, unsigned int arrayWidth);
    void rotate(const GameController&) override;
};

//                                *
// палка-3 со шуткой по середине ***
class Type3 : public TetrisFigure {
public:
    Type3(unsigned int arrayHeight, unsigned int arrayWidth);
    void rotate(const GameController&) override;
};

//                            *
// палка-3 со шуткой справа ***
class Type4 : public TetrisFigure {
public:
    Type4(unsigned int arrayHeight, unsigned int arrayWidth);
    void rotate(const GameController&) override;
};

//                                 **
// элемент 2-2 левоориентированный  **
class Type5 : public TetrisFigure {
public:
    Type5(unsigned int arrayHeight, unsigned int arrayWidth);
    void rotate(const GameController&) override;
};

//                                    **
// элемент 2-2 правоориентированный  **
class Type6 : public TetrisFigure {
public:
    Type6(unsigned int arrayHeight, unsigned int arrayWidth);
    void rotate(const GameController&) override;
};