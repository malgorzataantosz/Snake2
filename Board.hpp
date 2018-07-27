#pragma once

#include <map>
#include <random>

#include "Snake.hpp"
namespace board {
    const int SIZE = 20;
}
enum class fieldType{
    SEED, SNAKE, EMPTY
};

class Board {
public:
    Board();
    fieldType getFieldType(Segment segment) const;
    void randomizeSeed();
    void updateBoard();

    bool isLost() const;

    void setLost(bool lost);

private:
    Snake snake;
    Segment seed;
    std::vector<std::vector<fieldType>> gameBoard;
    bool lost;
};