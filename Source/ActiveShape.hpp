#pragma once
#include <vector>
#include <iostream>
#include <SFML/System/Vector2.hpp>

class GameArray;

class ActiveShape {
protected:
    std::vector <sf::Vector2u> coordinates; // may be private
    bool isActive_m;

public:
    ActiveShape(std::vector<sf::Vector2u> &&coord);
    ActiveShape();
    virtual ~ActiveShape() = default;
    void moveDown();
    unsigned int getCellsNum() const;
    std::vector <sf::Vector2u> getCurCoordinates() const;
    bool isActive() const;
    void setInactive();
    void setActive();

    virtual void rotate(const GameArray&) = 0;
    // c такой сигнатурой можно перенести метод checkShapeMoving из GameArray
    // тоже чисто виртуальный но с реализацией по умолчанию (как сейчас)
};

//          **
// квадрат  ** 
class Type0 : public ActiveShape {
public:
    Type0(unsigned int arrayHeight, unsigned int arrayWidth);
    void rotate(const GameArray&) override;
    virtual ~Type0(){
        std::cout << "Destr type0" << std::endl;
    }
};

//
// палка-4   ****  
class Type1 : public ActiveShape {
public:
    Type1(unsigned int arrayHeight, unsigned int arrayWidth);
    void rotate(const GameArray&) override;
};

//                         * 
// палка-3 со шткой слева  ***  
class Type2 : public ActiveShape {
public:
    Type2(unsigned int arrayHeight, unsigned int arrayWidth);
    void rotate(const GameArray&) override;
};

//                                *
// палка-3 со шуткой по середине ***
class Type3 : public ActiveShape {
public:
    Type3(unsigned int arrayHeight, unsigned int arrayWidth);
    void rotate(const GameArray&) override;
};

//                            *
// палка-3 со шуткой справа ***
class Type4 : public ActiveShape {
public:
    Type4(unsigned int arrayHeight, unsigned int arrayWidth);
    void rotate(const GameArray&) override;
};

//                                 **
// элемент 2-2 левоориентированный  **
class Type5 : public ActiveShape {
public:
    Type5(unsigned int arrayHeight, unsigned int arrayWidth);
    void rotate(const GameArray&) override;
};

//                                    **
// элемент 2-2 правоориентированный  **
class Type6 : public ActiveShape {
public:
    Type6(unsigned int arrayHeight, unsigned int arrayWidth);
    void rotate(const GameArray&) override;
};