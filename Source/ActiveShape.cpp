#include "ActiveShape.hpp"

ActiveShape::ActiveShape()
    : rotateVariants(1)
    , currentRotate(0) 
{
}

ActiveShape::ActiveShape(std::vector<sf::Vector2u> &&coord, int r_Variants){
    coordinates = coord;
    rotateVariants = r_Variants;
    currentRotate = 0;
}

void ActiveShape::moveDown(){
    for (auto &elem : coordinates)
        elem.y--;
}

std::vector <sf::Vector2u> ActiveShape::getCurCoordinates() const {
    return coordinates;
}


unsigned int ActiveShape::getCellsNum() const {
    return coordinates.size();
}


// СЛЕВА НАПРАВО
// СВЕРХУ ВНИЗ

Type0::Type0(unsigned int height, unsigned int width)
    : ActiveShape({{width / 2,     height - 3},
                   {width / 2 + 1, height - 3},
                   {width / 2,     height - 4},
                   {width / 2 + 1, height - 4}},
                  1) {}

void Type0::rotate(const GameArray& array) {
    // nothihg
}



Type1::Type1(unsigned int height, unsigned int width)
    : ActiveShape({{width / 2, height - 1},
                   {width / 2, height - 2},
                   {width / 2, height - 3},
                   {width / 2, height - 4}},
                  2) {}

void Type1::rotate(const GameArray& array) {
    currentRotate++;
    currentRotate %= rotateVariants;
    decltype(coordinates) newCoord;
    switch (currentRotate){
        case 0:
            newCoord = {
                { coordinates[3].x-1, coordinates[3].y },
                { coordinates[3].x,   coordinates[3].y },
                { coordinates[3].x+1, coordinates[3].y },
                { coordinates[3].x+2, coordinates[3].y }
                };
            for (const auto elem : newCoord)
                if (array.isPainted(elem))
                    return;
            coordinates.swap(newCoord);
            break;
        case 1:
            newCoord = {
                { coordinates[1].x, coordinates[1].y+3 },
                { coordinates[1].x, coordinates[1].y+2 },
                { coordinates[1].x, coordinates[1].y+1 },
                { coordinates[1].x, coordinates[1].y   }
                };
            for (const auto elem : newCoord)
                if (array.isPainted(elem))
                    return;
            coordinates.swap(newCoord);
            break;
        default:
            throw "type 1 rotate error";
    }
}



Type2::Type2(unsigned int height, unsigned int width)
    : ActiveShape({{width / 2,     height - 3},
                   {width / 2,     height - 4},
                   {width / 2 + 1, height - 4},
                   {width / 2 + 2, height - 4}},
                  4) {}

void Type2::rotate(const GameArray& array) {
}



Type3::Type3(unsigned int height, unsigned int width)
    : ActiveShape({{width / 2,     height - 4},
                   {width / 2 + 1, height - 3},
                   {width / 2 + 1, height - 4},
                   {width / 2 + 2, height - 4}},
                  4) {}

void Type3::rotate(const GameArray& array) {
}



Type4::Type4(unsigned int height, unsigned int width)
    : ActiveShape({{width / 2,     height - 4},
                   {width / 2 + 1, height - 4},
                   {width / 2 + 2, height - 3},
                   {width / 2 + 2, height - 4}},
                  4) {}

void Type4::rotate(const GameArray& array) {
}



Type5::Type5(unsigned int height, unsigned int width)
    : ActiveShape({{width / 2,     height - 4},
                   {width / 2 + 1, height - 3},
                   {width / 2 + 1, height - 4},
                   {width / 2 + 2, height - 3}},
                  2) {}

void Type5::rotate(const GameArray& array) {
}



Type6::Type6(unsigned int height, unsigned int width)
    : ActiveShape({{width / 2,     height - 3},
                   {width / 2 + 1, height - 3},
                   {width / 2 + 1, height - 4},
                   {width / 2 + 2, height - 4}},
                  2) {}

void Type6::rotate(const GameArray& array) {
}