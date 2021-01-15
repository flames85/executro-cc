#include "position.h"

Position::Position(int x, int y, Direction direction) : 
	x(x), y(y), heading(direction)
{
}

bool Position::operator== (const Position& position) const
{
	return (x == position.x && y == position.y && heading == position.heading);
}