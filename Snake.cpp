
#include "Snake.hpp"

Direction Snake::getDirection() const {
    return direction;
}

void Snake::extendSnake() {
    Segment oldHead = snakeBody.front();
    switch(direction) {
        case Direction::UP:
            oldHead.y--;
            if(oldHead.y < 0)
                oldHead.y += SIZE;
            break;
        case Direction::DOWN:
            oldHead.y++;
            if(oldHead.y >= SIZE)
                oldHead.y = 0;
            break;
        case Direction::LEFT:
            oldHead.x--;
            if(oldHead.x < 0)
                oldHead.x += SIZE;
            break;
        case Direction::RIGHT:
            oldHead.x++;
            if(oldHead.x >= SIZE)
                oldHead.x = 0;
            break;
    }
    snakeBody.push_front(oldHead);
}

size_t Snake::getSize() const {
    return snakeBody.size();
}

Snake::Snake(const int SIZE): SIZE(SIZE) {
    snakeBody.push_back(Segment(SIZE/2, SIZE/2));
    snakeBody.push_back(Segment(SIZE/2, SIZE/2+1));
    snakeBody.push_back(Segment(SIZE/2, SIZE/2+2));

    direction = Direction::UP;
}

void Snake::deleteTail() {

    snakeBody.pop_back();
}

Segment Snake::getSegment(int index) const {
    return snakeBody.at(index);
}

void Snake::changeDirection(Direction newDirection) {
    direction = newDirection;
}
