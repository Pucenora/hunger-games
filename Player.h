#ifndef _PLAYER_H
#define _PLAYER_H

#include "MovingObject.h"

class Player : public MovingObject
{
    enum {
        INITIAL_POWER                   = 1000,
        INITIAL_NUM_ARROWS              = 4,
        MIN_TICKS_BETWEEN_ARROWS        = 3,
        SHOOT_ARROW_PROBABILITY         = 20,
        CHANGE_DIRECTION_PROBABILITY    = 10,
        MOVE_INTERVAL                   = 2
    };

    char name;
    int power;
    int remainingArrows;
    unsigned int lastArrowTick;

    void fight(Player& opponent);
    void setRandomDirection();
    void shootArrow();
    Grid::Square& getNextMove();

    DroppingObject* findClosestObject() const;
    bool checkWallsInPath(const Grid::Square& target) const;
    bool hasPlayersInRange() const;
    bool playerInRange(const Player& opponent) const;

public:
    Player(char name, int power = INITIAL_POWER, Direction direction = RIGHT);
    ~Player();

    void setSquare(Grid::Square& square);
    void update();
    void increasePower(int amount);
    void decreasePower(int amount);
    void addArrows(int amount);

    char getName() const;
    int getPower() const;
    int getRemainingArrows() const;
    void draw() const;
};

#endif