#include "Wall.h"
#include "Square.h"

void Wall::Draw() {
	GotoPosition();
	cout << '#';
}

bool Wall::SetSquare(Square* square) {
    square->SetWall(this);
    return Object::SetSquare(square);
}