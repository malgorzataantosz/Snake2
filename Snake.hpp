#pragma once

#include <queue>

struct Segment {
    Segment(int x, int y) : x(x), y(y) {}

    bool operator==(const Segment& seg) const {
        return (x==seg.x && y==seg.y);
    }

    bool operator!=(const Segment& seg) const {
        return !operator==(seg);
    }

    int x;
    int y;
};
enum class Direction{
    UP, DOWN, LEFT, RIGHT
};
class Snake{
public:
    Snake(const int SIZE);
    void extendSnake();
    Direction getDirection() const;
    size_t getSize() const;
    void deleteTail();
    Segment getSegment(int index) const;
    void changeDirection(Direction newDirection);

private:
    std::deque<Segment> snakeBody;
    Direction direction;
    const int SIZE;

};