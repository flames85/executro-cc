#pragma once
#include "direction.h"


struct Position {
	Position(int x, int y, Direction direction);
	bool operator== (const Position& position) const;
	Position turn(int times) const;
	Position move(int factor) const;

	int x ;
	int y ;
	Direction heading ;
};

