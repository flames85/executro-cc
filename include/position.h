#pragma once
#include "direction.h"

struct Position {
	Position(int x, int y, Direction direction);
	bool operator== (const Position& position) const;

	int x;
	int y;
	Direction heading;
};

