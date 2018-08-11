#include "GameArray.hpp"

GameArray::GameArray(const Settings &s) : height(s.getFieldSize().y), width(s.getFieldSize().x) {
    ptrArray = new ArrayCell*[height];
    for (int i = 0; i < height; i++)
        ptrArray[i] = new ArrayCell[width]();
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
    if (!activeShape.isActive()){
        moveActiveShapeToArray();
        // shapeGenerator->generateNewShape(activeShape);
    }
    if (checkShapeMoving())
        activeShape.moveDown();
    else {
        activeShape.setInactive();
    }
}

bool GameArray::checkShapeMoving() const {
    for (const auto &curShapeCoord : activeShape.getCurCoordinates())
        if (ptrArray[curShapeCoord.x][curShapeCoord.y-1].isPainted())
            return false;
    return true;
}

void GameArray::moveActiveShapeToArray(){
    for (auto const &curShapeCoord : activeShape.getCurCoordinates())
        ptrArray[curShapeCoord.x][curShapeCoord.y].makePainted();
}

inline
bool GameArray::isPainted(sf::Vector2u coord) const {
    return ptrArray[coord.x][coord.y].isPainted();
}

std::ostream& operator<<(std::ostream &out, const GameArray &gmr){
    for (int i = 0; i < gmr.height; i++){
        out << std::setw(3) << gmr.height - i << "| ";
        for (int j = 0; j < gmr.width; j++)
            out << gmr.ptrArray[i][j].isPainted() << " ";
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
