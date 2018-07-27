#pragma once

#include "Board.hpp"

class Game {
public:
    Game();
    void displayBoard ();
    void mainLoop();
private:
    Board board;

    std::map<fieldType, char> marking;
};