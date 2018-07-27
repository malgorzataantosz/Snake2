#include <iostream>
#include <chrono>
#include <zconf.h>
#include "Game.hpp"

Game::Game() {
    marking = {{fieldType::SNAKE, 'X'}, {fieldType::EMPTY, ' '}, {fieldType::SEED, 'o'}};
}

void Game::displayBoard() {
    for(int i = 0; i<board::SIZE; i++){
        for(int j = 0; j<board::SIZE; j++){
            std::cout << marking[board.getFieldType(Segment(j,i))];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

}

void Game::mainLoop() {
    while(!board.isLost()){
        system("clear");
        board.updateBoard();
        displayBoard();
        usleep(1000000);

    }

}
