#include "TetrisFigure.hpp"

TetrisFigure::TetrisFigure()
    : rotateVariants(1)
    , nextRotate(0+1) 
{
}

TetrisFigure::TetrisFigure(std::vector<sf::Vector2u> &&coord, int r_Variants){
    coordinates = coord;
    shapeColor = generateColor();
    rotateVariants = r_Variants;
    nextRotate = 1;
}

void TetrisFigure::moveDown(){
    for (auto &elem : coordinates)
        elem.y--;
}

void TetrisFigure::moveLeft(){
    for (auto &elem : coordinates)
        elem.x--;
}

void TetrisFigure::moveRight(){
    for (auto &elem : coordinates)
        elem.x++;
}

std::vector <sf::Vector2u> TetrisFigure::getCurCoordinates() const {
    return coordinates;
}

unsigned int TetrisFigure::getCellsNum() const {
    return coordinates.size();
}

const sf::Color& TetrisFigure::getColor() const {
    return shapeColor;
}

sf::Color TetrisFigure::generateColor(){
    // check randomizze
    // try to do universal reference
    unsigned int r = rand() % 2;
    unsigned int g = rand() % 2;
    unsigned int b = rand() % 2;
    return sf::Color(r * 255, g * 255, b * 255);
}


// СЛЕВА НАПРАВО
// СВЕРХУ ВНИЗ

Type0::Type0(unsigned int height, unsigned int width)
    : TetrisFigure({
                { width / 2,     height - 3 },
                { width / 2 + 1, height - 3 },
                { width / 2,     height - 4 },
                { width / 2 + 1, height - 4 } },
                1) {}

void Type0::rotate(const GameField& array) {
    // nothihg
}



Type1::Type1(unsigned int height, unsigned int width)
    : TetrisFigure({
                { width / 2,  height - 1 },
                { width / 2,  height - 2 },
                { width / 2,  height - 3 },
                { width / 2,  height - 4 } },
                2) {}

void Type1::rotate(const GameField& array) {
    decltype(coordinates) newCoord;
    switch (nextRotate){
        case 0:
            newCoord = {
                { coordinates[3].x - 1, coordinates[3].y },
                { coordinates[3].x,     coordinates[3].y },
                { coordinates[3].x + 1, coordinates[3].y },
                { coordinates[3].x + 2, coordinates[3].y }
            };
            break;
        case 1:
            newCoord = {
                { coordinates[1].x, coordinates[1].y + 3 },
                { coordinates[1].x, coordinates[1].y + 2 },
                { coordinates[1].x, coordinates[1].y + 1 },
                { coordinates[1].x, coordinates[1].y     }
            };
            break;
        default:
            throw "type 1 rotate error";
    }
    for (const auto elem : newCoord)
        if (array.isCellPainted(elem))
            return;
    coordinates.swap(newCoord);
    nextRotate++;
    nextRotate %= rotateVariants;
}



Type2::Type2(unsigned int height, unsigned int width)
    : TetrisFigure({
                { width / 2,     height - 3 },
                { width / 2,     height - 4 },
                { width / 2 + 1, height - 4 },
                { width / 2 + 2, height - 4 } },
                4) {}

void Type2::rotate(const GameField& array) {
    decltype(coordinates) newCoord;
    switch (nextRotate){
        case 0:
            newCoord = {
                { coordinates[1].x,     coordinates[1].y     },
                { coordinates[1].x,     coordinates[1].y - 1 },
                { coordinates[1].x + 1, coordinates[1].y - 1 },
                { coordinates[1].x + 2, coordinates[1].y - 1 }
            };
            break;
        case 1:
            newCoord = {
                { coordinates[1].x,     coordinates[1].y - 1 },
                { coordinates[1].x + 1, coordinates[1].y - 1 },
                { coordinates[1].x + 1, coordinates[1].y     },
                { coordinates[1].x + 1, coordinates[1].y + 1 },
            };
            break;
        case 2:
            newCoord = {
                { coordinates[2].x - 2, coordinates[2].y     },
                { coordinates[2].x - 1, coordinates[2].y     },
                { coordinates[2].x,     coordinates[2].y     },
                { coordinates[2].x,     coordinates[2].y - 1 },
            };
            break;
        case 3:
            newCoord = {
                { coordinates[1].x,     coordinates[1].y     },
                { coordinates[1].x,     coordinates[1].y - 1 },
                { coordinates[1].x,     coordinates[1].y - 2 },
                { coordinates[1].x + 1, coordinates[1].y     },
            };
            break;
        default:
            throw "type 2 rotate error";
    }
    for (const auto elem : newCoord)
        if (array.isCellPainted(elem))
            return;
    coordinates.swap(newCoord);
    nextRotate++;
    nextRotate %= rotateVariants;
}



Type3::Type3(unsigned int height, unsigned int width)
    : TetrisFigure({
                { width / 2,     height - 4 },
                { width / 2 + 1, height - 3 },
                { width / 2 + 1, height - 4 },
                { width / 2 + 2, height - 4 } },
                4) {}

void Type3::rotate(const GameField& array) {
    decltype(coordinates) newCoord;
    switch (nextRotate){
        case 0:
            newCoord = {
                { coordinates[1].x,     coordinates[1].y     },
                { coordinates[1].x,     coordinates[1].y - 1 },
                { coordinates[1].x + 1, coordinates[1].y - 1 },
                { coordinates[1].x + 2, coordinates[1].y - 1 }
            };
            break;
        case 1:
            newCoord = {
                { coordinates[2].x,     coordinates[2].y + 1 },
                { coordinates[2].x,     coordinates[2].y     },
                { coordinates[2].x,     coordinates[2].y - 1 },
                { coordinates[2].x + 1, coordinates[2].y     },
            };
            break;
        case 2:
            newCoord = {
                { coordinates[1].x - 1, coordinates[1].y     },
                { coordinates[1].x,     coordinates[1].y     },
                { coordinates[1].x,     coordinates[1].y - 1 },
                { coordinates[1].x + 1, coordinates[1].y     },
            };
            break;
        case 3:
            newCoord = {
                { coordinates[1].x - 1, coordinates[1].y     },
                { coordinates[1].x,     coordinates[1].y + 1 },
                { coordinates[1].x,     coordinates[1].y     },
                { coordinates[1].x,     coordinates[1].y - 1 },
            };
            break;
        default:
            throw "type 3 rotate error";
    }
    for (const auto elem : newCoord)
        if (array.isCellPainted(elem))
            return;
    coordinates.swap(newCoord);
    nextRotate++;
    nextRotate %= rotateVariants;
}



Type4::Type4(unsigned int height, unsigned int width)
    : TetrisFigure({
                { width / 2,     height - 4 },
                { width / 2 + 1, height - 4 },
                { width / 2 + 2, height - 3 },
                { width / 2 + 2, height - 4 } },
                4) {}

void Type4::rotate(const GameField& array) {
    decltype(coordinates) newCoord;
    switch (nextRotate){
        case 0:
            newCoord = {
                { coordinates[1].x - 1, coordinates[1].y     },
                { coordinates[1].x,     coordinates[1].y     },
                { coordinates[1].x + 1, coordinates[1].y - 1 },
                { coordinates[1].x + 1, coordinates[1].y     }
            };
            break;
        case 1:
            newCoord = {
                { coordinates[1].x - 1, coordinates[1].y + 1 },
                { coordinates[1].x,     coordinates[1].y + 1 },
                { coordinates[1].x,     coordinates[1].y     },
                { coordinates[1].x,     coordinates[1].y - 1 },
            };
            break;
        case 2:
            newCoord = {
                { coordinates[2].x - 1, coordinates[2].y     },
                { coordinates[2].x - 1, coordinates[2].y - 1 },
                { coordinates[2].x,     coordinates[2].y     },
                { coordinates[2].x + 1, coordinates[2].y     },
            };
            break;
        case 3:
            newCoord = {
                { coordinates[0].x,     coordinates[0].y + 1 },
                { coordinates[0].x,     coordinates[0].y     },
                { coordinates[0].x,     coordinates[0].y - 1 },
                { coordinates[0].x + 1, coordinates[0].y - 1 },
            };
            break;
        default:
            throw "type 4 rotate error";
    }
    for (const auto elem : newCoord)
        if (array.isCellPainted(elem))
            return;
    coordinates.swap(newCoord);
    nextRotate++;
    nextRotate %= rotateVariants;
}



Type5::Type5(unsigned int height, unsigned int width)
    : TetrisFigure({
                { width / 2,     height - 4 },
                { width / 2 + 1, height - 3 },
                { width / 2 + 1, height - 4 },
                { width / 2 + 2, height - 3 } },
                2) {}

void Type5::rotate(const GameField& array) {
    decltype(coordinates) newCoord;
    switch (nextRotate){
        case 0:
            newCoord = {
                { coordinates[3].x - 1, coordinates[3].y     },
                { coordinates[3].x,     coordinates[3].y     },
                { coordinates[3].x,     coordinates[3].y - 1 },
                { coordinates[3].x + 1, coordinates[3].y - 1 }
            };
            break;
        case 1:
            newCoord = {
                { coordinates[1].x - 1, coordinates[1].y     },
                { coordinates[1].x - 1, coordinates[1].y - 1 },
                { coordinates[1].x,     coordinates[1].y + 1 },
                { coordinates[1].x,     coordinates[1].y     }
            };
            break;
        default:
            throw "type 5 rotate error";
    }
    for (const auto elem : newCoord)
        if (array.isCellPainted(elem))
            return;
    coordinates.swap(newCoord);
    nextRotate++;
    nextRotate %= rotateVariants;
}



Type6::Type6(unsigned int height, unsigned int width)
    : TetrisFigure({
                { width / 2,     height - 3 },
                { width / 2 + 1, height - 3 },
                { width / 2 + 1, height - 4 },
                { width / 2 + 2, height - 4 } },
                2) {}

void Type6::rotate(const GameField& array) {
    decltype(coordinates) newCoord;
    switch (nextRotate){
        case 0:
            newCoord = {
                { coordinates[2].x - 1, coordinates[2].y - 1 },
                { coordinates[2].x,     coordinates[2].y     },
                { coordinates[2].x,     coordinates[2].y - 1 },
                { coordinates[2].x + 1, coordinates[2].y     }
            };
            break;
        case 1:
            newCoord = {
                { coordinates[1].x - 1, coordinates[1].y + 1 },
                { coordinates[1].x - 1, coordinates[1].y     },
                { coordinates[1].x,     coordinates[1].y     },
                { coordinates[1].x,     coordinates[1].y - 1 }
            };
            break;
        default:
            throw "type 6 rotate error";
    }
    for (const auto elem : newCoord)
        if (array.isCellPainted(elem))
            return;
    coordinates.swap(newCoord);
    nextRotate++;
    nextRotate %= rotateVariants;
}