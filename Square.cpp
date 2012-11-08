#include "Square.h"

Square::Square() {
	droppingObject = NULL;
	wall = NULL;
}

void Square::StepIn(Player* player) {
	players.push_front(player);
}

void Square::StepOut(Player* player) {
	players.remove(player);
}

void Square::SetPosition(int row, int col) {
    this->row = row;
	this->col = col;
}

bool Square::SetDroppingObject(DroppingObject* droppingObject) {
	if (droppingObject && !this->droppingObject) {
		this->droppingObject = droppingObject;
		return true;
	}
	return false;
}

void Square::SetWall(Wall* wall) {
	this->wall = wall;
}

int Square::GetRow() {
    return row;
}

int Square::GetCol() {
    return col;
}

PlayersList* Square::GetPlayers() {
    return &players;
}

DroppingObject* Square::GetDroppingObject() {
    return droppingObject;
}

Wall* Square::GetWall() {
    return wall;
}

bool Square::IsEmpty() {
	return (!droppingObject && !wall && !players.size());
}