#pragma once
#include <iostream>
#include <iomanip>
#include "ArrayCell.hpp"
#include "Settings.hpp"
#include "FigureGenerator.hpp"
#include "TetrisFigure.hpp"

class ActiveShape;
class FigureGenerator;

// Класс GameController отвечает за игровую логику, отклик на действия игрока.
// Каждый тик вызывает метод doStep(), который и двигает фигурки
// doStep() передвигает фигуру на единицу поля ниже, если не получается, оставляет фигуру на месте и генерирует новую


class GameController {
private:
    unsigned int width; 
    unsigned int height;
    std::vector <std::vector <ArrayCell> > gameField; // выделить поле в отдельный класс? думаю, да

    std::unique_ptr<TetrisFigure> activeShape;
    FigureGenerator figureGenerator;
    
public:
    GameController(const Settings&);
    ~GameController();
    void doStep(); // перемещает активную фигуру на этаж ниже или генерит новую
    bool checkShapeMoving() const;
    bool isPainted(sf::Vector2u coord) const;
    void displayActiveShapeOnArray();
    void removeActiveShapeFromArray();
    
    friend std::ostream& operator<<(std::ostream &out, const GameController &gmr);
};