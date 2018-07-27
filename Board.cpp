#include "Board.hpp"

Board::Board() : seed(0, 0), snake(board::SIZE) , lost(false) {
    gameBoard.resize(board::SIZE);
    for (auto i = 0; i < board::SIZE; i++) {
        gameBoard[i] = (std::vector<fieldType>(board::SIZE, fieldType::EMPTY));
    }

    gameBoard[snake.getSegment(0).x][snake.getSegment(0).y] = fieldType::SNAKE;
    gameBoard[snake.getSegment(1).x][snake.getSegment(1).y] = fieldType::SNAKE;
    gameBoard[snake.getSegment(2).x][snake.getSegment(2).y] = fieldType::SNAKE;
    randomizeSeed();
}

fieldType Board::getFieldType(Segment segment) const {
    return gameBoard[segment.x][segment.y];
}

void Board::randomizeSeed() {
    static std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<> dist(0, board::SIZE-1);
    int x;
    int y;
    do {
        x = dist(gen);
        y = dist(gen);
    } while(gameBoard[x][y] == fieldType::SNAKE);
    gameBoard[x][y] = fieldType::SEED;
    seed = Segment(x, y);
}

void Board::updateBoard() {
    snake.extendSnake();
    Segment snakeHead = snake.getSegment(0);
    Segment snakeTail = snake.getSegment(snake.getSize()-1);
    if(gameBoard[snakeHead.x][snakeHead.y]==fieldType::SNAKE){
        if(snakeHead == snakeTail){
            snake.deleteTail();
        }
        else
            lost = true;
    }
    else if (gameBoard[snakeHead.x][snakeHead.y] == fieldType::SEED){
        gameBoard[snakeHead.x][snakeHead.y] = fieldType::SNAKE;
        randomizeSeed();
    }
    else{
        gameBoard[snakeTail.x][snakeTail.y] = fieldType::EMPTY;
        snake.deleteTail();
        gameBoard[snakeHead.x][snakeHead.y] = fieldType::SNAKE;
    }
}

bool Board::isLost() const {
    return lost;
}

void Board::setLost(bool lost) {
    Board::lost = lost;
}

