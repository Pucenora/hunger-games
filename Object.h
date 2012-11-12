#ifndef _OBJECT_H
#define _OBJECT_H

#include "Dimensions.h"
#include "Gotoxy.h"
#include "Console.h"
#include <iostream>

using namespace std;

class Square;
class Game;

class Object
{
    Dimensions size;
    Game* game;
    Square* square;

public:
    Object();
    ~Object();

    virtual void Draw() {};
    virtual void SetSquare(Square* square);
    void SetGame(Game* game);
    void GotoPosition();
    void Clear();
    Dimensions* GetSize();
    Game* GetGame();
    Square* GetSquare();
    bool InArea(Square *square);
};

#endif