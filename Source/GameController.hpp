#pragma once
#include <iostream>
#include <iomanip>
// #include "ArrayCell.hpp"
#include "Settings.hpp"
#include "FigureGenerator.hpp"
#include "TetrisFigure.hpp"
#include "GameField.hpp"

class GameField;
class ActiveShape;
class FigureGenerator;

// Класс GameController отвечает за игровую логику, отклик на действия игрока.
// Каждый тик вызывает метод doStep(), который и двигает фигурки
// doStep() передвигает фигуру на единицу поля ниже, если не получается, оставляет фигуру на месте и генерирует новую


class GameController {
private:
    unsigned height;
    unsigned width;
    GameField gameField;
    std::unique_ptr<TetrisFigure> activeShape;
    FigureGenerator figureGenerator;
    
public:
    GameController(const Settings&);
    ~GameController();
    void doStep(); // перемещает активную фигуру на этаж ниже или генерит новую

private:
    bool canMoveActiveFigureDown() const;
    // bool isPainted(sf::Vector2u coord) const;
    void displayActiveFigure();
    void removeActiveFigure();
    void generateNewActiveFigure();
    
    friend std::ostream& operator<<(std::ostream &out, const GameController &gmr);
};