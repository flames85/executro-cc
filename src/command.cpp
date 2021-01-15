#include "command.h"


namespace
{
	Position turn(const Position& pos, int times)
	{
		static Direction directions[] = { EAST, SOUTH, WEST, NORTH };
		Direction heading = directions[(pos.heading + times) % DIRECTION_MAX_COUNT];

		return Position{ pos.x, pos.y, heading };
	}

	Position moveX(const Position& pos, int times)
	{
		return Position{ pos.x + times, pos.y, pos.heading };
	}

}

Position CommandTurnLeft::exec(const Position& pos) const
{
	return turn(pos, 3);
}

Position CommandTurnRight::exec(const Position& pos) const
{
	return turn(pos, 1);
}


Position CommandTurnRound::exec(const Position& pos) const
{
	return turn(pos, 2);
}

Position CommandForward::exec(const Position& pos) const
{
	return moveX(pos, 1);
}

Position CommandBackward::exec(const Position& pos) const
{
	return moveX(pos, -1);
}