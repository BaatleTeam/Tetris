#pragma once
#include <iostream>

enum class FigureType {
    NoType = 0,
    Type0,
    Type1,
    Type2,
    Type3,
    Type4,
    Type5,
    Type6,
};

inline std::ostream& operator<<(std::ostream& out, FigureType ft){
    switch (ft){
        case FigureType::NoType:
            out << "Figure type - no type. ";
            break;
        case FigureType::Type0:
            out << "Figure Type - 0";
            break;
        case FigureType::Type1:
            out << "Figure Type - 1. ";
            break;
        case FigureType::Type2:
            out << "Figure Type - 2. ";
            break;
        case FigureType::Type3:
            out << "Figure Type - 3. ";
            break;
        case FigureType::Type4:
            out << "Figure Type - 4. ";
            break;
        case FigureType::Type5:
            out << "Figure Type - 5. ";
            break;
        case FigureType::Type6:
            out << "Figure Type - 6. ";
            break;
        default:
            throw "Try to handle no-exist type of figure. operator<<\n";
    }
    return out;
}
