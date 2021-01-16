#include "position.h"

Position::Position(int x, int y, Direction direction) : 
	x(x), y(y), heading(direction)
{
}

bool Position::operator== (const Position& position) const
{
	return (x == position.x && y == position.y && heading == position.heading);
}

Position Position::turn(int times) const
{
	static Direction directions[] =
	{
		Direction::EAST,
		Direction::SOUTH,
		Direction::WEST,
		Direction::NORTH
	};

	Direction newHeading = directions[(int(heading) + times) % int(Direction::DIRECTION_MAX_COUNT)];

	return Position{ x, y, newHeading };
}

Position Position::move(int factor) const
{
	static Position positions[] =
	{
		{1, 0,  Direction::EAST},
		{0, -1,  Direction::SOUTH},
		{-1, 0,  Direction::WEST},
		{0, 1,  Direction::NORTH}
	};
	Position step = positions[int(heading)];
	return Position{ x + factor * step.x, y + factor * step.y, heading };
}
