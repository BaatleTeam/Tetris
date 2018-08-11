#include "GameArray.hpp"

GameArray::GameArray(const Settings &s) : height(s.getFieldSize().y + 3), width(s.getFieldSize().x + 2), activeShape({{1,5}, {2,5}, {3,5}}) {
    ptrArray = new ArrayCell*[height];
    for (int i = 0; i < height; i++)
        ptrArray[i] = new ArrayCell[width]();
    for (int i = 0; i < width; i++)
        ptrArray[0][i].makePainted();
    for (int i = 1; i < height; i++){
        ptrArray[i][0].makePainted();
        ptrArray[i][width-1].makePainted();
    }

    // высота увеличивается на 3, т.к. 0-уровень и первые два выделяются по буфер
    // ширина на 2 по той же причине
}

GameArray::~GameArray(){
    freeArray();
}

void GameArray::freeArray(){
    for (int i = 0; i < width; i++)
        delete[] ptrArray[i];
    delete ptrArray;
    ptrArray = nullptr;
}

void GameArray::doStep(){
    // if (!activeShape.isActive()){
    //     displayActiveShapeOnArray();
    //     // shapeGenerator->generateNewShape(activeShape);
    // }
    if (checkShapeMoving()){
        removeActiveShapeFromArray();
        activeShape.moveDown();
        displayActiveShapeOnArray();
    }
    else {
        activeShape.setInactive();
    }
}

bool GameArray::checkShapeMoving() const {
    for (const auto &curShapeCoord : activeShape.getCurCoordinates())
        if (ptrArray[curShapeCoord.y-1][curShapeCoord.x].isPainted())
            return false;
    return true;
}

void GameArray::displayActiveShapeOnArray(){
    for (auto const &curShapeCoord : activeShape.getCurCoordinates())
        ptrArray[curShapeCoord.y][curShapeCoord.x].makePainted();
}

void GameArray::removeActiveShapeFromArray(){
    for (auto const &curShapeCoord : activeShape.getCurCoordinates())
        ptrArray[curShapeCoord.y][curShapeCoord.x].makeUnpainted();  
}

inline
bool GameArray::isPainted(sf::Vector2u coord) const {
    return ptrArray[coord.y][coord.x].isPainted();
}

std::ostream& operator<<(std::ostream &out, const GameArray &gmr){
    for (int i = 0; i < gmr.height; i++){
        out << std::setw(3) << gmr.height -1 - i << "| ";
        for (int j = 0; j < gmr.width; j++)
            out << gmr.ptrArray[gmr.height -1 - i][j].isPainted() << " ";
        out << "\n";
    }
    out << std::setw(4);
    out << (char)192;
    for (int i = 0; i < gmr.width; i++)
        out  <<  "--";
    out << "\n";
    out << std::setw(6);
    for (int i = 0; i < gmr.width; i++)
        out  << i << " ";
    out << "\n";
    for (const auto &elem : gmr.activeShape.getCurCoordinates())
        out << "x = " << elem.x << " y = " <<  elem.y << "\n";
    out << "\n\n" << std::endl;
    return out;
}

// ------------------------------------------------------------------------------


ActiveShape::ActiveShape(){
    isActive_m = false;
}

ActiveShape::ActiveShape(std::vector<sf::Vector2u> &&coord){
    coordinates = coord;
    isActive_m = true;
}

void ActiveShape::moveDown(){
    for (auto &elem : coordinates)
        elem.y--;
}

std::vector <sf::Vector2u> ActiveShape::getCurCoordinates() const {
    return coordinates;
}

bool ActiveShape::isActive() const {
    return isActive_m;
}

void ActiveShape::setInactive() {
    isActive_m = false;
}

void ActiveShape::setActive(){
    isActive_m = true;
}

unsigned int ActiveShape::getCellsNum() const {
    return coordinates.size();
}
